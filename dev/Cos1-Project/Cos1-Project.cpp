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
    void getmovesp1(chessBoard& board1);
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
    for(int bx = x+1, by = y-1; bx < 5 && by > -1; bx++, by--)
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
    for (int bx = x -1, by = y +1; bx > -1 && by  < 5; bx--, by++)
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
    for (int bx = x -1, by = y - 1; bx > -1 && by > -1; bx--, by--)
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
    for(int by = y +1, bx = x; by < 5; by++)
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
    for(int bx = x +1, by = y; bx < 5; bx++)
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
void King::getmovesp1(chessBoard& board1)
{
    int x = GetX();
    int y = GetY();
    if(int bx = x-1, by = y; bx > -1)
    {
        Pieces* left = board1.getPiece(bx, by);
        if (left == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (left->isP2())
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
        else if (right->isP2())
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
        else if (back->isP2())
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
        else if (front->isP2())
        {
            board1.setOccupied(bx, by, true);
        }
    }
    if (int by = y - 1, bx = x -1; by > -1 && bx > -1)
    {
        Pieces* frontL = board1.getPiece(bx, by);
        if (frontL == nullptr)
        {
            board1.setOccupied(bx, by, true);
        }
        else if (frontL->isP2())
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
        else if (frontR->isP2())
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
        else if (backL->isP2())
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
        else if (backR->isP2())
        {
            board1.setOccupied(bx, by, true);
        }
    }
}
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