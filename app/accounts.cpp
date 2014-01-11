
#include <QtDBus>
#include "accounts.h"

Accounts::Accounts(QObject *parent) :
    QObject(parent)
{
}

Accounts::getUsers()
{
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface adbus_iface("org.freedesktop.Accounts",
       "/org/freedesktop/Accounts",
       "org.freedesktop.Accounts.User", bus);
    // adbus_iface.callWithArgumentList()
}


