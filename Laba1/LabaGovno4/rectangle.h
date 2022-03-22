#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <shape.h>

class Rectangle : public Shape
{
private:
    double length = 120;
    double width = 60;
     //переменная импользуется для выбора между уменьшением/увеличением или поворотом вправо/влево
public:
    Rectangle();
    double square() override;
    double perimetr() override;
protected:
   // QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // RECTANGLE_H
