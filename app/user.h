#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT

public:
    explicit User(QObject *parent = 0);
    
    // Set object path and init default values for it.
    void setObjectPath(const QString&);

public:     // Getters

    bool isAdmin ();
    bool isLocked();
    QString Uid();
    QString UserName () const;

private:
    void loadUserInfo ();

private:
    QString m_path;
    QString m_userName;
    QString m_uid;
    quint32 m_accountType;  // If true, user is member of 'Sudoers'.

};

#endif // USER_H
