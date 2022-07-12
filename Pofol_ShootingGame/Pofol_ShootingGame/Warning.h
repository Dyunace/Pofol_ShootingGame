#pragma once
#include "Headers.h"

// ���� ȭ�� ���� ���� ���ؼ� Scene�� �ڽ� Ŭ������ �߰����� ����

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

