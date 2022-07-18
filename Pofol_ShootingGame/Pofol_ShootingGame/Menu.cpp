#include "Menu.h"
#include "LogoImage.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Warning.h"
#include "UserInstance.h"

Menu::Menu() : Selection(0), isWarning(false) {}
Menu::Menu(string* _str) : Selection(0), isWarning(false) {}
Menu::~Menu(){}

void Menu::Initialize()
{
	Selection = 0;
	isWarning = false;
}

void Menu::Update()
{
	if (isWarning)
	{
		int warning = Warning::GetInstance()->Update();
		if (warning == 1)
			isWarning = false;
	}
	else
	{
		if (InputManager::GetInstance()->GetKey() & KEY_UP && Selection > 0)
			Selection -= 1;

		if (InputManager::GetInstance()->GetKey() & KEY_DOWN && Selection < 2)
			Selection += 1;

		if (InputManager::GetInstance()->GetKey() & KEY_ENTER)
			switch (Selection)
			{
			case 0:
				UserInstance::GetInstance()->SetBullet("LaserBullet");

				SceneManager::GetInstance()->SetScene(STAGE);
				//SceneManager::GetInstance()->SetScene(WEAPON);
				break;
			case 1:
				SceneManager::GetInstance();
				break;
			case 2:
				isWarning = true;
				Warning::GetInstance()->SetWarning(WARNING::WEXIT);
				break;
			default:
				break;
			}
	}
}

void Menu::Render()
{
	LogoImage::GetInstance()->RenderLogoImage(46);
	Scene::MakeBorder(25, 24, 15, 3);
	CursorManager::GetInstance()->WriteBuffer(30, 27, (char*)"Start Game");
	CursorManager::GetInstance()->WriteBuffer(30, 30, (char*)"Option");
	CursorManager::GetInstance()->WriteBuffer(30, 33, (char*)"Exit Game");

	if (isWarning)
		Warning::GetInstance()->Render();
	else
	{
		if (Selection == 0)
			CursorManager::GetInstance()->WriteBuffer(45, 27, (char*)"<<");
		else if (Selection == 1)
			CursorManager::GetInstance()->WriteBuffer(45, 30, (char*)"<<");
		else if (Selection == 2)
			CursorManager::GetInstance()->WriteBuffer(45, 33, (char*)"<<");
	}
}

void Menu::Release()
{
}