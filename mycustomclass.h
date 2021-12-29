#ifndef MYCUSTOMCLASS_H
#define MYCUSTOMCLASS_H

#include <QList>
#include <QObject>
#include <QMetaObject>
#include <QMetaProperty>

#include <iostream>

class MyCustomClass
{
public:
    MyCustomClass();

    template <typename T>
    static bool Match (const T& object, const QList<QString>& propNames, QString input)
    {   
//        if(object == nullptr) //проверка на нулевой указаетль
//            return false;

        for(const QString& str: propNames)
        {
            const int index = object.metaObject()->indexOfProperty(str.toStdString().c_str());
            const QVariant& value = object.metaObject()->property(index).read(&object);

            if(value.toString().startsWith(input,Qt::CaseInsensitive))
                return true;
        }
        return false;
    }
};

#endif // MYCUSTOMCLASS_H
