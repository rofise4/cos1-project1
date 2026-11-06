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
    Pieces* piece = board1.getPiece(0, 0);
    setPosition(1, 21);
    if (piece == &p2r1)
    {
        std::cout << "The rook is here just not drawn";
    }
    else
        std::cout << "Huston we have another problem";
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
    //pl1p1.draw();
    //pl1p2.draw();
    //pl1p3.draw();
    //pl1p4.draw();
    //pl1p5.draw();
    //  pl1p6.draw();
     // pl1p7.draw();
     // pl1p8.draw();
    //pl2p1.draw();
    //pl2p2.draw();
    //pl2p3.draw();
    //pl2p4.draw();
    //pl2p5.draw();
    //  pl2p6.draw();
     // pl2p7.draw();
     // pl2p8.draw();
    //p1r1.draw();
    //Pieces* piece2 = board1.getPiece(0, 0);
    //setPosition(1, 24);
    //if (piece2 == &p2r1)
    //{
    //    std::cout << "The rook is here just not drawn";
    //}
    //else
     //   std::cout << "Huston we have another problem";
    // p1r2.draw();
    //p2r1.draw();
    // p2r2.draw();
    //p1b1.draw();
    // p1b2.draw();
    //p2b1.draw();
    // p2b2.draw();
    //p1kn1.draw();
    //p1kn2.draw();
    //p2kn1.draw();
    //  p2kn2.draw();
    //p1q.draw();
    //p2q.draw();
    //p1k.draw();
    //p2k.draw();

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
//making this a boolean to see if the move is safe
//if will expose own king fails, then will use the result in the turn loop to send you back to selecting a piece
bool game::capture(COORD highlighted)
{
    bool canMove = false;
    bool pass;
    bool safeFromSelfCheck = false;
    bool needPieceBackup = false;
    COORD compare;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    while (canMove == false)
    {
        compare = game::getClicks(hInput);
        //this makes sure that the new location is already marked as a legal move
        if (board1.getOccupied(compare.X, compare.Y) == true)
        {
            //checking for nullptr at new potential location
            if (board1.getPiece(compare.X, compare.Y) != nullptr)
            {
                //saving old piece, so if reset is needed can place back to original location
                //second thought cant access saved piece in this, I could however maybe use a variable then save outside of function
                needPieceBackup = true;
            }
            //run the move
            if (needPieceBackup == true)
            {
                //now saving old piece in same section if the new location is not nullptr
                //requires writing this twice
                Pieces* toBeCaptured = board1.getPiece(compare.X, compare.Y);
                Pieces* piece = board1.getPiece(highlighted.X, highlighted.Y);
                board1.placeP(piece, compare.X, compare.Y);
                //check that its safe
                safeFromSelfCheck = testCheckSelf(getCurrentPlayer());
                if (safeFromSelfCheck == true)
                {
                    return true;
                    canMove = true;
                }
                else
                {
                    //if move is not safe
                    board1.placeP(piece, highlighted.X, highlighted.Y);
                    board1.placeP(toBeCaptured, compare.X, compare.Y);
                    return false;
                }
            }
            else
            {
                //now saving old piece in same section if the new location is not nullptr
//requires writing this twice
                Pieces* piece = board1.getPiece(highlighted.X, highlighted.Y);
                board1.placeP(piece, compare.X, compare.Y);
                //check that its safe
                safeFromSelfCheck = testCheckSelf(getCurrentPlayer());
                if (safeFromSelfCheck == true)
                {
                    return true;
                    canMove = true;
                }
                else
                {
                    //if move is not safe
                    board1.placeP(piece, highlighted.X, highlighted.Y);
                    return false;
                }
            }
        }
    }

}
COORD game::getP1KingLocation()
{
    COORD King = { -1,-1 };


            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    Pieces* piece = board1.getPiece(i, j);
                    if (piece == &p1k)
                    {
                        King.X = i;
                        King.Y = j;
                        return King;
                    }
                }
            }

    return King;
}
COORD game::getP2KingLocation()
{
    COORD King = { -1, -1 };


    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Pieces* piece = board1.getPiece(i, j);
            if (piece == &p2k)
            {
                King.X = i;
                King.Y = j;
                return King;
            }
        }
    }

    return King;
}
bool game::testCheckSelf(int currentPlayer)
{
    
    board1.resetOccupied();
    /*writing this in advance, idea is basically allow temporary move in my move function
    next loop through all enemy pieces, get available moves and compare to self king coordinates
    if any available moves from the opponent would touch your kings coordinates after the planned move
    reject it and reset to force you reselct.
    
    MAJOR NOTE TO SELF FOR ADDING THIS INTO TURN------
    REESSSSEEETTTT TEST MOVE BOTH PASS AND FAIL, DO NOT ALLOW TO THROUGH OFF MATH BEING PERFORMED 
    I WILL BE DISAPOINTED IN FUTURE YOU*/
    
    //to get functional im writing this twice for either player rather then making 1 function thats more complicated. revise later as needed
    if (currentPlayer == 1)
    {
        COORD ownKing = getP1KingLocation();
        //get coordinates for player 1 king
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                //loop through all pieces, check if null first
                Pieces* piece = board1.getPiece(i, j);
                if (piece != nullptr)
                {
                    //if enemy piece
                    if (piece->isP2())
                    {
                        //mark available moves
                        piece->getmovesp1(board1, 2);
                    }
                }
            }
        }
        //once all available opponent moves are marked, compare with kings coordinance
        if (board1.getOccupied(ownKing.X, ownKing.Y))
        {
            board1.resetOccupied();
            return false;
        }
        else
        {
            board1.resetOccupied();
            return true;
        }
    }
    else
    {
        COORD ownKing = getP2KingLocation();
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                Pieces* piece = board1.getPiece(i, j);
                if (piece != nullptr)
                {
                    if (!piece->isP2())
                    {
                        piece->getmovesp1(board1, 1);
                    }
                }
            }
        }
        if (board1.getOccupied(ownKing.X, ownKing.Y))
        {
            board1.resetOccupied();
            return false;
        }
        else
        {
            board1.resetOccupied();
            return true;
        }
    }
}