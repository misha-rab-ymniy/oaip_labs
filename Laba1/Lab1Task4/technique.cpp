#include "technique.h"

Technique::Technique()
{

}

const QString &Technique::getType() const
{
    return type;
}

void Technique::setType(const QString &newType)
{
    type = newType;
}

const QString &Technique::getFirm() const
{
    return firm;
}

void Technique::setFirm(const QString &newFirm)
{
    firm = newFirm;
}

const QString &Technique::getModel() const
{
    return model;
}

void Technique::setModel(const QString &newModel)
{
    model = newModel;
}

int Technique::getPrice() const
{
    return price;
}

void Technique::setPrice(int newPrice)
{
    price = newPrice;
}

bool Technique::getIsAval() const
{
    return isAval;
}

void Technique::setIsAval(bool newIsAval)
{
    isAval = newIsAval;
}

QString Technique::toString()
{
    return type + " " + firm + " " + model + " " + QString::number(price) + " " + (isAval ? "доступен" : "не доступен") + "\n";
}
