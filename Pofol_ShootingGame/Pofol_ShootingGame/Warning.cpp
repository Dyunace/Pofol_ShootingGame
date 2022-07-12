#include "Warning.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "SceneManager.h"
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
	Selection = 0;

	switch (_State)
	{
	case WOPTION:
		State = 1;
		break;
	case WEXIT:
		State = 2;
		break;
	case WCLOSE:
		break;
	default:
		State = 0;
		break;
	}
}

int Warning::Update()
{
	if (InputManager::GetInstance()->GetKey() & KEY_LEFT)
		Selection = 0;

	if (InputManager::GetInstance()->GetKey() & KEY_RIGHT)
		Selection = 1;

	if (InputManager::GetInstance()->GetKey() & KEY_ENTER)
	{
		if (Selection == 0)
			SceneManager::GetInstance()->SetScene(EXIT);
		else if (Selection == 1)
		{
			State = 0;
			return 1;
		}
	}

	return 0;
}

void Warning::Render()
{
	if (State != 0)
	{
		MakeBorder();
		if (State == 2)
			CursorManager::GetInstance()->WriteBuffer(28, 27, (char*)"Do you want Exit Game?");

		CursorManager::GetInstance()->WriteBuffer(28, 29, (char*)"Yes");
		CursorManager::GetInstance()->WriteBuffer(43, 29, (char*)"No");

		if (Selection == 0)
			CursorManager::GetInstance()->WriteBuffer(33, 29, (char*)"<<");
		else if (Selection == 1)
			CursorManager::GetInstance()->WriteBuffer(48, 29, (char*)"<<");
	}
}

void Warning::Release()
{
}

void Warning::MakeBorder()
{
	CursorManager::GetInstance()->WriteBuffer(23, 25, (char*)"###################################");
	CursorManager::GetInstance()->WriteBuffer(23, 26, (char*)"#                                 #");
	CursorManager::GetInstance()->WriteBuffer(23, 27, (char*)"#                                 #");
	CursorManager::GetInstance()->WriteBuffer(23, 28, (char*)"#                                 #");
	CursorManager::GetInstance()->WriteBuffer(23, 29, (char*)"#                                 #");
	CursorManager::GetInstance()->WriteBuffer(23, 30, (char*)"#                                 #");
	CursorManager::GetInstance()->WriteBuffer(23, 31, (char*)"###################################");
}
