#ifndef STAR8_H
#define STAR8_H

#include <shape.h>

class Star8 : public Shape
{
private:
    int Radius = 80;
    int radius = 60;
    int top = 8;
    double size = 46.4758;
public:
    Star8();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STAR8_H
