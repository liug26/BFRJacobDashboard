#include "canhandler.h"

CanHandler::CanHandler(QObject *parent) :
    QObject(parent)
{
}

QString CanHandler::userName()
{
    return m_userName;
}

void CanHandler::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
