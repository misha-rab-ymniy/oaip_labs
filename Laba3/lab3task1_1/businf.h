#ifndef BUSINF_H
#define BUSINF_H
#include <QString>
#include <QTime>
#include <QVector>

class List
{

private:
    struct BusInf{
        QString numBus;
        QString typeBus;
        QString destination;
        QTime departureTime;
        QTime arrivalTime;
        int prev;
        int next;
        int index;
    };
    int size;
    int begin, end;
    QVector<BusInf> bus;
public:
    List();
    void Add(QString numFlight, QString typeBus, QString destination, QTime departureTime, QTime arrivalTime);
    void Add(BusInf tmp);
    QString toString();
    QString toString(const QString& destination);
    void deleteBus(const QString& numBus);
    void deleteAll();
    BusInf getStruct(const QString& numBus);
    bool find(const QString& numBus);
    bool isEmpty();
};
#endif // BUSINF_H
