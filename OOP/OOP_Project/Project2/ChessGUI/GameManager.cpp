#include "GameManager.h"

GameManager::GameManager() {
	players = vector<Player*>(2);
	viewer = Viewer(this);
	board = Board();
}

GameManager::~GameManager() {
	delete players[0];
	delete players[1];
}

int GameManager::start() {
	// load main frame
    int argc = 0;
    char *argv[] = {};
    QApplication a(argc,argv);
    ChessGUI w;
    w.show();
    return a.exec();
    //return viewer.start();
}

void GameManager::start_game() {
	// start game loop
	// load game frame
	viewer.render_board();
}

void GameManager::game_over() {
	// load end frame
	// show game result
}
