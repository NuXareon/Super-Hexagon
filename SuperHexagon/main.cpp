#include "GL\freeglut.h"
#include "RenderManager.h"
#include "GameManager.h"
#include "InputManager.h"
#include "TimeManager.h"
using namespace std;

InputManager gInputManager;
TimeManager gTimeManager;
GameManager gGameManager;
RenderManager gRenderManager;

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
}

// Wrapper for the Keyboard functions callback
void keyboardFuncWrapper(unsigned char key, int x, int y) {
	gInputManager.keyboardInput(key, x, y);
}

void keyboardFuncWrapper(int key, int x, int y) {
	gInputManager.keyboardInputSpecial(key, x, y);
}

void keyboardUpFuncWrapper(unsigned char key, int x, int y) {
	gInputManager.keyboardInputUp(key, x, y);
}

void keyboardUpFuncWrapper(int key, int x, int y) {
	gInputManager.keyboardInputSpecialUp(key, x, y);
}

//Wrapper for the idle function callback
void idleFuncWrapper() {
	gTimeManager.updateClocks();
	gGameManager.run();
	glutPostRedisplay();	
}

// Wrapper for the display function callback
void renderFuncWrapper() {
	gRenderManager.render(gGameManager.getPlayer(), gGameManager.getBeatmap());
}

int main(int argcp, char *argv[]) {
	// Initializing sub-systems
	// Window system init
	glutInit(&argcp, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(150, 60);
	glutInitWindowSize(1600, 900);
	glutCreateWindow("Super Hexagon");
	glutReshapeFunc(reshape);
	// Set up input management
	gInputManager.startUp();
	glutKeyboardFunc(keyboardFuncWrapper);
	glutSpecialFunc(keyboardFuncWrapper);
	glutKeyboardUpFunc(keyboardUpFuncWrapper);
	glutSpecialUpFunc(keyboardUpFuncWrapper);
	// Set up time management
	Clock::init();
	gTimeManager.startUp();
	// Set up game logic sub-system
	Line::setSpeed(0.5f);
	gGameManager.startUp(&gInputManager, &gTimeManager);
	glutIdleFunc(idleFuncWrapper);
	// Set up render sub-system
	gRenderManager.startUp();
	glutDisplayFunc(renderFuncWrapper);
	// Entering game loop
	glutMainLoop();
	// Note: we can return here using glutLeaveMainLoop()
}