#include "room.h"

Room::Room()
{

}

int Room::getWrpId() const
{
    return wrpId;
}

void Room::setWrpId(int newWrpId)
{
    wrpId = newWrpId;
}

int Room::getWrpParentId() const
{
    return wrpParentId;
}

void Room::setWrpParentId(int newWrpParentId)
{
    wrpParentId = newWrpParentId;
}

QString Room::getWrpCode() const
{
    return wrpCode;
}

void Room::setWrpCode(QString newWrpCode)
{
    wrpCode = newWrpCode;
}

QString Room::getWrpName() const
{
    return wrpName;
}

void Room::setWrpName(QString newWrpName)
{
    wrpName = newWrpName;
}

int Room::getControlAreaId() const
{
    return controlAreaId;
}

void Room::setControlAreaId(int newControlAreaId)
{
    controlAreaId = newControlAreaId;
}


