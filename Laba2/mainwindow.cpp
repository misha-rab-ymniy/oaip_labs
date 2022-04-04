#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->show->setEnabled(false);
    ui->stackDelete->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_push_clicked()
{
    st.Push(ui->stackValue->value());
    ui->show->setEnabled(true);
    ui->stackDelete->setEnabled(true);
}


void MainWindow::on_show_clicked()
{
    ui->textEdit->setText(QString::number(st.Top()));
}

void MainWindow::on_stackDelete_clicked()
{
    st.Pop();
    if (!st.getSize()){
        ui->show->setEnabled(false);
        ui->stackDelete->setEnabled(false);
    }
}


void MainWindow::on_pushButton_clicked()
{
    WeakStruct *a = new WeakStruct(ui->stackValue_2->value());
    shared_ptr<WeakStruct> b(a->ptr);
    int z = b->ptr.lock()->value;
    ui->textEdit_2->setText(QString::number(z));
}

