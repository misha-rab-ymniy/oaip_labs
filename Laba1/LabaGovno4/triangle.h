#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <shape.h>

// Наследуемся от QGraphicsItem
class Triangle : public Shape
{
private:
    double size = 80;
    double angel = 60;
public:
    Triangle();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // TRIANGLE_H
