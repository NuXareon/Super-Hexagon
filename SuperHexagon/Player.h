#pragma once
#include "InputManager.h"

#define NUMLANES 5

class Player
{
public:
	Player();
	~Player();
	float getPosition() const;
	void movePlayer(InputDirection dir, float dt);
private:
	float m_speed;
	float m_position;
	unsigned __int8 m_lane;
};

