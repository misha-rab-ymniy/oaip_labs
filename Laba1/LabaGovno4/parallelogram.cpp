#include "parallelogram.h"

Parallelogram::Parallelogram()
{

}

void Parallelogram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-80,40) << QPoint(-30,-40) << QPoint(70,-40) << QPoint(20, 40);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Parallelogram::square(){
    return this->getK() * this->getK() * sin(angel*M_PI/180) * FirstLen * SecondLen;
}

double Parallelogram::perimetr(){
    return (2*getK()*FirstLen + 2*getK()*SecondLen);
}
