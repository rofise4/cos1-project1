#include "Pieces.h"
#include "Chess.h"
#include "ConsoleGraphics.h"
#include <iostream>

void Pawn::getmovesp1(chessBoard& board1, int currentPlayer)
{
    int x = GetX();
    int y = GetY();
    //move testing, taking x and y coordinates
    //checking at coordinates +/- from x and y to test the different directions



    //if unocupied, highlight it, also checking within board bounds.
    if (currentPlayer == 1)
    {
        if (y - 1 > -1)
        {
            Pieces* front = board1.getPiece(x, y - 1);
            if (front == nullptr)
            {
                board1.setOccupied(x, y - 1, true);
                //highlight square
            }
        }
        if (x - 1 > -1 && y - 1 > -1)
        {
            Pieces* dLeft = board1.getPiece(x - 1, y - 1);
            if (dLeft != nullptr)
            {
                if (dLeft->isP2())
                {
                    board1.setOccupied(x - 1, y - 1, true);
                    //highlight square
                }
            }
        }
        if (y - 1 > -1 && x + 1 < 5)
        {
            Pieces* dRight = board1.getPiece(x + 1, y - 1);
            if (dRight != nullptr)
            {
                //check isp2
                if (dRight->isP2())
                {
                    board1.setOccupied(x + 1, y - 1, true);
                    //highlight square
                }
            }
        }
    }
    else if (currentPlayer == 2)
    {
        if (y + 1 < 5)
        {
            Pieces* front = board1.getPiece(x, y + 1);
            if (front == nullptr)
            {
                board1.setOccupied(x, y + 1, true);
                //highlight square
            }
        }
        if (x - 1 > -1 && y + 1 < 5)
        {
            Pieces* dLeft = board1.getPiece(x - 1, y + 1);
            if (dLeft != nullptr)
            {
                if (!dLeft->isP2())
                {
                    board1.setOccupied(x - 1, y + 1, true);
                    //highlight square
                }
            }
        }
        if (y + 1 < 5 && x + 1 < 5)
        {
            Pieces* dRight = board1.getPiece(x + 1, y + 1);
            if (dRight != nullptr)
            {
                //check isp2
                if (!dRight->isP2())
                {
                    board1.setOccupied(x + 1, y + 1, true);
                    //highlight square
                }
            }
        }
    }
}
void Rook::getmovesp1(chessBoard& board1, int currentPlayer)
{
    int x = GetX();
    int y = GetY();
    for (int fy = y - 1; fy > -1; fy--)
    {
        Pieces* front = board1.getPiece(x, fy);
        if (front == nullptr)
        {
            board1.setOccupied(x, fy, true);
        }
        else if (front != nullptr)
        {
            if (front->isP2() && currentPlayer == 1)
            {
                board1.setOccupied(x, fy, true);
                break;
            }
            else if (!front->isP2() && currentPlayer == 2)
            {
                board1.setOccupied(x, fy, true);
                break;
            }
            else
                break;
        }
    }
    for (int lx = x - 1; lx > -1; lx--)
    {
        Pieces* dLeft = board1.getPiece(lx, y);
        if (dLeft == nullptr)
        {
            board1.setOccupied(lx, y, true);
        }
        else if (dLeft != nullptr)
        {
            if (dLeft->isP2() && currentPlayer == 1)
            {
                board1.setOccupied(lx, y, true);
                break;
            }
            else if (!dLeft->isP2() && currentPlayer == 2)
            {
                board1.setOccupied(lx, y, true);
                break;
            }
            else
            {
                break;
            }
        }
    }
    for (int rx = x + 1; rx < 5; rx++)
    {
        Pieces* dRight = board1.getPiece(rx, y);
        if (dRight == nullptr)
        {
            board1.setOccupied(rx, y, true);
        }
        else if (dRight != nullptr)
        {
            if (dRight->isP2() && currentPlayer == 1)
            {
                board1.setOccupied(rx, y, true);
                break;
            }
            else if (!dRight->isP2() && currentPlayer == 2)
            {
                board1.setOccupied(rx, y, true);
                break;
            }
            else
            {
                break;
            }
        }
    }
    for (int by = y + 1; by < 5; by++)
    {
        Pieces* back = board1.getPiece(x, by);
        if (back == nullptr)
        {
            board1.setOccupied(x, by, true);
        }
        else if (back != nullptr)
        {
            if (back->isP2() && currentPlayer == 1)
            {
                board1.setOccupied(x, by, true);
                break;
            }
            else if (!back->isP2() && currentPlayer == 2)
            {
                board1.setOccupied(x, by, true);
                break;
            }
            else
            {
                break;
            }
        }
    }
}
void Knight::getmovesp1(chessBoard& board1, int currentPlayer)
{
    int x = GetX();
    int y = GetY();
    if (x + 1 < 5 && y - 2 > -1)
    {
        Pieces* frontR = board1.getPiece(x + 1, y - 2);
        if (frontR == nullptr)
        {
            board1.setOccupied(x + 1, y - 2, true);
        }
        else if (frontR->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(x + 1, y - 2, true);
        }
        else if (!frontR->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(x + 1, y - 2, true);
        }
    }
    if (x - 1 > -1 && y - 2 > -1)
    {
        Pieces* frontL = board1.getPiece(x - 1, y - 2);
        if (frontL == nullptr)
        {
            board1.setOccupied(x - 1, y - 2, true);
        }
        else if (frontL->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(x - 1, y - 2, true);
        }
        else if (!frontL->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(x - 1, y - 2, true);
        }
    }
    if (x + 1 < 5 && y + 2 < 5)
    {
        Pieces* backR = board1.getPiece(x + 1, y + 2);
        if (backR == nullptr)
        {
            board1.setOccupied(x + 1, y + 2, true);
        }
        else if (backR->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(x + 1, y + 2, true);
        }
        else if (!backR->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(x + 1, y + 2, true);
        }
    }
    if (x - 1 > -1 && y + 2 < 5)
    {
        Pieces* backL = board1.getPiece(x - 1, y + 2);
        if (backL == nullptr)
        {
            board1.setOccupied(x - 1, y + 2, true);
        }
        else if (backL->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(x - 1, y + 2, true);
        }
        else if (!backL->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(x - 1, y + 2, true);
        }
    }
    if (x + 2 < 5 && y - 1 > -1)
    {
        Pieces* rightUp = board1.getPiece(x + 2, y - 1);
        if (rightUp == nullptr)
        {
            board1.setOccupied(x + 2, y - 1, true);
        }
        else if (rightUp->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(x + 2, y - 1, true);
        }
        else if (!rightUp->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(x + 2, y - 1, true);
        }
    }
    if (x + 2 < 5 && y + 1 < 5)
    {
        Pieces* rightDown = board1.getPiece(x + 2, y + 1);
        if (rightDown == nullptr)
        {
            board1.setOccupied(x + 2, y + 1, true);
        }
        else if (rightDown->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(x + 2, y + 1, true);
        }
        else if (!rightDown->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(x + 2, y + 1, true);
        }
    }
    if (x - 2 > -1 && y - 1 > -1)
    {
        Pieces* leftUp = board1.getPiece(x - 2, y - 1);
        if (leftUp == nullptr)
        {
            board1.setOccupied(x - 2, y - 1, true);
        }
        else if (leftUp->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(x - 2, y - 1, true);
        }
        else if (!leftUp->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(x - 2, y - 1, true);
        }
    }
    if (x - 2 > -1 && y + 1 < 5)
    {
        Pieces* leftDown = board1.getPiece(x - 2, y + 1);
        if (leftDown == nullptr)
        {
            board1.setOccupied(x - 2, y + 1, true);
        }
        else if (leftDown->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(x - 2, y + 1, true);
        }
        else if (!leftDown->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(x - 2, y + 1, true);
        }
    }
}
void Bishop::getmovesp1(chessBoard& board1, int currentPlayer)
{
    int x = GetX();
    int y = GetY();
    for (int bx = x + 1, by = y - 1; bx < 5 && by > -1; bx++, by--)
    {
        Pieces* frontR = board1.getPiece(bx, by);
        if (frontR == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (frontR->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!frontR->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int bx = x - 1, by = y + 1; bx > -1 && by < 5; bx--, by++)
    {
        Pieces* backL = board1.getPiece(bx, by);
        if (backL == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (backL->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!backL->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int bx = x - 1, by = y - 1; bx > -1 && by > -1; bx--, by--)
    {
        Pieces* frontL = board1.getPiece(bx, by);
        if (frontL == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (frontL->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!frontL->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int bx = x + 1, by = y + 1; bx < 5 && by < 5; bx++, by++)
    {
        Pieces* backR = board1.getPiece(bx, by);
        if (backR == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (backR->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!backR->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
}
void Queen::getmovesp1(chessBoard& board1, int currentPlayer)
{
    int x = GetX();
    int y = GetY();
    for (int bx = x + 1, by = y - 1; bx < 5 && by > -1; bx++, by--)
    {
        Pieces* frontR = board1.getPiece(bx, by);
        if (frontR == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (frontR->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!frontR->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int bx = x - 1, by = y + 1; bx > -1 && by < 5; bx--, by++)
    {
        Pieces* backL = board1.getPiece(bx, by);
        if (backL == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (backL->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!backL->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int bx = x - 1, by = y - 1; bx > -1 && by > -1; bx--, by--)
    {
        Pieces* frontL = board1.getPiece(bx, by);
        if (frontL == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (frontL->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!frontL->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int bx = x + 1, by = y + 1; bx < 5 && by < 5; bx++, by++)
    {
        Pieces* backR = board1.getPiece(bx, by);
        if (backR == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (backR->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!backR->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int by = y + 1, bx = x; by < 5; by++)
    {
        Pieces* back = board1.getPiece(bx, by);
        if (back == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (back->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!back->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int by = y - 1, bx = x; by > -1; by--)
    {
        Pieces* front = board1.getPiece(bx, by);
        if (front == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (front->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!front->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int bx = x + 1, by = y; bx < 5; bx++)
    {
        Pieces* right = board1.getPiece(bx, by);
        if (right == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (right->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!right->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
    for (int bx = x - 1, by = y; bx > -1; bx--)
    {
        Pieces* left = board1.getPiece(bx, by);
        if (left == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (left->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else if (!left->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
            break;
        }
        else
            break;
    }
}
void King::getmovesp1(chessBoard& board1, int currentPlayer)
{
    int x = GetX();
    int y = GetY();
    if (int bx = x - 1, by = y; bx > -1)
    {
        Pieces* left = board1.getPiece(bx, by);
        if (left == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (left->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (!left->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
        }
    }
    if (int bx = x + 1, by = y; bx < 5)
    {
        Pieces* right = board1.getPiece(bx, by);
        if (right == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (right->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (!right->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
        }
    }
    if (int by = y + 1, bx = x; by < 5)
    {
        Pieces* back = board1.getPiece(bx, by);
        if (back == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (back->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (!back->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
        }
    }
    if (int by = y - 1, bx = x; by > -1)
    {
        Pieces* front = board1.getPiece(bx, by);
        if (front == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (front->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (!front->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
        }
    }
    if (int by = y - 1, bx = x - 1; by > -1 && bx > -1)
    {
        Pieces* frontL = board1.getPiece(bx, by);
        if (frontL == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (frontL->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (!frontL->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
        }
    }
    if (int by = y - 1, bx = x + 1; by > -1 && bx < 5)
    {
        Pieces* frontR = board1.getPiece(bx, by);
        if (frontR == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (frontR->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (!frontR->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
        }
    }
    if (int by = y + 1, bx = x - 1; by < 5 && bx > -1)
    {
        Pieces* backL = board1.getPiece(bx, by);
        if (backL == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (backL->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (!backL->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
        }
    }
    if (int by = y + 1, bx = x + 1; by < 5 && bx < 5)
    {
        Pieces* backR = board1.getPiece(bx, by);
        if (backR == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (backR->isP2() && currentPlayer == 1)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (!backR->isP2() && currentPlayer == 2)
        {
            board1.setOccupied(bx, by, true);
        }
    }
}