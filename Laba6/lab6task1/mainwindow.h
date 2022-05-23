#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"

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

    void on_delet_clicked();

    void on_search_clicked();

    void on_postOrder_clicked();

    void on_preorder_clicked();

    void on_inorder_clicked();

    void on_insert_clicked();

    void on_heightCalc_clicked();

private:
    Ui::MainWindow *ui;
    tree tree;
};
#endif // MAINWINDOW_H
