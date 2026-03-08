#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtimer.h"

short player1Time,player2Time,currentPlayer,gameTime;
QTimer *pQTimer;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);
    ui->setupUi(this);
    setGameInfoText("select game lenght", 20);
    ui->P1TimerProgress->setValue(0);
    ui->P2TimerProgress->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if(currentPlayer == 1){
        player1Time--;
    }
    else if (currentPlayer == 2){
        player2Time--;
    }
    updateProgressBar();
    if (player1Time <= 0)
    {
        winGame(2);
    }
    else if (player2Time <= 0) winGame(1);

}
void MainWindow::winGame(short player)
{
    pQTimer->stop();
    ui->P1Label->setText("");
    ui->P2Label->setText("");
    if (player == 1){
        setGameInfoText("Player 1 Won!", 30);
    }
    else {
        setGameInfoText("Player 2 Won!", 30);
    }

}
void MainWindow::updateProgressBar()
{
    ui->P1TimerProgress->setRange(0,gameTime);
    ui->P2TimerProgress->setRange(0,gameTime);
    ui->P1TimerProgress->setValue(player1Time);
    ui->P2TimerProgress->setValue(player2Time);
    ui->P1Label->setText(QString::number(player1Time / 100));
    ui->P2Label->setText(QString::number(player2Time / 100));
}

void MainWindow::setGameInfoText(QString s, short x)
{
    ui->P2Label->setText(s);
    QFont font = ui->P2Label->font();
    font.setPointSize(x);
    ui->P2Label->setFont(font);
}

void MainWindow::on_Nappi1_clicked()
{
    currentPlayer = 1;
}


void MainWindow::on_Nappi2_clicked()
{
    currentPlayer = 2;
}


void MainWindow::on_Timer1_clicked()
{
    gameTime = 12000;
    setGameInfoText("Ready to play 2 min game", 20);
}


void MainWindow::on_Timer2_clicked()
{
    gameTime = 30000;
    setGameInfoText("Ready to play 5 min game", 20);
}


void MainWindow::on_Aloitus_clicked()
{
    player1Time = gameTime;
    player2Time = gameTime;
    currentPlayer = 1;
    ui->P2Label->setText("Game Started");
    pQTimer->start(10);
}


void MainWindow::on_Lopetus_clicked()
{
    winGame(currentPlayer);
}
