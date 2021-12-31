#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <iostream>
#include <QObject>
#include <optional>


class Room : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int wrpId READ getWrpId WRITE setWrpId)
    Q_PROPERTY(int wrpParentId READ getWrpParentId WRITE setWrpParentId)
    Q_PROPERTY(QString wrpCode READ getWrpCode WRITE setWrpCode)
    Q_PROPERTY(QString wrpName READ getWrpName WRITE setWrpName)
    Q_PROPERTY(int worSurcontrolAreaIdname READ getControlAreaId WRITE setControlAreaId)

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

    int getWrpId() const;
    void setWrpId(int newWrpId);

    int getWrpParentId() const;
    void setWrpParentId(int newWrpParentId);

    QString getWrpCode() const;
    void setWrpCode(QString newWrpCode);

    QString getWrpName() const;
    void setWrpName(QString newWrpName);

    int getControlAreaId() const;
    void setControlAreaId(int newControlAreaId);

private:
    int wrpId;
    int wrpParentId;
    QString wrpCode;
    QString wrpName;
    int controlAreaId;

};

#endif // ROOM_H
