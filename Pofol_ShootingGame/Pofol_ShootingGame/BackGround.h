#pragma once
#include "Headers.h"

class BackGround
{
public:
	BackGround();
	~BackGround();
private:
	char* Buffer[2];
	char* RandBuffer[3];
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
};

