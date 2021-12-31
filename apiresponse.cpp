#include "apiresponse.h"
#include "deserealizator.h"
#include "division.h"
#include "worker.h"
#include "room.h"

using std::cout;
using std::in;
using std::endl;

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
    int falseCounter = 0;
    int counter = 1;
    for(const auto& room: rooms)
    {
        auto new_room = std::make_shared<Room>();
        des.Deserealize(new_room.get(), room.toObject());

        if(match.Match(*new_room, properties, userInput)){
            std::cout << "Room " << counter << "----> " << new_room->getWrpName().toStdString() << std::endl;
            ++counter;
        }else{
            ++falseCounter;
        }
        //list.append(new_slot);

    }
    if(falseCounter == rooms.count()){

    }
}

void APIResponse::onWorkerResult(QNetworkReply *workerReply)
{
    MyCustomClass match;
    Deserealizator des;
    QJsonDocument document = QJsonDocument::fromJson(workerReply->readAll());
    QJsonArray workers = document.array();

    int counter = 1;
    for(const auto& worker: workers)
    {
        auto new_worker = std::make_shared<Worker>();
        des.Deserealize(new_worker.get(), worker.toObject());
        if(match.Match(*new_worker, properties, userInput)){
            std::cout << counter << " ----> " << new_worker->getWorFamily().toStdString() << " " << new_worker->getWorName().toStdString() << " "  << new_worker->getWorSurname().toStdString() << std::endl;
            ++counter;
        }
        //list.append(new_slot);
    }
}

void APIResponse::onDivisionResult(QNetworkReply *divisionReply)
{
    MyCustomClass match;
    Deserealizator des;
    QJsonDocument document = QJsonDocument::fromJson(divisionReply->readAll());
    QJsonArray divisions = document.array();

    int counter = 1;
    for(const auto& division: divisions)
    {
        auto new_division = std::make_shared<Division>();
        des.Deserealize(new_division.get(), division.toObject());
        if(match.Match(*new_division, properties, userInput)){
            std::cout << counter << " ----> " << new_division->getDivName().toStdString() << std::endl;
            ++counter;
        }
        //list.append(new_slot);
    }
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

