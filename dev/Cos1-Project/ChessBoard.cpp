#include "ChessBoard.h"
#include "ConsoleGraphics.h"
#include <iostream>

    chessBoard::chessBoard()
    {
        Initialize();
    }
    //initialize is just creating board and not populating yet and assigning colors to squares
    void chessBoard::Initialize()
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
                        std::cout << "     ";
                        setPosition(x, y + 1);
                        std::cout << "     ";
                        setPosition(x, y + 2);
                        std::cout << "     ";
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
                        std::cout << "     ";
                        setPosition(x, y + 1);
                        std::cout << "     ";
                        setPosition(x, y + 2);
                        std::cout << "     ";
                    }
                }
            }
        }
    }
    bool chessBoard::Empty(int x, int y)
    {
        if (squares[y][x] == nullptr)
        {
            return true;
        }
    }
    Pieces* chessBoard::getPiece(int x, int y)
    {
        return squares[y][x];
    }
    bool chessBoard::getOccupied(int x, int y)
    {
        return occupied[y][x];
    }
    void chessBoard::DrawBoard()
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
                    std::cout << "     ";
                    setPosition(x, y + 1);
                    std::cout << "     ";
                    setPosition(x, y + 2);
                    std::cout << "     ";
                }
                else if (highlighted[i][j] == true)
                {
                    Yellow();
                    x = (coordinatex[j] * 5) + 15;
                    y = (coordinatey[i] * 3) + 4;
                    setPosition(x, y);
                    std::cout << "     ";
                    setPosition(x, y + 1);
                    std::cout << "     ";
                    setPosition(x, y + 2);
                    std::cout << "     ";
                }
                else if ((i + j) % 2 == 0)
                {
                    SetWhiteSquare();
                    x = (coordinatex[j] * 5) + 15;
                    y = (coordinatey[i] * 3) + 4;
                    setPosition(x, y);
                    std::cout << "     ";
                    setPosition(x, y + 1);
                    std::cout << "     ";
                    setPosition(x, y + 2);
                    std::cout << "     ";
                }
                else
                {
                    SetBlackSquare();
                    x = (coordinatex[j] * 5) + 15;
                    y = (coordinatey[i] * 3) + 4;
                    setPosition(x, y);
                    std::cout << "     ";
                    setPosition(x, y + 1);
                    std::cout << "     ";
                    setPosition(x, y + 2);
                    std::cout << "     ";
                }

                if (squares[i][j] != nullptr)
                {

                    squares[i][j]->draw(occupied[i][j], highlighted[i][j]);

                }
            }
        }
    }
    void chessBoard::placeP(Pieces* piece, int newx, int newy)
    {
        squares[newy][newx] = piece;
        piece->initializex(newx, newy);
    }
    void chessBoard::seclected(int newx, int newy, bool clicked)
    {
        highlighted[newy][newx] = clicked;
    }
    void chessBoard::resetSelected()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                highlighted[i][j] = false;
            }
        }
    }
    void chessBoard::setOccupied(int newx, int newy, bool selected)
    {
        occupied[newy][newx] = selected;
    }
    void chessBoard::resetOccupied()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                occupied[i][j] = false;
            }
        }
    }

