#pragma once
#include <vector>

class Drafting
{
private:
	//creating starting budgets for each player
	int p1Budget = 20;
	int p2Budget = 20;

	//creating vector to store pieces purchased by each player
	//not sure what data type is best, I might save piece to an int and just convert it withing game when assigning pieces to load
	std::vector<int> p1Pieces;
	std::vector<int> p2Pieces;

public:
	void startDraft();
	std::vector<int> selectPiece(int currentPlayer, int p1Budget, int p2Budget, std::vector<int> options);
	std::vector<int> displayDraftPieces(int currentPlayer, int p1Budget, int p2Budget);
	void resetDraftV();
	std::vector<int> getP1Pieces();
	std::vector<int> getP2Pieces();
	void displayBudget();
	void resetConsole();
};