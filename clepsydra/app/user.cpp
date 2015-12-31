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
#include <QVariantMap>
#include "user.h"

#include "config.h"

User::User(QObject *parent) :
    QObject(parent)
{
}

User::~User()
{
}

QVariantMap& User::getUserData ()
{
    return m_accountLimits;
}

void User::setUserData (const QVariantMap& data )
{
    m_accountLimits = data;
}

void User::setObjectPath(const QString& path)
{
    m_path = path;
    loadUserInfo();
}

bool User::isAdmin()
{
    bool reply = false;
    if (m_isAdmin!=0)
        reply = true;
    return reply;
}

void User::setValue (const QString& settings, bool newVal)
{
    if (settings == CLEPSYDRA_LOCKED && m_isAdmin)  {
        // Make sure that admin accounts are not locked
        m_isLocked = false;
        return;
    } else {
        m_isLocked = newVal;
    }
    if (m_accountLimits.contains("default") ) {
        QVariantMap data = m_accountLimits.value("default").toMap();
        data.insert(settings, m_isLocked);
        m_accountLimits.insert("default", data);
    }
}

bool User::isLocked()
{
    return m_isLocked;
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
    m_isLocked = adbus_iface.property("Locked").toBool();
    m_isAdmin = adbus_iface.property("AccountType").toInt();
}
