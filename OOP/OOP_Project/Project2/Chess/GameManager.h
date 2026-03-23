#pragma once
#include <map>
#include "Player.h"
#include "Board.h"
#include "Viewer.h"
#include "GameSetting.h"

using std::map;

enum class GameMode {
	p2p,
	p2a
};

class GameManager
{
public:
	
	map<Team, Player*> players;
	int current_player = 0;
	Board board;
	Viewer viewer;
	GameSetting setting;
	Team stage;

	GameManager();
	~GameManager();
	void start();
	void start_game(GameMode);
	void game_over(Team);
};

