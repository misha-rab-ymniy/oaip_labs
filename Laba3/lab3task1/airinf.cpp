#include "airinf.h"

List::List() : head(nullptr), tail(nullptr){}

List::~List()
{
    while (head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}

void List::Add(QString numFlight, QString typePlane, QString destination, QTime departuretime)
{
    AirInf *temp = new AirInf;
    temp->next = nullptr;
    temp->numFlight = numFlight;
    temp->typePlane = typePlane;
    temp->destination = destination;
    temp->departureTime = departuretime;

    if (head != nullptr)
    {
       temp->prev = tail;
       tail->next = temp;
       tail = temp;
    }
    else
    {
       temp->prev = nullptr;
       head = tail = temp;
    }
}

QString List::toString()
{
    QString str;
    AirInf *temp = head;
    while (temp != nullptr)
    {
        str += temp->numFlight;
        str += ' ';
        str += temp->typePlane;
        str += ' ';
        str += temp->destination;
        str += ' ';
        str += temp->departureTime.toString(Qt::LocaleDate);
        str += '\n';
        temp = temp->next;
    }
    return str;
}

QString List::toString(const QString &departuretime)
{
    QString str;
    AirInf *temp = head;
    while (temp != nullptr)
    {
        if (temp->departureTime.toString() == departuretime){
            str += temp->numFlight;
            str += ' ';
            str += temp->typePlane;
            str += ' ';
            str += temp->destination;
            str += ' ';
            str += temp->departureTime.toString(Qt::LocaleDate);
            str += '\n';
        }
        temp = temp->next;
    }
    return str;
}

void List::deleteFlight(const QString &destination)
{
    AirInf *temp = head;
    while (temp != nullptr)
    {
        if (temp->destination == destination){
            if (temp->prev != nullptr && temp->next != nullptr){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            else if (temp->prev == nullptr && temp->next == nullptr){
                head = temp->next;
                tail = temp->prev;
            }
            else if (temp->prev == nullptr){
                head = temp->next;
                temp->next->prev = temp->prev;
            }
            else if (temp->next == nullptr){
                tail = temp->prev;
                temp->prev->next = temp->next;
            }
        }
        temp = temp->next;
    }
}

void List::deleteAll()
{
    head = nullptr;
    tail = nullptr;
}

bool List::isEmpty()
{
    if(head == nullptr){
        return true;
    }
    return false;
};

