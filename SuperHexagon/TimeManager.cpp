#include "TimeManager.h"
#include <Windows.h>

TimeManager::TimeManager()
{
}

TimeManager::~TimeManager()
{
}

void TimeManager::startUp() 
{
	m_wallClock = new Clock();
	m_gameClock = new Clock();
}

void TimeManager::shutDown()
{

}

void TimeManager::updateClocks()
{
	LARGE_INTEGER queryCounter;
	QueryPerformanceCounter(&queryCounter);
	unsigned __int64 wallClockCounter = m_wallClock->getTimeCycles();
	float deltaTime = Clock::cyclesToSeconds(queryCounter.QuadPart - wallClockCounter);
	m_wallClock->update(deltaTime);
	m_gameClock->update(deltaTime);
}

float TimeManager::getWallClockDeltaSeconds() const
{
	return m_wallClock->getDeltaTime();
}

float TimeManager::getGameClockDeltaSeconds() const
{
	return m_gameClock->getDeltaTime();
}

Clock* TimeManager::getWallClock() const
{
	return m_wallClock;
}

Clock* TimeManager::getGameClock() const
{
	return m_gameClock;
}