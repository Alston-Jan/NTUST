#include "User.h"

User::User(string user_id, string pass, Privilege pri) : id(user_id),
                                                         passwd(pass),
                                                         privilege(pri) {}
