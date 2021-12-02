#ifndef WORKER_H
#define WORKER_H

#include <QString>

class Worker
{
public:
    Worker();
    Worker(QString worid, QString firstname, QString secondname):WorId(worid), FirstName(firstname), SecondName(secondname)
    {

    }

    const QString &getWorId() const;
    void setWorId(const QString &newWorId);

    const QString &getFirstName() const;
    void setFirstName(const QString &newFirstName);

    const QString &getSecondName() const;
    void setSecondName(const QString &newSecondName);

private:
    QString WorId;
    QString FirstName;
    QString SecondName;

};

#endif // WORKER_H
