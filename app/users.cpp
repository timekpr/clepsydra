#include <QtDBus>
#include "users.h"

Users::Users(QObject *parent) :
    QObject(parent)
{
}

void Users::getStandardUsers()
{
    QDBusConnection bus = QDBusConnection::sessionBus();
    // org.freedesktop.Accounts
    QDBusInterface dbus_iface("org.freedesktop.DBus", "/org/freedesktop/DBus",
                              "org.freedesktop.DBus", bus);
    qDebug() << dbus_iface.call("ListNames").arguments().at(0);
}
