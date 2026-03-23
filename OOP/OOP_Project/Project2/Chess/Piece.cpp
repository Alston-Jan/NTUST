#include <stdexcept>
#include "Piece.h"

Position::Position() {
	row = 0;
	col = 0;
}

Position::Position(int _row, int _col) {
	row = _row;
	col = _col;
}

Piece::Piece() {
	throw std::logic_error{ "Not allow" };
}

Piece::Piece(Team _team,PieceType type, Position pos) {
	team = _team;
	piece_type = type;
	position = pos;
}