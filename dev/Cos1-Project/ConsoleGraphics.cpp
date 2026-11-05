#include <Windows.h>
#include "ConsoleGraphics.h"
#include <string>
#include <iostream>
#include "Game.h"
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