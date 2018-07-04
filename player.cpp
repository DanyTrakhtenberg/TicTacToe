#include "player.h"
#include<QString>
#include<QDebug>
Player::Player(QObject *parent) : QObject(parent)
{

}
Player::Player(QString name, QString gameSymbol, int score, QLabel *labelScore):name(name),gameSymbol(gameSymbol),
  labelScore(labelScore),
  score(score),
  QObject(nullptr)
{

}

void Player::increaseScore()
{
    score++;
    labelScore->setText(QString::number(score));
}

Player::~Player()
{
qDebug()<<"Player "<<name.data()<<" destroyed"<<"\n";
}

