#include "Chess.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>

void SetConsoleSize()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD bufferSize;
    bufferSize.X = 200;
    bufferSize.Y = 200;

    SetConsoleScreenBufferSize(console, bufferSize);

    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = 79;
    windowSize.Bottom = 49;

    SetConsoleWindowInfo(console, TRUE, &windowSize);
}
void SetWhiteSquare()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}
void SetBlackSquare()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void SetPinkBackground()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
}
void SetP2ColorWhite()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN);
}
void SetP1ColorWhite()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}
void SetP2ColorBlack()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_GREEN);
}
void SetP1ColorBlack()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
}
void Pink()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, BACKGROUND_BLUE | BACKGROUND_RED);
}
void colorBG()
{
    SetPinkBackground();
    for (int i = 0; i < 80; i++)
    {
        std::cout << std::string(80, ' ');
    }
}

void setPosition(int x, int y)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(console, position);
}
void MaximizeConsole()
{
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}
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
COORD game::getClicks(HANDLE hInput)
{
    //input record is storing what input takes place, key stroke, mouse click, position etc. its saving it to a variable called input.
    INPUT_RECORD input;
    //storing number of events as variable events, which is needed with the api functions below
    DWORD events;
    //creating a loop that will run input checking until it gets a mouse click with coordinates that satisfy as being within the game board.
    bool clicked = false;
    //starting invalid coordinates for use in determing if valid click will be within grid later to change state of clicked
    COORD selected = { -1,-1 };
    while (!clicked)
    {
        //error handling, readconsole input is taking the hInput stream and saving the input to &input, its requesting 1 input and saving the number recorded to &events
        bool success = ReadConsoleInput(hInput, &input, 1, &events);

        if (success == false)
        {
            //providing a failsafe for input errors outside of out of bound clicks
            return { -1, -1 };
        }
        //if input got stored an event == to a mouse event, comparison statment
        if (input.EventType == MOUSE_EVENT)
        {
            //record mouse event to mouse through the input of mouse event
            MOUSE_EVENT_RECORD mouse = input.Event.MouseEvent;
            //dweventflags == 0 confirms its a mouse click and not scrolling
            //dwbuttonstate checks the type of button press and from left 1st is using bitwise and to makesure its a left click
            if (mouse.dwEventFlags == 0 && (mouse.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED))
            {
                //saving mouse position x and y to integers for doing math to calculate where on the board it falls.
                //side note ive typed mouse so many times its starting to look like moose to me. could be the late night side effect.
                int mouseX = mouse.dwMousePosition.X;
                int mouseY = mouse.dwMousePosition.Y;
                //board is 5x5 each tile is 5 wide and 3 tall, the display off sets x + 15, y + 4. This is checking to see if the coordinates are outside of the board.
                if (mouseX < 15 || mouseX >= 40 || mouseY < 4 || mouseY >= 19)
                {
                    //outof bounds confirmed skip the loop and restart
                    continue;
                }
                //reversing the math on the column display of (x * 5) + 15 and (y * 3) + 4 and saving to the coordinate variable selected
                selected.X = (mouseX - 15) / 5;
                selected.Y = (mouseY - 4) / 3;
                //setting clicked to true to end the loop
                clicked = true;
            }
        }
    }
    //returning the coordinates of selected
    return selected;
}
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
void game::run()
{
    setupPieces();
    SwitchPlayer();
    board1.placeP(&p2kn1, 2, 3);
    p2kn1.getmovesp1(board1, currentPlayer);
    board1.DrawBoard();
    // Sleep(1000);
     //board1.placeP(&pl2p1, 1, 5);
     //pl2p1.Isp2(true);
     //board1.placeP(&pl1p5, 3, 5);
     //Sleep(1000);
     //pl1p3.getmovesp1(board1);
     //Sleep(1000);
     //board1.DrawBoard();
     //Sleep(1000);
     //board1.resetOccupied();
     //board1.DrawBoard();
     //Sleep(1000);
     //p1r1.getmovesp1(board1);
     //board1.DrawBoard();
     //Sleep(1000);
     //board1.resetOccupied();
     //board1.DrawBoard();
     //Sleep(1000);
     //board1.placeP(&p1r1, 4, 4);
     //board1.DrawBoard();
     //Sleep(1000);
     //p1r1.getmovesp1(board1);
     //board1.DrawBoard();
     //Sleep(1000);
     //board1.resetOccupied();
     //board1.placeP(&p1kn1, 5, 3);
     //p1kn1.getmovesp1(board1);
     //board1.DrawBoard();


}
void Menu()
{
    SetConsoleSize();
    std::cout << "Welcome to Chess Wars!" << "\n";
    std::cout << "To play enter 'y', to exit press anything else" << "\n";
    std::string run;
    std::cin >> run;
    if (run == "y" || run == "Y")
    {
        setPosition(0, 0);
        colorBG();
        setPosition(0, 0);
        game game1;
        game1.run();
        Sleep(3000);
    }
    else
        std::cout << "Goodbye";

}
