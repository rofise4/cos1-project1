#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
using namespace std;
void SetConsoleSize();
void SetWhiteSquare();
void SetBlackSquare();
void SetPinkBackground();
void SetP2ColorWhite();
void SetP1ColorWhite();
void SetP2ColorBlack();
void SetP1ColorBlack();
void Pink();
void colorBG();
void setPosition(int x, int y);
void MaximizeConsole();
class chessBoard;
class Pieces
{
public:
    void Isp2(bool p2)
        //setting player 2
    {
        isp2 = p2;
    }
    void getmovesp1()
        //getters for p1 move
    {
        int x = GetX();
        int y = GetY();
    }
    bool isP2()
        //checking if a piece is player 2
    {
        return isp2;
    }
    virtual char GetSymbol()
    {
        return ' ';
    }
    virtual void move()
    {
        cout << "it did not load correctly";
    }

    virtual void draw()
    {
        //setting board dimensions for drawing, accounting for height and width of drawn squares
        int tempx = (GetX() * 5) + 15;
        int tempy = (GetY() * 3) + 4;
        if ((GetY() + GetX()) % 2 == 0)
        {
            /*alternating black and white pieces using mod 2 to ofset grid
            draws square with back ground color white or balck and then draws the symbol for any assosiated pieces
            pieces check for p1 or p2 and set there own background color*/
            setPosition(tempx, tempy + 1);
            if (isp2)
            {
                SetP2ColorWhite();
                cout << "  ";
                cout << GetSymbol();
                SetWhiteSquare();
            }
            else
            {
                SetP1ColorWhite();
                cout << "  ";
                cout << GetSymbol();
                SetWhiteSquare();
            }
        }
        else
        {
            SetBlackSquare();
            setPosition(tempx, tempy);
            cout << "     ";
            setPosition(tempx, tempy + 1);
            cout << "  ";
            if (isp2)
            {
                SetP2ColorBlack();
                cout << GetSymbol();
                SetBlackSquare();
            }
            else
            {
                SetP1ColorBlack();
                cout << GetSymbol();
                SetBlackSquare();
            }
            cout << "  ";
            setPosition(tempx, tempy + 2);
            cout << "     ";

        }

    }
    void initializex(int newx, int newy)
        //getters/setters for board dimensions in drawing and handling curor placement
    {
        x = newx;
        y = newy;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
private:
    //starting cursor position and player two default place holder
    bool isp2 = false;
    int x = 0;
    int y = 0;
};
class Square : public Pieces
{
public:

private:
};

class Pawn : public Pieces
{
public:
    //get symbol returns p for pawn, bottom of each gets a forwards decloration for calling moves once defined later
    char GetSymbol()
    {
        return 'p';
    }
    void getmovesp1(chessBoard& board1, int currentPlayer);

private:
};
class Rook : public Pieces
{
public:
    //returning r for rook
    char GetSymbol()
    {
        return 'r';
    }
    void getmovesp1(chessBoard& board1, int currentPlayer);
private:
};
class Knight : public Pieces
{
public:
    //n for night
    char GetSymbol()
    {
        return 'n';
    }
    void getmovesp1(chessBoard& board1, int currentPlayer);
private:
};
class Bishop : public Pieces
{
public:
    //returning b for bishop
    char GetSymbol()
    {
        return 'b';
    }
    void getmovesp1(chessBoard& board1, int currentPlayer);
private:
};
class Queen : public Pieces
{
public:
    //returning q for queen
    char GetSymbol()
    {
        return 'q';
    }
    void getmovesp1(chessBoard& board1, int currentPlayer);
private:
};
class King : public Pieces
{
public:
    //returning k for king
    char GetSymbol()
    {
        return 'k';
    }
    void getmovesp1(chessBoard& board1, int currentPlayer);
private:
};

class chessBoard
{
public:
    chessBoard()
    {
        Initialize();
    }
    //initialize is just creating board and not populating yet and assigning colors to squares
    void Initialize()
    {
        int x;
        int y;
        /*i and j act as the x and y coordinates of the board. [I][J] starts as nullptr with occupied status as false. Essentially during the
        draw initilization this just says nothing is here and is creating the blank board to build uppon*/
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                squares[i][j] = nullptr;
                //i and j match regular index value, use in draw loop instead for coordinate multiplication
                coordinatey[i] = i;
                coordinatex[j] = j;
                occupied[i][j] = false;
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                /*using mod 2 on the combined value just to create an alternating sequence between white and black squares because
                every new square will have a coordinate point that is offset by one in value*/
                if ((i + j) % 2 == 0)
                {
                    if (squares[i][j] == nullptr)
                    {
                        //calling setwhitesquare to set as white
                        SetWhiteSquare();
                        /*I am scaling positions of squares based on width and hight of drawing then setting cout "   " to shape the initial square
                        the background color is set using set white square above*/
                        x = (coordinatex[j] * 5) + 15;
                        y = (coordinatey[i] * 3) + 4;
                        setPosition(x, y);
                        cout << "     ";
                        setPosition(x, y + 1);
                        cout << "     ";
                        setPosition(x, y + 2);
                        cout << "     ";
                    }
                }
                else
                {
                    if (squares[i][j] == nullptr)
                    {
                        //same as set white, this just work in reverse to set bg color to black
                        SetBlackSquare();
                        x = (coordinatex[j] * 5) + 15;
                        y = (coordinatey[i] * 3) + 4;
                        setPosition(x, y);
                        cout << "     ";
                        setPosition(x, y + 1);
                        cout << "     ";
                        setPosition(x, y + 2);
                        cout << "     ";
                    }
                }
            }
        }
    }
    bool Empty(int x, int y)
    {
        if (squares[y][x] == nullptr)
        {
            return true;
        }
    }
    Pieces* getPiece(int x, int y)
    {
        return squares[y][x];
    }
    bool getOccupied(int x, int y)
    {
        return occupied[y][x];
    }
    void DrawBoard()
    {
        int x;
        int y;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (occupied[i][j] == true)
                {
                    Pink();
                    x = (coordinatex[j] * 5) + 15;
                    y = (coordinatey[i] * 3) + 4;
                    setPosition(x, y);
                    cout << "     ";
                    setPosition(x, y + 1);
                    cout << "     ";
                    setPosition(x, y + 2);
                    cout << "     ";
                }
                else if ((i + j) % 2 == 0)
                {
                    SetWhiteSquare();
                    x = (coordinatex[j] * 5) + 15;
                    y = (coordinatey[i] * 3) + 4;
                    setPosition(x, y);
                    cout << "     ";
                    setPosition(x, y + 1);
                    cout << "     ";
                    setPosition(x, y + 2);
                    cout << "     ";
                }
                else
                {
                    SetBlackSquare();
                    x = (coordinatex[j] * 5) + 15;
                    y = (coordinatey[i] * 3) + 4;
                    setPosition(x, y);
                    cout << "     ";
                    setPosition(x, y + 1);
                    cout << "     ";
                    setPosition(x, y + 2);
                    cout << "     ";
                }
                if (squares[i][j] != nullptr)
                {
                    squares[i][j]->draw();
                }
            }
        }
    }
    void placeP(Pieces* piece, int newx, int newy)
    {
        squares[newy][newx] = piece;
        piece->initializex(newx, newy);
    }
    void setOccupied(int newx, int newy, bool selected)
    {
        occupied[newy][newx] = selected;
    }
    void resetOccupied()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                occupied[i][j] = false;
            }
        }
    }
private:
    bool occupied[5][5];
    Pieces* squares[5][5];
    int coordinatey[5];
    int coordinatex[5];
};


class game
{
public:
    void setupPieces();
    void run();
    //adding switch to change between player 1 and two.
    void SwitchPlayer()
    {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    int getCurrentPlayer()const
    {
        return currentPlayer;
    }
    //defenition in game, but will be defined bellow in line with my run and setup functions for orginization in one file
    //coordinate return type, handle is acting as the bounds to console and hInpute is what binds it to the console input stream
    //coord returns a pair of x,y together. since i developed my board using [x][y] for storing positions between my pieces it allows for easier plugging into my existing code
    COORD getClicks(HANDLE hInput);
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
