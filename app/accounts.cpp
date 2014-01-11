
#include <QtDBus>
#include "accounts.h"
#include "user.h"

Accounts::Accounts(QObject *parent) :
    QObject(parent)
{
}

void  Accounts::getUsers()
{
    // QList<User> users;
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface adbus_iface("org.freedesktop.Accounts",
       "/org/freedesktop/Accounts",
       "org.freedesktop.Accounts", bus);
    QList<QVariant> argumentList;
    qDebug() << adbus_iface.callWithArgumentList(QDBus::AutoDetect, "ListCachedUsers", argumentList);
//    inline QDBusPendingReply<QList<QDBusObjectPath> > ListCachedUsers()
//    {
//        QList<QVariant> argumentList;
//        return asyncCallWithArgumentList(QLatin1String("ListCachedUsers"), argumentList);
//    }
    //return users;
}


