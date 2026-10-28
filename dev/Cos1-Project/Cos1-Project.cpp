#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>

using namespace std;
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
        cout << string(80, ' ');
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
class chessBoard;
class Pieces
{
public:
    void Isp2(bool p2)
    {
        isp2 = p2;
    }
    void getmovesp1()
    {
        int x = GetX();
        int y = GetY();
    }
    bool isP2()
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
        int tempx = (GetX() * 5) + 15;
        int tempy = (GetY() * 3) + 4;
        if ((GetY() + GetX()) % 2 == 0)
        {
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
    char GetSymbol()
    {
        return 'p';
    }
    void getmovesp1(chessBoard& board1);

private:
};
class Rook : public Pieces
{
public:
    char GetSymbol()
    {
        return 'r';
    }
    void getmovesp1(chessBoard& board1);
private:
};
class Knight : public Pieces
{
public:
    char GetSymbol()
    {
        return 'n';
    }
    void getmovesp1(chessBoard& board1);
private:
};
class Bishop : public Pieces
{
public:
    char GetSymbol()
    {
        return 'b';
    }
private:
};
class Queen : public Pieces
{
public:
    char GetSymbol()
    {
        return 'q';
    }
private:
};
class King : public Pieces
{
public:
    char GetSymbol()
    {
        return 'k';
    }
private:
};
class chessBoard
{
public:
    chessBoard()
    {
        Initialize();
    }
    void Initialize()
    {
        int x;
        int y;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                squares[i][j] = nullptr;
                //i and j match regular index value, use in draw loop instead for coordinate multiplication
                coordinatey[i] = i;
                coordinatex[j] = j;
                occupied[i][j] = false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    if (squares[i][j] == nullptr)
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
                }
                else
                {
                    if (squares[i][j] == nullptr)
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
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
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
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                occupied[i][j] = false;
            }
        }
    }
private:
    bool occupied[8][8];
    Pieces* squares[8][8];
    int coordinatey[8];
    int coordinatex[8];
};
void Pawn::getmovesp1(chessBoard& board1)
{
    int x = GetX();
    int y = GetY();
    Pieces* front = board1.getPiece(x, y - 1);
    Pieces* dLeft = board1.getPiece(x - 1, y - 1);
    Pieces* dRight = board1.getPiece(x + 1, y - 1);
    if (front == nullptr && y < 8)
    {
        board1.setOccupied(x, y - 1, true);
        //highlight square
    }
    else
    {
        //not front
    }
    if (dLeft != nullptr || dRight != nullptr)
    {
        if (dLeft != nullptr && x > -1)
        {
            //check isp2
            if (dLeft->isP2())
            {
                board1.setOccupied(x - 1, y - 1, true);
                //highlight square
            }
            else
            {
                //not valid move
            }
        }
        else
        {
            //no available moves
        }
        if (dRight != nullptr && x < 8)
        {
            //check isp2
            if (dRight->isP2())
            {
                board1.setOccupied(x + 1, y - 1, true);
                //highlight square
            }
            else
            {
                //no available moves
            }
        }
        else
        {
            //no available moves
        }
    }
    else
    {
        //no moves available
    }
}
void Rook::getmovesp1(chessBoard& board1)
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
            if (front->isP2())
            {
                board1.setOccupied(x, fy, true);
            }
            else
            {
                break;
            }
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
            if (dLeft->isP2())
            {
                board1.setOccupied(lx, y, true);
            }
            else
            {
                break;
            }
        }
    }
    for (int rx = x + 1; rx < 8; rx++)
    {
        Pieces* dRight = board1.getPiece(rx, y);
        if (dRight == nullptr)
        {
            board1.setOccupied(rx, y, true);
        }
        else if (dRight != nullptr)
        {
            if (dRight->isP2())
            {
                board1.setOccupied(rx, y, true);
            }
            else
            {
                break;
            }
        }
    }
    for (int by = y + 1; by < 7; by++)
    {
        Pieces* back = board1.getPiece(x, by);
        if (back == nullptr)
        {
            board1.setOccupied(x, by, true);
        }
        else if (back != nullptr)
        {
            if (back->isP2())
            {
                board1.setOccupied(x, by, true);
            }
            else
            {
                break;
            }
        }
    }
}
void Knight::getmovesp1(chessBoard& board1)
{
    int x = GetX();
    int y = GetY();
    if (x + 1 < 8 && y - 2 > -1)
    {
        Pieces* frontR = board1.getPiece(x + 1, y - 2);
        if (frontR == nullptr)
        {
            board1.setOccupied(x + 1, y - 2, true);
        }
        else if (frontR->isP2())
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
        else if (frontL->isP2())
        {
            board1.setOccupied(x - 1, y - 2, true);
        }
    }
    if (x + 1 < 8 && y + 2 < 8)
    {
        Pieces* backR = board1.getPiece(x + 1, y + 2);
        if (backR == nullptr)
        {
            board1.setOccupied(x + 1, y + 2, true);
        }
        else if (backR->isP2())
        {
            board1.setOccupied(x + 1, y + 2, true);
        }
    }
    if (x - 1 > -1 && y + 2 < 8)
    {
        Pieces* backL = board1.getPiece(x - 1, y + 2);
        if (backL == nullptr)
        {
            board1.setOccupied(x - 1, y + 2, true);
        }
        else if (backL->isP2())
        {
            board1.setOccupied(x - 1, y + 2, true);
        }
    }
    if (x + 2 < 8 && y - 1 > -1)
    {
        Pieces* rightUp = board1.getPiece(x + 2, y - 1);
        if (rightUp == nullptr)
        {
            board1.setOccupied(x + 2, y - 1, true);
        }
        else if (rightUp->isP2())
        {
            board1.setOccupied(x + 2, y - 1, true);
        }
    }
    if (x + 2 < 8 && y + 1 < 8)
    {
        Pieces* rightDown = board1.getPiece(x + 2, y + 1);
        if (rightDown == nullptr)
        {
            board1.setOccupied(x + 2, y + 1, true);
        }
        else if (rightDown->isP2())
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
        else if (leftUp->isP2())
        {
            board1.setOccupied(x - 2, y - 1, true);
        }
    }
    if (x - 2 > -1 && y + 1 < 8)
    {
        Pieces* leftDown = board1.getPiece(x - 2, y + 1);
        if (leftDown == nullptr)
        {
            board1.setOccupied(x - 2, y + 1, true);
        }
        else if (leftDown->isP2())
        {
            board1.setOccupied(x - 2, y + 1, true);
        }
    }
}
class game
{
public:
    void setupPieces();
    void run();
private:
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
void game::setupPieces()
{
    board1.placeP(&pl1p1, 0, 6);
    board1.placeP(&pl1p2, 1, 6);
    board1.placeP(&pl1p3, 2, 6);
    board1.placeP(&pl1p4, 3, 6);
    board1.placeP(&pl1p5, 4, 6);
    board1.placeP(&pl1p6, 5, 6);
    board1.placeP(&pl1p7, 6, 6);
    board1.placeP(&pl1p8, 7, 6);
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
    board1.placeP(&pl2p6, 5, 1);
    pl2p6.Isp2(true);
    board1.placeP(&pl2p7, 6, 1);
    pl2p7.Isp2(true);
    board1.placeP(&pl2p8, 7, 1);
    pl2p8.Isp2(true);
    board1.placeP(&p1r1, 0, 7);
    board1.placeP(&p1r2, 7, 7);
    board1.placeP(&p2r1, 0, 0);
    p2r1.Isp2(true);
    board1.placeP(&p2r2, 7, 0);
    p2r2.Isp2(true);
    board1.placeP(&p1kn1, 1, 7);
    board1.placeP(&p1kn2, 6, 7);
    board1.placeP(&p2kn1, 1, 0);
    p2kn1.Isp2(true);
    board1.placeP(&p2kn2, 6, 0);
    p2kn2.Isp2(true);
    board1.placeP(&p1b1, 2, 7);
    board1.placeP(&p1b2, 5, 7);
    board1.placeP(&p2b1, 2, 0);
    p2b1.Isp2(true);
    board1.placeP(&p2b2, 5, 0);
    p2b2.Isp2(true);
    board1.placeP(&p1q, 3, 7);
    board1.placeP(&p2q, 4, 0);
    p2q.Isp2(true);
    board1.placeP(&p1k, 4, 7);
    board1.placeP(&p2k, 3, 0);
    p2k.Isp2(true);
    pl1p1.draw();
    pl1p2.draw();
    pl1p3.draw();
    pl1p4.draw();
    pl1p5.draw();
    pl1p6.draw();
    pl1p7.draw();
    pl1p8.draw();
    pl2p1.draw();
    pl2p2.draw();
    pl2p3.draw();
    pl2p4.draw();
    pl2p5.draw();
    pl2p6.draw();
    pl2p7.draw();
    pl2p8.draw();
    p1r1.draw();
    p1r2.draw();
    p2r1.draw();
    p2r2.draw();
    p1b1.draw();
    p1b2.draw();
    p2b1.draw();
    p2b2.draw();
    p1kn1.draw();
    p1kn2.draw();
    p2kn1.draw();
    p2kn2.draw();
    p1q.draw();
    p2q.draw();
    p1k.draw();
    p2k.draw();
}
void game::run()
{
    setupPieces();
    Sleep(1000);
    board1.placeP(&pl2p1, 1, 5);
    pl2p1.Isp2(true);
    board1.placeP(&pl1p5, 3, 5);
    Sleep(1000);
    pl1p3.getmovesp1(board1);
    Sleep(1000);
    board1.DrawBoard();
    Sleep(1000);
    board1.resetOccupied();
    board1.DrawBoard();
    Sleep(1000);
    p1r1.getmovesp1(board1);
    board1.DrawBoard();
    Sleep(1000);
    board1.resetOccupied();
    board1.DrawBoard();
    Sleep(1000);
    board1.placeP(&p1r1, 4, 4);
    board1.DrawBoard();
    Sleep(1000);
    p1r1.getmovesp1(board1);
    board1.DrawBoard();
    Sleep(1000);
    board1.resetOccupied();
    board1.placeP(&p1kn1, 5, 3);
    p1kn1.getmovesp1(board1);
    board1.DrawBoard();



}
int main()
{
    SetConsoleSize();
    string run;
    cin >> run;
    while (run == "y")
    {
        setPosition(0, 0);
        colorBG();
        setPosition(0, 0);
        game game1;
        game1.run();
        Sleep(10000000);

    }

}