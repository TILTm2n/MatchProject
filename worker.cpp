#include "worker.h"

Worker::Worker()
{

}

int Worker::getWorId() const
{
    return WorId;
}

void Worker::setWorId(int newWorId)
{
    WorId = newWorId;
}

const QString &Worker::getFirstName() const
{
    return FirstName;
}

void Worker::setFirstName(const QString &newFirstName)
{
    FirstName = newFirstName;
}

const QString &Worker::getSecondName() const
{
    return SecondName;
}

void Worker::setSecondName(const QString &newSecondName)
{
    SecondName = newSecondName;
}



