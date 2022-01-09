#include <QNetworkAccessManager>
#include <QCoreApplication>
#include <QNetworkRequest>
#include <QString>
#include <memory>
#include <QList>
#include <QUrl>

#include "mycustomclass.h"
#include "apiresponse.h"
#include "apiresponse.h"
#include "division.h"
#include "worker.h"
#include "room.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using namespace std::chrono_literals;

QList<int> getListOfInts(const QString& stringOfInts)
{
    QStringList stringListOfInts = stringOfInts.split(QLatin1Char(','), Qt::SkipEmptyParts);
    QList<int> listOfInts;

    for(QString num: stringListOfInts){
        listOfInts.append(num.toInt());
    }
    return listOfInts;
}

template <typename P>
void printChoseMessage(const P& pointObj, QList<QString>& properties)
{
    string listOfChoosenNumbers;
    QList<int> listOfInts;

    cout << "You chose " << pointObj->metaObject()->className() << " that has propertires:"<< endl;
    for(int i = pointObj->metaObject()->propertyOffset(); i < pointObj->metaObject()->propertyCount(); ++i)
    {
          cout << i << " -> " << pointObj->metaObject()->property(i).name() << endl << endl;
    }

    cout << std::string(35, '_') << endl;

    cout << "Which properties have I to use to search required data?"<< endl << endl;

    cin.ignore(32767, '\n');
    getline(cin, listOfChoosenNumbers);

    QString stringOfInts = QString(listOfChoosenNumbers.c_str());

    listOfInts = getListOfInts(stringOfInts);

    QList<QMetaProperty> metaProperties = getMetaProperties(listOfInts, pointObj);

    for(auto prop: metaProperties)
    {
        cout << "-> " << prop.name() << endl;

        properties.append(QString(prop.name())); //могут быть проблемы с размером
    }


};

template <typename P>
QList<QMetaProperty> getMetaProperties(const QList<int>& ints, const P& targetObject)
{
    QList<QMetaProperty> propsList;

    for(auto num: ints)
    {
        propsList.append(targetObject->metaObject()->property(num));
    }
    return propsList;
}





int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    Worker *wrk = new Worker();
    Room *rm = new Room();
    Division *dvsn = new Division();
    APIResponse* netManager = new APIResponse();

    int numberOfObject;
    string nameOfObject;
    QList<QString> searchProperties;

//    bool again = true;
//    while (again) {
//        int answer;
//        cout << std::string(35, '_') << endl << endl;
//        cout << "Хотите найти еще что-нибудь?" << endl << endl;
//        cout << "1. Да" << endl;
//        cout << "2. Нет" << endl;
//        cin >> answer;
//        if(answer == 1){
//            again = true;
//        }else if(answer == 2){
//             again = false;
//        }
//    }

    cout << std::string(35, '_') << endl << endl;
    cout << "Console Nuclear Power Plant App" << endl;
    cout << std::string(35, '_') << endl << endl;

    cout << "Select your entity:" << endl;
    cout << "1. Division" << endl;
    cout << "2. Room" << endl;
    cout << "3. Worker" << endl;
    cout << std::string(35, '_') << endl << endl;

    cout << "Input -> ";
    cin >> numberOfObject;
    switch (numberOfObject)
    {
    case 1:
        printChoseMessage(dvsn, searchProperties);
        break;
    case 2:
        printChoseMessage(rm, searchProperties);
        break;
    case 3:
        printChoseMessage(wrk, searchProperties);
        break;
    default:
        cout << "pososi" << endl;
        break;
    }
    cout << std::string(35, '_') << endl << endl;

    netManager->properties = searchProperties;

    string input;

    cout << "Please, input string -> " << endl << endl;

    cin >> input;
    QString userInput = QString(input.c_str());

    cout << std::string(35, '_') << endl << endl;

    cout << "poka rabotaet" << endl << endl;

    netManager->userInput = userInput;

    cout << "userInput = " << netManager->userInput.toStdString() << endl << endl;

    switch (numberOfObject)
    {
    case 1:
        netManager->getDivisionManager()->get(QNetworkRequest(QUrl("http://localhost:5001/api/Division")));
        break;
    case 2:
        netManager->getRoomManager()->get(QNetworkRequest(QUrl("http://localhost:5001/api/Room")));
        break;
    case 3:
        netManager->getWorkerManager()->get(QNetworkRequest(QUrl("http://localhost:5001/api/Worker")));
        break;
    default:
        cout << "pososi" << endl;
        break;
    }

    cout << "1. Division" << endl;

    delete wrk;
    delete rm;
    delete  dvsn;

    return a.exec();
}
