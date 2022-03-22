#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ass.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_openButton_clicked();

    void on_showAll_clicked();

    void on_saveButton_clicked();

    void on_sortButton_clicked();

    void on_delButton_clicked();

private:
    Ui::MainWindow *ui;
    Ass* ass = new Ass;
};
#endif // MAINWINDOW_H
