#include "Game.h"
#include "ChessBoard.h"
#include <vector>

void game::setupPieces()
{
    board1.placeP(&p1k, 0, 4);
    board1.placeP(&p2k, 4, 0);
    p2k.Isp2(true);

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
        else
        {
            return false;
        }
    }

}
COORD game::getKingLocation(int player)
{
    COORD King = { -1,-1 };


            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    Pieces* piece = board1.getPiece(i, j);
                    if (piece == &p1k && player == 1 || piece == &p2k && player == 2)
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
        COORD ownKing = getKingLocation(1);
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
        COORD ownKing = getKingLocation(2);
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
bool game::getMoves(int currentPlayer)
{
    bool clear = false;
    if (currentPlayer == 1)
    {

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

                        continue;
                    }
                    else
                    {
                        board1.resetOccupied();
                        //mark available moves
                        piece->getmovesp1(board1, 1);

                        //copy moves coords to seperate list
                        std::vector<COORD> toTest;
                        //cycle through moves and cross off list after testing self check
                        //move to next piece
                        for (SHORT x = 0; x < 5; x++)
                        {
                            //looping through x and y coordinates on grid
                            for (SHORT y = 0; y < 5; y++)
                            {
                                //testing coordinate to see if it is one of the highlighted available moves
                                if (board1.getOccupied(x, y))
                                {
                                    //save the coordinates and add to vector to cycle through with tests
                                    COORD test = { x,y };
                                    toTest.push_back(test);
                                }
                                else
                                    continue;
                            }
                        }
                        for (COORD test : toTest)
                        {
                            //save the pieces that simulate capture
                            Pieces* removed = board1.getPiece(test.X, test.Y);
                            //make the move temporarily
                            board1.placeP(piece, test.X, test.Y);
                            //check to see if the move solved check and king is safe
                            clear = testCheckSelf(currentPlayer);
                            //return piece moved
                            board1.placeP(piece, i, j);
                            //return captured piece if one excisted
                            if (removed != nullptr)
                            {
                                board1.placeP(removed, test.X, test.Y);
                            }
                            //test if we cleared check before moving to next piece
                            if (clear == true)
                            {
                                return true;
                            }
                        }


                    }
                }
            }
        }
        return false;
    }
    else
    {

        for (int i = 0; i < 5; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                //loop through all pieces, check if null first
                Pieces* piece = board1.getPiece(i, j);
                if (piece != nullptr)
                {
                    //if enemy piece
                    if (!piece->isP2())
                    {

                        continue;
                    }
                    else
                    {
                        board1.resetOccupied();
                        //mark available moves
                        piece->getmovesp1(board1, 2);

                        //copy moves coords to seperate list
                        std::vector<COORD> toTest;
                        //cycle through moves and cross off list after testing self check
                        //move to next piece
                        for (SHORT x = 0; x < 5; x++)
                        {
                            //looping through x and y coordinates on grid
                            for (SHORT y = 0; y < 5; y++)
                            {
                                //testing coordinate to see if it is one of the highlighted available moves
                                if (board1.getOccupied(x, y))
                                {
                                    //save the coordinates and add to vector to cycle through with tests
                                    COORD test = { x,y };
                                    toTest.push_back(test);
                                }
                                else
                                    continue;
                            }
                        }
                        for (COORD test : toTest)
                        {
                            //save the pieces that simulate capture
                            Pieces* removed = board1.getPiece(test.X, test.Y);
                            //make the move temporarily
                            board1.placeP(piece, test.X, test.Y);
                            //check to see if the move solved check and king is safe
                            clear = testCheckSelf(currentPlayer);
                            //return piece moved
                            board1.placeP(piece, i, j);
                            //return captured piece if one excisted
                            if (removed != nullptr)
                            {
                                board1.placeP(removed, test.X, test.Y);
                            }
                            //test if we cleared check before moving to next piece
                            if (clear == true)
                            {
                                return true;
                            }
                        }


                    }
                }
            }
        }
        return false;
    }
}

bool game::testCheckmate(int currentPlayer)
{
    //are you in check and have no available moves
    if (testCheckSelf(currentPlayer) == false)
    {
        if (getMoves(currentPlayer) == false)
        {
            return true;
        }
    }
    else
        return false;
}
bool game::testStaleMate(int currentPlayer)
{
    if (testCheckSelf(currentPlayer) == true)
    {
        if (getMoves(currentPlayer) == false)
        {
            return true;
        }
    }
    else
        return false;
}
void game::placeDraftPiece(Pieces* piece)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    COORD selected;
    Drafting drafting;
    bool valid = false;
    bool p1safe = false;
    bool p2safe = false;
    while (valid == false)
    {
        //checks for input within the console
        selected = getClicks(hInput);
        if (selected.X >= 0 && selected.X < 5 && selected.Y >= 0 && selected.Y < 5)
        {
            //makes sure square is empty
            if (board1.getPiece(selected.X, selected.Y) == nullptr)
            {
                //places piece then tests for any check situations created by it
                board1.placeP(piece, selected.X, selected.Y);
                p1safe = testCheckSelf(1);
                p2safe = testCheckSelf(2);
                if (p1safe && p2safe)
                {
                    valid = true;
                }
                else
                {
                    drafting.resetConsole();
                    setPosition(0, 22);
                    std::cout << "That move is invalid because it places a king in check ";
                }
            }
            else
            {
                drafting.resetConsole();
                setPosition(0, 22);
                std::cout << "That move is invalid because the square is already occupied ";
            }
        }
    }
}
Pieces* game::createPieces(int pieceID, int currentPlayer)
{
    //take id from drafting vector and create a new piece
    Pieces* piece = nullptr;
    if (pieceID == 1)
    {
        piece = new Pawn();
    }
    else if (pieceID == 2)
    {
        piece = new Knight();
    }
    else if (pieceID == 3)
    {
        piece = new Bishop();
    }
    else if (pieceID == 4)
    {
        piece = new Rook();
    }
    else if (pieceID == 5)
    {
        piece = new Queen();
    }
    if (piece != nullptr)
    {
        //if its player 2 mark it
        if (currentPlayer == 2)
        {
            piece->Isp2(true);
        }
        //add it to created pieces vector so it can be deleted later
        createdPieces.push_back(piece);
    }

    return piece;
}
//free up memory
void game::deleteCreatedPieces()
{
    for (Pieces* piece : createdPieces)
    {
        delete piece;
    }
    createdPieces.clear();
}