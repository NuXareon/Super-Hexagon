#include "Player.h"


Player::Player() :
m_speed(1.5f),
m_lane(0),
m_position(0.0f)
{
}


Player::~Player()
{
}

float Player::getPosition() const 
{
	return m_position;
}

void Player::movePlayer(InputDirection dir, float dt) 
{
	if (dir == RIGHT) m_position += m_speed*dt;
	else if (dir == LEFT) m_position -= m_speed*dt;
	if (m_position > 1.0f) m_position -= 1.0f;
	if (m_position < 0.0f) m_position += 1.0f;
}