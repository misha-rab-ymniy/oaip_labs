#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_all_clicked()
{
    ui->display->append((bs.all() ? QString("all") : QString("not all")) + " bits are one");
}


void MainWindow::on_any_clicked()
{
    ui->display->append((bs.any() ? QString("at least one bit is one") : QString("all bits are zero")));
}


void MainWindow::on_count_clicked()
{
    ui->display->append("count of ones is " + QString::number(bs.count()));
}


void MainWindow::on_flip_clicked()
{
    bs.flip();
}


void MainWindow::on_none_clicked()
{
    ui->display->append((!bs.none() ? QString("at least one bit is one") : QString("all bits are zero")));
}


void MainWindow::on_reset_clicked()
{
    bs.reset();
}


void MainWindow::on_set_clicked()
{
    bs.set();
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->display->append("size is " + QString::number(bs.size()));
}


void MainWindow::on_pushButton_clicked()
{
    QString ans;
    ans = bs.to_string();
    ui->display->append(bs.to_string());
}


void MainWindow::on_setIndex_clicked()
{
    int index = ui->index->value();
    bs.set(index);
}


void MainWindow::on_flipIndex_2_clicked()
{
    int index = ui->index->value();
    bs.flip(index);
}


void MainWindow::on_resetIndex_clicked()
{
    int index = ui->index->value();
    bs.reset(index);
}


void MainWindow::on_testIndex_clicked()
{
    int index = ui->index->value();
    ui->display->append("bit with index " + QString::number(index) + " is " + QString::number(bs.test(index)));
}

