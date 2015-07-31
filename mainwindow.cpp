#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLoad_clicked()
{
    QFile loadFile(QStringLiteral("data/lights.json"));

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("cannot open file!");
    }
    else
    {
        qDebug() << "file opened.";
    }

    QByteArray loadData = loadFile.readAll();

    QJsonDocument jsonDoc(QJsonDocument::fromJson(loadData));
}
