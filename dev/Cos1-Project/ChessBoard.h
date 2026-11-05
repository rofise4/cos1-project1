#pragma once
#include "Pieces.h"


class chessBoard
{
public:
    chessBoard();

    //initialize is just creating board and not populating yet and assigning colors to squares
    void Initialize();

    bool Empty(int x, int y);

    Pieces* getPiece(int x, int y);

    bool getOccupied(int x, int y);

    void DrawBoard();

    void placeP(Pieces* piece, int newx, int newy);

    void setOccupied(int newx, int newy, bool selected);

    void resetOccupied();
private:
    bool occupied[5][5];
    Pieces* squares[5][5];
    int coordinatey[5];
    int coordinatex[5];
};