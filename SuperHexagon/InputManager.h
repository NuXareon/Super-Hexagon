#pragma once
enum InputDirection : __int8 {STOP, RIGHT, LEFT};

class InputManager
{
public:
	InputManager();
	~InputManager();
	void startUp();
	void shutDown();
	void keyboardInput(unsigned char key, int x, int y);
	void keyboardInputSpecial(int key, int x, int y);
	void keyboardInputUp(unsigned char key, int x, int y);
	void keyboardInputSpecialUp(int key, int x, int y);
	InputDirection getDirection() const;
private:
	InputDirection m_direction;
};