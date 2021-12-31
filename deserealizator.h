#ifndef DESEREALIZATOR_H
#define DESEREALIZATOR_H

#include <QList>
#include <QObject>
#include <QJsonValue>
#include <QStringList>
#include <QJsonObject>
#include <QMetaObject>
#include <QMetaProperty>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Deserealizator
{
public:
    Deserealizator();

template<typename T>
    static void Deserealize(T* t, const QJsonObject& jv)
    {   
        QStringList propNames = jv.keys();

        for(int i = t->metaObject()->propertyOffset(); i < t->metaObject()->propertyCount(); ++i)
        {
            const auto nameProp = QString(t->metaObject()->property(i).name());
            auto value = jv.value(nameProp);

            if(propNames.contains(nameProp, Qt::CaseInsensitive)){
                auto value = jv.value(nameProp);

                if(value.isDouble()){
                    t->metaObject()->property(i).write(t, value.toInt());
                }else{
                    t->metaObject()->property(i).write(t, value.toString());
                }
            }
        }
    }
};


#endif // DESEREALIZATOR_H
