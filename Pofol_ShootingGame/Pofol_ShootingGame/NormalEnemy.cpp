#include "NormalEnemy.h"
#include "CursorManager.h"

NormalEnemy::NormalEnemy(){}
NormalEnemy::~NormalEnemy(){}

void NormalEnemy::Initialize()
{
	Buffer[0] = (char*)"¦®";
	Buffer[1] = (char*)"¦¯";
	Buffer[2] = (char*)"¥µ";
	Buffer[3] = (char*)"¥³";
}

int NormalEnemy::Update()
{
	pObject->SetPosition(40, 10);

	return 0;
}

void NormalEnemy::Render()
{
	for (int i = 0; i < 4; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x + ((i % 2) * 2),
			pObject->GetPosition().y + (i / 2) + pObject->GetScale().y,
			Buffer[i]
		);
}

void NormalEnemy::Release()
{
}
