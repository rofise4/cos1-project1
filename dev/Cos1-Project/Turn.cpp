#include "Game.h"
#include <iostream>

COORD game::getPieceSelected(HANDLE hInput)
{
	bool valid = false;
	COORD test;
	int player = getCurrentPlayer();
	while (valid == false)
	{
		board1.resetSelected();
		test = getClicks(hInput);

		valid = game::validatePlayer(player, test);
	}
	board1.seclected(test.X, test.Y, true);
	setPosition(3, 30);
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