#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool plusTrigger = false;
bool minTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i=0; i<10; i++){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }

    connect(ui->Plus, SIGNAL(released()), this,
        SLOT(MathButtonPressed()));
    connect(ui->Minus, SIGNAL(released()), this,
        SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this,
        SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this,
        SLOT(MathButtonPressed()));
    connect(ui->Equals, SIGNAL(released()), this,
        SLOT(EqualButtonPressed()));
    connect(ui->Clear, SIGNAL(released()), this,
            SLOT(Clear()));

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui ->Display->text();
    if((displayVal.toDouble() ==0) || (displayVal.toDouble() == 0.0)){
        ui->Display->setText(butVal);
    } else{
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}
void MainWindow::MathButtonPressed(){
    divTrigger=false;
    multTrigger=false;
    plusTrigger=false;
    minTrigger=false;
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive)==0){
        divTrigger=true;
    } else if(QString::compare(butVal, "*", Qt::CaseInsensitive)==0){
        multTrigger=true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive)==0){
        plusTrigger=true;
    } else{
        minTrigger=true;
    }
    ui->Display->setText("");
}

void MainWindow::ChangeNumberSign(){
    QString displayVal = ui ->Display->text();
    QRegularExpression reg("[-]?[0-9.]*");
    QRegularExpressionMatch match = reg.match(displayVal);
    if(match.hasMatch()) {
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign =-1 * dblDisplayVal;
        ui ->Display->setText(QString::number(dblDisplayValSign));
    }
}
void MainWindow::EqualButtonPressed(){
    double solution=0.0;
    QString displayVal = ui ->Display->text();
    double dblDisplayVal=displayVal.toDouble();
    if(plusTrigger || minTrigger || multTrigger || divTrigger){
        if(plusTrigger){
            solution= calcVal + dblDisplayVal;
        } else if(minTrigger){
            solution= calcVal - dblDisplayVal;
        } else if(multTrigger){
            solution= calcVal * dblDisplayVal;
        } else if(divTrigger){
            solution= calcVal / dblDisplayVal;
        }
    }
    ui->Display->setText(QString::number(solution));
}
void MainWindow::Clear(){
        double solution=0.0;
        QString displayVal = ui ->Display->text();
        ui->Display->setText(QString::number(solution));
    }
