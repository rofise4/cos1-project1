#pragma once
#include "ChessBoard.h"
#include "Pieces.h"
#include <Windows.h>
#include "Drafting.h"

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
    void placeDraftPiece(Pieces* piece);
    Pieces* createPieces(int pieceID, int currentPlayer);
    void deleteCreatedPieces();
    void placePieces(Drafting& drafting);
private:
    //starting player value
    int currentPlayer = 1;
    chessBoard board1;
    std::vector<Pieces*> createdPieces;
    King p1k;
    King p2k;
};