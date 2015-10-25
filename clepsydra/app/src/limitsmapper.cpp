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
#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QJsonDocument>
#include "limitsmapper.h"

LimitsMapper::LimitsMapper(QObject *parent) :
    QObject(parent)
{
}

void LimitsMapper::getLimits(const QString& location, const QString& groupName)
{
    m_LimitsMap.clear();
    m_LimitsMap.insert("user", groupName);
    QSettings* limits = new QSettings (location, QSettings::IniFormat, this);
    limits->beginGroup(groupName);
    QStringList keylist = limits->allKeys();
    foreach (const QString& key, keylist) {
        m_LimitsMap.insert(key, limits->value(key));
    }
    delete limits;
}

void LimitsMapper::map2Json(const QString& user, const QVariantMap& map )
{
    QJsonDocument d = QJsonDocument::fromVariant(map);
    if (d.isEmpty())  {
        qDebug () << "empty";
    } else {
        QString filename = "/tmp/";
        filename.append(user + ".json");
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);
        out << d.toJson();
        file.close();
    }
}

void LimitsMapper::getDefaultLimits(QVariantMap& map)
{
    QString filename = QString("/etc/clepsydra/clepsydradefault.json");
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
    map = obj.toVariantMap();
}

void LimitsMapper::json2Map (const QString& user, QVariantMap& map)
{
    QString val;
    QFile file;
    bool hasnotfile = false;
    QString filename = "/tmp/";
    filename.append(user + ".json");
    file.setFileName(filename);
    if ( !file.isReadable() ) {
        // Make sure that users have a at least a defaults
        filename = QString("/etc/clepsydra/clepsydradefault.json");
        file.setFileName(filename);
        hasnotfile = true;
    }
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)==true) {
        val = file.readAll();
        file.close();
    } else {
        qDebug () << filename << "json file not found";
        return;
    }

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    if (d.isEmpty()) {
        qDebug () << "Not valid document.";
        return;
    }
    QJsonObject obj = d.object();
    map = obj.toVariantMap();

    if (hasnotfile)  {
        // save file to filesystem
        map2Json(user, map);
    }
}

void LimitsMapper::readGroups2Map(QVariantMap& target, const QString &file)
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


