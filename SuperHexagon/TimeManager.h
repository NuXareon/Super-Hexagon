#pragma once
#include "Clock.h"

class TimeManager
{
public:
	TimeManager();
	~TimeManager();
	void startUp();
	void shutDown();
	void updateClocks();
	void pauseGameClock(float t = 0.f);
	float getWallClockDeltaSeconds() const;
	float getGameClockDeltaSeconds() const;
	Clock* getWallClock() const;
	Clock* getGameClock() const;
	Clock* getPauseClock() const;
private:
	Clock* m_wallClock;
	Clock* m_gameClock;
	Clock* m_pauseClock;

	float m_pauseTime;
};

