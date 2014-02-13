// Copyright (c) 2014 Olli-Pekka Wallin <opwallin@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QtDBus>
#include "user.h"

#define KEY_ACCOUNT_LOCKED "AccountLocked"

User::User(QObject *parent) :
    QObject(parent)
{
}

User::~User()
{
}

void User::setObjectPath(const QString& path)
{
    m_path = path;
    loadUserInfo();
}

bool User::isAdmin()
{
    bool reply = false;
    if (m_accountType!=0)
        reply = true;
    return reply;
}

bool User::isLocked()
{
    return m_accountLimits.key(KEY_ACCOUNT_LOCKED).toInt();
}

QString User::UserName() const
{
    return m_userName;
}

void User::loadUserInfo()
{
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface adbus_iface("org.freedesktop.Accounts",
       m_path,"org.freedesktop.Accounts.User", bus);

    m_userName = adbus_iface.property("UserName").toString();
    m_uid = adbus_iface.property("Uid").toString();
    m_accountLimits.insert(KEY_ACCOUNT_LOCKED, adbus_iface.property("Locked").toBool() );
    m_accountType = adbus_iface.property("AccountType").toInt();
}
