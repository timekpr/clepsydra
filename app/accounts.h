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
    
    ~Accounts ();

    // Get users
    void getUsers ();

public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.Accounts"; }


private:
    QList<User*>*    m_users;

};

#endif // ACCOUNTS_H
