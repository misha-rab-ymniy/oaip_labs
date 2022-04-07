#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->deleteButton->setEnabled(false);
    ui->showAllButton->setEnabled(false);
    ui->showButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    if(ui->lineNumFlight->text().isEmpty() || ui->lineTypePlane->text().isEmpty() || ui->lineDestination->text().isEmpty()){
        QMessageBox::warning(this,"Предупреждение", "Заполните пожалуйста все поля");
        return;
    }
    if (BusesPark.find(ui->lineNumFlight->text()) || BusesWay.find(ui->lineNumFlight->text())){
        QMessageBox::warning(this,"Предупреждение", "Автобус с таким номером уже есть");
        return;
    }
    BusesPark.Add(ui->lineNumFlight->text(), ui->lineTypePlane->text(), ui->lineDestination->text(), ui->timeDepartureTime->time(), ui->timeArrivalTime->time());
    ui->deleteButton->setEnabled(true);
    ui->showAllButton->setEnabled(true);
    ui->showButton->setEnabled(true);
    ui->textBrowser->setText(BusesPark.toString());
}


void MainWindow::on_deleteButton_clicked()
{
    BusesPark.deleteAll();
    BusesWay.deleteAll();
    ui->deleteButton->setEnabled(!BusesPark.isEmpty());
    ui->showAllButton->setEnabled(!BusesPark.isEmpty());
    ui->showButton->setEnabled(!BusesPark.isEmpty());
    ui->textBrowser->setText(BusesPark.toString());
    ui->lineDelNumBus->clear();
    ui->textBrowser_2->setText(BusesPark.toString());
}


void MainWindow::on_showAllButton_clicked()
{
    ui->textBrowser->setText(BusesPark.toString());
    ui->textBrowser_2->setText(BusesPark.toString());
}

void MainWindow::on_showButton_clicked()
{
    ui->textBrowser->setText(BusesPark.toString(ui->lineShowDestination->text()));
    ui->textBrowser_2->setText(BusesWay.toString(ui->lineShowDestination->text()));
    ui->lineShowDestination->clear();
}


void MainWindow::on_saveFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    QTextStream out(&file);
    QString str;
    str = BusesPark.toString() + BusesWay.toString();
    out << str;
}

void MainWindow::on_openFileButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream in(&file);
    if (in.atEnd()){
        QMessageBox::warning(this,"Предупреждение","Файл является пустым");
        return;
    }
    BusesPark.deleteAll();
    BusesWay.deleteAll();
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    QString str1, str2, str3, str4;
    QTime time, time1;
    while(!in.atEnd()){
        in >> str1;
        if (str1.isEmpty()){
            ui->deleteButton->setEnabled(!BusesPark.isEmpty());
            ui->showAllButton->setEnabled(!BusesPark.isEmpty());
            ui->showButton->setEnabled(!BusesPark.isEmpty());
            ui->textBrowser->setText(BusesPark.toString());
            return;
        }
        in >> str2;
        in >> str3;
        in >> str4;
        time = QTime::fromString(str4,Qt::LocalDate);
        in >> str4;
        time1 = QTime::fromString(str4,Qt::LocalDate);
        if(!time.isValid() || !time.isValid()){
            BusesPark.deleteAll();
            QMessageBox::critical(this,"Ошибка","Неправильный формат в файле");
            return;
        }
        BusesPark.Add(str1, str2, str3, time, time1);
    }

    ui->deleteButton->setEnabled(!BusesPark.isEmpty());
    ui->showAllButton->setEnabled(!BusesPark.isEmpty());
    ui->showButton->setEnabled(!BusesPark.isEmpty());
    ui->textBrowser->setText(BusesPark.toString());
}

void MainWindow::on_changeButton_clicked()
{
    if(BusesPark.find(ui->lineDelNumBus->text())){
        BusesWay.Add(BusesPark.getStruct(ui->lineDelNumBus->text()));
        BusesPark.deleteBus(ui->lineDelNumBus->text());
    }
    else if (BusesWay.find(ui->lineDelNumBus->text())){
        BusesPark.Add(BusesWay.getStruct(ui->lineDelNumBus->text()));
        BusesWay.deleteBus(ui->lineDelNumBus->text());
    }
    else {
        QMessageBox::warning(this,"Предупреждение","Нет такого автобуса");
        return;
    }
    ui->textBrowser->setText(BusesPark.toString());
    ui->textBrowser_2->setText(BusesWay.toString());
}

