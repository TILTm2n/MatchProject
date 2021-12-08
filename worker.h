#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <iostream>
#include <QObject>

class Worker: public QObject
{
    Q_OBJECT
public:
    Worker();
    Worker(const QString& worid, const QString& firstname, const QString& secondname)
        :WorId(worid)
        , FirstName(firstname)
        , SecondName(secondname)
    {

    }

    const QString &getFirstName() const;
    void setFirstName(const QString &newFirstName);

    const QString &getSecondName() const;
    void setSecondName(const QString &newSecondName);



    const QString &getWorId() const;
    void setWorId(const QString &newWorId);

private:
    QString WorId;
    QString FirstName;
    QString SecondName;

};

#endif // WORKER_H
