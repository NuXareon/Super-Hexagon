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
	m_beatmap.push_back(Line(0, 0.1f, 0.1f));
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
	float dt = m_Time->getGameClockDeltaSeconds();
	InputDirection direction = m_Input->getDirection();
	m_player.movePlayer(direction, dt);
}

const Player* GameManager::getPlayer() {
	return &m_player;
}

const vector<Line>& GameManager::getBeatmap() {
	return m_beatmap;
}