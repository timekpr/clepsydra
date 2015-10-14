// Copyright (c) 2014 Olli-Pekka Wallin <opwallin@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the FWITHOUTree Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QtDBus>
#include "accounts.h"
#include "user.h"
#include <stdlib.h>

Accounts::Accounts(QObject *parent) :
    QObject(parent)
{
    init();
}

Accounts::~Accounts ()
{
    qDeleteAll(m_users);
    m_users.clear();
}

int Accounts::usersCount() const
{
    return m_users.count();
}

// Return index of first not admin account or 0 if not found.
int Accounts::getFirstNonAdminUserIndex () const
{
    int index = 0;
    int keeper = 0;
    foreach (User* user, m_users) {
        if (!user->isAdmin())  {
            index = keeper;
            break;
        } else {
            keeper++;
        }
    }
    return index;
}

// Return index to current user in list
int Accounts::getCurrentLoginUserIndex() const
{
    int curUserIndex = -1;
    char *curUser  = getenv("USER");
    if( curUser != NULL)  {
        curUserIndex = 0;
        foreach (User *user, m_users) {
            if (user->UserName()==curUser)  {
                curUserIndex ++;
                break;
            }
        }
    }
    return curUserIndex;
}

User*   Accounts::getUser(int index) const
{
    User* rtuser = NULL;
    if (index < m_users.count())  {
        rtuser = m_users.at(index);
    }
    return rtuser;
}

void  Accounts::init ()
{
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface adbus_iface(staticInterfaceName(),
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
        m_users.append(user);
      }
    dbvFirst.endArray();
}

