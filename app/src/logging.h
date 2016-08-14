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
    void logByteData (char *, int len);

#if (defined (LINUX) || defined (__linux__))
    const QByteArray&  getRandomData (int len);
#endif

private:
    QFile m_logger;
    QByteArray  m_randomData;
};

#endif // LOGGING_H
