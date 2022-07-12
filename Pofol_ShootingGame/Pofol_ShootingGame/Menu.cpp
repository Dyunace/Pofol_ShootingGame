#include "Menu.h"
#include "LogoImage.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Warning.h"

Menu::Menu() : Selection(0), isWarning(false) {}
Menu::Menu(string* _str){}
Menu::~Menu(){}

void Menu::Initialize()
{
	Selection = 0;
	isWarning = false;
}

void Menu::Update()
{
	// 경고창 체크
	if (isWarning)
	{
		int warning = Warning::GetInstance()->Update();
		if (warning == 1)
			isWarning = false;
	}
	else
	{
		// 선택지 위로
		if (InputManager::GetInstance()->GetKey() & KEY_UP && Selection > 0)
			Selection -= 1;

		// 선택지 아래로
		if (InputManager::GetInstance()->GetKey() & KEY_DOWN && Selection < 2)
			Selection += 1;

		if (InputManager::GetInstance()->GetKey() & KEY_ENTER)
			switch (Selection)
			{
			case 0:
				SceneManager::GetInstance();
				break;
			case 1:
				SceneManager::GetInstance();
				break;
			case 2:
				isWarning = true;
				Warning::GetInstance()->SetWarning(WEXIT);
				break;
			default:
				break;
			}
	}
}

void Menu::Render()
{
	LogoImage::GetInstance()->RenderLogoImage(46);
	MakeBorder();
	CursorManager::GetInstance()->WriteBuffer(30, 27, (char*)"Start Game");
	CursorManager::GetInstance()->WriteBuffer(30, 30, (char*)"Option");
	CursorManager::GetInstance()->WriteBuffer(30, 33, (char*)"Exit Game");

	if (isWarning)
		Warning::GetInstance()->Render();
	else
	{
		if (Selection == 0)
			CursorManager::GetInstance()->WriteBuffer(50, 27, (char*)"<<");
		else if (Selection == 1)
			CursorManager::GetInstance()->WriteBuffer(50, 30, (char*)"<<");
		else if (Selection == 2)
			CursorManager::GetInstance()->WriteBuffer(50, 33, (char*)"<<");
	}
}

void Menu::Release()
{
}

void Menu::MakeBorder()
{
	CursorManager::GetInstance()->WriteBuffer(25, 25, (char*)"##############################");
	CursorManager::GetInstance()->WriteBuffer(25, 26, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 27, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 28, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 29, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 30, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 31, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 32, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 33, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 34, (char*)"#                            #");
	CursorManager::GetInstance()->WriteBuffer(25, 35, (char*)"##############################");
}