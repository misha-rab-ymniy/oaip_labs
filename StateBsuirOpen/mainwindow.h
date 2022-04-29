#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_openButton_clicked();

private:
    Ui::MainWindow *ui;
    QString code;
    std::string temp;
    std::vector<std::string> univerName;
    std::vector<std::string> teamName;
    std::vector<std::string> humanName;
    std::vector<std::string> total;
};
#endif // MAINWINDOW_H
