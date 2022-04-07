#ifndef AIRINF_H
#define AIRINF_H
#include <QString>
#include <QDateTime>

class List
{
public:
    List();
    ~List();
    void Add(QString numFlight, QString typePlane, QString destination, QTime departuretime);
    QString toString();
    QString toString(const QString& departureTime);
    void deleteFlight(const QString& destination);
    void deleteAll();
    bool isEmpty();

private:
    struct AirInf{
        QString numFlight;
        QString typePlane;
        QString destination;
        QTime departureTime;
        AirInf *prev;
        AirInf *next;
    };
    AirInf *head, *tail;
};

#endif // AIRINF_H
