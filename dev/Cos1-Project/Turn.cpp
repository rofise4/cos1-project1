#include "Game.h"
#include <iostream>

COORD game::getPieceSelected(HANDLE hInput)
{
	bool valid = false;
	bool movesExsist = false;
	COORD test;
	int player = getCurrentPlayer();
	while (movesExsist == false)
	{
		while (valid == false)
		{
			board1.resetSelected();
			test = getClicks(hInput);

			valid = game::validatePlayer(player, test);
		}
		Pieces* piece = board1.getPiece(test.X, test.Y);
		piece->getmovesp1(board1, getCurrentPlayer());
		movesExsist = board1.validateOccupied();
		if (movesExsist == false)
		{
			board1.resetOccupied();
			board1.resetSelected();
			valid = false;
		}
		else
			break;
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
	capture(highlighted);
	board1.DrawBoard();
	board1.resetOccupied();
	board1.resetSelected();
	board1.DrawBoard();
	SwitchPlayer();
	//setPosition(0, 20);
	/*if (board1.getPiece(highlighted.X, highlighted.Y) == nullptr)
	{
		std::cout << "Old square is empty no memory issues";
	}
	else
		std::cout << "Huston, we have a problem";*/
}