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

#include "config.h"
#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QString().append(CLEPSYDRA_WORKING_FOLDER).append(CLEPSYDRA_SQLITE_FILE);
    m_db->setDatabaseName (path);
    if (!m_db.open())  {
       qDebug() << "Error: connection with database fail";
    }
    else  {
       qDebug() << "Database: connection ok";
    }

    // Just making application working for smoother.
    getDefaults ();
}

void Database::getLimits(const QString & name, QVariantMap &map)
{
    QSqlQuery query;
    query.prepare("SELECT FROM limits WHERE user = (:name)");
    query.bindValue(":name", name);
    success = query.exec();
    if(!success)  {
        QSqlRecord record = query.record();
        if (query.next()) {
            for (int i=0; i<record.count(); ++i) {
                map.insert(record.fieldName(i++), query.value(i));
            }
        }
    }
}

void Database::addLimits(const QString &, const QVariantMap &)
{
}

void Database::updateLimits(const QString &, const QVariantMap &)
{
}

