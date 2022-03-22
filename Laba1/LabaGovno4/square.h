#ifndef SQUARE_H
#define SQUARE_H

#include <shape.h>

class Square : public Shape
{
private:
    double size = 60;
public:
    Square();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // SQUARE_H
