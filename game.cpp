#include "game.h"
#include<vector>
#include<QPushButton>
#include"utlls.h"
#include<QDebug>
#include<vector>
#include<QPushButton>
#include<map>
#include<QThread>
Game::Game( QObject *parent )
    : QObject(parent)
{

}

void Game::SetSymbolAndCheckWinning(int x , int y)
{
    std::map<utills::enumXor0,QString> mapXor0ToString;
    mapXor0ToString[utills::X]="X";
    mapXor0ToString[utills::O]="0";
    auto xVector = ptrGame2Dvec->at(x);
    auto pushButton = xVector.at(y);
    if (pushButton->text()!= "") {
        return;
    }
    numberOfSpacesNotAvalible++;
    pushButton->setText(mapXor0ToString[enumXor0]);
    utills::enumRetFromChrckWinFunc enumHoWon = CheckHowWonTheGame();
    if(enumHoWon == utills::Player1Win)
    {
        numberOfSpacesNotAvalible=0;
        player1->increaseScore();
        enumXor0 = utills::X;
        setAllBlank();
    }
    else if(enumHoWon == utills::Player2Win)
    {
        numberOfSpacesNotAvalible=0;
        player2->increaseScore();
        enumXor0 = utills::X;
        setAllBlank();
    }
    else if (numberOfSpacesNotAvalible >= TotalnumberOfSpaces) {
        numberOfSpacesNotAvalible=0;
        labelTie->setText("Tie");
     //   QThread::sleep(10);
      //  labelTie->setText("");
        setAllBlank();
        enumXor0 = utills::X;
    }
    else
    {
        if (enumXor0 == utills::X) {
            enumXor0 = utills::O;
        }
        else {
            enumXor0 = utills::X;
        }
    }
}

utills::enumRetFromChrckWinFunc Game::checkWiningDiagonal()
{
    utills::enumRetFromChrckWinFunc retWiningResuly = utills::NoOnwWon;
    int xCounter = 0;
    int oCouner  = 0;
    int rowCount;
    int colCount;
    for( rowCount = 0 , colCount = 0 ; rowCount < utills::sizeOfRow ; rowCount++,colCount++)
    {
          retWiningResuly = checkHowWonTheGameInsideLoop(rowCount,colCount,xCounter,oCouner);
          if (retWiningResuly!=utills::NoOnwWon)
          {
              return retWiningResuly;
          }
    }
    xCounter = 0;
    oCouner  = 0;
    for( rowCount = 0 , colCount = utills::sizeOfColumn-1 ; rowCount < utills::sizeOfRow ; rowCount++,colCount--)
    {
        retWiningResuly = checkHowWonTheGameInsideLoop(rowCount,colCount,xCounter,oCouner);
        if (retWiningResuly!=utills::NoOnwWon)
        {
            return retWiningResuly;
        }
    }


    return retWiningResuly;
}


utills::enumRetFromChrckWinFunc Game::checkHowWonTheGameInsideLoop(int rowCount, int colCount, int &xCounter, int &oCounter)
{

    auto x = ptrGame2Dvec->at(rowCount);
    auto y = x.at(colCount);
    if(y->text() == "X")
    {
        xCounter++;
        if(xCounter >= utills::sizeOfRow)
        {
            if(player1->gameSymbol == "X")
            {
                return utills::Player1Win;
            }
            else
            {
                return utills::Player2Win;
            }
        }
    }
    else if((y->text() == "0"))
    {
        oCounter++;
        if(oCounter >= utills::sizeOfRow)
        {

            if(player1->gameSymbol == "0")
            {
                return utills::Player1Win;
            }
            else
            {
                return utills::Player2Win;
            }
        }
    }
    return utills::NoOnwWon;
}


utills::enumRetFromChrckWinFunc Game::CheckHowWonTheGame()
{
    utills::enumRetFromChrckWinFunc enumRetResult = utills::NoOnwWon ;
    enumRetResult = checkWiningForRow();
    if (enumRetResult != utills::NoOnwWon)
    {
        return enumRetResult;
    }
    enumRetResult = checkWiningForColumn();
    if(enumRetResult != utills::NoOnwWon)
    {
        return enumRetResult;
    }

    enumRetResult = checkWiningDiagonal();
    if(enumRetResult != utills::NoOnwWon)
    {
        return enumRetResult;
    }

    return enumRetResult;
}

utills::enumRetFromChrckWinFunc Game::checkWiningForColumn()
{
    utills::enumRetFromChrckWinFunc retWiningResuly = utills::NoOnwWon;
    int xCounter = 0;
    int oCouner  = 0;
    for(int colCount =  0; colCount < utills::sizeOfColumn ; colCount++ )
    {
        xCounter = 0;
        oCouner  = 0;
        for(int rowCount = 0 ; rowCount < utills::sizeOfRow ; rowCount++)
        {
            retWiningResuly = checkHowWonTheGameInsideLoop(rowCount,colCount,xCounter,oCouner);
            if (retWiningResuly != utills::NoOnwWon) {
                return retWiningResuly;
            }
        }

    }
    return retWiningResuly;

}


utills::enumRetFromChrckWinFunc Game::checkWiningForRow()
{
    int xCounter = 0;
    int oCouner  = 0;
    for(auto row:*ptrGame2Dvec)
    {
        xCounter = 0;
        oCouner  = 0;
        for(QPushButton* col:row)
        {
            if(col->text() == "X")
            {
                xCounter++;
                if(xCounter >= utills::sizeOfRow)
                {
                    if(player1->gameSymbol == "X")
                    {
                        return utills::Player1Win;
                    }
                    else
                    {
                        return utills::Player2Win;
                    }
                }
            }
            else if(col->text() == "0")
            {
                oCouner++;
                if(oCouner >= utills::sizeOfRow)
                {
                    if(player1->gameSymbol == "0")
                    {
                        return utills::Player1Win;
                    }
                    else
                    {
                        return utills::Player2Win;
                    }
                }
            }
        }
    }
    return utills::NoOnwWon;
}


void Game::SetGamePtr(std::vector<std::vector<QPushButton *> > &ptr2Dvec2 )
{
    ptrGame2Dvec = &ptr2Dvec2;
}
void Game::setAllBlank()
{
    for(auto row:*ptrGame2Dvec)
    {
        for(auto elmInRow: row)
        {
            elmInRow->setText("");
        }
    }
}

Game::~Game()
{
    qDebug()<<"Game  destroyed"<<"\n";
}

