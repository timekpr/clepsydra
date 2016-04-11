// Copyright (c) 2016 Olli-Pekka Wallin <opwallin@gmail.com>

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

#ifndef __DATABASE_BASE_H__
#define __DATABASE_BASE_H__

#include <QVariantMap>
#include <QObject>

class DatabaseBase
{
public:

    //
    virtual void saveLimits(const QVariantMap& map)=0;

    // Return false if user not found or error occurs otherwise true
    // if limists found for user.
    virtual bool getUserLimits (const QString& user, QVariantMap&)=0;

    //
    virtual QVariantMap&    getDefaultLimits ()=0;
    
};

#endif // __DATABASE_BASE_H__
