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
private:
    QFile m_logger;
};

#endif // LOGGING_H
