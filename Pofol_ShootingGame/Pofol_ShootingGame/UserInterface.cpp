#include "UserInterface.h"
#include "CursorManager.h"
#include "UserInstance.h"

UserInterface* UserInterface::Instance = nullptr;

UserInterface::UserInterface()
{
	UIPos = Vector3(2, ConsoleHeightSize - 6);
}
UserInterface::~UserInterface()
{
}
void UserInterface::Update(){}
void UserInterface::Render()
{
	StageInterface();
}

void UserInterface::StageInterface()
{
	UserInterface::MakeUI(UIPos.x, UIPos.y, 38, 5);

	// 생명
	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 2, UIPos.y + 1, (char*)"Life : ");
	for (float f = 0; f < UserInstance::GetInstance()->GetLife(); ++f)
		CursorManager::GetInstance()->WriteBuffer(UIPos.x + 9 + (f * 2), UIPos.y + 1, (char*)"♥");


	// 폭탄
	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 2, UIPos.y + 3, (char*)"Boom : ");
	for (float f = 0; f < UserInstance::GetInstance()->GetBoom(); ++f)
		CursorManager::GetInstance()->WriteBuffer(UIPos.x + 9 + (f * 2), UIPos.y + 3, (char*)"♠");


	// 총알 및 레벨
	char* BulletName = nullptr;
	if (UserInstance::GetInstance()->GetBullet() == NORMALBULLET)
		BulletName = (char*)"Normal";
	else if (UserInstance::GetInstance()->GetBullet() == LASERBULLET)
		BulletName = (char*)"Laser";

	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 60, UIPos.y + 1, BulletName);
	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 67, UIPos.y + 1, (char*)"Lv.");
	CursorManager::GetInstance()->WriteBuffer
	(UIPos.x + 72, UIPos.y + 1, UserInstance::GetInstance()->GetBulletLevel());


	// 점수
	int Score = UserInstance::GetInstance()->GetScore();
	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 60, UIPos.y + 3, (char*)"Score : ");

	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 69, UIPos.y + 3, Score / 10000);
	Score = Score - ((Score / 10000) * 10000);

	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 70, UIPos.y + 3, Score / 1000);
	Score = Score - ((Score / 1000) * 1000);

	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 71, UIPos.y + 3, Score / 100);
	Score = Score - ((Score / 100) * 100);

	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 72, UIPos.y + 3, Score / 10);
	Score = Score - ((Score / 10) * 10);

	CursorManager::GetInstance()->WriteBuffer(UIPos.x + 73, UIPos.y + 3, Score);
}

void UserInterface::MakeUI(float _x, float _y, float _Width, float _Height)
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
