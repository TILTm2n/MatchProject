#ifndef APIRESPONSE_H
#define APIRESPONSE_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QList>
#include <QObject>
#include <QString>
#include <QStringList>


class APIResponse : public QObject
{
    Q_OBJECT

public:
    APIResponse();

    QNetworkAccessManager *getRoomManager() const;
    void setRoomManager(QNetworkAccessManager *newRoomManager);

    QNetworkAccessManager *getWorkerManager() const;
    void setWorkerManager(QNetworkAccessManager *newWorkerManager);

    QNetworkAccessManager *getDivisionManager() const;
    void setDivisionManager(QNetworkAccessManager *newDivisionManager);

private slots:
    void onRoomResult(QNetworkReply* roomReply);
    void onWorkerResult(QNetworkReply* workerReply);
    void onDivisionResult(QNetworkReply* divisionReply);


private:
    QNetworkAccessManager* roomManager;
    QNetworkAccessManager* workerManager;
    QNetworkAccessManager* divisionManager;
};

#endif // APIRESPONSE_H
