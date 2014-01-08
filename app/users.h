#ifndef USERS_H
#define USERS_H

#include <QObject>

class Users : public QObject
{
    Q_OBJECT
public:
    explicit Users(QObject *parent = 0);
    
    void getStandardUsers ();
};

#endif // USERS_H
