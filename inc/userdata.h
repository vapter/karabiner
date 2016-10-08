#ifndef USERDATA_H
#define USERDATA_H


#include "user.h"
#include <QFile>
#include <QDataStream>
#include <QVector>
#include <QApplication>
#include <QStringList>

class UserData : public QObject
{
    Q_OBJECT

public:
    UserData();
    static UserData* GetInstance();

    int SaveUserFile(QString filepath);
    int ParseUserFile(QString filepath);
    int AddNewUser(User user);
    int DeleteUser(QString username);
    int AddNewPwEntry(User* user, PwEntry password_entry);

    QVector<User>* GetUsers();
    User* GetUser(QString username);

signals:
    void userDataChanged(QString newUsername);
    void PwEntryChanged(QString newServiceName);

private:
    static UserData *userdata_instance;
    QVector<User> users;
};

#endif // USERDATA_H
