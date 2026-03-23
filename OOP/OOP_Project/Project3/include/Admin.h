#pragma once
#include "User.h"

class Admin : public User
{
public:
    Admin(string user_id, string password) : User(user_id, password, Privilege::Admin){};
};
