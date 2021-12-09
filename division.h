#ifndef DIVISION_H
#define DIVISION_H
#include <QString>
#include <iostream>
#include <QObject>
#include <optional>


class Division : public QObject
{
    Q_OBJECT
    Q_PROPERTY(std::optional<int> divId READ getDivId WRITE setDivId)
    Q_PROPERTY(std::optional<QString> divCode READ getDivCode WRITE setDivCode)
    Q_PROPERTY(std::optional<QString> divName READ getDivName WRITE setDivName)
    Q_PROPERTY(std::optional<int> divParentId READ getDivParentId WRITE setDivParentId)
    Q_PROPERTY(std::optional<int> divCehId READ getDivCehId WRITE setDivCehId)

public:
    Division();
    Division(const int& div_id,
             const QString& div_code,
             const QString& div_name,
             const int& div_parent_id,
             const int& div_ceh_id)
            : divId(div_id),
              divCode(div_code),
              divName(div_name),
              divParentId(div_parent_id),
              divCehId(div_ceh_id)
    {

    }

    std::optional<int> getDivId() const;
    void setDivId(std::optional<int> newDivId);

    std::optional<QString> getDivCode() const;
    void setDivCode(std::optional<QString> newDivCode);

    std::optional<QString> getDivName() const;
    void setDivName(std::optional<QString> newDivName);

    std::optional<int> getDivParentId() const;
    void setDivParentId(std::optional<int> newDivParentId);

    std::optional<int> getDivCehId() const;
    void setDivCehId(std::optional<int> newDivCehId);

private:
    std::optional<int> divId;
    std::optional<QString> divCode;
    std::optional<QString> divName;
    std::optional<int> divParentId;
    std::optional<int> divCehId;

};

#endif // DIVISION_H
