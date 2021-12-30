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
        //T* t = new T();

        QStringList propNames = jv.keys();
        for(auto key: propNames){
            auto value = jv.value(key);
            cout << key.toStdString() << "------> " << value.toString().toStdString() << endl;
        }


//        for(int i = t->metaObject()->propertyOffset(); i < t->metaObject()->propertyCount(); ++i)
//        {
//            const auto nameProp = QString(t->metaObject()->property(i).name());

//            if(propNames.contains(nameProp, Qt::CaseInsensitive)){
//                auto value = jv.value(nameProp);
//                cout << "fhgvhvhh" << value.toString().toStdString() << endl;
//                t->metaObject()->property(i).write(t, value);
//            }
//        }

        cout << "отработал десериализатор" << endl;
    }
};

#endif // DESEREALIZATOR_H
