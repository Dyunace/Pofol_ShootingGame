#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : Key(0)
{

}

InputManager::~InputManager()
{

}

void InputManager::InputKey()
{
	Key = 0;

	if (GetAsyncKeyState(VK_UP))
		Key |= KEY_UP;

	if (GetAsyncKeyState(VK_DOWN))
		Key |= KEY_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		Key |= KEY_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		Key |= KEY_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		Key |= KEY_SPACE;

	if (GetAsyncKeyState(VK_RETURN))
		Key |= KEY_ENTER;

	if (GetAsyncKeyState(VK_CONTROL))
		Key |= KEY_CTRL;

	if (GetAsyncKeyState(VK_MENU))
		Key |= KEY_ALT;

	if (GetAsyncKeyState(VK_TAB))
		Key |= KEY_TAB;

	if (GetAsyncKeyState(VK_ESCAPE))
		Key |= KEY_ESC;

	if (GetAsyncKeyState('F'))
		Key |= KEY_F;

	if (GetAsyncKeyState('D'))
		Key |= KEY_D;
}

