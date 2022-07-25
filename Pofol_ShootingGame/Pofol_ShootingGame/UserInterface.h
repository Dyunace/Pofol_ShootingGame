#pragma once

class UserInterface
{
public:
	UserInterface() {};
	~UserInterface() {};
public:
	static void MakeUI(float _x, float _y, float _Width, float _Height)
	{
		// 최상/최하단 줄
		for (int i = 0; i < _Width + 2; ++i)
			for (int j = 0; j < 2; ++j)
				CursorManager::GetInstance()->WriteBuffer(_x + (-2) + (2 * i), _y + (-1) + ((_Height + 1) * j), (char*)"##");

		// 가장자리 줄
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < _Height; ++j)
				CursorManager::GetInstance()->WriteBuffer(_x + (-2) + ((_Width * 2 + 2) * i), _y + j, (char*)"##");

		// 중앙 공백
		for (int i = 0; i < _Width; ++i)
			for (int j = 0; j < _Height; ++j)
				CursorManager::GetInstance()->WriteBuffer(_x + (2 * i), _y + j, (char*)"  ");
	}
	
};