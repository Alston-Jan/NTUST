#pragma once
#include "Player.h"

class GameManager;

class Viewer
{
	GameManager * game_manager;

public:
	
	Viewer(); // not allow
	Viewer(GameManager*);
	~Viewer();

	void clear();
	void reset();

	void render_sf();
	void render_gf();
	void render_ef(Player*);

	void render_board();
	void render_game_status();

	Move get_move();
	PieceType ask_promote();
};

