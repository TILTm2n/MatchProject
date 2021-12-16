#include <QCoreApplication>
#include "mycustomclass.h"
#include "worker.h"
#include "room.h"
#include "division.h"
#include <memory>
#include <QList>
#include <QString>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

template <typename P>
void printChoseMessage(const P& pointObj)
{
    string listOfChoosenNumbers;
    QString stringOfInts = QString(listOfChoosenNumbers.c_str());
    QList<int> listOfInts;

    cout << "You chose " << pointObj->metaObject()->className() << " that has propertires:"<< endl;
    for(int i = pointObj->metaObject()->propertyOffset(); i < pointObj->metaObject()->propertyCount(); ++i)
    {
          cout << i << " -> " << pointObj->metaObject()->property(i).name() << endl;
    }
    cout << "Which properties have I to use to search required data?"<< endl;

    getline(cin, listOfChoosenNumbers);

    QStringList stringListOfInts = stringOfInts.split(QLatin1Char(','), Qt::SkipEmptyParts);

    for(auto num: stringListOfInts){
        listOfInts.append(num.toInt());
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

}




int main(int argc, char *argv[])
{

    Worker *wrk = new Worker();
    Room *rm = new Room();
    Division *dvsn = new Division();

    int numberOfObject;
    string nameOfObject;

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
        printChoseMessage(dvsn);
        break;
    case 2:
        printChoseMessage(rm);
        break;
    case 3:
        printChoseMessage(wrk);
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
