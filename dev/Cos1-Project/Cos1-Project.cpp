#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include "ConsoleGraphics.h"
#include "Game.h"

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

int main()
{
	Menu();
}