#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setRowCount(15);
    ui->spinBox->setMaximum(15);
    QFile file("E:/proga/build-lab3task3-Desktop_Qt_5_9_9_MinGW_32bit-Debug/OPZ.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString str;
    while(!in.atEnd()){
        ++row;
        in >> str;
        ui->tableWidget->setItem(row-1, 0,new QTableWidgetItem(str));
        Stack<QChar> stack;
        QString polandStr;
        if (!check(str) || str.isEmpty()){
            return;
        }
        ui->tableWidget->setRowCount(row);
        ui->tableWidget->setItem(row-1, 0,new QTableWidgetItem(str));
        int ind = str.indexOf(' ');
        while(ind + 1){
            str.remove(ind, 1);
            ind = str.indexOf(' ');
        }
        //ui->label->setText(str);
        for (int i = 0; i < str.size(); ++i){
            if(str[i].isLetter()){
                if(str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e'){
                    polandStr += str[i];
                    polandStr += ' ';
                }
                else {
                    return;
                }
            }
            else if(str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '('){
                if((stack.Top() == '/' || stack.Top() == '*') && i + 1 != str.size() && (str[i] == '+' || str[i] == '-')){
                    while (stack.Top() != '(' && stack.getSize()){
                        polandStr += stack.Top();
                        polandStr += ' ';
                        stack.Pop();
                    }
                }
                else if ((stack.Top() == '-' || stack.Top() == '+') && i + 1 != str.size() && (str[i] == '-' || str[i] == '+')){
                    polandStr += stack.Top();
                    polandStr += ' ';
                    stack.Pop();
                }
                else if((stack.Top() == '/' || stack.Top() == '*') && i + 1 != str.size() && (str[i] == '*' || str[i] == '/')){
                    polandStr += stack.Top();
                    polandStr += ' ';
                    stack.Pop();
                }
                stack.Push(str[i]);
            }
            else if(str[i] == ')'){
                while (stack.Top() != '('){
                    polandStr += stack.Top();
                    polandStr += ' ';
                    stack.Pop();
                }
                stack.Pop();
                if ((i + 1 != str.size() && str[i + 1] != '*' && str[i+1] != '/') || stack.Top() == '*' || stack.Top() == '/'){
                    while (stack.getSize() && stack.Top() != '('){
                        polandStr += stack.Top();
                        polandStr += ' ';
                        stack.Pop();
                    }
                }

            }
            else{
                return;
            }
        }
        while (stack.getSize()){
            polandStr += stack.Top();
            polandStr += ' ';
            stack.Pop();
        }
        //ui->label_post->setText(polandStr);
        ui->tableWidget->setItem(row-1, 1,new QTableWidgetItem(polandStr));
        ind = polandStr.indexOf(' ');
        while(ind + 1){
            polandStr.remove(ind, 1);
            ind = polandStr.indexOf(' ');
        }
        bool isZero = false;
        Stack<double> val;
        for (int i = 0; i < polandStr.size(); ++i){
            if(polandStr[i].isLetter()){
                val.Push(value(polandStr[i]));
            }
            else{
                double value1, value2;
                switch (polandStr[i].toLatin1()){
                case '-':
                    value2 = val.Top();
                    val.Pop();
                    value1 = val.Top() - value2 ;
                    val.Pop();
                    val.Push(value1);
                    break;
                case '+':
                    value1 = val.Top();
                    val.Pop();
                    value1 += val.Top();
                    val.Pop();
                    val.Push(value1);
                    break;
                case '/':
                    value2 = val.Top();
                    val.Pop();
                    if(value2 == 0){
                        ui->tableWidget->setItem(row-1, 2,new QTableWidgetItem("не дели на ноль"));
                        isZero = true;
                        break;
                    }
                    value1 = val.Top() / value2;
                    val.Pop();
                    val.Push(value1);
                    break;
                case '*':
                    value1 = val.Top();
                    val.Pop();
                    value1 *= val.Top();
                    val.Pop();
                    val.Push(value1);
                    break;
                }
            }
        }
        if(!isZero){
            ui->tableWidget->setItem(row-1, 2,new QTableWidgetItem(QString::number(val.Top())));

        }
    }

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

double MainWindow::value(const QChar &c)
{
    switch(c.toLatin1()){
    case 'a':
        return ui->doubleSpinBox_a->value();
    case 'b':
        return ui->doubleSpinBox_b->value();
    case 'c':
        return ui->doubleSpinBox_c->value();
    case 'd':
        return ui->doubleSpinBox_d->value();
    case 'e':
        return ui->doubleSpinBox_e->value();
    }
}

bool MainWindow::check(const QString &str)
{
    for (int i = 0; i < str.size(); ++i){
        if (str[i] != '+' && str[i] != '/' && str[i] != '*' && str[i] != '-' && str[i] != 'a' && str[i] != ' ' && str[i] != 'b' && str[i] != 'c' && str[i] != 'd' && str[i] != 'e' && str[i] != '(' && str[i] != ')'){
            return false;
        }
    }
    if (isBktNormal(str) == -1){
        return true;
    }
    return false;
}

void MainWindow::on_pushButton_clicked()
{
    Stack<QChar> stack;
    QString str;
    QString polandStr;
    str = ui->lineEdit->text();
    if (!check(str) || str.isEmpty()){
        QMessageBox::critical(this,"Ошибка","Неверный формат ввода");
        return;
    }
    ++row;
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(row);
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setItem(row-1, 0,new QTableWidgetItem(str));
    int ind = str.indexOf(' ');
    while(ind + 1){
        str.remove(ind, 1);
        ind = str.indexOf(' ');
    }
    //ui->label->setText(str);
    for (int i = 0; i < str.size(); ++i){
        if(str[i].isLetter()){
            if(str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e'){
                polandStr += str[i];
                polandStr += ' ';
            }
            else {
                return;
            }
        }
        else if(str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '('){
            if((stack.Top() == '/' || stack.Top() == '*') && i + 1 != str.size() && (str[i] == '+' || str[i] == '-')){
                while (stack.Top() != '(' && stack.getSize()){
                    polandStr += stack.Top();
                    polandStr += ' ';
                    stack.Pop();
                }
            }
            else if ((stack.Top() == '-' || stack.Top() == '+') && i + 1 != str.size() && (str[i] == '-' || str[i] == '+')){
                polandStr += stack.Top();
                polandStr += ' ';
                stack.Pop();
            }
            else if((stack.Top() == '/' || stack.Top() == '*') && i + 1 != str.size() && (str[i] == '*' || str[i] == '/')){
                polandStr += stack.Top();
                polandStr += ' ';
                stack.Pop();
            }
            stack.Push(str[i]);
        }
        else if(str[i] == ')'){
            while (stack.Top() != '('){
                polandStr += stack.Top();
                polandStr += ' ';
                stack.Pop();
            }
            stack.Pop();
            if ((i + 1 != str.size() && str[i + 1] != '*' && str[i+1] != '/') || stack.Top() == '*' || stack.Top() == '/'){
                while (stack.getSize() && stack.Top() != '('){
                    polandStr += stack.Top();
                    polandStr += ' ';
                    stack.Pop();
                }
            }

        }
        else{
            return;
        }
    }
    while (stack.getSize()){
        polandStr += stack.Top();
        polandStr += ' ';
        stack.Pop();
    }
    //ui->label_post->setText(polandStr);
    ui->tableWidget->setItem(row-1, 1,new QTableWidgetItem(polandStr));
    ind = polandStr.indexOf(' ');
    while(ind + 1){
        polandStr.remove(ind, 1);
        ind = polandStr.indexOf(' ');
    }
    Stack<double> val;
    for (int i = 0; i < polandStr.size(); ++i){
        if(polandStr[i].isLetter()){
            val.Push(value(polandStr[i]));
        }
        else{
            double value1, value2;
            switch (polandStr[i].toLatin1()){
            case '-':
                value2 = val.Top();
                val.Pop();
                value1 = val.Top() - value2 ;
                val.Pop();
                val.Push(value1);
                break;
            case '+':
                value1 = val.Top();
                val.Pop();
                value1 += val.Top();
                val.Pop();
                val.Push(value1);
                break;
            case '/':
                value2 = val.Top();
                val.Pop();
                if(value2 == 0){
                    QMessageBox::warning(this,"Предупреждение","На ноль делить нельзя");
                    ui->tableWidget->setItem(row-1, 2,new QTableWidgetItem("не дели на ноль"));
                    return;
                }
                value1 = val.Top() / value2;
                val.Pop();
                val.Push(value1);
                break;
            case '*':
                value1 = val.Top();
                val.Pop();
                value1 *= val.Top();
                val.Pop();
                val.Push(value1);
                break;
            }
        }
    }
    ui->tableWidget->setItem(row-1, 2,new QTableWidgetItem(QString::number(val.Top())));
    //ui->label_res->setText(QString::number(val.Top()));
}


void MainWindow::on_pushButton_2_clicked()
{
    row = 0;
    ui->spinBox->setMaximum(0);
    ui->tableWidget->setRowCount(0);
}


void MainWindow::on_changeButton_clicked()
{
    int ind;
    QString polandStr;
    polandStr = ui->tableWidget->item(ui->spinBox->value() - 1,1)->text();
    ind = polandStr.indexOf(' ');
    while(ind + 1){
        polandStr.remove(ind, 1);
        ind = polandStr.indexOf(' ');
    }
    Stack<double> val;
    for (int i = 0; i < polandStr.size(); ++i){
        if(polandStr[i].isLetter()){
            val.Push(value(polandStr[i]));
        }
        else{
            double value1, value2;
            switch (polandStr[i].toLatin1()){
            case '-':
                value2 = val.Top();
                val.Pop();
                value1 = val.Top() - value2 ;
                val.Pop();
                val.Push(value1);
                break;
            case '+':
                value1 = val.Top();
                val.Pop();
                value1 += val.Top();
                val.Pop();
                val.Push(value1);
                break;
            case '/':
                value2 = val.Top();
                val.Pop();
                if(value2 == 0){
                    QMessageBox::warning(this,"Предупреждение","На ноль делить нельзя");
                    ui->tableWidget->setItem(ui->spinBox->value() - 1, 2,new QTableWidgetItem("не дели на ноль"));
                    return;
                }
                value1 = val.Top() / value2;
                val.Pop();
                val.Push(value1);
                break;
            case '*':
                value1 = val.Top();
                val.Pop();
                value1 *= val.Top();
                val.Pop();
                val.Push(value1);
                break;
            }
        }
    }
    ui->tableWidget->setItem(ui->spinBox->value() - 1, 2,new QTableWidgetItem(QString::number(val.Top())));
}

