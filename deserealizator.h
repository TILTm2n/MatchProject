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

class Deserealizator
{
public:
    Deserealizator();

private:

template<typename T>
    static T* Deserealize(const T* t,QJsonValue jv)
    {   
        //T* t = new T();
        int amountOfProp = t->metaObject()->propertyOffset();
        QStringList propNames = jv.toObject().keys();

        for(int i = 0; i = amountOfProp; ++i){
            for(const QString& name: propNames){
                if(t->metaObject()->property(i).name() == name.toStdString()){
                    t->metaObject()->property(i).write(&t, name);
                }
            }
        }

        return t;
    }
};

#endif // DESEREALIZATOR_H
