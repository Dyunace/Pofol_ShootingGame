#pragma once
#include "Headers.h"
#include "CursorManager.h"

class LogoImage
{
public:
	LogoImage() {};
	~LogoImage() {};
public:
	void RenderLogoImage(const int _Count)
	{
	if (_Count > 3)
	CursorManager::GetInstance()->WriteBuffer(0,   0,(char*)"¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë");
	if (_Count > 6)
	CursorManager::GetInstance()->WriteBuffer(0,  1, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 9)
	CursorManager::GetInstance()->WriteBuffer(0,  2, (char*)"¢Ë¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¢Ë¢Ë¢Ë¢Ë¡¡¡¡¢Ë");
	if (_Count > 12)
	CursorManager::GetInstance()->WriteBuffer(0,  3, (char*)"¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 15)
	CursorManager::GetInstance()->WriteBuffer(0,  4, (char*)"¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 18)
	CursorManager::GetInstance()->WriteBuffer(0,  5, (char*)"¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 21)
	CursorManager::GetInstance()->WriteBuffer(0,  6, (char*)"¢Ë¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 24)
	CursorManager::GetInstance()->WriteBuffer(0,  7, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 27)
	CursorManager::GetInstance()->WriteBuffer(0,  8, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 30)
	CursorManager::GetInstance()->WriteBuffer(0,  9, (char*)"¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 33)
	CursorManager::GetInstance()->WriteBuffer(0, 10, (char*)"¢Ë¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 36)
	CursorManager::GetInstance()->WriteBuffer(0, 11, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 39)
	CursorManager::GetInstance()->WriteBuffer(0, 12, (char*)"¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë");
	if (_Count > 42)
	CursorManager::GetInstance()->WriteBuffer(0, 13, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 45)
	CursorManager::GetInstance()->WriteBuffer(0, 14, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¢Ë¢Ë¢Ë¢Ë¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 48)
	CursorManager::GetInstance()->WriteBuffer(0, 15, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 51)
	CursorManager::GetInstance()->WriteBuffer(0, 16, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 54)
	CursorManager::GetInstance()->WriteBuffer(0, 17, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 57)
	CursorManager::GetInstance()->WriteBuffer(0, 18, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 60)
	CursorManager::GetInstance()->WriteBuffer(0, 19, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 63)
	CursorManager::GetInstance()->WriteBuffer(0, 20, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 66)
	CursorManager::GetInstance()->WriteBuffer(0, 21, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 69)
	CursorManager::GetInstance()->WriteBuffer(0, 22, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë¢Ë¢Ë¡¡¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¢Ë¡¡¡¡¡¡¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 72)
	CursorManager::GetInstance()->WriteBuffer(0, 23, (char*)"¢Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢Ë");
	if (_Count > 75)
	CursorManager::GetInstance()->WriteBuffer(0, 24, (char*)"¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë¢Ë");

	if (_Count > 78 && TextVisible)
	CursorManager::GetInstance()->WriteBuffer(30, 30, (char*)"Push Enter to Start");

	if (GetTickCount64() % 6 == 0)
		TextToggle();
	}
private:
	bool TextVisible = false;

	void TextToggle()
	{
		TextVisible = !TextVisible;
	}
};