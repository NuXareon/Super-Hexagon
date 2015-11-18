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
	float getWallClockDeltaSeconds() const;
	float getGameClockDeltaSeconds() const;
	Clock* getWallClock() const;
	Clock* getGameClock() const;
private:
	Clock* m_wallClock;
	Clock* m_gameClock;
};

