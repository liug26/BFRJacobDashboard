#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>
#include <QtSerialBus/QCanBus>
#include <QDebug>
#include <QTimer>

class CanHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 numberFramesWritten READ numberFramesWritten WRITE setNumberFramesWritten NOTIFY numberFramesWrittenChanged)
    Q_PROPERTY(QString canStatusMessage READ canStatusMessage WRITE setCanStatusMessage NOTIFY canStatusMessageChanged)
    Q_PROPERTY(QString socketCanStatus READ socketCanStatus WRITE setSocketCanStatus NOTIFY socketCanStatusChanged)
    Q_PROPERTY(qint64 testCanData READ testCanData WRITE setTestCanData NOTIFY testCanDataChanged)


    Q_PROPERTY(qint64 rpmData READ rpmData WRITE setRpmData NOTIFY rpmDataChanged)
    Q_PROPERTY(float coolantData READ coolantData WRITE setCoolantData NOTIFY coolantDataChanged)
    Q_PROPERTY(float afrData READ afrData WRITE setAfrData NOTIFY afrDataChanged)
    Q_PROPERTY(float biasData READ biasData WRITE setBiasData NOTIFY biasDataChanged)
    Q_PROPERTY(float voltageData READ voltageData WRITE setVoltageData NOTIFY voltageDataChanged)
    Q_PROPERTY(qint64 gearData READ gearData WRITE setGearData NOTIFY gearDataChanged)
    Q_PROPERTY(qint64 speedData READ speedData WRITE setSpeedData NOTIFY speedDataChanged)

    QML_ELEMENT

public:
    explicit CanHandler(QObject *parent = nullptr);

    // 0 is success, > 0 is error
    void connectCanBus();
    void processErrors(QCanBusDevice::CanBusError);
    void processReceivedFrames();
    void processFramesWritten(qint64 count);
    void busStatus();

    void setNumberFramesWritten(const qint64 &a);
    qint64 numberFramesWritten() const;

    void setCanStatusMessage(const QString &a);
    QString canStatusMessage() const;

    void setTestCanData(const qint64 &a);
    qint64 testCanData() const;

    void setRpmData(const qint64 &a);
    qint64 rpmData() const;
    void setCoolantData(const float &a);
    float coolantData() const;
    void setAfrData(const float &a);
    float afrData() const;
    void setBiasData(const float &a);
    float biasData() const;
    void setVoltageData(const float &a);
    float voltageData() const;
    void setGearData(const qint64 &a);
    qint64 gearData() const;
    void setSpeedData(const float &a);
    float speedData() const;

    void setSocketCanStatus(const QString &a);
    QString socketCanStatus() const;

signals:
    void numberFramesWrittenChanged();
    void canStatusMessageChanged();
    void socketCanStatusChanged();
    void testCanDataChanged();

    void rpmDataChanged();
    void coolantDataChanged();
    void afrDataChanged();
    void biasDataChanged();
    void voltageDataChanged();
    void gearDataChanged();
    void speedDataChanged();

    void canConnectionFailed(QString err_str);
    void canConnectionSuccess(QString conn_str);

private:
    qint64 m_numberFramesWritten = 0;
    QString m_canStatusMessage = "No Status Yet..";
    QString m_socketCanStatus = "No Status Yet..";
    qint64 m_canTestData = -1;

    qint64 m_rmpData = -1;
    float m_coolantData = -1;
    float m_afrData = -1;
    float m_biasData = -1;
    float m_voltageData = -1;
    qint64 m_gearData = -1;
    float m_speedData = -1;

    std::unique_ptr<QCanBusDevice> m_canDevice;
    QTimer *m_busStatusTimer = nullptr;
};

#endif // BACKEND_H
