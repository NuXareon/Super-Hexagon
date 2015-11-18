#include "RenderManager.h"
#include "GL\freeglut.h"

RenderManager::RenderManager()
{
}


RenderManager::~RenderManager()
{
}

void RenderManager::startUp() {
}

void RenderManager::shutDown() {

}

void RenderManager::render(const Player* p, const vector<Line>& beatmap) const {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// draw player
	float pPos = p->getPosition();
	glBegin(GL_TRIANGLES);
		glVertex3f(pPos-0.1f, 0.f, 0.f);
		glVertex3f(pPos+0.1f, 0.f, 0.f);
		glVertex3f(pPos, 0.2f, 0.f);
	glEnd();
	// drawn lines
	for (Line l : beatmap) {
		float lWidth, lDuration;
		unsigned __int8 lLane;
		l.getInfo(lDuration, lWidth, lLane);
		float lBegin, lEnd;
		float lLaneF = static_cast<float>(lLane);
		float nLanes = static_cast<float>(NUMLANES + 1);
		lBegin = lLaneF / nLanes;
		lEnd = (lLaneF + 1.f) / nLanes;
		glBegin(GL_QUADS);
			glVertex3f(lBegin, lDuration, 0.f);
			glVertex3f(lEnd, lDuration, 0.f);
			glVertex3f(lEnd, lDuration + lWidth, 0.f);
			glVertex3f(lBegin, lDuration + lWidth, 0.f);
		glEnd();
	}
	glutSwapBuffers();
}