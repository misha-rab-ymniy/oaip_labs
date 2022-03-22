#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setGeometry(0,40,1920,1000);

    scene = new QGraphicsScene();
    time = new QTimer();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(-250,-250,500,500);

    this->EnabledActions(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_TriangleButton_clicked()
{
    scene->removeItem(universal);
    universal = new Triangle;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_RectangleButton_clicked()
{
    scene->removeItem(universal);
    universal = new Rectangle;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_CircleButton_clicked()
{
    scene->removeItem(universal);
    universal = new Circle;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_RombButton_clicked()
{
    scene->removeItem(universal);
    universal = new Romb;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_SquareButton_clicked()
{
    scene->removeItem(universal);
    universal = new Square;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_HexagonButton_clicked()
{
    scene->removeItem(universal);
    universal = new Hexagon;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_Star5Button_clicked()
{
    scene->removeItem(universal);
    universal = new Star5;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_Star6Button_clicked()
{
    scene->removeItem(universal);
    universal = new Star6;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_ParallelogramButton_clicked()
{

    scene->removeItem(universal);
    universal = new Parallelogram;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

void Widget::on_Star8Button_clicked()
{
    if (universal != nullptr){
        scene->removeItem(universal);
    };
    universal = new Star8;
    this->EnabledActions(true);
    PutVal();
    scene->addItem(universal);
    universal->setPos(0,0);
}

//__________________________________________________________________________

void Widget::on_sizeplus_pressed()
{
    universal->setUnivers(true);
    connect(time, SIGNAL(timeout()), this, SLOT(size_slot()));
    time->start(10);
}


void Widget::on_sizeplus_released()
{
    time->stop();
    disconnect(time, SIGNAL(timeout()), this, SLOT(size_slot()));
}

void Widget::on_sizeminus_pressed()
{
    universal->setUnivers(false);
    connect(time, SIGNAL(timeout()), this, SLOT(size_slot()));
    time->start(10);
}


void Widget::on_sizeminus_released()
{
    time->stop();
    disconnect(time, SIGNAL(timeout()), this, SLOT(size_slot()));
}

void Widget::size_slot(){
    PutVal();
    universal->size();
}
//____________________________________________________________________________

void Widget::on_move_up_pressed()
{
    connect(time, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    time->start(10);
}


void Widget::on_move_up_released()
{
    time->stop();
    disconnect(time, SIGNAL(timeout()), this, SLOT(move_up_slot()));
}

void Widget::move_up_slot(){
    ui->CentrMassNum->setText("(" + QString::number(universal->pos().x()) + "," + QString::number(-universal->pos().y()) + ")");
    universal->move_up();
}
//_______________________________________________________________________________

void Widget::on_rotate_right_pressed()
{
    universal->setUnivers(true);
    connect(time, SIGNAL(timeout()), this, SLOT(rotate_slot()));
    time->start(10);
}

void Widget::on_rotate_right_released()
{
    time->stop();
    disconnect(time, SIGNAL(timeout()), this, SLOT(rotate_slot()));
}

void Widget::on_rotate_left_pressed()
{
    universal->setUnivers(false);
    connect(time, SIGNAL(timeout()), this, SLOT(rotate_slot()));
    time->start(10);
}


void Widget::on_rotate_left_released()
{
    time->stop();
    disconnect(time, SIGNAL(timeout()), this, SLOT(rotate_slot()));
}

void Widget::rotate_slot()
{
    universal->rotate();
}
//________________________________________________________________________

void Widget::on_move_down_pressed()
{
    connect(time, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    time->start(10);
}


void Widget::on_move_down_released()
{
    time->stop();
    disconnect(time, SIGNAL(timeout()), this, SLOT(move_down_slot()));
}

void Widget::move_down_slot()
{
    ui->CentrMassNum->setText("(" + QString::number(universal->pos().x()) + "," + QString::number(universal->pos().y()) + ")");
    universal->move_down();
}
//________________________________________________________________________

void Widget::on_move_left_pressed()
{
    connect(time, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    time->start(10);
}


void Widget::on_move_left_released()
{
    time->stop();
    disconnect(time, SIGNAL(timeout()), this, SLOT(move_left_slot()));
}

void Widget::move_left_slot()
{
    ui->CentrMassNum->setText("(" + QString::number(universal->pos().x()) + "," + QString::number(universal->pos().y()) + ")");
    universal->move_left();
}

//_______________________________________________________________________

void Widget::on_move_right_pressed()
{
    connect(time, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    time->start(10);
}


void Widget::on_move_right_released()
{
    time->stop();
    disconnect(time, SIGNAL(timeout()), this, SLOT(move_right_slot()));
}

void Widget::move_right_slot()
{
    ui->CentrMassNum->setText("(" + QString::number(universal->pos().x()) + "," + QString::number(universal->pos().y()) + ")");
    universal->move_right();
}
//__________________________________________________________________________

void Widget::on_CanveModButton_clicked()
{

    scene->removeItem(universal);
    CanveMod = !CanveMod;
    RightClicked = false;
    if (!CanveMod){
        ui->CircleButton->setEnabled(true);
        scene->clear();
        FirstP = false;
    }
    this->Zeroing();
    this->EnabledButtons(!CanveMod);
    this->EnabledActions(false);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(CanveMod)
    {
        if (event->button() == Qt::LeftButton && !RightClicked){
            if (FirstP){
                scene->addLine(PreviousPoint.x() - 856,PreviousPoint.y() - 528, QCursor::pos().x() - 856, QCursor::pos().y() - 528, QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap));
            }
            else{
                scene->addEllipse(QCursor::pos().x() - 856,QCursor::pos().y() - 528, 4, 4, QPen(Qt::NoPen), QBrush(Qt::black));
                FirstPoint.rx() = QCursor::pos().x();
                FirstPoint.ry() = QCursor::pos().y();
            }
            FirstP = true;
            PreviousPoint = QCursor::pos();
        }
        if (event->button() == Qt::RightButton){
            RightClicked = true;
            scene->addLine(PreviousPoint.x() - 856,PreviousPoint.y() - 528, FirstPoint.rx() - 856, FirstPoint.ry() - 528, QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap));
        }
    }
    if (event->button() == Qt::MidButton){
        on_CanveModButton_clicked();
    }
}
//______________________________________________________________________

void Widget::EnabledButtons(bool enable){
    ui->CircleButton->setEnabled(enable);
    ui->HexagonButton->setEnabled(enable);
    ui->ParallelogramButton->setEnabled(enable);
    ui->RectangleButton->setEnabled(enable);
    ui->RombButton->setEnabled(enable);
    ui->SquareButton->setEnabled(enable);
    ui->Star5Button->setEnabled(enable);
    ui->Star6Button->setEnabled(enable);
    ui->Star8Button->setEnabled(enable);
    ui->TriangleButton->setEnabled(enable);
    ui->move_down->setEnabled(enable);
    ui->move_left->setEnabled(enable);
    ui->move_right->setEnabled(enable);
    ui->move_up->setEnabled(enable);
    ui->rotate_left->setEnabled(enable);
    ui->rotate_right->setEnabled(enable);
    ui->sizeminus->setEnabled(enable);
    ui->sizeplus->setEnabled(enable);
}

void Widget::EnabledActions(bool enable){
    ui->move_down->setEnabled(enable);
    ui->move_left->setEnabled(enable);
    ui->move_right->setEnabled(enable);
    ui->move_up->setEnabled(enable);
    ui->rotate_left->setEnabled(enable);
    ui->rotate_right->setEnabled(enable);
    ui->sizeminus->setEnabled(enable);
    ui->sizeplus->setEnabled(enable);
}

void Widget::Zeroing(){
    ui->SquareNum->setText("0");
    ui->PerimetrNum->setText("0");
    ui->CentrMassNum->setText("(0,0)");
}

void Widget::PutVal(){
    ui->SquareNum->setText(QString::number(universal->square()));
    ui->PerimetrNum->setText(QString::number(universal->perimetr()));
}


