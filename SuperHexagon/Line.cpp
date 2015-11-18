#include "Line.h"

float Line::s_speed;

Line::Line(int l, float d, float w = 1.0f) :
m_lane(l),
m_distance(d),
m_width(w)
{
}

Line::~Line()
{
}

void Line::setSpeed(float speed)
{
	s_speed = speed;
}

void Line::getInfo(float& d, float& w, unsigned __int8& l) const
{
	d = m_distance;
	w = m_width;
	l = m_lane;
}

float Line::updateDistance(float dt)
{
	m_distance -= s_speed*dt;
	return m_distance;
}

void Line::setDistance(float d)
{
	m_distance = d;
}