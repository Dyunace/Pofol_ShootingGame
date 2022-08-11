#include "LogoImage.h"

LogoImage* LogoImage::Instance = nullptr;
LogoImage::LogoImage() {}
LogoImage::~LogoImage() {}

void LogoImage::RenderLogoImage(const int _Count)
{
	// �׵θ� ���ֱ� + �ΰ� �̹��� �Ʒ��� ������ -> ������ ��

	if (_Count > 3)		CursorManager::GetInstance()->WriteBuffer(20, 6, (char*)"                                     /\\\\");
	if (_Count > 6)		CursorManager::GetInstance()->WriteBuffer(20, 7, (char*)"       /\\\\                           /\\\\");
	if (_Count > 9)		CursorManager::GetInstance()->WriteBuffer(20, 8, (char*)" /\\\\\\\\ /\\\\        /\\\\       /\\\\    /\\\\\\\\\\\\");
	if (_Count > 12)	CursorManager::GetInstance()->WriteBuffer(20, 9, (char*)"/\\\\    /\\\\\\\\    /\\\\  /\\\\  /\\\\  /\\\\   /\\\\");
	if (_Count > 15)	CursorManager::GetInstance()->WriteBuffer(20, 10, (char*)"  /\\\\\\ /\\\\ /\\\\ /\\\\    /\\\\/\\\\    /\\\\  /\\\\");
	if (_Count > 18)	CursorManager::GetInstance()->WriteBuffer(20, 11, (char*)"    /\\\\/\\\\  /\\\\ /\\\\  /\\\\  /\\\\  /\\\\   /\\\\");
	if (_Count > 21)	CursorManager::GetInstance()->WriteBuffer(20, 12, (char*)"/\\\\ /\\\\/\\\\  /\\\\   /\\\\       /\\\\       /\\\\");
	if (_Count > 24)	CursorManager::GetInstance()->WriteBuffer(25, 13, (char*)"");
	if (_Count > 27)	CursorManager::GetInstance()->WriteBuffer(25, 14, (char*)"         /\\\\");
	if (_Count > 30)	CursorManager::GetInstance()->WriteBuffer(25, 15, (char*)"         /\\\\");
	if (_Count > 33)	CursorManager::GetInstance()->WriteBuffer(25, 16, (char*)" /\\\\\\\\  /\\\\\\\\\\   /\\\\     /\\\\ /\\\\\\");
	if (_Count > 36)	CursorManager::GetInstance()->WriteBuffer(25, 17, (char*)"/\\\\      /\\\\   /\\\\  /\\\\    /\\\\");
	if (_Count > 39)	CursorManager::GetInstance()->WriteBuffer(25, 18, (char*)"  /\\\\\\   /\\\\  /\\\\    /\\\\   /\\\\");
	if (_Count > 42)	CursorManager::GetInstance()->WriteBuffer(25, 19, (char*)"    /\\\\  /\\\\  /\\\\   /\\\\    /\\\\");
	if (_Count > 45)	CursorManager::GetInstance()->WriteBuffer(25, 20, (char*)"/\\\\ /\\\\   /\\\\    /\\\\ /\\\\\\ /\\\\\\");

	// ��� �ؽ�Ʈ
	if (_Count > 48 && TextVisible)
		CursorManager::GetInstance()->WriteBuffer(25, 30, (char*)"Press \"F\" or \"Space Bar\" for Start");

	if (_Count % 6 == 0)
		TextToggle();
}
