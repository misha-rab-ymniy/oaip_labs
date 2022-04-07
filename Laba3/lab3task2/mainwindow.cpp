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

int MainWindow::isBktNormal(const QString &str)
{
    //Если строка верна, то возвращаемое значение равно -1
    //Если строка неверна, то возвращаемое значение равно номеру ошибочной скобки
    Stack<QChar> stack;
    Stack<int> numBkt;
    for (int i = 0; i < str.size(); ++i) {
        switch (str[i].toLatin1()) {
        case '(': stack.Push(')'); numBkt.Push(i); break;
        case '[': stack.Push(']'); numBkt.Push(i); break;
        case '{': stack.Push('}'); numBkt.Push(i); break;
        case ')':
        case ']':
        case '}':
            if (!stack.getSize() || stack.Top() != str[i]) {
                return i + 1;
            }
            numBkt.Pop();
            stack.Pop();
            break;
        }
    }
    if (!stack.getSize()){
        return - 1;
    }
    else{
        return numBkt.Top() + 1;
    }
}


void MainWindow::on_checkButton_clicked()
{
    int checkedVal = isBktNormal(ui->lineEdit->text());
    if (checkedVal == -1){
        QMessageBox::information(this, "Итог","Всё верно");
    }
    else{
        QMessageBox::information(this, "Итог","Ошибка в строке 1 и столбце " + QString::number(checkedVal));
    }
}


void MainWindow::on_openButton_clicked()
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
    QString str;
    str = in.readAll();
    int exept = isBktNormal(str);
    if(exept != -1){
        in.seek(0);
        str = in.readLine();
        int row = 1;
        while(exept - str.size() - row > 0){
            ++row;
            exept -= str.size();
            str = in.readLine();
            if(in.atEnd()){
                break;
            }
        }
        exept -= row - 1;
        QMessageBox::information(this, "Итог","Ошибка в строке " + QString::number(row) + " и столбце " + QString::number(exept));
        in.seek(0);
        ui->textBrowser->setText(in.readAll());
        return;
    };
    QMessageBox::information(this, "Итог","Всё верно");
    in.seek(0);
    ui->textBrowser->setText(in.readAll());
}

