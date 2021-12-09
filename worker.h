#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <iostream>
#include <QObject>
#include <optional>

class Worker: public QObject
{
    Q_OBJECT

    Q_PROPERTY(std::optional<int> worId READ getWorId WRITE setWorId)
    Q_PROPERTY(std::optional<int> tubNum READ getTubNum WRITE setTubNum)
    Q_PROPERTY(std::optional<QString> worFamily READ getWorFamily WRITE setWorFamily)
    Q_PROPERTY(std::optional<QString> worName READ getWorName WRITE setWorName)
    Q_PROPERTY(std::optional<QString> worSurname READ getWorSurname WRITE setWorSurname)
    Q_PROPERTY(std::optional<int> divId READ getDivId WRITE setDivId)
    Q_PROPERTY(std::optional<QString> divCode READ getDivCode WRITE setDivCode)
    Q_PROPERTY(std::optional<QString> worFio READ getWorFio WRITE setWorFio)


public:
    Worker();
    Worker(const int& worid,
           const int& tubname,
           const QString& worfamily,
           const QString& worname,
           const QString& worsurname,
           const int& divid,
           const QString& divcode,
           const QString& worfio)
        : worId(worid),
          tubNum(tubname),
          worFamily(worfamily),
          worName(worname),
          worSurname(worsurname),
          divId(divid),
          divCode(divcode),
          worFio(worfio)
    {

    }

    std::optional<int> getWorId() const;
    void setWorId(std::optional<int> newWorId);

    std::optional<int> getTubNum() const;
    void setTubNum(std::optional<int> newTubNum);

    std::optional<QString> getWorFamily() const;
    void setWorFamily(std::optional<QString> newWorFamily);

    std::optional<QString> getWorName() const;
    void setWorName(std::optional<QString> newWorName);

    std::optional<QString> getWorSurname() const;
    void setWorSurname(std::optional<QString> newWorSurname);

    std::optional<int> getDivId() const;
    void setDivId(std::optional<int> newDivId);

    std::optional<QString> getDivCode() const;
    void setDivCode(std::optional<QString> newDivCode);

    std::optional<QString> getWorFio() const;
    void setWorFio(std::optional<QString> newWorFio);

private:
    std::optional<int> worId;
    std::optional<int> tubNum;
    std::optional<QString> worFamily;
    std::optional<QString> worName;
    std::optional<QString> worSurname;
    std::optional<int> divId;
    std::optional<QString> divCode;
    std::optional<QString> worFio;
};

#endif // WORKER_H
