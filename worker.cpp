#include "worker.h"

Worker::Worker()
{

}

std::optional<int> Worker::getWorId() const
{
    return worId;
}

void Worker::setWorId(std::optional<int> newWorId)
{
    worId = newWorId;
}

std::optional<int> Worker::getTubNum() const
{
    return tubNum;
}

void Worker::setTubNum(std::optional<int> newTubNum)
{
    tubNum = newTubNum;
}

std::optional<QString> Worker::getWorFamily() const
{
    return worFamily;
}

void Worker::setWorFamily(std::optional<QString> newWorFamily)
{
    worFamily = newWorFamily;
}

std::optional<QString> Worker::getWorName() const
{
    return worName;
}

void Worker::setWorName(std::optional<QString> newWorName)
{
    worName = newWorName;
}

std::optional<QString> Worker::getWorSurname() const
{
    return worSurname;
}

void Worker::setWorSurname(std::optional<QString> newWorSurname)
{
    worSurname = newWorSurname;
}

std::optional<int> Worker::getDivId() const
{
    return divId;
}

void Worker::setDivId(std::optional<int> newDivId)
{
    divId = newDivId;
}

std::optional<QString> Worker::getDivCode() const
{
    return divCode;
}

void Worker::setDivCode(std::optional<QString> newDivCode)
{
    divCode = newDivCode;
}

std::optional<QString> Worker::getWorFio() const
{
    return worFio;
}

void Worker::setWorFio(std::optional<QString> newWorFio)
{
    worFio = newWorFio;
}







