#include "LogoImage.h"

LogoImage* LogoImage::Instance = nullptr;
LogoImage::LogoImage() {}
LogoImage::~LogoImage() {}

void LogoImage::RenderLogoImage(const int _Count)
{
	// 테두리 없애기 + 로고 이미지 아래로 내리기 -> 참고할 것

	if (_Count > 3)		CursorManager::GetInstance()->WriteBuffer(20, 4 + 2, (char*)"                                     /\\\\");
	if (_Count > 6)		CursorManager::GetInstance()->WriteBuffer(20, 5 + 2, (char*)"       /\\\\                           /\\\\");
	if (_Count > 9)		CursorManager::GetInstance()->WriteBuffer(20, 6 + 2, (char*)" /\\\\\\\\ /\\\\        /\\\\       /\\\\    /\\/\\ /\\");
	if (_Count > 12)	CursorManager::GetInstance()->WriteBuffer(20, 7 + 2, (char*)"/\\\\    /\\ /\\    /\\\\  /\\\\  /\\\\  /\\\\   /\\\\");
	if (_Count > 15)	CursorManager::GetInstance()->WriteBuffer(20, 8 + 2, (char*)"  /\\\\\\ /\\\\  /\\\\/\\\\    /\\\\/\\\\    /\\\\  /\\\\");
	if (_Count > 18)	CursorManager::GetInstance()->WriteBuffer(20, 9 + 2, (char*)"    /\\\\/\\   /\\\\ /\\\\  /\\\\  /\\\\  /\\\\   /\\\\");
	if (_Count > 21)	CursorManager::GetInstance()->WriteBuffer(20, 10 + 2, (char*)"/\\\\ /\\\\/\\\\  /\\\\   /\\\\       /\\\\       /\\\\");
	if (_Count > 24)	CursorManager::GetInstance()->WriteBuffer(25, 11 + 2, (char*)"");
	if (_Count > 27)	CursorManager::GetInstance()->WriteBuffer(25, 12 + 2, (char*)"         /\\\\");
	if (_Count > 30)	CursorManager::GetInstance()->WriteBuffer(25, 13 + 2, (char*)"         /\\\\");
	if (_Count > 33)	CursorManager::GetInstance()->WriteBuffer(25, 14 + 2, (char*)" /\\\\\\\\ /\\/\\ /\\   /\\\\    /\\ /\\\\\\");
	if (_Count > 36)	CursorManager::GetInstance()->WriteBuffer(25, 15 + 2, (char*)"/\\\\      /\\\\   /\\\\  /\\\\  /\\\\");
	if (_Count > 39)	CursorManager::GetInstance()->WriteBuffer(25, 16 + 2, (char*)"  /\\\\\\   /\\\\  /\\\\   /\\\\  /\\\\");
	if (_Count > 42)	CursorManager::GetInstance()->WriteBuffer(25, 17 + 2, (char*)"    /\\\\  /\\\\  /\\\\   /\\\\  /\\\\");
	if (_Count > 45)	CursorManager::GetInstance()->WriteBuffer(25, 18 + 2, (char*)"/\\\\ /\\\\   /\\\\   /\\\\ /\\\\\\/\\\\\\");

	// 가운데 텍스트
	if (_Count > 48 && TextVisible)
		CursorManager::GetInstance()->WriteBuffer(30, 30, (char*)"Push Enter to Start");

	if (_Count % 6 == 0)
		TextToggle();
}
