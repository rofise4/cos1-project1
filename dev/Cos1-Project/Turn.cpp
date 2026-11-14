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
bool game::Turn()
{
	bool proceed = false;
	//wraping the select piece and then movement logic in a while loop
	//using the safety check just added to capture and changes to make it a boolean function
	//if it fails you select a new piece and try again
	//if it passes we draw the board and switch turns
	//also will be adding a check next so if you click a different square during capture it resets and allows you to select a different piece
	//so this should set that up
	while (proceed == false)
	{
		bool stale = false;
		bool mate = false;
		if (getMoves(currentPlayer) == true)
		{
			board1.resetOccupied();
			board1.resetSelected();
			setPosition(5, 27);
			std::cout << "Are legal moves available	" << getMoves(currentPlayer);
			//first test got frozen with piece highlighted
			//making sure it actually looped by redrawing after clearing highlights
			board1.DrawBoard();
			HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
			highlightCheck();
			setPosition(0, 22);
			if (currentPlayer == 1)
			{
				std::cout << "Player 1s turn";
			}
			else
			{
				std::cout << "Player 2s turn";
			}

			COORD highlighted = getPieceSelected(hInput);
			board1.DrawBoard();
			Pieces* piece = board1.getPiece(highlighted.X, highlighted.Y);
			piece->getmovesp1(board1, getCurrentPlayer());
			board1.DrawBoard();
			proceed = capture(highlighted);
			board1.resetOccupied();
			board1.resetSelected();
			board1.DrawBoard();


		}
		else
		{
			mate = testCheckmate(currentPlayer);
			stale = testStaleMate(currentPlayer);
		}
		if (mate == true || stale == true)
		{
			SwitchPlayer();
			if (mate == true)
			{
				setPosition(7, 24);
				std::cout << "Player " << currentPlayer << " Wins by CheckMate!";
			}
			if (stale == true)
			{
				setPosition(7, 25);
				std::cout << "StaleMate No Winners!";
			}
			return false;
		}
		if (proceed == true)
		{
			SwitchPlayer();
		}
	}
	return true;


	//setPosition(0, 20);
	/*if (board1.getPiece(highlighted.X, highlighted.Y) == nullptr)
	{
		std::cout << "Old square is empty no memory issues";
	}
	else
		std::cout << "Huston, we have a problem";*/
}