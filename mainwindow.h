#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>
#include <QPushButton>
#include <memory>
class Game;
namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
 std::vector<std::vector<QPushButton*> > vectorPushButton2DTicTac;
 std::vector<QPushButton*> vectorPushButton2DTicTacFirsRow;
 std::vector<QPushButton*> vectorPushButton2DTicTacSecondRow;
 std::vector<QPushButton*> vectorPushButton2DTicTacTherdRow;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
 void on_pushButtonTicPlac0_0_clicked();

 void on_pushButtonTicPlac0_1_clicked();

 void on_pushButtonTicPlac0_2_clicked();

 void on_pushButtonTicPlac1_0_clicked();

 void on_pushButtonTicPlac1_1_clicked();

 void on_pushButtonTicPlac1_2_clicked();

 void on_pushButtonTicPlac2_0_clicked();

 void on_pushButtonTicPlac2_1_clicked();

 void on_pushButtonTicPlac2_2_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Game> gameptr;
    void init();
    void setLabels(std::shared_ptr<Game> game);
    void checkPutPtr(std::vector<std::vector<QPushButton *> > &ptr2Dvec);
    void checkWhoWonAndSetLabelAndScore();
};

#endif // MAINWINDOW_H
