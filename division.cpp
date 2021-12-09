#include "division.h"

Division::Division()
{

}

std::optional<int> Division::getDivId() const
{
    return divId;
}

void Division::setDivId(std::optional<int> newDivId)
{
    divId = newDivId;
}

std::optional<QString> Division::getDivCode() const
{
    return divCode;
}

void Division::setDivCode(std::optional<QString> newDivCode)
{
    divCode = newDivCode;
}

std::optional<QString> Division::getDivName() const
{
    return divName;
}

void Division::setDivName(std::optional<QString> newDivName)
{
    divName = newDivName;
}

std::optional<int> Division::getDivParentId() const
{
    return divParentId;
}

void Division::setDivParentId(std::optional<int> newDivParentId)
{
    divParentId = newDivParentId;
}

std::optional<int> Division::getDivCehId() const
{
    return divCehId;
}

void Division::setDivCehId(std::optional<int> newDivCehId)
{
    divCehId = newDivCehId;
}
