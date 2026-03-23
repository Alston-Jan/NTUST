#pragma once
#include <string>
#include "Board.h"

using std::string;

class GameManager;

class Player
{
public:

	string name;
	GameManager* game_manager;

	Player() {}
	Player(GameManager* gm) { game_manager = gm; }
	~Player() {}
	virtual Move OnMove() = 0;
	virtual PieceType OnPromote() = 0;
};


class HumanPlayer :public Player {
public:
	HumanPlayer(GameManager*, string);
	Move OnMove() override;
	PieceType OnPromote() override;
};
