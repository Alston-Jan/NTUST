#include <cmath>
#include "Board.h"
#include "GameManager.h"

using std::max;
using std::min;

Board::Board(GameManager* gm) {

	game_manager = gm;

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

Piece* Board::at(Position pos) {

	for (auto& team : pieces) {
		for (auto& p : team.second) {
			if (p.position == pos)
				return &p;
		}
	}
	return nullptr;
}

bool Board::validate_move(Move move) {
	Piece* piece = at(move.from);
	if (piece == nullptr || move.from == move.to)return false;
	if (piece->team != game_manager->stage)return false;
	if (at(move.to) != nullptr && piece->team == at(move.to)->team)
		return false;


	if (piece->piece_type==PieceType::Pawn) {

		// first move
		if ((piece->team == Team::White && piece->position.row == 2 &&
			move.from.col == move.to.col && move.to.row == 4 &&
			at(Position(3, piece->position.col)) == nullptr &&
			at(Position(4, piece->position.col)) == nullptr
			) ||
			(piece->team == Team::Black && piece->position.row == 7 &&
				move.from.col == move.to.col && move.to.row == 5 &&
				at(Position(6, piece->position.col)) == nullptr &&
				at(Position(5, piece->position.col)) == nullptr
				)
			) return true;
		
		// passant capturing
		
		// eat other
		if ((piece->team == Team::White &&
			move.to.row - move.from.row == 1 &&
			abs(move.to.col - move.from.col) == 1) &&
			at(move.to) != nullptr ||
			(piece->team == Team::Black &&
				move.to.row - move.from.row == -1 &&
				abs(move.to.col - move.from.col) == 1 &&
				at(move.to) != nullptr)
			)return true;
		
		// normal
		if ((piece->team == Team::White &&
			move.from.col == move.to.col &&
			move.to.row == move.from.row + 1 &&
			at(move.to) == nullptr) ||
			(piece->team == Team::Black &&
				move.from.col == move.to.col &&
				move.to.row == move.from.row - 1 &&
				at(move.to) == nullptr))return true;
	}
	else if (piece->piece_type == PieceType::Rook) {
		if (move.from.col == move.to.col) {
			for (int i = min(move.from.row + 1, move.to.row + 1);
				i != max(move.to.row, move.from.row);
				i++
				) {
				if (at(Position(i, move.from.col)) != nullptr)return false;
			}
			return true;
		}
		if (move.from.row == move.to.row) {
			for (int i = min(move.from.col + 1, move.to.col + 1);
				i != max(move.to.col, move.from.col);
				i++
				) {
				if (at(Position(move.from.row, i)) != nullptr)return false;
			}
			return true;
		}
	}
	else if (piece->piece_type == PieceType::Knight) {
		if ((abs(move.to.col - move.from.col) == 2 &&
			abs(move.to.row - move.from.row) == 1) ||
			(abs(move.to.col - move.from.col) == 1 &&
				abs(move.to.row - move.from.row) == 2)
			)return true;
	}
	else if (piece->piece_type == PieceType::Bishop) {
		if (abs(move.to.col - move.from.col) == abs(move.to.row - move.from.row)) {
			Position start, end;
			if (move.to.row > move.from.row) {
				start = move.from;
				end = move.to;
			}
			else {
				start = move.to;
				end = move.from;
			}
			int col_unit = abs(end.col - start.col) / (end.col - start.col);
			for (int i = start.row + 1,
				j = start.col + col_unit;
				i != end.row;
				i++, j += col_unit
				) {
				if (at(Position(i, j)) != nullptr)return false;
			}
			return true;
		}
	}
	else if (piece->piece_type == PieceType::Queen) {
		if (move.from.col == move.to.col) {
			for (int i = min(move.from.row + 1, move.to.row + 1);
				i != max(move.to.row, move.from.row);
				i++
				) {
				if (at(Position(i, move.from.col)) != nullptr)return false;
			}
			return true;
		}
		if (move.from.row == move.to.row) {
			for (int i = min(move.from.col + 1, move.to.col + 1);
				i != max(move.to.col, move.from.col);
				i++
				) {
				if (at(Position(move.from.row, i)) != nullptr)return false;
			}
			return true;
		}
		if (abs(move.to.col - move.from.col) == abs(move.to.row - move.from.row)) {
			Position start, end;
			if (move.to.row > move.from.row) {
				start = move.from;
				end = move.to;
			}
			else {
				start = move.to;
				end = move.from;
			}
			int col_unit = abs(end.col - start.col) / (end.col - start.col);
			for (int i = start.row + 1,
				j = start.col + col_unit;
				i != end.row;
				i++, j += col_unit
				) {
				if (at(Position(i, j)) != nullptr)return false;
			}
			return true;
		}
	}
	else if (piece->piece_type == PieceType::King) {
		// castling
		// normal
		if (abs(move.to.row - move.from.row) <= 1 &&
			abs(move.to.col - move.from.col) <= 1
			)return true;
	}

	return false;
}

void Board::move_piece(Move move) {
	if (at(move.to) != nullptr)kill(at(move.to));
	at(move.from)->position = move.to;
}

void Board::kill(Piece* killee) {
	for (int i = 0; i < pieces[killee->team].size();i++){
		if (&pieces[killee->team][i] == killee) {
			pieces[killee->team].erase(
				pieces[killee->team].begin() + i
			);
		}
	}
}