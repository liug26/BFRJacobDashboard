#include "canhandler.h"


void CanHandler::setNumberFramesWritten(const qint64 &a) {
    if (a != m_numberFramesWritten) {
        m_numberFramesWritten = a;
        emit numberFramesWrittenChanged();
    }
}
qint64 CanHandler::numberFramesWritten() const {
    return m_numberFramesWritten;
}

void CanHandler::setCanStatusMessage(const QString &a) {
    if (a != m_canStatusMessage) {
        m_canStatusMessage = a;
        emit numberFramesWrittenChanged();
    }
}
QString CanHandler::canStatusMessage() const {
    return m_canStatusMessage;
}

void CanHandler::setTestCanData(const qint64 &a) {
    QString test = QStringLiteral("%1").arg(a);
    qDebug() << qPrintable(test);
    if (a != m_canTestData) {
        m_canTestData = a;
        emit testCanDataChanged();
    }
}
qint64 CanHandler::testCanData() const {
    return m_canTestData;
}

void CanHandler::setSocketCanStatus(const QString &a) {
    if (a != m_socketCanStatus) {
        m_socketCanStatus = a;
        emit socketCanStatusChanged();
    }
}
QString CanHandler::socketCanStatus() const {
    return m_socketCanStatus;
}



void CanHandler::setRpmData(const qint64 &a) {
    if (a != m_rmpData) {
        m_rmpData = a;
        emit rpmDataChanged();
    }
}
qint64 CanHandler::rpmData() const {
    return m_rmpData;
}

void CanHandler::setCoolantData(const float &a) {
    if (a != m_coolantData) {
        m_coolantData = a;
        emit coolantDataChanged();
    }
}
float CanHandler::coolantData() const {
    return m_coolantData;
}


void CanHandler::setAfrData(const float &a) {
    if (a != m_afrData) {
        qDebug() << "Setting AFR Data: " << a ;
        m_afrData = a;
        emit afrDataChanged();
    }
}
float CanHandler::afrData() const {
    return m_afrData;
}


void CanHandler::setBiasData(const float &a) {
    if (a != m_biasData) {
        m_biasData = a;
        emit biasDataChanged();
    }
}
float CanHandler::biasData() const {
    return m_biasData;
}


void CanHandler::setVoltageData(const float &a) {
    if (a != m_voltageData) {
        m_voltageData = a;
        emit voltageDataChanged();
    }
}
float CanHandler::voltageData() const {
    return m_voltageData;
}

void CanHandler::setGearData(const qint64 &a) {
    if (a != m_gearData) {
        m_gearData = a;
        emit gearDataChanged();
    }
}
qint64 CanHandler::gearData() const {
    return m_gearData;
}

void CanHandler::setSpeedData(const float &a) {
    if (a != m_speedData) {
        m_speedData = a;
        emit speedDataChanged();
    }
}
float CanHandler::speedData() const {
    return m_speedData;
}
