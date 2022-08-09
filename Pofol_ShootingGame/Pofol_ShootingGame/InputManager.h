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
	int InputDelay;

public:
	DWORD GetKey() const { return Key; }

	int GetInputDelay() const { return InputDelay; }
	void SetInputDelay(int _Delay = 3) { InputDelay = _Delay; }
	void MinusInputDelay() { --InputDelay; }

public:
	void InputKey();
};

