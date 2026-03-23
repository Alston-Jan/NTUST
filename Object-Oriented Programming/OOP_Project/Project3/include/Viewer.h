#pragma once

class BoardManager;

class Viewer
{
    BoardManager &board_manager;

public:
    Viewer();
    Viewer(BoardManager *);
    void render_menu();
    void render_board_list();
    void render_login_success();
    void render_login_fail();
};
