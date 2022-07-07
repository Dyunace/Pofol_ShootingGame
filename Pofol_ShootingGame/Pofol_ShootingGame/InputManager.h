#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;

		return Instance;
	}
private:
	InputManager();
public:
	~InputManager();
private:
	DWORD Key;
public:
	DWORD GetKey() const { return Key; }
	void InputKey();
};

