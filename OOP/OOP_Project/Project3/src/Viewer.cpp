#include <iostream>
#include <string>
#include "Viewer.h"
#include "BoardManager.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Viewer::Viewer(BoardManager *bm) : board_manager(*bm)
{
}

void Viewer::render_menu()
{
    string username, password;
    cout << "Enter user id: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    board_manager.login(username, password);
}

void Viewer::render_login_success()
{
    cout << "Login success!" << endl;
}

void Viewer::render_login_fail()
{
    cout << "Login failed." << endl;
}

void Viewer::render_board_list()
{
    cout << endl
         << "Board List" << endl
         << "==========" << endl;
    for (auto &board : board_manager.get_board_list())
    {
        cout << board.id << endl;
    }
}
