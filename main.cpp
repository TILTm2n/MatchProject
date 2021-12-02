#include <QCoreApplication>
#include "mycustomclass.h"
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyCustomClass *mcc = new MyCustomClass();

    return a.exec();
}
