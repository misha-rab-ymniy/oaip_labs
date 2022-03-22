#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <triangle.h>
#include <rectangle.h>
#include <shape.h>
#include <circle.h>
#include <romb.h>
#include <square.h>
#include <hexagon.h>
#include <star5.h>
#include <star6.h>
#include <star8.h>
#include <parallelogram.h>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    void EnabledButtons(bool enable);

    void EnabledActions(bool enable);

    void Zeroing();

    void PutVal();

private slots:
    void on_TriangleButton_clicked();

    void on_RectangleButton_clicked();

    void on_CircleButton_clicked();

    void on_RombButton_clicked();

    void on_SquareButton_clicked();

    void on_HexagonButton_clicked();

    void on_Star5Button_clicked();

    void on_Star6Button_clicked();

    void on_Star8Button_clicked();

    void on_ParallelogramButton_clicked();

//________________________________________________________________________________________

    void size_slot();

    void on_sizeplus_pressed();

    void on_sizeplus_released();

    void on_sizeminus_pressed();

    void on_sizeminus_released();

//________________________________________________________________________________________

    void on_move_up_pressed();

    void on_move_up_released();

    void move_up_slot();

//________________________________________________________________________________________

    void on_rotate_right_pressed();

    void on_rotate_right_released();

    void on_rotate_left_pressed();

    void on_rotate_left_released();

    void rotate_slot();
//________________________________________________________________________________________

    void on_move_down_pressed();

    void on_move_down_released();

    void move_down_slot();

//_______________________________________________________________________________________

    void on_move_left_pressed();

    void on_move_left_released();

    void move_left_slot();

//_______________________________________________________________________________________

    void on_move_right_pressed();

    void on_move_right_released();

    void move_right_slot();
//________________________________________________________________________________________

    void mousePressEvent(QMouseEvent *event);

    void on_CanveModButton_clicked();

private:
    Ui::Widget *ui;

    QGraphicsScene *scene;
    QTimer *time;
    Shape *universal = nullptr;

    QPointF PreviousPoint;
    QPointF FirstPoint;
    bool RightClicked = false;
    bool CanveMod = false;
    bool FirstP = false;
};
#endif // WIDGET_H
