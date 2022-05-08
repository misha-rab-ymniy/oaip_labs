#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox_3->setEnabled(false);
    ui->operatorButton->setEnabled(false);
    ui->showButton->setEnabled(false);
    ui->popBackButton->setEnabled(false);
    ui->popFrontButton->setEnabled(false);
    for(int i =0; i < 10000; ++i){
        if(i%2 == 1){
            a.push_front(i);
        }
        else{
            a.push_back(i);
        }
    }
    a.clear();
    for(int i =0; i < 10000; ++i){
        if(i%2 == 1){
            a.push_front(i);
        }
        else{
            a.push_back(i);
        }
    }
    a.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    a.push_front(ui->spinBox->value());
    ui->textBrowser->setText(QString::number(a.size()));
    //ui->spinBox_2->setValue(ui->spinBox_2->value() + 1);
    ui->spinBox->setValue(ui->spinBox->value() + 1);
    ui->spinBox_3->setEnabled(true);
    ui->operatorButton->setEnabled(true);
    ui->showButton->setEnabled(true);
    ui->popBackButton->setEnabled(true);
    ui->popFrontButton->setEnabled(true);
    ui->spinBox_3->setMaximum(a.size()-1);
    //deque<int>::iterator it = a.begin();
    //qDebug() << *it;
    qDebug() << a.toString();
}


void MainWindow::on_popFrontButton_clicked()
{
    a.pop_front();
    ui->textBrowser->setText(QString::number(a.size()));
    //ui->spinBox_2->setValue(ui->spinBox_2->value() - 1);
    ui->spinBox->setValue(ui->spinBox->value() - 1);
    ui->spinBox_3->setMaximum(a.size()-1);
    if(a.empty()){
        ui->spinBox_3->setMinimum(0);
        ui->spinBox_3->setEnabled(false);
        ui->operatorButton->setEnabled(false);
        ui->showButton->setEnabled(false);
        ui->popBackButton->setEnabled(false);
        ui->popFrontButton->setEnabled(false);
    }
    qDebug() << a.toString();
}


void MainWindow::on_pushBackButton_clicked()
{
    a.push_back(ui->spinBox->value());
    ui->textBrowser->setText(QString::number(a.size()));
    //ui->spinBox_2->setValue(ui->spinBox_2->value() + 1);
    ui->spinBox->setValue(ui->spinBox->value() + 1);
    ui->spinBox_3->setEnabled(true);
    ui->operatorButton->setEnabled(true);
    ui->showButton->setEnabled(true);
    ui->popBackButton->setEnabled(true);
    ui->popFrontButton->setEnabled(true);
    ui->spinBox_3->setMaximum(a.size()-1);
    qDebug() << a.toString();
}


void MainWindow::on_popBackButton_clicked()
{
    a.pop_back();
    ui->textBrowser->setText(QString::number(a.size()));
    //ui->spinBox_2->setValue(ui->spinBox_2->value() - 1);
    ui->spinBox->setValue(ui->spinBox->value() - 1);
    ui->spinBox_3->setMaximum(a.size()-1);
    if(a.empty()){
        ui->spinBox_3->setMinimum(0);
        ui->spinBox_3->setEnabled(false);
        ui->operatorButton->setEnabled(false);
        ui->showButton->setEnabled(false);
        ui->popBackButton->setEnabled(false);
        ui->popFrontButton->setEnabled(false);
    }
    qDebug() << a.toString();
}


void MainWindow::on_clearButton_clicked()
{
    a.clear();
    ui->textBrowser->setText(QString::number(a.size()));
    //ui->spinBox_2->setValue(0);
    ui->spinBox->setValue(0);
    ui->spinBox_3->setEnabled(false);
    ui->operatorButton->setEnabled(false);
    ui->showButton->setEnabled(false);
    ui->popBackButton->setEnabled(false);
    ui->popFrontButton->setEnabled(false);
    ui->spinBox_3->setMaximum(0);
    qDebug() << a.toString();
}


void MainWindow::on_isEmptyButton_clicked()
{
    ui->textBrowser->setText(a.empty() ? "true" : "false");
}


void MainWindow::on_operatorButton_clicked()
{
    ui->textBrowser->setText(QString::number(a[ui->spinBox_3->value()]));
}


void MainWindow::on_showButton_clicked()
{
    QString ans;
    for(auto c : a){
        ans += QString::number(c) + ' ';
    }
//    for(deque<int>::iterator it = a.begin(); it != a.end(); ++it){
//        ans += QString::number(*it) + ' ';
//    }
    ui->textBrowser->setText(ans);
}

