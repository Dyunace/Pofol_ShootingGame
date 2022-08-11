#pragma once
#include "Headers.h"

class UserInterface
{
private:
	static UserInterface* Instance;
public:
	static UserInterface* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new UserInterface;

		return Instance;
	}

private:
	Vector3 UIPos;
private:
	UserInterface();
public:
	~UserInterface();
public:
	void Update();
	void Render();

	void StageInterface();

	void MakeUI(float _x, float _y, float _Width, float _Height);
};