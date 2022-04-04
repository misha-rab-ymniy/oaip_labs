#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Pointers.h"
#include "stack.h"
#include "weakstruct.h"

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

    void on_push_clicked();

    void on_show_clicked();

    void on_stackDelete_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Stack st;
};
#endif // MAINWINDOW_H
