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
    Flights.Add(ui->lineNumFlight->text(), ui->lineTypePlane->text(), ui->lineDestination->text(), ui->timeDepartureTime->time());
    ui->deleteButton->setEnabled(true);
    ui->showAllButton->setEnabled(true);
    ui->showButton->setEnabled(true);
    ui->textBrowser->setText(Flights.toString());
}


void MainWindow::on_deleteButton_clicked()
{
    Flights.deleteFlight(ui->lineDeleteDestination->text());
    ui->deleteButton->setEnabled(!Flights.isEmpty());
    ui->showAllButton->setEnabled(!Flights.isEmpty());
    ui->showButton->setEnabled(!Flights.isEmpty());
    ui->textBrowser->setText(Flights.toString());
    ui->lineDeleteDestination->clear();
}


void MainWindow::on_showAllButton_clicked()
{
    ui->textBrowser->setText(Flights.toString());
}

void MainWindow::on_showButton_clicked()
{
    ui->textBrowser->setText(Flights.toString(ui->findTimeDepartureTime->time().toString()));
    ui->findTimeDepartureTime->setTime(QTime(0,0,0));
}


void MainWindow::on_saveFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    QTextStream out(&file);
    out << Flights.toString();
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
    QString str1, str2, str3, str4;
    QTime time;
    while(!in.atEnd()){
        in >> str1;
        if (str1.isEmpty()){
            ui->deleteButton->setEnabled(!Flights.isEmpty());
            ui->showAllButton->setEnabled(!Flights.isEmpty());
            ui->showButton->setEnabled(!Flights.isEmpty());
            ui->textBrowser->setText(Flights.toString());
            return;
        }
        in >> str2;
        in >> str3;
        in >> str4;
        time = QTime::fromString(str4,Qt::LocalDate);
        if(!time.isValid()){
            Flights.deleteAll();
            QMessageBox::critical(this,"Ошибка","Неправильный формат в файле");
            return;
        }
        Flights.Add(str1, str2, str3, time);
    }
    ui->deleteButton->setEnabled(!Flights.isEmpty());
    ui->showAllButton->setEnabled(!Flights.isEmpty());
    ui->showButton->setEnabled(!Flights.isEmpty());
    ui->textBrowser->setText(Flights.toString());
}

