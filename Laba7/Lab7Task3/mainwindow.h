#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bitset.h"
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
    void on_all_clicked();

    void on_any_clicked();

    void on_count_clicked();

    void on_flip_clicked();

    void on_none_clicked();

    void on_reset_clicked();

    void on_set_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_setIndex_clicked();

    void on_flipIndex_2_clicked();

    void on_resetIndex_clicked();

    void on_testIndex_clicked();

private:
    bitset<32> bs;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
