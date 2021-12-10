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

    //methods
    const auto printChoseMessage = [](string& chosenNumber,  const class Division* division)
    {
        cout << "You chose Division that has propertires:"<< endl;
        chosenNumber = "Division";
        for(int i = division->metaObject()->propertyOffset(); i < division->metaObject()->propertyCount(); ++i)
        {
              cout << i << " -> " << division->metaObject()->property(i).name() << endl;
        }
        cout << "Which properties have I to use to search required data?"<< endl;
    };

    // variables


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


    delete wrk;
    delete rm;
    delete  dvsn;
    return 0;
}
