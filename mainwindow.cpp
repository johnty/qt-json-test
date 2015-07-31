#include "mainwindow.h"
#include "ui_mainwindow.h"


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

    qDebug() << " is object = " << jsonDoc.isObject() << "   is array = " << jsonDoc.isArray();

    if (jsonDoc.isObject()) {
        myLight.read(jsonDoc.object());
        myLight.print();
    }
}

void MainWindow::read(QJsonDocument doc)
{

}
