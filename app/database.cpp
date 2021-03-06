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
        qDebug() << "Error: Database cannot be found !!!! " << m_path;
        return;
    }
    m_db.setDatabaseName (m_path);
    if (!m_db.open())  {
       qDebug() << "Error: connection with database fail";
    }
    else  {
       qDebug() << "Database: connection ok";
    }
    // Just making application work for more smoother.
    getDefaults ();
}

bool Database::getUserLimits(const QString &name, QVariantMap &map)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM limits WHERE account = :account;");
    query.bindValue(":account", name);
    bool success = query.exec();
    map.clear();
    if(success)  {
        while (query.next()) {
            QSqlRecord record = query.record();
            for (int i=0; i<record.count(); ++i) {
                map.insert(record.fieldName(i), query.value(i));
            }
        }
    }
    if (map.isEmpty())  {
        map = m_map;
        map.insert( ("account"), name);
        saveLimits(map);
    }
    return true;
}


void Database::saveLimits (const QVariantMap &map)
{
    QSqlQuery query;
    query.prepare("INSERT INTO limits (account, active, bounded, boundedByDay,limitAccessOnDuration, limitAccessOnDurationEachDay, " \
                  " limitAccessOnDurationEachDayTime,limitAccessOnDurationPerDay,limitAccessOnDurationPerDayTime, limitAccessOnTimeFrame, limitAccessOnTimeFrameEachDay, " \
                  "limitAccessOnTimeFrame, limitAccessOnTimeFrameEachDay, limitAccessOnTimeFrameEachDayTime, limitAccessOnTimeFramePerDay, limitAccessOnTimeFramePerDayTime ) "
        "VALUES (:account, :active, :bounded, :boundedByDay, :limitAccessOnDuration, :limitAccessOnDurationEachDay, " \
                 " :limitAccessOnDurationEachDayTime, :limitAccessOnDurationPerDay, :limitAccessOnDurationPerDayTime, :limitAccessOnTimeFrame, :limitAccessOnTimeFrameEachDay," \
                  " :limitAccessOnTimeFrame, :limitAccessOnTimeFrameEachDay, :limitAccessOnTimeFrameEachDayTime, :limitAccessOnTimeFramePerDay, :limitAccessOnTimeFramePerDayTime );" );

    query.bindValue(":account", map.value(CLEPSYDRA_ACCOUNT).toString());
    query.bindValue(":active", map.value(CLEPSYDRA_ACTIVE).toBool());
    query.bindValue(":bounded", map.value(CLEPSYDRA_LIMIT_BOUNDED).toBool());
    query.bindValue(":boundedByDay", map.value(CLEPSYDRA_LIMIT_BOUNDEDBYDAY).toBool());
    query.bindValue(":limitAccessOnDuration", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION).toBool());
    query.bindValue(":limitAccessOnDurationEachDay", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_EACH_DAY).toBool());
    query.bindValue(":limitAccessOnDurationEachDayTime", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_EACH_DAY_TIME).toString());
    query.bindValue(":limitAccessOnDurationPerDay", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_PER_DAY).toBool());
    query.bindValue(":limitAccessOnDurationPerDayTime", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_PER_DAY_TIME).toString());

    query.bindValue(":limitAccessOnTimeFrame", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME).toBool());
    query.bindValue(":limitAccessOnTimeFrameEachDay", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_EACH_DAY).toBool());
    query.bindValue(":limitAccessOnTimeFrameEachDayTime", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_EACH_DAY_TIME).toString());
    query.bindValue(":limitAccessOnTimeFramePerDay", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_PER_DAY).toBool());
    query.bindValue(":limitAccessOnTimeFramePerDayTime", map.value(CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_PER_DAY_TIME).toString());

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


bool Database::updateAccountValues(const QString &name, const QString &key, const QVariant& value)
{
    bool retValue = false;
    if (key == CLEPSYDRA_ACCOUNT)  {
        qDebug() << "it's account key";
        return false;
    }
    QString sql ("UPDATE limits SET ");
    if (value.type() == QVariant::Bool )  {
        sql.append (key).append (" = '" ).append(QString::number(value.toBool())).append("' where account= '").append(name).append("';");
    } else {
        // Should be QVariant::String
        sql.append (key).append (" = '" ).append(value.toString()).append("' where account = '").append(name).append("';");
    }
    QSqlQuery query(sql);
    bool success = query.exec();
    qDebug () << query.lastQuery();
    if (success) {
        retValue = true;
    }
    return retValue;
}

bool Database::checkDbExists()
{
    QFile file(m_path);
    return file.exists();
}

void Database::getDefaults()
{
    QSqlQuery query;
    query.exec("SELECT * FROM defaults;");
    while (query.next()) {
        QSqlRecord record = query.record();
        m_map.clear();
        for (int i=0; i<record.count(); ++i) {
            m_map.insert(record.fieldName(i), query.value(i));
        }
    }
}

