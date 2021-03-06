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
#include <QDir>

#include "config.h"
#include "logging.h"

#if (defined (LINUX) || defined (__linux__))
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

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
    homepath.append(name);
    m_logger.setFileName(homepath);
}


void Logging::logHexData (const QString& data, const QString& header)
{
    m_logger.open(QIODevice::Append);
    /* Check it opened OK */
    if(!m_logger.isOpen()){
        qDebug()  << "- Error, unable to open" << m_logger.fileName() << "for output";
        return;
    }

    /* Point a QTextStream object at the file */
    QTextStream outStream(&m_logger);
    /* Write the line to the file */

    outStream << "\n" << header << "\n\n" ;

    outStream << data;

    outStream << "\n\n ";
    // m_logger.write(data.toStdString().c_str(), data.length() );
    m_logger.close();
}

void Logging::logByteData (unsigned char *array, int len)
{
    QString result;
    int numInLine = 0;
    result.reserve(3 * len - 1);
    for(unsigned char* i = array, *end = array + len; i < end; ++i, ++numInLine) {
        if(!result.isEmpty()) {
            result += QLatin1Char(' ');
        }
        if (numInLine >= 20 )  {
            result += QLatin1Char('\n');
            numInLine = 0;
        }
        result += QString("%1").arg(static_cast<uint>(*i), 2, 16, QLatin1Char('0'));
    }
    result += QLatin1Char('\n');
    logHexData(result, "foof");
}

#if (defined (LINUX) || defined (__linux__))

const QByteArray& Logging::getRandomData(int len)
{
    int random_generarator = open("/dev/random", O_RDONLY);
    char buffer[50];
    size_t dataLen = len;
    while (dataLen < sizeof(buffer))  {
        ssize_t result = read(random_generarator, buffer + dataLen, (sizeof buffer) - dataLen);
        if (result < 0) {
           // error, unable to read /dev/random
        }
       dataLen += result;
    }
    close(random_generarator);
    m_randomData.append((const char*)buffer, sizeof (buffer));
    qDebug () << m_randomData;
    return m_randomData;
}

#endif


