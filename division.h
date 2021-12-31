#ifndef DIVISION_H
#define DIVISION_H
#include <QString>
#include <iostream>
#include <QObject>
#include <optional>


class Division : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int divId READ getDivId WRITE setDivId)
    Q_PROPERTY(QString divCode READ getDivCode WRITE setDivCode)
    Q_PROPERTY(QString divName READ getDivName WRITE setDivName)
    Q_PROPERTY(int divParentId READ getDivParentId WRITE setDivParentId)
    Q_PROPERTY(int divCehId READ getDivCehId WRITE setDivCehId)

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

    int getDivId() const;
    void setDivId(int newDivId);

    QString getDivCode() const;
    void setDivCode(QString newDivCode);

    QString getDivName() const;
    void setDivName(QString newDivName);

    int getDivParentId() const;
    void setDivParentId(int newDivParentId);

    int getDivCehId() const;
    void setDivCehId(int newDivCehId);

private:
    int divId;
    QString divCode;
    QString divName;
    int divParentId;
    int divCehId;

};

#endif // DIVISION_H
