#include <QtCore/QCoreApplication>
#include "OverLoads.h"
#include "person.h"
#include <QtCore>

void Save()
{
    Person person1;
    person1.Age = 36;
    person1.Name = "Bryan";

    Person person2;
    person2.Age = 18;
    person2.Name = "Heather";

    QFile file("e:/test/people.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Could not open file";
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_7);

    out << person1;
    out << person2;

    file.flush();
    file.close();

}

void Load()
{
    Person person1;
    Person person2;


    QFile file("e:/test/people.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open file";
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_7);

    in >> person1;
    in >> person2;

    file.close();

    qDebug() << person1.Name << " is " << person1.Age;
    qDebug() << person2.Name << " is " << person2.Age;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Save();
    Load();
    return a.exec();
}
