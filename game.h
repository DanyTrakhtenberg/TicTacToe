#ifndef GAME_H
#define GAME_H

#include <QObject>
#include<QPushButton>
#include "player.h"
#include "utlls.h"
#include<memory>
class memory;
class vector;

//#include <memory>
//#include <vector>



class Game : public QObject
{
    Q_OBJECT
    utills::enumRetFromChrckWinFunc checkWiningForRow();
    utills::enumRetFromChrckWinFunc checkWiningForColumn();
    utills::enumRetFromChrckWinFunc checkWiningDiagonal();
    utills::enumRetFromChrckWinFunc checkHowWonTheGameInsideLoop(int rowCount, int colCount, int &xCounter, int &oCounter);
    int TotalnumberOfSpaces = utills::sizeOfColumn*utills::sizeOfRow;
    int numberOfSpacesNotAvalible = 0;
public:
    QLabel *labelTie;
    explicit Game(QObject *parent = 0);
    void SetGamePtr(std::vector<std::vector<QPushButton *> > &ptr2Dvec2);
    std::vector<std::vector<QPushButton*>> *ptrGame2Dvec;
    void setAllBlank();
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    utills::enumXor0 enumXor0 = utills::X;
    ~Game();

    utills::enumRetFromChrckWinFunc CheckHowWonTheGame();
    void SetSymbolAndCheckWinning(int x, int y);
};

#endif // GAME_H
