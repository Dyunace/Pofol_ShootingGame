#include "Menu.h"
#include "LogoImage.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Warning.h"
#include "UserInterface.h"

Menu::Menu() : Selection(0), isWarning(false), mPosY(0) {}
Menu::~Menu(){}

void Menu::Initialize()
{
	Selection = 0;
	isWarning = false;

	mPosY = 27.0f;
}

void Menu::Update()
{
	if (isWarning)
	{
		int warning = Warning::GetInstance()->Update();
		if (warning == 0)
			SceneManager::GetInstance()->SetScene(EXIT);
		else if (warning == 1)
			isWarning = false;
	}
	else
	{
		// 메뉴 이동 키 입력
		if (InputManager::GetInstance()->GetKey() & KEY_UP && Selection > 0)
			Selection -= 1;

		if (InputManager::GetInstance()->GetKey() & KEY_DOWN && Selection < 2)
			Selection += 1;

		// 선택 키 입력
		if (InputManager::GetInstance()->GetKey() & KEY_ENTER || InputManager::GetInstance()->GetKey() & KEY_F)
		{
			switch (Selection)
			{
			case 0:
				// 무기 선택 화면
				if (InputManager::GetInstance()->GetInputDelay() == 0)
				{
					InputManager::GetInstance()->SetInputDelay();
					SceneManager::GetInstance()->SetScene(WEAPON);
				}
				break;
			case 1:
				// 옵션 (공사 중)
				SceneManager::GetInstance();
				break;
			case 2:
				// 게임 종료
				if (InputManager::GetInstance()->GetInputDelay() == 0)
				{
					InputManager::GetInstance()->SetInputDelay();
					isWarning = true;
					Warning::GetInstance()->SetWarning(WARNING::WEXIT);
				}
				break;
			default:
				break;
			}
		}
	}
}

void Menu::Render()
{
	LogoImage::GetInstance()->RenderLogoImage(46);
	UserInterface::GetInstance()->MakeUI(25, mPosY, 15, 13);
	CursorManager::GetInstance()->WriteBuffer(30, mPosY + 3, (char*)"Start Game");
	CursorManager::GetInstance()->WriteBuffer(30, mPosY + 6, (char*)"Option");
	CursorManager::GetInstance()->WriteBuffer(30, mPosY + 9, (char*)"Exit Game");

	if (isWarning)
		Warning::GetInstance()->Render();
	else
	{
		float y = 0.0f;

		if (Selection == 0)
			y = mPosY + 3;
		else if (Selection == 1)
			y = mPosY + 6;
		else if (Selection == 2)
			y = mPosY + 9;
		
		CursorManager::GetInstance()->WriteBuffer(45.0f, y, (char*)"<<", 12);
	}
}

void Menu::Release()
{
}