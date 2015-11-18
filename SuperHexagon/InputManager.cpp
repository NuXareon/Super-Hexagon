#include <iostream>
#include "InputManager.h"
#include "GL\freeglut.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::startUp() 
{
	m_direction = STOP;
}

void InputManager::shutDown() 
{

}

void InputManager::keyboardInput(unsigned char key, int x, int y)
{
	if (key == 27) exit(0);
	if (key == 'd' || key == 'D') m_direction = RIGHT;
	else if (key == 'a' || key == 'A') m_direction = LEFT;
}

void InputManager::keyboardInputSpecial(int key, int x, int y) 
{
	if (key == GLUT_KEY_RIGHT) m_direction = RIGHT;
	else if (key == GLUT_KEY_LEFT) m_direction = LEFT;
}

void InputManager::keyboardInputUp(unsigned char key, int x, int y) 
{
	if ((key == 'd' || key == 'D') && m_direction == RIGHT) m_direction = STOP;
	else if ((key == 'a' || key == 'A') && m_direction == LEFT) m_direction = STOP;
}

void InputManager::keyboardInputSpecialUp(int key, int x, int y) 
{
	if ((key == GLUT_KEY_RIGHT) && m_direction == RIGHT) m_direction = STOP;
	else if ((key == GLUT_KEY_LEFT) && m_direction == LEFT) m_direction = STOP;
}

InputDirection InputManager::getDirection() const
{
	return m_direction;
}