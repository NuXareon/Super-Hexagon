#pragma once
#include <vector>
#include "Line.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
using namespace std;

class GameManager
{
public:
	GameManager();
	~GameManager();
	void startUp(InputManager* input, TimeManager* time);
	void shutDown();
	void run();
	const Player& getPlayer() const;
	const vector<Line>& getBeatmap() const;
private:
	vector<Line> m_beatmap;	// change to std::list
	Player m_player;
	InputManager* m_Input;
	TimeManager* m_Time;

	void checkCollisionKill(unsigned __int8 lane);
	void checkLateralCollision(unsigned __int8 lane, float width, float distance, float oldPlayerPos, float playerWidth);
};

