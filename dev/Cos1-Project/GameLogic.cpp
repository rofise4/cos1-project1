#include "Game.h"
#include "ChessBoard.h"

void game::setupPieces()
{
    board1.placeP(&pl1p1, 0, 3);
    board1.placeP(&pl1p2, 1, 3);
    board1.placeP(&pl1p3, 2, 3);
    board1.placeP(&pl1p4, 3, 3);
    board1.placeP(&pl1p5, 4, 3);
    //board1.placeP(&pl1p6, 5, 6);
   // board1.placeP(&pl1p7, 6, 6);
  //  board1.placeP(&pl1p8, 7, 6);
    board1.placeP(&pl2p1, 0, 1);
    pl2p1.Isp2(true);
    board1.placeP(&pl2p2, 1, 1);
    pl2p2.Isp2(true);
    board1.placeP(&pl2p3, 2, 1);
    pl2p3.Isp2(true);
    board1.placeP(&pl2p4, 3, 1);
    pl2p4.Isp2(true);
    board1.placeP(&pl2p5, 4, 1);
    pl2p5.Isp2(true);
    //board1.placeP(&pl2p6, 5, 1);
    //pl2p6.Isp2(true);
    //board1.placeP(&pl2p7, 6, 1);
    //pl2p7.Isp2(true);
    //board1.placeP(&pl2p8, 7, 1);
    //pl2p8.Isp2(true);
    board1.placeP(&p1r1, 0, 4);
    // board1.placeP(&p1r2, 4, 4);
    board1.placeP(&p2r1, 0, 0);
    p2r1.Isp2(true);
    // board1.placeP(&p2r2, 4, 0);
     //p2r2.Isp2(true);
    board1.placeP(&p1kn1, 1, 4);
    //board1.placeP(&p1kn2, 3, 4);
    board1.placeP(&p2kn1, 1, 0);
    p2kn1.Isp2(true);
    //board1.placeP(&p2kn2, 3, 0);
    //p2kn2.Isp2(true);
    board1.placeP(&p1b1, 2, 4);
    //board1.placeP(&p1b2, 2, 4);
    board1.placeP(&p2b1, 2, 0);
    p2b1.Isp2(true);
    //board1.placeP(&p2b2, 5, 0);
    //p2b2.Isp2(true);
    board1.placeP(&p1q, 3, 4);
    board1.placeP(&p2q, 3, 0);
    p2q.Isp2(true);
    board1.placeP(&p1k, 4, 4);
    board1.placeP(&p2k, 4, 0);
    p2k.Isp2(true);
    pl1p1.draw();
    pl1p2.draw();
    pl1p3.draw();
    pl1p4.draw();
    pl1p5.draw();
    //  pl1p6.draw();
     // pl1p7.draw();
     // pl1p8.draw();
    pl2p1.draw();
    pl2p2.draw();
    pl2p3.draw();
    pl2p4.draw();
    pl2p5.draw();
    //  pl2p6.draw();
     // pl2p7.draw();
     // pl2p8.draw();
    p1r1.draw();
    // p1r2.draw();
    p2r1.draw();
    // p2r2.draw();
    p1b1.draw();
    // p1b2.draw();
    p2b1.draw();
    // p2b2.draw();
    p1kn1.draw();
    //p1kn2.draw();
    p2kn1.draw();
    //  p2kn2.draw();
    p1q.draw();
    p2q.draw();
    p1k.draw();
    p2k.draw();
}
void game::SwitchPlayer()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}
int game::getCurrentPlayer()const
{
    return currentPlayer;
}
bool game::validatePlayer(int currentPlayer, COORD highlighted)
{
    bool valid = false;
    Pieces* piece = board1.getPiece(highlighted.X, highlighted.Y);
    if (piece != nullptr)
    {
        if (piece->isP2())
        {
            if (currentPlayer == 2)
            {
                valid = true;
            }
            else
                //not nessasary because its initialized to false, but its easier to follow later
                valid = false;
        }
        else
        {
            if (currentPlayer == 1)
            {
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
    }
    return valid;
}
void game::capture(COORD highlighted)
{
    bool canMove = false;
    bool pass;
    COORD compare;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    while (canMove == false)
    {
        compare = game::getClicks(hInput);
        if (board1.getOccupied(compare.X, compare.Y) == true)
        {
            Pieces* piece = board1.getPiece(highlighted.X, highlighted.Y);
            board1.placeP(piece, compare.X, compare.Y);
            canMove = true;
        }
    }

}