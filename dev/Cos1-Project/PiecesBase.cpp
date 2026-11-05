#include "Pieces.h"
#include "ConsoleGraphics.h"
#include <iostream>


    void Pieces::Isp2(bool p2)
        //setting player 2
    {
        isp2 = p2;
    }
    void Pieces::getmovesp1()
        //getters for p1 move
    {
        int x = GetX();
        int y = GetY();
    }
    bool Pieces::isP2()
        //checking if a piece is player 2
    {
        return isp2;
    }
    char Pieces::GetSymbol()
    {
        return ' ';
    }
    void Pieces::move()
    {
        std::cout << "it did not load correctly";
    }

    void Pieces::draw()
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
                std::cout << "  ";
                std::cout << GetSymbol();
                SetWhiteSquare();
            }
            else
            {
                SetP1ColorWhite();
                std::cout << "  ";
                std::cout << GetSymbol();
                SetWhiteSquare();
            }
        }
        else
        {
            SetBlackSquare();
            setPosition(tempx, tempy);
            std::cout << "     ";
            setPosition(tempx, tempy + 1);
            std::cout << "  ";
            if (isp2)
            {
                SetP2ColorBlack();
                std::cout << GetSymbol();
                SetBlackSquare();
            }
            else
            {
                SetP1ColorBlack();
                std::cout << GetSymbol();
                SetBlackSquare();
            }
            std::cout << "  ";
            setPosition(tempx, tempy + 2);
            std::cout << "     ";

        }

    }
    void Pieces::initializex(int newx, int newy)
        //getters/setters for board dimensions in drawing and handling curor placement
    {
        x = newx;
        y = newy;
    }
    int Pieces::GetX()
    {
        return x;
    }
    int Pieces::GetY()
    {
        return y;
    }
    char Pawn::GetSymbol()
    {
        return 'p';
    }
    char Rook::GetSymbol()
    {
        return 'r';
    }
    char Knight::GetSymbol()
    {
        return 'n';
    }
    char Bishop::GetSymbol()
    {
        return 'b';
    }
    char Queen::GetSymbol()
    {
        return 'q';
    }
    char King::GetSymbol()
    {
        return 'k';
    }