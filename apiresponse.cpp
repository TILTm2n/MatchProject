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

    //QList<std::shared_ptr<Room>> list;

    //std::cout << userInput.toStdString() << std::endl;

    for(const auto& room: rooms)
    {
        //std::cout << room.toObject().value("wrpName").toString().toStdString() << std::endl;
        auto new_slot = std::make_shared<Room>();

        cout << "началло работы десериализатора" << endl;
        des.Deserealize(new_slot.get(), room.toObject());

        cout << "вот сейчас будет значение" << endl;
        cout << new_slot->getWrpId().value() << endl;
        cout << new_slot->getWrpParentId().value() << endl;
        cout << new_slot->getWrpCode().value_or("Кода нет").toStdString() << endl;
        cout << new_slot->getWrpName().value_or("Имени нет").toStdString() << endl;
        cout << new_slot->getControlAreaId().value() << endl;
        cout << "вот только что было значение" << endl;
//        cout << new_slot->metaObject()->property(0).typeName() << endl;
//        cout << new_slot->metaObject()->property(0).name() << endl;
//        cout << new_slot->metaObject()->property(1).name() << endl;
//        cout << new_slot->metaObject()->property(2).name() << endl;
//        cout << new_slot->metaObject()->property(3).name() << endl;
//        cout << new_slot->metaObject()->property(4).name() << endl;
//        cout << new_slot->metaObject()->property(5).name() << endl;

//        if(match.Match(*new_slot, properties, userInput)){
//            std::cout << new_slot->getWrpName().value().toStdString() << std::endl;
//        }

        //list.append(new_slot);
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

