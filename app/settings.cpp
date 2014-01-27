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

#include <QDebug>
#include <QStringList>
#include "settings.h"

Settings::Settings(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings (staticSettingsFile(), QSettings::IniFormat, this);
    m_allkeys = m_settings->allKeys();
}

const QString&  Settings::version ()
{
    return m_settings->value ("VERSION").toString();
}

const QString&  Settings::logDir ()
{
    return m_settings->value ("directories/LOGFILE").toString();
}

const QString&  Settings::clepsydraDir ()
{
    return m_settings->value ("directories/CLEPSYDRADIR").toString();
}

const QString& Settings::workdir()
{
    return m_settings->value ("directories/CLEPSYDRAWORK").toString();
}

int Settings::gracePeriod ()
{
    return m_settings->value ("variables/GRACEPERIOD").toInt();
}

int Settings::polltime ()
{
    return m_settings->value ("variables/POLLTIME").toInt();
}

const QString& Settings::lockLasts()
{
    return m_settings->value ("variables/LOCKLASTS").toString();
}

