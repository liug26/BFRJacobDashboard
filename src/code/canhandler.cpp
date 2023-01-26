#include "canhandler.h"
#include "external_libs/aemnet_definitions.h"
#include "./utils.h"

using aemnet_utils::msg_t;
using aemnet_utils::msg_00_t;
using aemnet_utils::msg_03_t;
using aemnet_utils::msg_04_t;
using aemnet_utils::msg_08_t;
using aemnet_utils::msg_09_t;

using namespace Utils;

CanHandler::CanHandler(QObject *parent) :
    QObject(parent),
    m_busStatusTimer(new QTimer(this))
{
    connectCanBus();

    connect(m_busStatusTimer, &QTimer::timeout, this, &CanHandler::busStatus);
}

void CanHandler::connectCanBus()
{
    QString errorString;
    m_canDevice.reset(QCanBus::instance()->createDevice("socketcan", "can0",
                                                        &errorString));
    if (!m_canDevice) {
        setCanStatusMessage(tr("Error creating device '%1', reason: '%2'")
                            .arg("socketcan").arg(errorString));
        return;
    }

    connect(m_canDevice.get(), &QCanBusDevice::errorOccurred,
            this, &CanHandler::processErrors);
    connect(m_canDevice.get(), &QCanBusDevice::framesReceived,
            this, &CanHandler::processReceivedFrames);
    connect(m_canDevice.get(), &QCanBusDevice::framesWritten,
            this, &CanHandler::processFramesWritten);

    if (!m_canDevice->connectDevice()) {
        setCanStatusMessage(m_canDevice->errorString());

        m_canDevice.reset();
    } else {
        setCanStatusMessage("Connection Appears to have Succeeded!");

        const QVariant bitRate = m_canDevice->configurationParameter(QCanBusDevice::BitRateKey);
        if (bitRate.isValid()) {
            //            const bool isCanFd =
            //                    m_canDevice->configurationParameter(QCanBusDevice::CanFdKey).toBool();
            //            const QVariant dataBitRate =
            //                    m_canDevice->configurationParameter(QCanBusDevice::DataBitRateKey);
            //            if (isCanFd && dataBitRate.isValid()) {
            //                setSocketCanStatus(tr("Plugin: %1, connected to %2 at %3 / %4 kBit/s")
            //                `                  .arg(p.pluginName).arg(p.deviceInterfaceName)
            //                                  .arg(bitRate.toInt() / 1000).arg(dataBitRate.toInt() / 1000));
            //            } else {
            //                setSocketCanStatus(tr("Plugin: %1, connected to %2 at %3 kBit/s")
            //                                  .arg(p.pluginName).arg(p.deviceInterfaceName)
            //                                  .arg(bitRate.toInt() / 1000));
            //            }
        }
        //        else {
        //            setSocketCanStatus(tr("Plugin: %1, connected to %2")
        //                    .arg(p.pluginName).arg(p.deviceInterfaceName));
        //        }

        if (m_canDevice->hasBusStatus())
            m_busStatusTimer->start(2000);
        else
            setSocketCanStatus(tr("No CAN bus status available."));
    }
}

void CanHandler::busStatus()
{
    if (!m_canDevice || !m_canDevice->hasBusStatus()) {
        setSocketCanStatus(tr("No CAN bus status available."));
        m_busStatusTimer->stop();
        return;
    }

    switch (m_canDevice->busStatus()) {
        case QCanBusDevice::CanBusStatus::Good:
            setSocketCanStatus("CAN bus status: Good.");
            break;
        case QCanBusDevice::CanBusStatus::Warning:
            setSocketCanStatus("CAN bus status: Warning.");
            break;
        case QCanBusDevice::CanBusStatus::Error:
            setSocketCanStatus("CAN bus status: Error.");
            break;
        case QCanBusDevice::CanBusStatus::BusOff:
            setSocketCanStatus("CAN bus status: Bus Off.");
            break;
        default:
            setSocketCanStatus("CAN bus status: Unknown.");
            break;
    }
}

static QString frameFlags(const QCanBusFrame &frame)
{
    QString result = QLatin1String(" --- ");

    if (frame.hasBitrateSwitch())
        result[1] = QLatin1Char('B');
    if (frame.hasErrorStateIndicator())
        result[2] = QLatin1Char('E');
    if (frame.hasLocalEcho())
        result[3] = QLatin1Char('L');

    return result;
}



void CanHandler::processReceivedFrames()
{
    if (!m_canDevice)
        return;

    setNumberFramesWritten(m_numberFramesWritten + 1);

    while (m_canDevice->framesAvailable()) {
        const QCanBusFrame frame = m_canDevice->readFrame();

        QString view;
        if (frame.frameType() == QCanBusFrame::ErrorFrame){
            view = m_canDevice->interpretErrorFrame(frame);
            setCanStatusMessage(view);
            return;
        } else
            switch (frame.frameId()) {
                case 0x100:
                    setTestCanData(framePayloadUint(frame));
                    break;
                case 0x1:
                    setRpmData(framePayloadUint(frame));
                    break;
                case 0x2:
                    setCoolantData(framePayloadFloat(frame));
                    break;
                case 0x3:
                    setVoltageData(framePayloadFloat(frame));
                    break;
                case 0x4:
                    setAfrData(framePayloadFloat(frame));
                    break;
                case 0x5:
                    setBiasData(framePayloadFloat(frame));
                    break;
                case AEMNET_MSG_ID(0x00): {
                    msg_00_t* msg_00 = (msg_00_t *)framePayloadMessage(frame);
                    float rpm = fixed_u16_2_float(swap_bytes(msg_00->rpm), 0.39063, 0.0);
                    float coolant_temp = fixed_s8_2_float(msg_00->coolant_temp, 1.0, 0.0);
                    setCoolantData(coolant_temp);
                    setRpmData(rpm);
                    qDebug() << "Coolant Temp: " << coolant_temp << " RPM: " << rpm;
                    break;
                }
                case AEMNET_MSG_ID(0x03):{
                    msg_03_t* msg_03 = (msg_03_t *)framePayloadMessage(frame);
                    float afr1 = fixed_u8_2_float(msg_03->afr1, 0.057227, 7.325);
                    float afr2 = fixed_u8_2_float(msg_03->afr2, 0.057227, 7.325);

                    float battery_voltage = fixed_u16_2_float(swap_bytes(msg_03->battery_voltage), 0.0002455, 0.0);
                    float speed = fixed_u16_2_float(swap_bytes(msg_03->vehicle_speed), 0.00390625, 0.0);

                    // ONLY NEED one of the AFRs
                    setAfrData((afr1 + afr2)/ 2);
                    setVoltageData(6);

                    setGearData(msg_03->gear);
                    setSpeedData(speed);

                    qDebug() << "AFR: " << afr1 << "/" << afr2 << " Voltage: " << battery_voltage << " Gear: " << msg_03->gear;
                    break;
                }
                case AEMNET_MSG_ID(0x04):{
                    // Don't need any data from this one
                    // msg_04_t* msg_04 = (msg_04_t *)framePayloadMessage(frame);
                    // qDebug() << "Oil Pressure: " << msg_04->oil_pressure;
                    break;
                }
                case AEMNET_MSG_ID(0x08):{
                    msg_08_t* msg_08 = (msg_08_t *)framePayloadMessage(frame);
                    qDebug() << "Transmission Temp: " << msg_08->trans_temp << " Bitmap I guess: " << msg_08->bitmap;
                    break;
                }
                case AEMNET_MSG_ID(0x09):{
                    msg_09_t* msg_09 = (msg_09_t *)framePayloadMessage(frame);
                    qDebug() << "Brake Pressure: " << msg_09->brake_pressure << " Boost: " << msg_09->launch_boost_target;
                    break;
                }
            }
    }
}

void CanHandler::processFramesWritten(qint64 count)
{
    setNumberFramesWritten(m_numberFramesWritten + count);
}

void CanHandler::processErrors(QCanBusDevice::CanBusError error)
{
    switch (error) {
        case QCanBusDevice::ReadError:
        case QCanBusDevice::WriteError:
        case QCanBusDevice::ConnectionError:
        case QCanBusDevice::ConfigurationError:
        case QCanBusDevice::UnknownError:
            setCanStatusMessage(m_canDevice->errorString());
            break;
        default:
            break;
    }
}
