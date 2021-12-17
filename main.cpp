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

    Worker *wrk = new Worker();
    Room *rm = new Room();
    Division *dvsn = new Division();

    int numberOfObject;
    string nameOfObject;

    //string listOfChoosenNumbers;
    //QString stringOfInts = QString(listOfChoosenNumbers.c_str());

    QList<QString> searchProperties;

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






    delete wrk;
    delete rm;
    delete  dvsn;
    return 0;
}
