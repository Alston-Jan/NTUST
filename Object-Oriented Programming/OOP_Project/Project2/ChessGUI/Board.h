#pragma once
#include <map>
#include <vector>
#include "Piece.h"

using std::map;
using std::vector;

class Board
{
public:
	map<Team, vector< Piece>> pieces;

	Board();
};

