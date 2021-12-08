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
    static bool Match (const T* object, const QList<QString>& propNames, QString input)
    {   
        if(object == nullptr) //проверка на нулевой указаетль
            return false;

        for(size_t i = object->metaObject()->propertyOffset(); i < object->metaObject()->propertyCount(); ++i)
        {
            const char* propertyName = object->metaObject()->property(i).name(); //имя свойства
            if (propNames.contains(propertyName,Qt::CaseInsensitive))
            {
                QVariant propertyValue = object->metaObject()->property(i).read(object); // значение свойства
                const QString& propertyValueStr = propertyValue.toString();
                if (propertyValueStr.startsWith(input, Qt::CaseInsensitive))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

#endif // MYCUSTOMCLASS_H
