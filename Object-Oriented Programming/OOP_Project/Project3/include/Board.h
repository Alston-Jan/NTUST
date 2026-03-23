#pragma once
#include <string>
#include <vector>
#include "Post.h"

using std::string;
using std::vector;

class Board
{
    vector<Post> post_list;

public:
    const string id;

    Board();
    Board(string id);
};
