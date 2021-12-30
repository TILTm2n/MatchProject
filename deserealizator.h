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

        for(size_t i = 0; i < t->metaObject()->propertyOffset(); ++i){
            for(const QString& name: propNames){
                if(t->metaObject()->property(i).name() == name.toStdString()){
                    t->metaObject()->property(i).write(t, name);
                }
            }
        }
        cout << "отработал десериализатор" << endl;
    }
};

#endif // DESEREALIZATOR_H
