#pragma once
#include <vector>
#include "Player.h"
#include "Line.h"
using namespace std;

class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	void startUp();
	void shutDown();
	void render(const Player& p, const vector<Line>& beatmap) const;
private:
};

