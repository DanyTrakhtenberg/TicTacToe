#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<vector>
#include<QDebug>
#include <memory>
#include "game.h"
//#include "democlass.h"
#include "player.h"
#include "utlls.h"


using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    gameptr =std::make_shared<Game>();
    gameptr->SetGamePtr(vectorPushButton2DTicTac);
    gameptr->labelTie = ui->labelTie;
    gameptr->player1 = make_shared<Player>("Dany","X",0,ui->labelPlayer1Score);
    gameptr->player2 = make_shared<Player>("Oscar","0",0,ui->labelPlayer2Score);
    setLabels(gameptr);


}

void MainWindow::setLabels(shared_ptr<Game> game)
{
    ui->labelPlayer1Name->setText("Name:"+game->player1->name);
    ui->labelPlayer2Name->setText("Name:"+game->player2->name);
    ui->labelPlayer1Score->setText("Score:"+QString::number(game->player1->score));
    ui->labelPlayer2Score->setText("Score:"+QString::number(game->player2->score));
}

void MainWindow::checkPutPtr(std::vector<std::vector<QPushButton *> > &ptr2Dvec)
{
    ptr2Dvec[0][0]->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init()
{

    vectorPushButton2DTicTacFirsRow.push_back(ui->pushButtonTicPlac0_0);
    vectorPushButton2DTicTacFirsRow.push_back(ui->pushButtonTicPlac0_1);
    vectorPushButton2DTicTacFirsRow.push_back(ui->pushButtonTicPlac0_2);
    vectorPushButton2DTicTac.push_back(vectorPushButton2DTicTacFirsRow);
    vectorPushButton2DTicTacSecondRow.push_back(ui->pushButtonTicPlac1_0);
    vectorPushButton2DTicTacSecondRow.push_back(ui->pushButtonTicPlac1_1);
    vectorPushButton2DTicTacSecondRow.push_back(ui->pushButtonTicPlac1_2);
    vectorPushButton2DTicTac.push_back(vectorPushButton2DTicTacSecondRow);
    vectorPushButton2DTicTacTherdRow.push_back(ui->pushButtonTicPlac2_0);
    vectorPushButton2DTicTacTherdRow.push_back(ui->pushButtonTicPlac2_1);
    vectorPushButton2DTicTacTherdRow.push_back(ui->pushButtonTicPlac2_2);
    vectorPushButton2DTicTac.push_back(vectorPushButton2DTicTacTherdRow);


}

void MainWindow::checkWhoWonAndSetLabelAndScore()
{

}

void MainWindow::on_pushButtonTicPlac0_0_clicked()
{
gameptr->SetSymbolAndCheckWinning(0,0);
}

void MainWindow::on_pushButtonTicPlac0_1_clicked()
{
gameptr->SetSymbolAndCheckWinning(0,1);
}

void MainWindow::on_pushButtonTicPlac0_2_clicked()
{
gameptr->SetSymbolAndCheckWinning(0,2);
}

void MainWindow::on_pushButtonTicPlac1_0_clicked()
{
gameptr->SetSymbolAndCheckWinning(1,0);
}

void MainWindow::on_pushButtonTicPlac1_1_clicked()
{
gameptr->SetSymbolAndCheckWinning(1,1);
}

void MainWindow::on_pushButtonTicPlac1_2_clicked()
{
gameptr->SetSymbolAndCheckWinning(1,2);
}

void MainWindow::on_pushButtonTicPlac2_0_clicked()
{
gameptr->SetSymbolAndCheckWinning(2,0);
}

void MainWindow::on_pushButtonTicPlac2_1_clicked()
{
gameptr->SetSymbolAndCheckWinning(2,1);
}

void MainWindow::on_pushButtonTicPlac2_2_clicked()
{
gameptr->SetSymbolAndCheckWinning(2,2);
}
