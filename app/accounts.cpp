
#include <QtDBus>
#include "accounts.h"
#include "user.h"

Accounts::Accounts(QObject *parent) :
    QObject(parent)
{
    m_users = new QList<User*>();
}

Accounts::~Accounts ()
{
    m_users->clear();
    delete m_users;
}

void  Accounts::getUsers()
{
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface adbus_iface("org.freedesktop.Accounts",
       "/org/freedesktop/Accounts",
       "org.freedesktop.Accounts", bus);
    QList<QVariant> argumentList;
    QDBusMessage msg = adbus_iface.callWithArgumentList(QDBus::AutoDetect, "ListCachedUsers", argumentList);

    QList<QVariant> outArgs = msg.arguments();
    QVariant first = outArgs.at(0);
    const QDBusArgument& dbvFirst = first.value<QDBusArgument>();
    QDBusObjectPath path;
    dbvFirst.beginArray();
    while (!dbvFirst.atEnd())  {
        User *user = new User();
        dbvFirst >> path;
        user->setObjectPath(path.path());
        m_users->append(user);
      }
    dbvFirst.endArray();
}

