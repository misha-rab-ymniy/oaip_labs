#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->topButton->setEnabled(false);
    ui->allQueueButton->setEnabled(false);
    ui->popButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int value = ui->spinBox->value();
    Queue.push(value);
    ui->allQueueButton->setEnabled(true);
    ui->topButton->setEnabled(true);
    ui->popButton->setEnabled(true);
}


void MainWindow::on_topButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::number(Queue.top()));
}


void MainWindow::on_popButton_clicked()
{
    Queue.pop();
    if(Queue.isEmpty()){
        ui->topButton->setEnabled(false);
        ui->allQueueButton->setEnabled(false);
        ui->popButton->setEnabled(false);
    }
}


void MainWindow::on_allQueueButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem(Queue.toString());
}


void MainWindow::on_findButton_clicked()
{
    if(ui->listWidget->count() > 4){
        ui->listWidget->clear();
    }
    queue<int> q;
    int sz = 10;
    QString ans;
    for (int i = 0; i < sz; ++i){
        int val = rand() % 100;
        ans += QString::number(val) + " ";
        q.push(val);
    }
    int min = q.top();
    for (int i = 0; i < sz; ++i){
        if (min > q.top()){
            min = q.top();
        }
        q.push(q.top());
        q.pop();
    }
    while(q.top() != min){
        q.push(q.top());
        q.pop();
    }
    ans += '\n';
    while (sz--) {
        ans += QString::number(q.top()) + " ";
        q.pop();
    }
    ui->listWidget->addItem(ans);
}

