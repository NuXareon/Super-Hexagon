#include "Clock.h"
#include <Windows.h>

float Clock::s_cyclesPerSecond;

Clock::Clock(unsigned __int64 startTimeCycles) :
m_timeCycles(startTimeCycles),
m_timeScale(1.0f),
m_isPaused(false),
m_lastDeltaSeconds(0.0f)
{
}

Clock::~Clock()
{
}

void Clock::init()
{
	LARGE_INTEGER* frequency = new LARGE_INTEGER;
	QueryPerformanceFrequency(frequency);
	s_cyclesPerSecond = static_cast<float>(frequency->QuadPart);
}

void Clock::update(float dt)
{
	if (!m_isPaused)
	{
		m_lastDeltaSeconds = dt * m_timeScale;
		unsigned __int64 dtScaledCycles = secondsToCycles(m_lastDeltaSeconds);
		m_timeCycles += dtScaledCycles;
	}
	else
	{
		m_lastDeltaSeconds = 0.f;
	}
}

unsigned __int64 Clock::getTimeCycles() const
{
	return m_timeCycles;
}

float Clock::getDeltaTime() const
{
	return m_lastDeltaSeconds;
}

float Clock::getDeltaTime(const Clock* const c) const
{
	float cycleDiference = m_timeCycles - c->getTimeCycles();
	return Clock::cyclesToSeconds(cycleDiference);
}

void Clock::setTimeScale(float scale)
{
	m_timeScale = scale;
}

float Clock::getTimeScale() const
{
	return m_timeScale;
}

void Clock::setPause(bool pause)
{
	m_isPaused = pause;
}

bool Clock::isPaused() const
{
	return m_isPaused;
}

float Clock::cyclesToSeconds(unsigned __int64 cycles)
{
	return static_cast<float>(cycles) / s_cyclesPerSecond;
}

__int64 Clock::secondsToCycles(float seconds)
{
	return static_cast<unsigned __int64>(seconds * s_cyclesPerSecond);
}