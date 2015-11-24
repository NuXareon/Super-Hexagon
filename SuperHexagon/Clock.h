#pragma once
class Clock
{
public:
	explicit Clock(unsigned __int64 startTimeCycles = 0);
	~Clock();
	static void init();
	void update(float dtRealSeconds);
	unsigned __int64 getTimeCycles() const;
	float getDeltaTime() const;
	float getDeltaTime(const Clock* const c) const;
	void setTimeScale(float scale);
	float getTimeScale() const;
	void setPause(bool pause);
	bool isPaused() const;
	static float cyclesToSeconds(unsigned __int64 cycles);
	static inline __int64 secondsToCycles(float seconds);
private:
	unsigned __int64 m_timeCycles;
	float m_timeScale;
	static float s_cyclesPerSecond;
	float m_lastDeltaSeconds;
	bool m_isPaused;
};

