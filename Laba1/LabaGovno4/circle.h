#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape.h>

class Circle : public Shape
{
private:
    double radius = 80;
public:
    Circle();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // CIRCLE_H
