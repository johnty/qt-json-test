#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void read(QJsonDocument doc);

private slots:
    void on_pushButtonLoad_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
