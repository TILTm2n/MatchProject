#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <iostream>
#include <QObject>

class Worker: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString WorId READ getWorId WRITE setWorId)
    Q_PROPERTY(QString FirstName READ getFirstName WRITE setFirstName)
    Q_PROPERTY(QString SecondName READ getSecondName WRITE setSecondName)

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
