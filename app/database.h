#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QVariantMap>
#include <QObject>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = 0);

public:

    //
    // Get limits for user, if user not found,
    // the new limits for user will be inserted and default limits returned for caller.
    //

    void getLimits (const QString&, QVariantMap&);
    void addLimits (const QString&, const QVariantMap&);
    void updateLimits (const QString&, const QVariantMap&);

private:
    void getDefaults ();

private:
    QSqlDatabase m_db;
    QVariantMap  m_map;

};

#endif // DATABASE_H
