#include "universal.h"

Universal::Universal()
{

}

QRectF Universal::boundingRect() const
{
    return QRectF(-500,-500,1000,1000);   // Ограничиваем область, в которой лежит фигура
}

bool Universal::getUnivers()
{
    return univers;
}

void Universal::setUnivers(bool rot)
{
    univers = rot;
}

//______________________________________________________________________________
void Universal::move_up(){
    this->setPos(this->x(), this->y() - 1);
    if (this->y() < -500){
       this->setPos(this->x(), 500);
    }
}

void Universal::size(){
    //static double k = 1;
    if(this->getUnivers()){
        k += 0.02;
        if (k > 14){
            k = 0;
        }
    }
    else
    {
        k -= 0.02;
        if (k < 0){
            k = 14;
        }
    }

    this->setScale(k);
}

void Universal::move_right()
{
    this->setPos(this->x() + 1, this->y());
    if (this->x() > 800){
       this->setPos(-800, this->y());
    }
}

void Universal::move_left()
{
    this->setPos(this->x() - 1, this->y());
    if (this->x() < -800){
       this->setPos(800, this->y());
    }
}

void Universal::move_down()
{
    this->setPos(this->x(), this->y() + 1);
    if (this->y() > 500){
       this->setPos(this->x(), -500);
    }
}

void Universal::rotate()
{
    if(this->getUnivers())
    {
        ++a;
    }
    else
    {
        --a;
    }
    this->setRotation(a);
}

double Universal::square(){
    return -1;
}

double Universal::perimetr(){
    return -1;
}

double Universal::getK(){
    return k;
}

void Universal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
}

