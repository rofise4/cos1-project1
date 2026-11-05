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
	board1.resetOccupied();
	board1.resetSelected();
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	setPosition(0, 20);
	std::cout << "Waiting for clicks";
	COORD highlighted = getPieceSelected(hInput);
	board1.DrawBoard();
	Pieces* piece = board1.getPiece(highlighted.X, highlighted.Y);
	piece->getmovesp1(board1, getCurrentPlayer());
	board1.DrawBoard();
}