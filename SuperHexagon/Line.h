#pragma once
class Line
{
public:
	explicit Line(int lane, float dist, float w);
	~Line();
	static void setSpeed(float speed);
	float updateDistance(float dt);
	void setDistance(float d);
	void getInfo(float& d, float& w, unsigned __int8& l) const;
private:
	float m_distance;
	float m_width;
	static float s_speed;
	unsigned __int8 m_lane;
};

