#pragma once
#include "Headers.h"

class Warning
{
private:
	static Warning* Instance;
public:
	static Warning* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Warning;

		return Instance;
	}
public:
	Warning();
	~Warning();
public:
	void SetWarning(WARNING _State);
	int Update();
	void Render();
	void Release();
private:
	int State;
	int Selection;
	void MakeBorder();
};

