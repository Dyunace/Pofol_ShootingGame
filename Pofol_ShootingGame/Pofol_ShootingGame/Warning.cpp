#include "Warning.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "SceneManager.h"
#include "UserInterface.h"
#include "Menu.h"

Warning* Warning::Instance = nullptr;

Warning::Warning() : Selection(0), State(0)
{
}

Warning::~Warning()
{
}

void Warning::SetWarning(WARNING _State)
{
	Selection = 1;

	switch (_State)
	{
	case WARNING::WOPTION:
		State = 0;
		break;
	case WARNING::WEXIT:
		State = 1;
		break;
	case WARNING::WPAUSE:
		State = 2;
		break;
	default:
		State = 99;
		break;
	}
}

int Warning::Update()
{
	if (State == 1 || State == 2)
	{
		if (InputManager::GetInstance()->GetKey() & KEY_DOWN && Selection != 1)
			++Selection;

		if (InputManager::GetInstance()->GetKey() & KEY_UP && Selection != 0)
			--Selection;
	}

	if (InputManager::GetInstance()->GetInputDelay() == 0)
	{
		if (InputManager::GetInstance()->GetKey() & KEY_F ||
			InputManager::GetInstance()->GetKey() & KEY_SPACE)
		{
			if (Selection == 0)
			{
				State = 99;

				return 0;
			}
			else if (Selection == 1)
			{
				State = 99;

				return 1;
			}
		}
	}

	return 99;
}

void Warning::Render()
{
	if (State != 99)
	{
		MakeBorder();

		// 경고 문구
		if (State == 1)
		{
			// 메뉴 텍스트
			CursorManager::GetInstance()->WriteBuffer(35, 26, (char*)"Exit Game?");

			// 메뉴 선택지
			CursorManager::GetInstance()->WriteBuffer(36, 29, (char*)"Yes");
			CursorManager::GetInstance()->WriteBuffer(36, 31, (char*)"No");

			// 현재 선택지
			if (Selection == 0)
				CursorManager::GetInstance()->WriteBuffer(42, 29, (char*)"<<");
			else if (Selection == 1)
				CursorManager::GetInstance()->WriteBuffer(42, 31, (char*)"<<");
		}
		else if (State == 2)
		{
			// 메뉴 텍스트
			CursorManager::GetInstance()->WriteBuffer(33, 23, (char*)"- Pause Menu -");

			// 메뉴 선택지
			CursorManager::GetInstance()->WriteBuffer(30, 26, (char*)"Back to Menu");
			CursorManager::GetInstance()->WriteBuffer(30, 28, (char*)"Continue Game");

			// 현재 선택지
			if (Selection == 0)
				CursorManager::GetInstance()->WriteBuffer(47, 26, (char*)"<<");
			else if (Selection == 1)
				CursorManager::GetInstance()->WriteBuffer(47, 28, (char*)"<<");
		}
	}
}

void Warning::Release()
{
}

void Warning::MakeBorder()
{
	if (State == 1)
		UserInterface::GetInstance()->MakeUI(30, 25, 10, 8);

	else if (State == 2)
		UserInterface::GetInstance()->MakeUI(28, 22, 12, 10);
}
