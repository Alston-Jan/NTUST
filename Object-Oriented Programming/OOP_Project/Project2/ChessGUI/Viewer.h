#pragma once
#include <QApplication>
#include "chessgui.h"

class GameManager;

class Viewer
{
	GameManager * game_manager;
    QApplication a;
    ChessGUI w;

public:
	
	Viewer(); // not allow
	Viewer(GameManager*);
	~Viewer();

    int start();
	void render_board();
	void render_main();
};

