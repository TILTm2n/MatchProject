#include <QCoreApplication>
#include "mycustomclass.h"
#include "worker.h"
#include <memory>
#include <QList>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    Worker *wkr = new Worker("2", "Александр", "Круглов");

    MyCustomClass *mcc = new MyCustomClass();

    QList<QString>  properties{"WorId", "FirstName", "SecondName"};

    std::cout << mcc->Match(wkr, properties, "Алек") << std::endl;

    delete wkr;
    delete mcc;

    //return a.exec();
    return 0;
    //проверка работоспособности
}
