#include "Stage1_Boss_Arm_Left.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Object.h"

Stage1_Boss_Arm_Left::Stage1_Boss_Arm_Left()
{
	for (int i = 0; i < 12; ++i)
		Buffer[i] = nullptr;
}
Stage1_Boss_Arm_Left::~Stage1_Boss_Arm_Left(){}

void Stage1_Boss_Arm_Left::Initialize()
{
	Buffer[0] = (char*)"¡ä";
	Buffer[1] = (char*)"¡ä";

	Buffer[2] = (char*)"¢Ã";
	Buffer[3] = (char*)"¢Ã";

	Buffer[4] = (char*)"¢È";
	Buffer[5] = (char*)"¢È";

	Buffer[6] = (char*)"¢È";
	Buffer[7] = (char*)"¢È";

	Buffer[8] = (char*)"¢È";
	Buffer[9] = (char*)"¢È";

	Buffer[10] = (char*)"¡å";
	Buffer[11] = (char*)"¡å";

	Hp = 150;

	if (pObject)
		pObject->SetScale(4.0f, 6.0f);

	Core = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_CORE)->front();
}

int Stage1_Boss_Arm_Left::Update()
{
	pObject->SetPosition(Core->GetPosition().x - 8, Core->GetPosition().y - 3);

	return 0;
}

void Stage1_Boss_Arm_Left::Render()
{
	if (pObject->GetPosition().y >= -5)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2) - 5,
				pObject->GetPosition().y + 5,
				Buffer[i + 10]
			);

	if (pObject->GetPosition().y >= -4)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2) - 4,
				pObject->GetPosition().y + 4,
				Buffer[i + 8]
			);

	if (pObject->GetPosition().y >= -3)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2) - 3,
				pObject->GetPosition().y + 3,
				Buffer[i + 6]
			);

	if (pObject->GetPosition().y >= -2)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2) - 2,
				pObject->GetPosition().y + 2,
				Buffer[i + 4]
			);

	if (pObject->GetPosition().y >= -1)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2) - 1,
				pObject->GetPosition().y + 1,
				Buffer[i + 2]
			);

	if (pObject->GetPosition().y >= 0)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2),
				pObject->GetPosition().y,
				Buffer[i]
			);
}

void Stage1_Boss_Arm_Left::Release()
{
}

void Stage1_Boss_Arm_Left::ShootBullet()
{
}
