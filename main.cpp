#include <QCoreApplication>
#include "mycustomclass.h"
#include "worker.h"
#include "room.h"
#include "division.h"
#include <memory>
#include <QList>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename P>
void printChoseMessage(string& chosenNumber, const P& pointObj)
{
    cout << "You chose ////////// that has propertires:"<< endl;
    chosenNumber = "//////////";
    for(int i = pointObj->metaObject()->propertyOffset(); i < pointObj->metaObject()->propertyCount(); ++i)
    {
          cout << i << " -> " << pointObj->metaObject()->property(i).name() << endl;
    }
    cout << "Which properties have I to use to search required data?"<< endl;
};



int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //Worker *wkr = new Worker{"2", "Александр", "Круглов"};

    //MyCustomClass *mcc = new MyCustomClass();

    //QList<QString>  properties{"worId", "worName", "worSurname"};

    //std::cout << mcc->Match(wkr, properties, "А") << std::endl;

    //delete wkr;
    //delete mcc;

    //return a.exec();

    Worker *wrk = new Worker();
    Room *rm = new Room();
    Division *dvsn = new Division();

    int numberOfObject;
    string nameOfObject;

    enum Entities
    {
        Division,
        Room,
        Worker
    };


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
        cout << "You chose Division that has propertires:"<< endl;
        nameOfObject = "Division";
        for(int i = dvsn->metaObject()->propertyOffset(); i < dvsn->metaObject()->propertyCount(); ++i)
        {
              cout << i << " -> " << dvsn->metaObject()->property(i).name() << endl;
        }
        cout << "Which properties have I to use to search required data?"<< endl;
        break;
    case 2:
        cout << "You chose Room that has propertires:"<< endl;
        nameOfObject = "Room";
        for(int i = rm->metaObject()->propertyOffset(); i < rm->metaObject()->propertyCount(); ++i)
        {
              cout << i << " -> " << rm->metaObject()->property(i).name() << endl;
        }
        cout << "Which properties have I to use to search required data?"<< endl;
        break;
    case 3:
        cout << "You chose Worker that has propertires:"<< endl;
        nameOfObject = "Worker";
        for(int i = wrk->metaObject()->propertyOffset(); i < wrk->metaObject()->propertyCount(); ++i)
        {
              cout << i << " -> " << wrk->metaObject()->property(i).name() << endl;
        }
        cout << "Which properties have I to use to search required data?"<< endl;
        break;
    default:
        cout << "pososi" << endl;
        break;
    }
    cout << std::string(35, '_') << endl;

    cout << "Коммит ради коммита 1"<< endl;
    cout << "Коммит ради коммита 2"<< endl;
    cout << "Коммит ради коммита 3"<< endl;
    cout << "Коммит ради коммита 4"<< endl;
    cout << "Коммит ради коммита 5"<< endl;

    delete wrk;
    delete rm;
    delete  dvsn;
    return 0;
}
