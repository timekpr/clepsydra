
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
    // QDBusMessage msg = adbus_iface.callWithArgumentList(QDBus::AutoDetect, "ListCachedUsers", argumentList);
    QDBusMessage msg = adbus_iface.call("Get","ListCachedUsers");

    QList<QVariant> outArgs = msg.arguments();
    qDebug() << outArgs;

    QVariant first = outArgs.at(0);
    qDebug() << first;

    QDBusVariant dbvFirst = first.value<QDBusVariant>();

//    qDebug() << "msg type " << msg.type();
//    argumentList = msg.arguments();
    //qDebug() << "argumentList" << argumentList.at(0);
    //QVariant vars =  argumentList;
    //QDBusVariant dbvFirst = vars.value<QDBusVariant>();
    QVariant vFirst = dbvFirst.variant();
    qDebug() << "ss" << vFirst;
    const QDBusArgument &dbusArgs = vFirst.value<QDBusArgument>();
    qDebug() << "QDBusArgument current type is" << dbusArgs.currentType();
    qDebug() << "QDBusArgument current type is" << dbusArgs.currentSignature();

    QDBusObjectPath path;
    dbusArgs.beginArray();
    while (!dbusArgs.atEnd())
    {
//        dbusArgs >> path;
        qDebug() << path.path();
        // append path to a vector here if you want to keep it
    }
    dbusArgs.endArray();

}

