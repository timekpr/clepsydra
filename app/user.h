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

#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT

public:
    explicit User(QObject *parent = 0);

    ~User ();
    
    // Set object path and init default values for it.
    void setObjectPath(const QString&);

public:     // Getters

    bool isAdmin ();
    bool isLocked();
    QString Uid();
    QString UserName () const;

private:
    void loadUserInfo ();

private:
    QString m_path;
    QString m_userName;
    bool    m_isLocked;
    QString m_uid;
    quint32 m_accountType;  // If true, user is member of 'Sudoers'.

};

#endif // USER_H
