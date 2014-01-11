#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <QObject>
#include "user.h"

class Accounts : public QObject
{
    Q_OBJECT
public:
    explicit Accounts(QObject *parent = 0);
    
    // Get users
    QList<User> getUsers ();

public:

private:

};

#endif // ACCOUNTS_H
