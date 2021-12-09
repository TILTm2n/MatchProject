#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <iostream>
#include <QObject>
#include <optional>


class Room : public QObject
{
    Q_OBJECT

    Q_PROPERTY(type wrpId READ getWrpId WRITE setWrpId)
    Q_PROPERTY(type wrpParentId READ getWrpParentId WRITE setWrpParentId)
    Q_PROPERTY(type wrpCode READ getWrpCode WRITE setWrpCode)
    Q_PROPERTY(type wrpName READ getWrpName WRITE setWrpName)
    Q_PROPERTY(type worSurcontrolAreaIdname READ getControlAreaId WRITE setControlAreaId)

public:
    Room();
    Room(const int& wrp_id,
         const int& wrp_parent_id,
         const QString& wrp_code,
         const QString& wrp_name,
         const int& control_area_id_name)
        : wrpId(wrp_id),
          wrpParentId(wrp_parent_id),
          wrpCode(wrp_code),
          wrpName(wrp_name),
          controlAreaId(control_area_id_name)

    {

    }

    std::optional<int> getWrpId() const;
    void setWrpId(std::optional<int> newWrpId);

    std::optional<int> getWrpParentId() const;
    void setWrpParentId(std::optional<int> newWrpParentId);

    std::optional<QString> getWrpCode() const;
    void setWrpCode(std::optional<QString> newWrpCode);

    std::optional<QString> getWrpName() const;
    void setWrpName(std::optional<QString> newWrpName);

    std::optional<int> getControlAreaId() const;
    void setControlAreaId(std::optional<int> newControlAreaId);

private:
    std::optional<int> wrpId;
    std::optional<int> wrpParentId;
    std::optional<QString> wrpCode;
    std::optional<QString> wrpName;
    std::optional<int> controlAreaId;

};

#endif // ROOM_H
