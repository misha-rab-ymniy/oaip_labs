#include "triangle.h"

Triangle::Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(-40,20 * sqrt(3)) << QPoint(0,-20 * sqrt(3)) << QPoint(40,20 * sqrt(3));
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Triangle::square(){
    return this->getK() * this->getK() * 0.5 * size * size * sin(angel*M_PI/180);
}

double Triangle::perimetr(){
    return size * getK() * 3;
}
