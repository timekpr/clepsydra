#include <QDebug>
#include <QFile>
#include <QDir>
#include "config.h"
#include "logging.h"

#define APPLICATION_HOME_PATH   ".clepsydra/"

Logging::Logging(QObject *parent) : QObject(parent)
{
}

void Logging::setFileName(const QString &name)
{
    QString homepath (QDir::homePath());
    homepath.append("/").append(QString(APPLICATION_HOME_PATH));
    QDir dir;
    dir.mkdir(homepath);

    qDebug () << homepath;
}


void Logging::logHexData (const QString& data, const QString& /*header*/)
{
    m_logger.open(stderr, QIODevice::WriteOnly);
    m_logger.write(data.toStdString().c_str(), data.length() );
    m_logger.close();
}

