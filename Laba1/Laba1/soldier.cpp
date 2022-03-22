#include "soldier.h"

soldier::soldier(QWidget* parent) : rectangle{parent}
{
    c1.rx() = 100;
    c1.ry() = 200;
    c2.rx() = 200;
    c2.ry() = 200;
    c3.rx() = 200;
    c3.ry() = 400;
    c4.rx() = 100;
    c4.ry() = 400;
    isMove = false;
    sound = new QSound("E:\\Загрузки\\soldaty-yunost-v-sapogah.wav");
//    QPushButton* doVladym = new QPushButton("do Vladym", this);
//    connect(doVladym, &QPushButton::clicked, this, &soldier::doVladym);
}

void soldier::draw(QPainter &painter){
    spriteImage = new QPixmap("E:/Загрузки/Vadim.jpg");
    painter.drawPixmap(c1.rx() - 8, c1.ry() - 143, *spriteImage);
    painter.drawLine(c1,c2);
    painter.drawLine(c2,c3);
    painter.drawLine(c3,c4);
    painter.drawLine(c4,c1);
    painter.drawLine(c2.rx() + 10, c2.ry() - 110, c2.rx() + 80, c2.ry() - 60);
    painter.drawLine(c2.rx(), c2.ry(), c2.rx() + 80, c2.ry() - 60);
    painter.drawLine(c4.rx() + 50, c4.ry(), c4.rx(), c4.ry() + 100);
    painter.drawLine(c4.rx() + 50, c4.ry(), c3.rx(), c3.ry() + 100);
    //painter.drawLine(c4,c1);
    if(isMove){
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
            c3.ry() = 400;
            c4.rx() = -100;
            c4.ry() = 400;
        }
    }
    update();
}

void soldier::DoAction() {
    isMove = !isMove;
    if (isMove){
        sound->setLoops(QSound::Infinite);
        sound->play();
    }
    else{
        sound->stop();
    }

}
