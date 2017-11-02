#ifndef OVERLOADS_H
#define OVERLOADS_H

#include "person.h"
#include <QtCore>

QDataStream &operator<<(QDataStream &out, const Person &person);
QDataStream &operator>>(QDataStream &in, Person &person);

QDataStream &operator<<(QDataStream &out, const Person &person)
{
    //Write a person class to the stream
    out << person.Age << person.Name;
    return out;
}

QDataStream &operator>>(QDataStream &in, Person &person)
{
    //Read in a person class
    person = Person();
    in >> person.Age >> person.Name;
    return in;
}

#endif // OVERLOADS_H
