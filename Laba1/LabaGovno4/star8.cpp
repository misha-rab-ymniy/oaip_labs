#include "star8.h"
#include <QDebug>

Star8::Star8()
{

}

void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int a=0;
    QPoint p[18]; //Массив для хранения координат вершин звезды

    //Цикл расчета вершин звезды
    for (int i=1;i<top*2+2;i++)
    {
       if (!(i%2)) //При выполнении условия четности следующие формулы
       {
           p[i].rx()=radius/2*cos(a*M_PI/180);
           p[i].ry()=radius/2*sin(a*M_PI/180);
       }
       else //При невыполнении условия четности следующие формулы
       {
           p[i].rx()=Radius*cos(a*M_PI/180);
           p[i].ry()=Radius*sin(a*M_PI/180);
       }
       a=a+180/top;
    }
    //Завершаем построение звезды соединяя её окончание с начальной точкой
    p[top*2+1].rx()=p[1].rx();
    p[top*2+1].ry()=p[1].ry();
    //moveto(p[1].x,p[1].y);
    qDebug() << "1";
    //Последовательное соединение точек массива, хранящего вершины звезды
    for (int i=1;i<top*2+1;i++)
    {
       painter->drawLine(p[i].rx(),p[i].ry(), p[i + 1].rx(),p[i + 1].ry());
    }
    //qDebug() << sqrt(p[1].rx()*p[2].rx() + p[1].ry() * p[2].ry());
    //delete []p; //Освобождаем память
    //Q_UNUSED(option);
    //Q_UNUSED(widget);
}

double Star8::square(){
    return this->getK() * this->getK() * (M_PI * radius * radius + (M_PI * Radius * Radius - M_PI * radius * radius) / 4);
}

double Star8::perimetr(){
    return size * 16 * getK();
}
