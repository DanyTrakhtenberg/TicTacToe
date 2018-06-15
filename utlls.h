#ifndef UTLLS_H
#define UTLLS_H
namespace utills {

const int sizeOfRow = 3;
const int sizeOfColumn = 3;
enum enumRetFromChrckWinFunc{
    Player1Win,
    Player2Win,
    NoOnwWon
};


enum enumXor0{
    X,
    O
};

}
class Utlls
{
public:
    Utlls();
    ~Utlls();
    enum enumRetFromChrckWinFunc{
        Player1Win,
        Player2Win,
        NoOnwWon
    };
};

#endif // UTLLS_H

