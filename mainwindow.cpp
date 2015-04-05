#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
ui->MyLabel->setText("My first programm");
QObject::connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(MyEventHandler()));
QObject::connect(this, SIGNAL(MySignal(QString)), ui->pushButton_2, SLOT(setText(QString)));
QObject::connect(this, SIGNAL(MySignal(QString)), ui->MyLabel, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::MyEventHandler()
{
  
    emit MySignal(ui->pushButton_1->text());

}
