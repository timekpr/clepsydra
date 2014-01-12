#include <QtDBus>
#include "user.h"

User::User(QObject *parent) :
    QObject(parent)
{
}

void User::setObjectPath(const QString& path)
{
    m_path = path;
    loadUserInfo();
}

void User::loadUserInfo()
{
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface adbus_iface("org.freedesktop.Accounts",
       m_path,"org.freedesktop.Accounts.User", bus);

    m_userName = adbus_iface.property("UserName").toString();
    m_uid = adbus_iface.property("Uid").toString();
    m_accountType = adbus_iface.property("AccountType").toInt();
    qDebug() << m_userName;
}
