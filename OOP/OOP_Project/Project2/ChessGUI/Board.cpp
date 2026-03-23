#include "Board.h"

Board::Board() {

	Team team = Team::White;

	pieces[team].push_back(Piece(team, PieceType::King, Position(1, 5)));
	pieces[team].push_back(Piece(team, PieceType::Queen, Position(1, 4)));
	pieces[team].push_back(Piece(team, PieceType::Bishop, Position(1, 3)));
	pieces[team].push_back(Piece(team, PieceType::Bishop, Position(1, 6)));
	pieces[team].push_back(Piece(team, PieceType::Knight, Position(1, 2)));
	pieces[team].push_back(Piece(team, PieceType::Knight, Position(1, 7)));
	pieces[team].push_back(Piece(team, PieceType::Rook, Position(1, 1)));
	pieces[team].push_back(Piece(team, PieceType::Rook, Position(1, 8)));

	team = Team::Black;

	pieces[team].push_back(Piece(team, PieceType::King, Position(8, 5)));
	pieces[team].push_back(Piece(team, PieceType::Queen, Position(8, 4)));
	pieces[team].push_back(Piece(team, PieceType::Bishop, Position(8, 3)));
	pieces[team].push_back(Piece(team, PieceType::Bishop, Position(8, 6)));
	pieces[team].push_back(Piece(team, PieceType::Knight, Position(8, 2)));
	pieces[team].push_back(Piece(team, PieceType::Knight, Position(8, 7)));
	pieces[team].push_back(Piece(team, PieceType::Rook, Position(8, 1)));
	pieces[team].push_back(Piece(team, PieceType::Rook, Position(8, 8)));

	for (int i = 1; i <= 8; i++) {
		pieces[Team::White].push_back(Piece(Team::White, PieceType::Pawn, Position(2, i)));
		pieces[Team::Black].push_back(Piece(Team::Black, PieceType::Pawn, Position(7, i)));
	}

}