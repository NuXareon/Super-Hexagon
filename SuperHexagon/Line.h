#pragma once
class Line
{
public:
	explicit Line(int lane, float dist, float w);
	~Line();
	void getInfo(float& d, float& w, unsigned __int8& l);
private:
	float m_distance;
	float m_width;
	unsigned __int8 m_lane;
};

