#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Board.h"
#include "Viewer.h"

using std::string;
using std::vector;

class BoardManager
{
    vector<User> user_list;
    vector<Board> board_list;
    Viewer viewer;
    User *current_user;

public:
    BoardManager();

    inline const vector<Board> &get_board_list() { return board_list; }

    void start();
    void login(string user_id, string password);
};
