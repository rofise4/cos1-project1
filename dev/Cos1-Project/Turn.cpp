#include "Game.h"
#include <iostream>

COORD game::getPieceSelected(HANDLE hInput)
{
	COORD test = getClicks(hInput);
	std::cout << test.X << " " << test.Y;
	return test;
}
void game::Turn()
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	setPosition(0, 20);
	std::cout << "Waiting for clicks";
	getPieceSelected(hInput);
}