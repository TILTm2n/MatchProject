#include "room.h"

Room::Room()
{

}

std::optional<int> Room::getWrpId() const
{
    return wrpId;
}

void Room::setWrpId(std::optional<int> newWrpId)
{
    wrpId = newWrpId;
}

std::optional<int> Room::getWrpParentId() const
{
    return wrpParentId;
}

void Room::setWrpParentId(std::optional<int> newWrpParentId)
{
    wrpParentId = newWrpParentId;
}

std::optional<QString> Room::getWrpCode() const
{
    return wrpCode;
}

void Room::setWrpCode(std::optional<QString> newWrpCode)
{
    wrpCode = newWrpCode;
}

std::optional<QString> Room::getWrpName() const
{
    return wrpName;
}

void Room::setWrpName(std::optional<QString> newWrpName)
{
    wrpName = newWrpName;
}

std::optional<int> Room::getControlAreaId() const
{
    return controlAreaId;
}

void Room::setControlAreaId(std::optional<int> newControlAreaId)
{
    controlAreaId = newControlAreaId;
}


