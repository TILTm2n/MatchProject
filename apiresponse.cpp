#include "apiresponse.h"

APIResponse::APIResponse()
{
    roomManager = new QNetworkAccessManager;
    workerManager = new QNetworkAccessManager;
    divisionManager = new QNetworkAccessManager;

    connect(roomManager, &QNetworkAccessManager::finished, this, &APIResponse::onRoomResult);
    connect(workerManager, &QNetworkAccessManager::finished, this, &APIResponse::onWorkerResult);
    connect(divisionManager, &QNetworkAccessManager::finished, this, &APIResponse::onDivisionResult);
}

void APIResponse::onRoomResult(QNetworkReply *roomReply)
{
    MyCustomClass match;

    QJsonDocument document = QJsonDocument::fromJson(roomReply->readAll());
    QJsonArray rooms = document.array();
    QList<QJsonObject> roomsJObjs;

    for(const auto& room: rooms){

        if(match.Match(&room, properties, userInput))
        {
            QString implementation;
            roomsJObjs.append(room.toObject());

            for(auto rm: roomsJObjs)
            {

            }

        }
    }


}

void APIResponse::onWorkerResult(QNetworkReply *workerReply)
{
    QJsonDocument document = QJsonDocument::fromJson(workerReply->readAll());
    QJsonArray workers = document.array();
}

void APIResponse::onDivisionResult(QNetworkReply *divisionReply)
{
    QJsonDocument document = QJsonDocument::fromJson(divisionReply->readAll());
    QJsonArray divisions = document.array();
}

QNetworkAccessManager *APIResponse::getDivisionManager() const
{
    return divisionManager;
}

void APIResponse::setDivisionManager(QNetworkAccessManager *newDivisionManager)
{
    divisionManager = newDivisionManager;
}

QNetworkAccessManager *APIResponse::getWorkerManager() const
{
    return workerManager;
}

void APIResponse::setWorkerManager(QNetworkAccessManager *newWorkerManager)
{
    workerManager = newWorkerManager;
}

QNetworkAccessManager *APIResponse::getRoomManager() const
{
    return roomManager;
}

void APIResponse::setRoomManager(QNetworkAccessManager *newRoomManager)
{
    roomManager = newRoomManager;
}

