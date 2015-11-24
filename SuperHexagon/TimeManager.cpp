#include "TimeManager.h"
#include <Windows.h>

TimeManager::TimeManager() :
m_pauseTime(-0.f)
{
}

TimeManager::~TimeManager()
{
}

void TimeManager::startUp()
{
	LARGE_INTEGER queryCounter;
	QueryPerformanceCounter(&queryCounter);
	m_wallClock = new Clock(queryCounter.QuadPart);
	m_gameClock = new Clock(queryCounter.QuadPart);
	m_pauseClock = new Clock(queryCounter.QuadPart);
	m_pauseClock->setPause(true);
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
	m_pauseClock->update(deltaTime);
	if (m_pauseTime > 0.f && m_pauseClock->getDeltaTime(m_gameClock) >= m_pauseTime) {
		m_gameClock->setPause(false);
		m_pauseClock->setPause(true);
		m_pauseTime = 0.f;
	}
}

void TimeManager::pauseGameClock(float t) {
	m_gameClock->setPause(true);
	if (t > 0.f) {
		m_pauseClock = new Clock(m_gameClock->getTimeCycles());
		m_pauseTime = t;
	}
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

Clock* TimeManager::getPauseClock() const
{
	return m_pauseClock;
}