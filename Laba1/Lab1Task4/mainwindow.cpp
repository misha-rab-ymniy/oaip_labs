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
    delete ass;
}

void MainWindow::on_pushButton_clicked()
{
    ass->AddTech(ui->typeGet->text(), ui->firmGet->text(), ui->modelGet->text(), ui->priceGet->value(), ui->yesOrNo->isChecked());
}


void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream in(&file);
    QString input;
    input = in.readAll();
    if (!ass->ReadFile(input)){
        ui->display->setText("русский военный корабль иди нахуй, неправильный формат");
        update();
        file.close();
        return;
    }
    file.close();
    ui->display->setText(input);
    update();
}


void MainWindow::on_showAll_clicked()
{
    ui->display->clear();
    ui->display->insertPlainText(ass->showAll());
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    QTextStream out(&file);
    out << ui->display->toPlainText();
    file.flush();
    file.close();
}


void MainWindow::on_sortButton_clicked()
{
    ass->Sort();
}


void MainWindow::on_delButton_clicked()
{
    ass->DelElem(ui->modButton->text());
}

