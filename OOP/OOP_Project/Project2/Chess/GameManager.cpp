#include "GameManager.h"

GameManager::GameManager() {
	players = map<Team, Player*>();
	viewer = Viewer(this);
	board = Board(this);
}

GameManager::~GameManager() {
	delete players[Team::White];
	delete players[Team::Black];
}

void GameManager::start() {
	while (true)
	{
		viewer.render_sf();
		start_game(GameMode::p2p);
	}
}

void GameManager::start_game(GameMode mode) {

	board = Board(this);

	if (mode == GameMode::p2p) {
		players[Team::White] = new HumanPlayer(this, "White");
		players[Team::Black] = new HumanPlayer(this, "Black");
	}

	stage = Team::White;
	Team winner;
	while (1) {
		viewer.render_gf();
		
		Move move = players[stage]->OnMove();

		// check win
		if (board.at(move.to) != nullptr && board.at(move.to)->piece_type == PieceType::King) {
			board.move_piece(move);
			viewer.render_gf();
			winner = stage;
			break;
		}

		board.move_piece(move);

		// check promote
		if (board.at(move.to)->piece_type == PieceType::Pawn &&
			board.at(move.to)->position.row == (board.at(move.to)->team == Team::White ? 8 : 1)
			) {
			PieceType promote_to = players[stage]->OnPromote();
			board.at(move.to)->piece_type = promote_to;
			viewer.render_gf();
		}

		// check situation

		stage = (stage == Team::White ? Team::Black : Team::White);
	}
	game_over(winner);
}

void GameManager::game_over(Team win) {
	// load end frame
	// show game result
	viewer.render_ef(players[win]);
}