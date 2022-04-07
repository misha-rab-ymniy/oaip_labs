#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include <QVector>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int isBktNormal(const QString& s);

private slots:
    void on_checkButton_clicked();

    void on_openButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
