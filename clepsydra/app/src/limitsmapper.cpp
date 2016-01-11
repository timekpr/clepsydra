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
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QJsonDocument>

#include "config.h"
#include "limitsmapper.h"



Storage::Storage(QObject *parent) :
    QObject(parent)
{
    readDefaultLimits ();
}

void Storage::readDefaultLimits()
{
    QString filename = QString(CLEPSYDRA_CONFIG_FOLDER).append(CLEPSYDRA_JSON_DEFAULTS_FILENAME);
    QFile file;
    QString data=NULL;
    file.setFileName(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)==true) {
        data = file.readAll();
        file.close();
    } else {
        qDebug () << filename << "json file not found";
        return;
    }
    QJsonDocument d = QJsonDocument::fromJson(data.toUtf8());
    if (d.isEmpty()) {
        qDebug () << "Not valid document.";
        return;
    }
    QJsonObject obj = d.object();
    QVariantMap tempData = obj.toVariantMap();
    m_defaultLimits = tempData.take("default").toMap();
}

// This method save all users limists to working dir and file
void Storage::saveLimits(const QVariantMap& map )
{
    QJsonDocument d = QJsonDocument::fromVariant(map);
    if (d.isEmpty())  {
        qDebug () << "empty";
    } else {
        QString filename = CLEPSYDRA_WORKING_FOLDER;
        filename.append(CLEPSYDRA_JSON_USERDATA_FILENAME);
        QFile file(filename);
        if (!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        // out << d.toJson();
        file.close();
    }
}

QVariantMap& Storage::getDefaultLimits()
{    
    return m_defaultLimits;
}


bool Storage::getUserLimits (const QString& user, QVariantMap& target)
{
    QString val;
    QFile file;
    QString filename = QString (CLEPSYDRA_WORKING_FOLDER).append(CLEPSYDRA_JSON_USERDATA_FILENAME);
    file.setFileName(filename);
    if ( !file.isReadable() ) {
        //
        return false;
    }
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)==true) {
        val = file.readAll();
        file.close();
    } else {
        qDebug () << filename << "json file not found";
        return false;
    }

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    if (d.isEmpty()) {
        qDebug () << "Not valid document.";
        return false;
    }

    QJsonObject obj = d.object();
    QJsonValue mapArray = obj.value(user);
    if (mapArray.isUndefined()) {
        qDebug () << "User not found from limits.";
        return false;
    }

    QVariantMap dataC = mapArray.toObject().toVariantMap();
    target = dataC.take(user).toMap();
    return true;
}

void Storage::readGroups2Map(QVariantMap& target, const QString &file)
{
    target.clear();
    QSettings* limits = new QSettings (file, QSettings::IniFormat, this);
    QStringList groups = limits->childGroups();
    if (groups.count()) {
        foreach (const QString& group, groups) {
            QVariantMap variantMap;
            limits->beginGroup(group);
            QStringList keylist = limits->allKeys();
            foreach (const QString& key, keylist) {
                variantMap.insert(key, limits->value(key));
            }
            target.insert(group, variantMap);
            limits->endGroup();
        }
    }
    delete limits;
}


