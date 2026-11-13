#include <iostream>
#include <vector>
#include "Game.h"
#include "Pieces.h"
#include "Drafting.h"
#include "ChessBoard.h"
#include "ConsoleGraphics.h"
#include <cstdlib>
#include <string>

std::vector<int> displayDraftPieces(int currentPlayer, int p1Budget, int p2Budget)
{
	/*this section is a little weird by design, so im going to give an overview
	the entire function is soley to create possible pieces for purchase, then display them and their cost to the player
	i have it filtering the selection weighted towards budget available however I am intentionally allowing pieces that may
	not be affordable in the lower budget ranges to be selected. I wanted to add some rng where overspending could make your last round of
	drafting unaffordable and leave you with less pieces, just a trade off to consider when making selections.*/
	int budget;
	int selected;
//	int queenS = 5;
//	int rook = 4;
//	int bishop = 3;
//	int knight = 2;
//	int pawn = 1;
	//setting budget to current player
	if (currentPlayer == 1)
	{
		budget = p1Budget;
	}
	else
	{
		budget = p2Budget;
	}
	std::vector<int> options;
	for (int i = 0; i < 3;)
		//filtering 3 options available to player based on random calls weighted based on remaining budget
	{
		selected = rand() % 5 + 1;
		if (budget >= 13)
		{
			if (selected > 2)
			{
				options.push_back(selected);
				i++;
			}
		}
		else if (budget >= 6 && budget < 13)
		{
			if (selected <= 4)
			{
				options.push_back(selected);
				i++;
			}
		}
		else
		{
			if (selected <= 3)
			{
				options.push_back(selected);
				i++;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1 << ". ";
		//loop through vector of available pieces and print name and piece depending on contents at location
		if (options[i] == 1)
		{
			std::cout << "Pawn : Price 1 ";
		}
		else if (options[i] == 2)
		{
			std::cout << "Knight : Price 3 ";
		}
		else if (options[i] == 3)
		{
			std::cout << "Bishop : Price 3 ";
		}
		else if (options[i] == 4)
		{
			std::cout << "Rook : Price 5 ";
		}
		else if (options[i] == 5)
		{
			std::cout << "Queen : Price 9 ";
		}
		else
			std::cout << "Well this is awkward, something went wrong";
		std::cout << "\n";
	}
	return options;
}
void startDraft()
{
	setPosition(3, 5);
	std::cout << "Welcome players, you will take turns purchasing your chess pieces accross three rounds " << "\n";
	
}