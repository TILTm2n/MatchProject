#include <QCoreApplication>
#include "mycustomclass.h"
#include "worker.h"
#include <memory>
#include <QList>

using std::cout;
using std::cin;
using std::endl;

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

    enum Entities
    {
        Division,
        Room,
        Worker
    };

    int numberOfObject;

    cout << std::string(30, '_') << endl << endl;
    cout << "Console Nuclear Power Plant App" << endl;
    cout << std::string(30, '_') << endl << endl;

    cout << "Select your entity..." << endl;
    cout << std::string(30, '_') << endl << endl;

    cout << "1. Division" << endl;
    cout << "2. Room" << endl;
    cout << "3. Worker" << endl;
    cout << std::string(30, '_') << endl << endl;

    cout << "Input: ";
    cin >> numberOfObject;
    cout << "You chose " << numberOfObject << endl;
    cout << std::string(30, '_') << endl;





    return 0;
}
