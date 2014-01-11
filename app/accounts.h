#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <QObject>
#include <QList>
#include "user.h"

class Accounts : public QObject
{
    Q_OBJECT
public:
    explicit Accounts(QObject *parent = 0);
    
    // Get users
    void getUsers ();

public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.Accounts"; }

private:

};

#endif // ACCOUNTS_H
