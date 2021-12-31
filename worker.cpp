#include "worker.h"

Worker::Worker()
{

}

int Worker::getWorId() const
{
    return worId;
}

void Worker::setWorId(int newWorId)
{
    worId = newWorId;
}

int Worker::getTubNum() const
{
    return tubNum;
}

void Worker::setTubNum(int newTubNum)
{
    tubNum = newTubNum;
}

QString Worker::getWorFamily() const
{
    return worFamily;
}

void Worker::setWorFamily(QString newWorFamily)
{
    worFamily = newWorFamily;
}

QString Worker::getWorName() const
{
    return worName;
}

void Worker::setWorName(QString newWorName)
{
    worName = newWorName;
}

QString Worker::getWorSurname() const
{
    return worSurname;
}

void Worker::setWorSurname(QString newWorSurname)
{
    worSurname = newWorSurname;
}

int Worker::getDivId() const
{
    return divId;
}

void Worker::setDivId(int newDivId)
{
    divId = newDivId;
}

QString Worker::getDivCode() const
{
    return divCode;
}

void Worker::setDivCode(QString newDivCode)
{
    divCode = newDivCode;
}

QString Worker::getWorFio() const
{
    return worFio;
}

void Worker::setWorFio(QString newWorFio)
{
    worFio = newWorFio;
}







