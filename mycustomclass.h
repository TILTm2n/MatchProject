#ifndef MYCUSTOMCLASS_H
#define MYCUSTOMCLASS_H

#include <QList>
#include <QMetaObject>


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
                if (object->metaObject()->property(i)->name() == str && object->metaObject()->property(i)->read(object)->toString()->startsWith(input, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};

#endif // MYCUSTOMCLASS_H
