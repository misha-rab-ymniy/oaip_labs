#include "square.h"

Square::Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //painter->setBrush(Qt::black);     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawRect(-size/2,-size/2,size,size);  // Рисуем треугольник по полигональной модели
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

double Square::square(){
    return this->getK() * this->getK() * size * size;
}

double Square::perimetr(){
    return 4 * getK() * size;
}
