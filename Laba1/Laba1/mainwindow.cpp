#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton* CreateSold = new QPushButton("Create Soldier", this);
    CreateSold ->setGeometry(100, 40 ,75, 30);
    QPushButton* go = new QPushButton("go", this);
    go->setGeometry(200, 40 ,75, 30);
    connect(go, &QPushButton::clicked, this, &MainWindow::CreateRect);
    connect(CreateSold, &QPushButton::clicked, this, &MainWindow::CreateSoldier);
//    QPushButton* doVladym = new QPushButton("do Vladym", this);
//    connect(doVladym, &QPushButton::clicked, this, &soldier::doVladym);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateRect()
{
    rectangle* a = new rectangle();
    a->show();
}

void MainWindow::CreateSoldier()
{
    soldier* a = new soldier();
    a->show();
}
