#include "Player.h"


Player::Player() :
m_speed(1.0f),
m_position(0.1f),
m_width(0.02f),
m_height(0.06f)
{
}


Player::~Player()
{
}

float Player::getPosition() const 
{
	return m_position;
}

void Player::setPosition(float p)
{
	m_position = p;
}

void Player::getDimensions(float& w, float& h) const
{
	w = m_width;
	h = m_height;
}

void Player::movePlayer(InputDirection dir, float dt) 
{
	if (dir == RIGHT) m_position += m_speed*dt;
	else if (dir == LEFT) m_position -= m_speed*dt;
	if (m_position > 1.0f) m_position -= 1.0f;
	if (m_position < 0.0f) m_position += 1.0f;
}