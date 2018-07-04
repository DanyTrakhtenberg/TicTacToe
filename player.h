#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include<QString>
#include<QLabel>
//class Qstring;

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    QString name;
    QString gameSymbol;
    QLabel  *labelScore;
    int score;
    ~Player();

    Player(QString name, QString gameSymbol, int score,QLabel *labelScore);
    void increaseScore();
signals:

public slots:
};

#endif // PLAYER_H
