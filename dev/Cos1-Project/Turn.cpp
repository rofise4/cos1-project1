#include "Game.h"
#include <iostream>

COORD game::getPieceSelected(HANDLE hInput)
{
	board1.resetSelected();
	COORD test = getClicks(hInput);
	board1.seclected(test.X, test.Y, true);
	std::cout << test.X << " " << test.Y;
	return test;
}
void game::Turn()
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	setPosition(0, 20);
	std::cout << "Waiting for clicks";
	COORD highlighted = getPieceSelected(hInput);
	board1.DrawBoard();
}