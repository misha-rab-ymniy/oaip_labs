#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <businf.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMainWindow>

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
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_showAllButton_clicked();

    void on_showButton_clicked();

    void on_saveFileButton_clicked();

    void on_openFileButton_clicked();
    void on_changeButton_clicked();

private:
    Ui::MainWindow *ui;
    List BusesPark;
    List BusesWay;
};
#endif // MAINWINDOW_H
