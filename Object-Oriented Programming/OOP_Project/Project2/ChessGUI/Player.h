#pragma once
class Player
{
public:
	Player() {}
	~Player() {}
	virtual void OnMove() = 0;
	virtual void OnPromote() = 0;
};

