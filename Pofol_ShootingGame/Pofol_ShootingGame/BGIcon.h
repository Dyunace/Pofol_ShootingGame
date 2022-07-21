#pragma once
#include "Headers.h"

class BGIcon
{
private:
	char* MyBuffer;
	Transform TransInfo;
	int MoveCount;
	float MoveSpeed;
public:
	BGIcon();
	~BGIcon();
public:
	void setIcon(const int _rand);
	void SetPosition(float _x, float _y);
	void SetPosition(Vector3 _Pos);
	Transform GetPosition() { return TransInfo; }
	void Update();
	void Render();
	void Release();
};