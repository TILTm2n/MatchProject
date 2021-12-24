#include "apiresponse.h"
#include "deserealizator.h"
#include "division.h"
#include "worker.h"
#include "room.h"

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
    Deserealizator des;

    QJsonDocument document = QJsonDocument::fromJson(roomReply->readAll());
    QJsonArray rooms = document.array();

QList<std::shared_ptr<Room>> list;

    for(const auto& room: rooms)
    {
        auto new_slot = std::make_shared<Room>();

        des.Deserealize(new_slot.get(), room.toObject());

        list.append(new_slot);


    }



//    qDebug() << typeid (rooms[0]).name();
//    //qDebug() << rooms[0].toObject().keys();
//    qDebug() << rooms[0].toObject().value("controlAreaId").toInt();
//    qDebug() << rooms[0].toObject().value("wrpCode");
//    qDebug() << QString(roomReply->readAll());
//    QList<QJsonObject> roomsJObjs;

//    for(const auto& room: rooms){

//        if(match.Match(&room, properties, userInput))
//        {
//            QString implementation;
//            roomsJObjs.append(room.toObject());

//            for(auto rm: roomsJObjs)
//            {

//            }

//        }
//    }


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

