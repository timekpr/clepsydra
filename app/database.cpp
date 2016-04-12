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

#include <QDebug>
#include <QFile>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include "config.h"
#include "database.h"

Database::Database(QObject *parent) : QObject (parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    // TODO Change working folder name for real folder name later on !!!!!
    m_path = QString().append(CLEPSYDRA_WORKING_FOLDER).append(CLEPSYDRA_SQLITE_FILE);
    if (!checkDbExists())  {
        qDebug() << "Error: Database cannot be found !!!! ";
        return;
    }
    m_db.setDatabaseName (m_path);
    if (!m_db.open())  {
       qDebug() << "Error: connection with database fail";
    }
    else  {
       qDebug() << "Database: connection ok";
    }
    // Just making application working for smoother.
    getDefaults ();
}

bool Database::getUserLimits(const QString &name, QVariantMap &map)
{
    QSqlQuery query;
    query.prepare("SELECT FROM limits WHERE account = (:account)");
    query.bindValue(":account", name);
    bool success = query.exec();
    if(!success)  {
        QSqlRecord record = query.record();
        if (query.next()) {
            for (int i=0; i<record.count(); ++i) {
                m_map.insert(record.fieldName(i), query.value(i));
            }
        } else {            
            map = m_map;
            map.insert( ("account"), name);
            saveLimits(map);
        }
    }
    return true;
}


void Database::saveLimits (const QVariantMap &map)
{
    QSqlQuery query;
    qDebug () << map;

    query.prepare("INSERT INTO limits (account, active, bounded, boundedByDay )  " \
        "VALUES (:account, :active, :bounded, :boundedByDay );" \
                 " " );

    query.bindValue(":account", map.value("account").toString());
    query.bindValue(":active", map.value("active").toBool());
    query.bindValue(":bounded", map.value("bounded").toBool());
    query.bindValue(":boundedByDay", map.value("boundedByDay").toBool());

    query.bindValue(":limitAccessOnDuration", map.value("limitAccessOnDuration"));
    // query.bindValue(":limitAccessOnDurationEachDay", map.value("limitAccessOnDurationEachDay"));
    // query.bindValue(":limitAccessOnDurationEachDayTime", map.value("limitAccessOnDurationEachDayTime"));
    // query.bindValue(":limitAccessOnDurationPerDay", map.value("limitAccessOnDurationPerDay"));
    //query.bindValue(":limitAccessOnDurationPerDayTime", map.value("limitAccessOnDurationPerDayTime"));

    // query.bindValue(":limitAccessOnTimeFrame", map.value("limitAccessOnTimeFrame"));

    //query.bindValue(":limitAccessOnTimeFrameEachDay", map.value("limitAccessOnTimeFrameEachDay"));
    //query.bindValue(":limitAccessOnTimeFramePerDay", map.value("limitAccessOnTimeFramePerDay"));
    //query.bindValue(":limitAccessOnTimeFrameEachDayTime", map.value("limitAccessOnTimeFrameEachDayTime"));
    //query.bindValue(":limitAccessOnTimeFramePerDayTime", map.value("limitAccessOnTimeFramePerDayTime"));

    bool success = query.exec();
    if (success)  {
        qDebug () << "Db row inserted " << map.value("account");
    } else {
        qDebug () << query.lastError();
    }
}

void Database::updateLimits(const QString &, const QVariantMap &)
{
}

bool Database::checkDbExists()
{
    QFile file(m_path);
    return file.exists();
}

void Database::getDefaults()
{
    QSqlQuery query;
    query.exec("SELECT * FROM defaults");
    while (query.next()) {
        QSqlRecord record = query.record();
        m_map.clear();
        for (int i=0; i<record.count(); ++i) {
            m_map.insert(record.fieldName(i), query.value(i));
        }
    }
}

