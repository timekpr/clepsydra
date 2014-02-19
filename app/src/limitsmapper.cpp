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

#include <QSettings>
#include <QStringList>
#include <QDebug>
#include "limitsmapper.h"

LimitsMapper::LimitsMapper(QObject *parent) :
    QObject(parent)
{
}

void LimitsMapper::getLimits(const QString& location, const QString& groupName)
{
    QSettings* limits = new QSettings (location, QSettings::IniFormat, this);
    limits->beginGroup(groupName);
    QStringList keylist = limits->allKeys();

    foreach (const QString& key, keylist) {
        qDebug () << key;
    }
}

