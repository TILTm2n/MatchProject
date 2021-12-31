#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <iostream>
#include <QObject>
#include <optional>

class Worker: public QObject
{
    Q_OBJECT

    Q_PROPERTY(int worId READ getWorId WRITE setWorId)
    Q_PROPERTY(int tubNum READ getTubNum WRITE setTubNum)
    Q_PROPERTY(QString worFamily READ getWorFamily WRITE setWorFamily)
    Q_PROPERTY(QString worName READ getWorName WRITE setWorName)
    Q_PROPERTY(QString worSurname READ getWorSurname WRITE setWorSurname)
    Q_PROPERTY(int divId READ getDivId WRITE setDivId)
    Q_PROPERTY(QString divCode READ getDivCode WRITE setDivCode)
    Q_PROPERTY(QString worFio READ getWorFio WRITE setWorFio)


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

    int getWorId() const;
    void setWorId(int newWorId);

    int getTubNum() const;
    void setTubNum(int newTubNum);

    QString getWorFamily() const;
    void setWorFamily(QString newWorFamily);

    QString getWorName() const;
    void setWorName(QString newWorName);

    QString getWorSurname() const;
    void setWorSurname(QString newWorSurname);

    int getDivId() const;
    void setDivId(int newDivId);

    QString getDivCode() const;
    void setDivCode(QString newDivCode);

    QString getWorFio() const;
    void setWorFio(QString newWorFio);

private:
    int worId;
    int tubNum;
    QString worFamily;
    QString worName;
    QString worSurname;
    int divId;
    QString divCode;
    QString worFio;
};

#endif // WORKER_H
