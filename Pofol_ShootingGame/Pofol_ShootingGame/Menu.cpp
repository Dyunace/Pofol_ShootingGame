#include "Menu.h"
#include "LogoImage.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Warning.h"
#include "UserInstance.h"

Menu::Menu() : Selection(0), isWarning(false) {}
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

		if (InputManager::GetInstance()->GetKey() & KEY_ENTER || InputManager::GetInstance()->GetKey() & KEY_F)
		{
			switch (Selection)
			{
			case 0:
				SceneManager::GetInstance()->SetScene(WEAPON);
				//SceneManager::GetInstance()->SetScene(STAGE);
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
}

void Menu::Render()
{
	LogoImage::GetInstance()->RenderLogoImage(46);
	Scene::MakeBorder(25, 24, 15, 13);
	CursorManager::GetInstance()->WriteBuffer(30, 27, (char*)"Start Game");
	CursorManager::GetInstance()->WriteBuffer(30, 30, (char*)"Option");
	CursorManager::GetInstance()->WriteBuffer(30, 33, (char*)"Exit Game");

	if (isWarning)
		Warning::GetInstance()->Render();
	else
	{
		int y;

		if (Selection == 0)
			y = 27;
		else if (Selection == 1)
			y = 30;
		else if (Selection == 2)
			y = 33;
		
		CursorManager::GetInstance()->WriteBuffer(45, y, (char*)"<<", 12);
	}
}

void Menu::Release()
{
}