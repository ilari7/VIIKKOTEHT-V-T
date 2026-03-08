#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateProgressBar();
    void timeout();
    void winGame(short);
    void setGameInfoText(QString, short);

private slots:
    void on_Nappi1_clicked();

    void on_Nappi2_clicked();

    void on_Timer1_clicked();

    void on_Timer2_clicked();

    void on_Aloitus_clicked();

    void on_Lopetus_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
