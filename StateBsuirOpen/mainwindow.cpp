#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <regex>
#include <QDebug>
#include <QXmlStreamReader>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->resizeSection(0,200);
    for(int i = 1; i < 16; ++i){
        ui->tableWidget->horizontalHeader()->resizeSection(i,40);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_openButton_clicked()
{
    univerName.clear();
    teamName.clear();
    humanName.clear();
    total.clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open txt"), "//", tr("txt files (*.html)"));
    QFile file(fileName);
    //QXmlStreamReader sr(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    code = file.readAll();
    file.close();
    std::regex regular("\\[<\\/span>([^\\]]*)\\]\\s([^\\s]*):?\\s([^,<]*),?\\s?([^,<]*)?,?\\s?([^,<]*)?");
    std::smatch result;

    std::regex reg("((<div class=\"table__data table__data_mood_pos\">)|(<div class=\"table__data\">)|(<div class=\"table__data table__data_mood_neg\">)|(class=\"table__cell table__cell_role_meta\" title=\"\\d*\">))([^<]+)");
    std::smatch res;

    temp = code.toStdString();
    std::string copy = code.toStdString();

    int num = 0;
    while(std::regex_search(temp, result, regular))
    {
        if(num > 1){
            univerName.push_back(result[1]);
            teamName.push_back(result[2]);
            std::string tmp = result[3];
            tmp+= ' ';
            tmp += result[4];
            tmp += ' ';
            tmp += result[5];
            tmp += ' ';
            humanName.push_back(tmp);
            int n = 0;
            while(std::regex_search(copy, res, reg) && n < 17)
            {
                std::string t;
                t += res[6];
                total.push_back(t);
                ++n;
                copy = res.suffix();
            }
        }
        ++num;
        temp = result.suffix();
    }
    QString team;
    for(size_t i = 0; i < univerName.size(); ++i){
        team += QString::number(i+1) + ' ' + QString::fromStdString(univerName[i]) + ' ' +
                QString::fromStdString(teamName[i]) + ' ' + QString::fromStdString(humanName[i]);
        for(size_t j = 17 * i; j < 17 * i + 17 && j < total.size(); ++j){
            team += QString::fromStdString(total[j]) + ' ';

        }
        team += '\n';
    }
    ui->textBrowser->setText(team);

    ui->tableWidget->setRowCount(univerName.size());
    for(size_t i = 0; i < univerName.size(); ++i){
        ui->tableWidget->verticalHeader()->resizeSection(i, 80);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(univerName[i]) + ' ' + QString::fromStdString(teamName[i]) + '\n' + QString::fromStdString(humanName[i])));
        for(size_t j = 17 * i; j < 17 * i + 17 && j < total.size(); ++j){
            ui->tableWidget->setItem(i, j % 17 + 1,new QTableWidgetItem(QString::fromStdString(total[j])));
        }

    }

    //on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
}




