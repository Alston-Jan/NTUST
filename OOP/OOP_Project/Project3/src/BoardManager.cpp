#include "BoardManager.h"

BoardManager::BoardManager() : viewer(this)
{
    user_list.push_back(Admin("root", "root"));
    board_list.push_back(Board("hello_world"));
}

void BoardManager::start()
{
    viewer.render_menu();
}

void BoardManager::login(string user_id, string passwd)
{
    bool valid = false;
    for (auto &user : user_list)
    {
        if (user.verify(user_id, passwd))
        {
            valid = true;
            current_user = &user;
        }
    }
    if (valid)
    {
        viewer.render_login_success();
        viewer.render_board_list();
    }
    else
    {
        viewer.render_login_fail();
        viewer.render_menu();
    }
}
