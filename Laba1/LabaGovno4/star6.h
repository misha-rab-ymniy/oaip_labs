#ifndef STAR6_H
#define STAR6_H

#include <shape.h>

class Star6 : public Shape
{
private:
    int Radius = 80;
    int radius = 80;
    int top = 6;
    double size = 52.1536;
public:
    Star6();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STAR6_H
