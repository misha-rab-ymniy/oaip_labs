#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"

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

    void on_topButton_clicked();

    void on_popButton_clicked();

    void on_allQueueButton_clicked();

    void on_findButton_clicked();

private:
    Ui::MainWindow *ui;
    queue<int> Queue;
};
#endif // MAINWINDOW_H
