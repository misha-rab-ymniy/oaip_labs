#include "circle.h"

Circle::Circle()
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawEllipse(-radius / 2,- radius / 2,radius,radius);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Circle::square(){
    return this->getK() * this->getK() * M_PI * radius * radius;
}

double Circle::perimetr(){
    return -1;
}
