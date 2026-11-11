#pragma once
#include "ChessBoard.h"
#include "Pieces.h"
#include <Windows.h>

class game
{
public:
    void setupPieces();
    void run();
    //adding switch to change between player 1 and two.
    void SwitchPlayer();

    int getCurrentPlayer()const;
    bool initializeMouse(HANDLE hInput);
    bool Turn();
    COORD getPieceSelected(HANDLE hInput);
    bool validatePlayer(int currentPlayer, COORD highlighted);
    //defenition in game loop, but will be defined bellow in line with my run and setup functions for orginization in one file
    //coordinate return type, handle is acting as the bounds to console and hInpute is what binds it to the console input stream
    //coord returns a pair of x,y together. since i developed my board using [x][y] for storing positions between my pieces it allows for easier plugging into my existing code
    COORD getClicks(HANDLE hInput);
    bool capture(COORD highlighted);
    bool testStaleMate(int currentPlayer);
    COORD getKingLocation(int player);
    bool testCheckSelf(int currentPlayer);
    bool testCheckmate(int currentPlayer);
    bool getMoves(int currentPlayer);
    void moveSimulation();
private:
    //starting player value
    int currentPlayer = 1;
    chessBoard board1;
    Pawn pl1p1;
    Pawn pl1p2;
    Pawn pl1p3;
    Pawn pl1p4;
    Pawn pl1p5;
    Pawn pl1p6;
    Pawn pl1p7;
    Pawn pl1p8;
    Pawn pl2p1;
    Pawn pl2p2;
    Pawn pl2p3;
    Pawn pl2p4;
    Pawn pl2p5;
    Pawn pl2p6;
    Pawn pl2p7;
    Pawn pl2p8;
    Rook p1r1;
    Rook p1r2;
    Rook p2r1;
    Rook p2r2;
    Knight p1kn1;
    Knight p1kn2;
    Knight p2kn1;
    Knight p2kn2;
    Bishop p1b1;
    Bishop p1b2;
    Bishop p2b1;
    Bishop p2b2;
    Queen p1q;
    Queen p2q;
    King p1k;
    King p2k;
};