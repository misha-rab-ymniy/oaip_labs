#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QPushButton>

class rectangle : public QWidget
{
    Q_OBJECT
private:
    QPoint c1;
    QPoint c2;
    QPoint c3;
    QPoint c4;
    bool isMove;
    bool SideMove; //QPixMap
public:
    rectangle(QWidget *parent = nullptr);
protected:
    virtual void DoAction();
    virtual void draw(QPainter& painter) ;
    void paintEvent(QPaintEvent*) override;
};

#endif // RECTANGLE_H
