#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

double Numero = 0.0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->Display->setText(QString::number(Numero));
    QPushButton *numButton;
        QString butName = "Button";
        numButton = MainWindow::findChild<QPushButton *>(butName);
        connect(numButton, SIGNAL(released()), this,
                SLOT(PlusOne()));
        connect(ui->Clear, SIGNAL(released()), this,
                SLOT(Clear()));

    }

    MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::PlusOne(){
    Numero ++;
    QString displayVal = ui ->Display->text();
    ui->Display->setText(QString::number(Numero));



}

void MainWindow::Clear(){

       QString displayVal = ui ->Display->text();
       ui->Display->setText(QString::number(0));
}
