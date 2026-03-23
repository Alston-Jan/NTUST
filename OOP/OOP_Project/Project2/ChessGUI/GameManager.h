#pragma once
#include <vector>
#include "Player.h"
#include "Board.h"
#include "Viewer.h"
#include "GameSetting.h"

using std::vector;

class GameManager
{
public:
	
	vector<Player*> players;
	int current_player = 0;
	Board board;
	Viewer viewer;
	GameSetting setting;

	GameManager();
	~GameManager();
    int start();
	void start_game();
	void game_over();
};

