#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "shape.h"

class Parallelogram : public Shape
{
private:
    double FirstLen = 100;
    double SecondLen = 94.34;
    double angel = 32;
public:
    Parallelogram();
    double square() override;
    double perimetr() override;
protected:
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // PARALLELOGRAM_H
