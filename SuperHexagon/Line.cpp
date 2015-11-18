#include "Line.h"

Line::Line(int l, float d, float w = 1.0f) :
m_lane(l),
m_distance(d),
m_width(w)
{
}

Line::~Line()
{
}

void Line::getInfo(float& d, float& w, unsigned __int8& l)
{
	d = m_distance;
	w = m_width;
	l = m_lane;
}