#ifndef SOLDIER_H
#define SOLDIER_H

#include "rectangle.h"
#include <QPixmap>
#include <QSound>

class soldier : public rectangle
{
    Q_OBJECT
public:
    soldier(QWidget* parent = nullptr);
    void draw(QPainter& painter) override;
    void doVladym();
private:
    QPoint c1;
    QPoint c2;
    QPoint c3;
    QPoint c4;

    QSound* sound;


    QPixmap *spriteImage;
    bool isMove;
public slots:
    void DoAction() override;
};

#endif // SOLDIER_H
