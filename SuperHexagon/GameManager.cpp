#include "GameManager.h"


GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::startUp(InputManager* input, TimeManager* time) {
	m_Input = input;
	m_Time = time;
	m_beatmap.push_back(Line(1, 0.1f, 0.1f));
	m_beatmap.push_back(Line(3, 0.1f, 0.1f));
	m_beatmap.push_back(Line(2, 0.3f, 0.1f));
	m_beatmap.push_back(Line(4, 0.3f, 0.1f));
	m_beatmap.push_back(Line(0, 0.7f, 0.3f));
	m_beatmap.push_back(Line(1, 0.7f, 0.3f));
	m_beatmap.push_back(Line(4, 0.7f, 0.3f));
	m_beatmap.push_back(Line(2, 0.7f, 0.3f));
	m_beatmap.push_back(Line(5, 0.7f, 0.3f));
}

void GameManager::shutDown() {

}

void GameManager::run() {
	float pWidht, pHeight;
	float dt = m_Time->getGameClockDeltaSeconds();
	float oldPos = m_player.getPosition();
	InputDirection direction = m_Input->getDirection();
	m_player.movePlayer(direction, dt);
	m_player.getDimensions(pWidht, pHeight);
	for (Line& l : m_beatmap)
	{
		float d0, width;
		unsigned __int8 lane;
		l.getInfo(d0, width, lane);
		float d1 = l.updateDistance(dt);
		if (d0 > pHeight-0.04 && d1 <= pHeight-0.04) checkCollisionKill(lane);
		else if (d1 <= pHeight-0.04) checkLateralCollision(lane, width, d1, oldPos, pWidht);

		if (d1 < -0.1f) l.setDistance(1.f); // temporal cyclic beatmap
	}
}

void GameManager::checkLateralCollision(unsigned __int8 l, float w, float d, float oldPos, float playerWidth) { // add player width
	float lLaneF = static_cast<float>(l);
	float nLanes = static_cast<float>(NUMLANES + 1);
	float lBegin = lLaneF / nLanes;
	float lEnd = (lLaneF + 1.f) / nLanes;
	float pPos = m_player.getPosition();
	if (d + w >= 0.f) {
		if (pPos + playerWidth > lBegin && pPos - playerWidth < lEnd) {
			if (oldPos <= (lBegin + lEnd) / 2.f) {
				m_player.setPosition(lBegin - playerWidth);
			}
			else if (oldPos > (lBegin + lEnd) / 2.f) {
				m_player.setPosition(lEnd + playerWidth);
			}
			else {
			}
		}
	}

}

void GameManager::checkCollisionKill(unsigned __int8 l) {
	float lLaneF = static_cast<float>(l);
	float nLanes = static_cast<float>(NUMLANES + 1);
	float lBegin = lLaneF / nLanes;
	float lEnd = (lLaneF + 1.f) / nLanes;
	float pPos = m_player.getPosition();
	if (pPos > lBegin && pPos < lEnd) 
	{
		m_Time->pauseGameClock(1.0f);
	}
}

const Player& GameManager::getPlayer() const {
	return m_player;
}

const vector<Line>& GameManager::getBeatmap() const {
	return m_beatmap;
}