#include "UserInterface.h"
#include "CursorManager.h"
#include "UserInstance.h"

UserInterface* UserInterface::Instance = nullptr;
void UserInterface::Update(){}
void UserInterface::Render()
{
	StageInterface();
}

void UserInterface::StageInterface()
{
	UserInterface::MakeUI(2, 1, 10, 5);
	UserInterface::MakeUI(60, 1, 9, 5);

	// ����
	CursorManager::GetInstance()->WriteBuffer(3, 2, (char*)"Life : ");
	for (float f = 0; f < UserInstance::GetInstance()->GetLife(); ++f)
		CursorManager::GetInstance()->WriteBuffer(11.0f + (f * 2), 2, (char*)"��");


	// ��ź
	CursorManager::GetInstance()->WriteBuffer(3, 4, (char*)"Boom : ");
	for (float f = 0; f < UserInstance::GetInstance()->GetBoom(); ++f)
		CursorManager::GetInstance()->WriteBuffer(11.0f + (f * 2), 4, (char*)"��");


	// �Ѿ� �� ����
	char* BulletName = nullptr;
	if (UserInstance::GetInstance()->GetBullet() == NORMALBULLET)
		BulletName = (char*)"Normal";
	else if (UserInstance::GetInstance()->GetBullet() == LASERBULLET)
		BulletName = (char*)"Laser";

	CursorManager::GetInstance()->WriteBuffer(62, 2, BulletName);
	CursorManager::GetInstance()->WriteBuffer(69, 2, (char*)"Lv.");
	CursorManager::GetInstance()->WriteBuffer
	(74, 2, UserInstance::GetInstance()->GetBulletLevel());


	// ����
	int Score = UserInstance::GetInstance()->GetScore();
	CursorManager::GetInstance()->WriteBuffer(62, 4, (char*)"Score : ");

	CursorManager::GetInstance()->WriteBuffer(71, 4, Score / 10000);
	Score = Score - ((Score / 10000) * 10000);

	CursorManager::GetInstance()->WriteBuffer(72, 4, Score / 1000);
	Score = Score - ((Score / 1000) * 1000);

	CursorManager::GetInstance()->WriteBuffer(73, 4, Score / 100);
	Score = Score - ((Score / 100) * 100);

	CursorManager::GetInstance()->WriteBuffer(74, 4, Score / 10);
	Score = Score - ((Score / 10) * 10);

	CursorManager::GetInstance()->WriteBuffer(75, 4, Score);
}

void UserInterface::MakeUI(float _x, float _y, float _Width, float _Height)
{
	// �ֻ�/���ϴ� ��
	for (int i = 0; i < _Width + 2; ++i)
		for (int j = 0; j < 2; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + (-2) + (2 * i), _y + (-1) + ((_Height + 1) * j), (char*)"##");

	// �����ڸ� ��
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < _Height; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + (-2) + ((_Width * 2 + 2) * i), _y + j, (char*)"##");

	// �߾� ����
	for (int i = 0; i < _Width; ++i)
		for (int j = 0; j < _Height; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + (2 * i), _y + j, (char*)"  ");
}
