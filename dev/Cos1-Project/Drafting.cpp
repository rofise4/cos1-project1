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
std::vector<int> selectPiece(int currentPlayer, int p1Budget, int p2Budget, std::vector<int> options)
{
	bool isValid = false;
	bool isInBudget = false;
	int locate;
	int budget;
	std::vector<int> selected;
	std::vector<int> prices = { 1, 3, 3, 5, 9 };
	bool anyavailable = false;
	//setting budget
	if (currentPlayer == 1)
	{
		budget = p1Budget;
	}
	else
	{
		budget = p2Budget;
	}
	//ensure there is an affordable selection or inform player their turn has ended
	for (int i = 0; i < 3; i++)
	{
		if (prices[options[i] - 1] > budget)
		{
			continue;
		}
		else
		{
			anyavailable = true;
		}
	}
	if (anyavailable == false)
	{
		std::cout << "It seems like you cannot afford to draft this turn, next players turn commencing " << "\n";
		selected.push_back(6);
		return selected;
	}
	//loop to restart until selection is valid, name might me slighly missleading for bool
	//renamed
	while (isValid == false)
	{
		//getting input for selection
		int attempted;
		std::cout << "Please enter the number for you selection and press enter: ";
		std::cin >> attempted;
		std::cout << "\n";

		//locate is -1 because selection from player is not starting at 0 where the vector starts
		locate = attempted - 1;
		//verifying input range
		if (locate >= 0 && locate <= 2)
		{
			if (prices[options[locate] -1] <= budget)
			{
				//copy contents of options to selected to get piece selected
				selected.push_back(options[locate]);
				return selected;
			}
			else
			{

				//tell them why before looping back
				std::cout << "Sorry but it appears you cannot afford that piece " << "\n";
			}
		}
	}
}
void Drafting::startDraft()
{
	
	std::vector<int> round;
	std::vector<int> selected;
	std::cout << "Welcome players, you will take turns purchasing your chess pieces accross multiple rounds " << "\n";
	std::cout << "Be warned, if your budget is too low you may not be able to purchase further pieces, so choose carefully " << "\n";
	for (int i = 0; i < 5; i++)
	{
	    std::cout << "Player 1, you currently have " << p1Budget << " remaining. Here are your options" << "\n";
		round = displayDraftPieces(1, p1Budget, p2Budget);
		//need to incoperate setters for purchase vectors;
		selected = selectPiece(1, p1Budget, p2Budget, round);
		if (selected[0] == 1)
		{
			p1Budget = p1Budget - 1;
			p1Pieces.push_back(1);
			std::cout << "You have succesfully purchased a pawn and your remaining budget is " << p1Budget << "\n";
		}
		else if (selected[0] == 2)
		{
			p1Budget = p1Budget - 3;
			p1Pieces.push_back(2);
			std::cout << "You have succesfully purchased a knight and your remaining budget is " << p1Budget << "\n";
		}
		else if (selected[0] == 3)
		{
			p1Budget = p1Budget - 3;
			p1Pieces.push_back(3);
			std::cout << "You have succesfully purchased a bishop and your remaining budget is " << p1Budget << "\n";
		}
		else if (selected[0] == 4)
		{
			p1Budget = p1Budget - 5;
			p1Pieces.push_back(4);
			std::cout << "You have succesfully purchased a rook and your remaining budget is " << p1Budget << "\n";
		}
		else if (selected[0] == 5)
		{
			p1Budget = p1Budget - 9;
			p1Pieces.push_back(5);
			std::cout << "You have succesfully purchased a queen and your remaining budget is " << p1Budget << "\n";
		}
		else
		{
			std::cout << "You have not purchased anything" << "\n";
		}
		std::cout << "Player 2, you currently have " << p2Budget << " remaining. Here are your options" << "\n";
		round = displayDraftPieces(2, p1Budget, p2Budget);
		//need to incoperate setters for purchase vectors;
		selected = selectPiece(2, p1Budget, p2Budget, round);
		if (selected[0] == 1)
		{
			p2Budget = p2Budget - 1;
			p2Pieces.push_back(1);
			std::cout << "You have succesfully purchased a pawn and your remaining budget is " << p2Budget << "\n";
		}
		else if (selected[0] == 2)
		{
			p2Budget = p2Budget - 3;
			p2Pieces.push_back(2);
			std::cout << "You have succesfully purchased a knight and your remaining budget is " << p2Budget << "\n";
		}
		else if (selected[0] == 3)
		{
			p2Budget = p2Budget - 3;
			p2Pieces.push_back(3);
			std::cout << "You have succesfully purchased a bishop and your remaining budget is " << p2Budget << "\n";
		}
		else if (selected[0] == 4)
		{
			p2Budget = p2Budget - 5;
			p2Pieces.push_back(4);
			std::cout << "You have succesfully purchased a rook and your remaining budget is " << p2Budget << "\n";
		}
		else if (selected[0] == 5)
		{
			p2Budget = p2Budget - 9;
			p2Pieces.push_back(5);
			std::cout << "You have succesfully purchased a queen and your remaining budget is " << p2Budget << "\n";
		}
		else
		{
			std::cout << "You have not purchased anything" << "\n";
		}
	}
}
void Drafting::resetDraftV()
{
	p1Budget = 20;
	p2Budget = 20;
	p1Pieces.clear();
	p2Pieces.clear();
}