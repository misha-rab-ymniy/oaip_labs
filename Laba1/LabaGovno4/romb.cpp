#include "romb.h"

Romb::Romb()
{

}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPolygon polygon;
    polygon << QPoint(0,-80) << QPoint(50,0) << QPoint(0,80) << QPoint(-50,0);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Romb::square(){
    return size * size * sin(angel*M_PI/180) * this->getK() * this->getK();
}

double Romb::perimetr(){
    return 4 * getK() * size;
}
