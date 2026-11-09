#pragma once
#include <iostream>
#include "ConsoleGraphics.h"

class chessBoard;

class Pieces
{
public:
	void Isp2(bool p2);
	virtual void getmovesp1(chessBoard& board1, int currentPlayer);
	bool isP2();
	virtual char GetSymbol();
	virtual void move();
	virtual void draw(bool pink = false, bool selected = false);
	void initializex(int newx, int newy);
	int GetX();
	int GetY();
private:
	bool isp2 = false;
	int x = 0;
	int y = 0;

};

class Square : public Pieces
{

};

class Pawn : public Pieces
{
public:
	char GetSymbol() override;
	void getmovesp1(chessBoard& board1, int currentPlayer);
};
class Rook : public Pieces
{
public:
	char GetSymbol() override;
	void getmovesp1(chessBoard& board1, int currentPlayer);
};

class Knight : public Pieces
{
public:
	char GetSymbol() override;
	void getmovesp1(chessBoard& board1, int currentPlayer);
};

class Bishop : public Pieces
{
public:
	char GetSymbol() override;
	void getmovesp1(chessBoard& board1, int currentPlayer);
};

class Queen : public Pieces
{
public:
	char GetSymbol() override;
	void getmovesp1(chessBoard& board1, int currentPlayer);
};
class King : public Pieces
{
public:
	char GetSymbol() override;
	void getmovesp1(chessBoard& board1, int currentPlayer);
};