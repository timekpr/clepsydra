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


#ifndef LOGGING_H
#define LOGGING_H

#include <QFile>
#include <QObject>

class Logging : public QObject
{
    Q_OBJECT
public:
    explicit Logging(QObject *parent = 0);

    void setFileName (const QString&);
    void logHexData (const QString&, const QString&);
    void logByteData (unsigned char *, int len);

#if (defined (LINUX) || defined (__linux__))
    const QByteArray&  getRandomData (int len);
#endif

private:
    QFile m_logger;
    QByteArray  m_randomData;
};

#endif // LOGGING_H
