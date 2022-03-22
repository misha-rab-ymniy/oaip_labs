#ifndef STAR_H
#define STAR_H

#include "universal.h"

class Star
{
private:
    int Radius;
    int radius;
    int top;
public:
    Star();
    virtual double square();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STAR_H
