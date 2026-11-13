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
	std::vector<int> p1Purchase;
	std::vector<int> p2Purchase;

public:
	void startDraft();
	void selectPiece(int player, int piecetype);
	std::vector<int> displayDraftPieces(int currentPlayer, int p1Budget, int p2Budget);
};