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

#ifndef LIMITSMAPPER_H
#define LIMITSMAPPER_H

#include <QVariantMap>
#include <QObject>

class Storage : public QObject
{
    Q_OBJECT
public:
    explicit Storage(QObject *parent = 0);  

public:

    virtual void getLimits (const QString&, const QString&)=0;

    virtual void readGroups2Map (QVariantMap&, const QString&)=0;
    //
    virtual void saveLimits(const QVariantMap& map)=0;

    // Return false if user not found or error occurs otherwise true
    // if limists found for user.
    virtual bool getUserLimits (const QString& user, QVariantMap&)=0;

    //
    QVariantMap&    getDefaultLimits ();

private :

    void  readDefaultLimits ();

private:
    QVariantMap m_groupMaps;
    QVariantMap m_defaultLimits;
    
};

#endif // LIMITSMAPPER_H
