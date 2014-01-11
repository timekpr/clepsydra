#include <QtDBus>
#include "user.h"

User::User(QObject *parent) :
    QObject(parent)
{
}

void User::getStandardUsers()
{

//    QDBusConnection::sessionBus().connect("org.gnome.SessionManager", "/org/gnome/SessionManager/Presence", "org.gnome.SessionManager.Presence" ,"StatusChanged", this, SLOT(MySlot(uint)));
//    // https://github.com/mauios/qtaccountsservice
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface adbus_iface("org.freedesktop.Accounts",
       "/org/freedesktop/Accounts/User1000",
       "org.freedesktop.Accounts.User", bus);

    qDebug() << "username" <<  adbus_iface.property("UserName").toString();
    qDebug() << "account type" <<  adbus_iface.property("AccountType").toInt();
    qDebug() << "Shell" <<  adbus_iface.property("Shell").toString();

}
