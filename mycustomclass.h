#ifndef MYCUSTOMCLASS_H
#define MYCUSTOMCLASS_H

#include <QList>
#include <QObject>
#include <QMetaObject>
#include <QMetaProperty>


class MyCustomClass
{
public:
    MyCustomClass();

    template <typename T>
    static bool Match (const T& object, QList<QString> propNames, QString input)
    {   
        for(const QString& str: propNames){
            for(int i = object->metaObject()->propertyOffset(); i < object->metaObject()->propertyCount(); ++i)
            {
                const char* propertyName = object->metaObject()->property(i).name(); //имя свойства
                QVariant propertyValue = object->metaObject()->property(i).read(object); // значение свойства
                QString strpropname = propertyValue.toString();

                if (propertyName == str && strpropname.startsWith(input, Qt::CaseInsensitive)){
                    return true;
                }
            }
        }
        return false;
    }
};

#endif // MYCUSTOMCLASS_H
