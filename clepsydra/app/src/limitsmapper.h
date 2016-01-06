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

class LimitsMapper : public QObject
{
    Q_OBJECT
public:
    explicit LimitsMapper(QObject *parent = 0);  

public:
    void getLimits (const QString&, const QString&);

    void readGroups2Map (QVariantMap&, const QString&);
    //
    void map2Json(const QVariantMap& map);

    // Return false if user not found or error occurs otherwise true
    // if limists found for user.
    bool json2Map (const QString& user, QVariantMap&);

    //
    QVariantMap&    getDefaultLimits ();

private :

    void  readDefaultLimits ();

private:
    QVariantMap m_groupMaps;
    QVariantMap m_defaultLimits;
    
};

#endif // LIMITSMAPPER_H
