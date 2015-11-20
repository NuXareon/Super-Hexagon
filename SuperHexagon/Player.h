#pragma once
#include "InputManager.h"

#define NUMLANES 5

class Player
{
public:
	Player();
	~Player();
	float getPosition() const;
	void getDimensions(float& w, float& h) const;
	void movePlayer(InputDirection dir, float dt);
private:
	float m_speed;
	float m_position;
	float m_width;		// distance from the middle of the player to one side, total width = 2*m_width
	float m_height;		// distance from the base of the player to the top
};

