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

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <QObject>
#include <QList>
#include "user.h"

class Accounts : public QObject
{
    Q_OBJECT
public:
    explicit Accounts(QObject *parent = 0);
    
    ~Accounts ();

    User*   getUser (int) const;
    int   getCurrentLoginUserIndex () const;
    int getFirstNonAdminUserIndex () const;
    int usersCount() const;

public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.Accounts"; }

private:

    void init ();

private:
    QList<User*>    m_users;

};

#endif // ACCOUNTS_H
