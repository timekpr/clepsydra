#include <QtDBus>
#include "users.h"

Users::Users(QObject *parent) :
    QObject(parent)
{
}

void Users::getStandardUsers()
{

//    QDBusConnection::sessionBus().connect("org.gnome.SessionManager", "/org/gnome/SessionManager/Presence", "org.gnome.SessionManager.Presence" ,"StatusChanged", this, SLOT(MySlot(uint)));
//    // https://github.com/mauios/qtaccountsservice
    QDBusConnection bus = QDBusConnection::systemBus();
//    // org.freedesktop.Accounts
    QDBusInterface adbus_iface("org.freedesktop.Accounts", "/org/freedesktop/Accounts/User1000",
       "org.freedesktop.Accounts.User", bus);

    qDebug() << "username" <<  adbus_iface.property("UserName").toString();
    qDebug() << "account type" <<  adbus_iface.property("AccountType").toInt();
    qDebug() << "Shell" <<  adbus_iface.property("Shell").toString();

//    QDBusInterface dbus_iface("org.freedesktop.Avahi", "/",
//       "org.freedesktop.Avahi.Server", bus);


//    QVariant api = dbus_iface.call( "GetAPIVersion").arguments().at(0);
//    qDebug () << "Avahi api version" << api.toInt();
//    QVariant hostName = dbus_iface.call( "GetHostName").arguments().at(0);
//    qDebug () << "Running on " << hostName.toString();
}
