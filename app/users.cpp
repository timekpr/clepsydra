#include <QtDBus>
#include "users.h"

Users::Users(QObject *parent) :
    QObject(parent)
{
}

void Users::getStandardUsers()
{
//    // https://github.com/mauios/qtaccountsservice
//    QDBusConnection bus = QDBusConnection::systemBus();
//    // org.freedesktop.Accounts
//    QDBusInterface dbus_iface("org.freedesktop.Accounts", "/org/freedesktop/Accounts",
//                              "org.freedesktop.DBus.Properties", bus);
//                              //"org.freedesktop.Accounts.User", bus);



//    // Calls DBus method
//    QDBusMessage result = dbus_iface.call( "GetAll",
//                                          "(a{sv})",
//                                          "Interfaces" );
//    qDebug() << result;
//    //qDebug() << dbus_iface.isValid();
//    //qDebug() << dbus_iface.call("Get").arguments().append(QString("(a{sv})"));
}
