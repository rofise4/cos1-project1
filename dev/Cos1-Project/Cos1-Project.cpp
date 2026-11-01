#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include "Chess.h"

using namespace std;


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