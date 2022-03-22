#include "rectangle.h"

rectangle::rectangle(QWidget *parent)
    : QWidget{parent}
{
    c1.rx() = 100;
    c1.ry() = 200;
    c2.rx() = 200;
    c2.ry() = 200;
    c3.rx() = 200;
    c3.ry() = 500;
    c4.rx() = 100;
    c4.ry() = 500;
    isMove = false;
    SideMove = true;

    QPushButton* doAction = new QPushButton("Do Action", this);
    connect(doAction, &QPushButton::clicked, this, &rectangle::DoAction);
    this->showMaximized();
}


void rectangle::draw(QPainter& painter){
    painter.drawLine(c1,c2);
    painter.drawLine(c2,c3);
    painter.drawLine(c3,c4);
    painter.drawLine(c4,c1);
    if(isMove){
        if (SideMove){
            c1.rx()+= 2;
            c2.rx()+= 2;
            c3.rx()+= 2;
            c4.rx()+= 2;
            if(c1.rx() > 1920){
                c1.rx() = -100;
                c1.ry() = 200;
                c2.rx() = 0;
                c2.ry() = 200;
                c3.rx() = 0;
                c3.ry() = 500;
                c4.rx() = -100;
                c4.ry() = 500;
            }
        }
    }
//                SideMove = false;
//        }
//        else if (!SideMove) {
//            c1.rx()-= 4;
//            c2.rx()-= 4;
//            c3.rx()-= 4;
//            c4.rx()-= 4;
//            if(c1.rx() < 100) SideMove = true;
//        }


    update();
}

void rectangle::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    draw(painter);
    painter.end();
}

void rectangle::DoAction()
{
    isMove = !isMove;
}
