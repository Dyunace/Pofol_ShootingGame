#pragma once
#include "Headers.h"

class BGIcon;
class BackGround
{
private:
	static BackGround* Instance;
	list<BGIcon*> BGIconList;
public:
	static BackGround* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new BackGround;

		return Instance;
	}
private:
	BackGround();
public:
	~BackGround();
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
public:
	void MakeBG();
};

