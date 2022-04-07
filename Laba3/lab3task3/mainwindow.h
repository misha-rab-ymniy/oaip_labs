#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double value(const QChar& c);
    bool check(const QString& str);
    int isBktNormal(const QString& s);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_changeButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> v;
    int row = 0;
};
#endif // MAINWINDOW_H
