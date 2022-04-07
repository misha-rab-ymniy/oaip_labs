#include "businf.h"

List::List() : begin(-1), end(-1), size(0){}

void List::Add(QString numFlight, QString typeBus, QString destination, QTime departureTime, QTime arrivalTime)
{
    BusInf tmp;
    tmp.numBus = numFlight;
    tmp.typeBus = typeBus;
    tmp.destination = destination;
    tmp.departureTime = departureTime;
    tmp.arrivalTime = arrivalTime;
    if (!bus.size()){
        end = 0;
        begin = 0;
        tmp.prev = -1;
        tmp.next = -1;
    }
    else{
        end = bus.size();
        begin = 0;
        tmp.prev = bus.size()-1;
        bus[tmp.prev].next = bus.size();
        tmp.next = -1;
    }
    bus.push_back(tmp);
}

void List::Add(BusInf tm)
{
    BusInf tmp;
    tmp.numBus = tm.numBus;
    tmp.typeBus = tm.typeBus;
    tmp.destination = tm.destination;
    tmp.departureTime = tm.departureTime;
    tmp.arrivalTime = tm.arrivalTime;
    if (!bus.size()){
        end = 0;
        begin = 0;
        tmp.prev = -1;
        tmp.next = -1;
    }
    else{
        end = bus.size();
        begin = 0;
        tmp.prev = bus.size()-1;
        bus[tmp.prev].next = bus.size();
        tmp.next = -1;
    }
    bus.push_back(tmp);
}

QString List::toString(){
    QString str;
    for(int i = 0; i < bus.size(); ++i)
    {
        str += bus[i].numBus;
        str += ' ';
        str += bus[i].typeBus;
        str += ' ';
        str += bus[i].destination;
        str += ' ';
        str += bus[i].departureTime.toString(Qt::LocaleDate);
        str += ' ';
        str += bus[i].arrivalTime.toString(Qt::LocaleDate);
        str += '\n';
    }
    return str;
}

QString List::toString(const QString &destination){
    QString str;
    for(int i = 0; i < bus.size(); ++i)
    {
        if(bus[i].destination == destination){
            str += bus[i].numBus;
            str += ' ';
            str += bus[i].typeBus;
            str += ' ';
            str += bus[i].destination;
            str += ' ';
            str += bus[i].departureTime.toString(Qt::LocaleDate);
            str += ' ';
            str += bus[i].arrivalTime.toString(Qt::LocaleDate);
            str += '\n';
        }
    }
    return str;
}

void List::deleteBus(const QString &numBus){
    for(int i = 0; i < bus.size(); ++i){
        if(bus[i].numBus == numBus){
            bus.erase(bus.begin() + i);
            end = bus.size();
            break;
        }
    }
    for(int i = 0; i < bus.size(); ++i){
        bus[i].prev = bus.size()-1;
        bus[bus[i].prev].next = bus.size();
        bus[i].next = -1;
    }
}

void List::deleteAll(){
    bus.clear();
    begin = -1;
    end = -1;
}

List::BusInf List::getStruct(const QString& numBus)
{
    BusInf tmp;
    for (int i = 0; i < bus.size(); ++i){
        if(bus[i].numBus == numBus){
            tmp.arrivalTime = bus[i].arrivalTime;
            tmp.departureTime = bus[i].departureTime;
            tmp.destination = bus[i].destination;
            tmp.numBus = bus[i].numBus;
            tmp.typeBus = bus[i].typeBus;
            break;
        }
    }
    return tmp;
}

bool List::find(const QString &numBus)
{
    for (int i = 0; i < bus.size(); ++i){
        if(bus[i].numBus == numBus){
            return true;
        }
    }
    return false;
}

bool List::isEmpty(){
    if(!bus.size()){
        return true;
    }
    return false;
}
