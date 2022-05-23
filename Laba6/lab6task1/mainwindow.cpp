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

void MainWindow::on_delet_clicked()
{
    tree.erase(ui->deleteKey->value());
}

void MainWindow::on_search_clicked()
{
    QString ans = tree.search(ui->searchKey->value());
    ui->display->setText(ans);
    update();
}


void MainWindow::on_postOrder_clicked()
{
    QString text = tree.postorderPrint();
    ui->display->setText(text);
    update();
}


void MainWindow::on_preorder_clicked()
{
    QString text = tree.preorderPrint();
    ui->display->setText(text);
    update();
}

void MainWindow::on_inorder_clicked()
{
    QString text = tree.inorderPrint();
    ui->display->setText(text);
    update();
}

void MainWindow::on_insert_clicked()
{
    int key = ui->key->value();
    QString data = ui->data->text();
    tree.insert(key, data);
}


void MainWindow::on_heightCalc_clicked()
{
    ui->display->setText(tree.heightCal());
}

