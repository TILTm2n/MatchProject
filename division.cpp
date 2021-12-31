#include "division.h"

Division::Division()
{

}

int Division::getDivId() const
{
    return divId;
}

void Division::setDivId(int newDivId)
{
    divId = newDivId;
}

QString Division::getDivCode() const
{
    return divCode;
}

void Division::setDivCode(QString newDivCode)
{
    divCode = newDivCode;
}

QString Division::getDivName() const
{
    return divName;
}

void Division::setDivName(QString newDivName)
{
    divName = newDivName;
}

int Division::getDivParentId() const
{
    return divParentId;
}

void Division::setDivParentId(int newDivParentId)
{
    divParentId = newDivParentId;
}

int Division::getDivCehId() const
{
    return divCehId;
}

void Division::setDivCehId(int newDivCehId)
{
    divCehId = newDivCehId;
}
