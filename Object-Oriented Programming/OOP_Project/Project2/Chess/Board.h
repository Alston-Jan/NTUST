#pragma once
#include <map>
#include <vector>
#include "Piece.h"

using std::map;
using std::vector;

struct Move
{
	Position from;
	Position to;

	Move(Position f, Position t) {
		from = f;
		to = t;
	}

};

class GameManager;

class Board
{
	GameManager* game_manager;
public:
	map<Team, vector< Piece>> pieces;

	Board() {};
	Board(GameManager*);
	
	Piece* at(Position);
	void kill(Piece*);

	bool validate_move(Move);
	void move_piece(Move);
};

