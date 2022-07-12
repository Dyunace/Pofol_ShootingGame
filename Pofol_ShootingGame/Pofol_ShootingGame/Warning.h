#pragma once
#include "Headers.h"

// 기존 화면 위에 띄우기 위해서 Scene에 자식 클래스로 추가하지 않음

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
private:
	Warning();
public:
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

