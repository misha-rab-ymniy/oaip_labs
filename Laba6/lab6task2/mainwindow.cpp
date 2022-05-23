#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hash_table.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int size = 0;
    hash_table table(30);
    for (int i = -10; i < 15; i += rand() % 2 + 1){
        size++;
        table.insertItem(i, i);
    }
    QString ans;
    QTextStream out(&ans);
    out << "HashTable:\n";
    out << table.displayHash();
    out << "\nMaxKey:\n";
    out << table.findMaxKey();
    ui->display->setText(ans);
}

