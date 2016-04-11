#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QVariantMap>
#include <database_base.h>

class Database : public QObject, public DatabaseBase
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = 0);

public:

    //
    // Get limits for user, if user not found,
    // the new limits for user will be inserted and default limits returned for caller.
    //

    bool getUserLimits (const QString&, QVariantMap&);
    //
    void saveLimits (const QVariantMap&);

    void updateLimits (const QString&, const QVariantMap&);

    QVariantMap& getDefaultLimits () {return m_map;}

private:
    void getDefaults ();
    bool checkDbExists ();

private:
    QSqlDatabase m_db;
    QVariantMap  m_map;
    QString m_path;
};

#endif // DATABASE_H
