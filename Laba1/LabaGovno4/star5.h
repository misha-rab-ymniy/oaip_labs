#ifndef STAR5_H
#define STAR5_H

#include <shape.h>

class Star5 : public Shape
{
private:
    int Radius = 60;
    int radius = 40;
    int top = 5;
    double size = 30.9839;
public:
    Star5();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STAR5_H
