#include "Stage1_Boss_Shield_Right.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Object.h"


Stage1_Boss_Shield_Right::Stage1_Boss_Shield_Right()
{
    for (int i = 0; i < 10; ++i)
        Buffer[i] = nullptr;
}
Stage1_Boss_Shield_Right::~Stage1_Boss_Shield_Right(){}

void Stage1_Boss_Shield_Right::Initialize()
{
    Buffer[0] = (char*)"��";
    Buffer[1] = (char*)"��";
    Buffer[2] = (char*)"��";
    Buffer[3] = (char*)"��";

    Buffer[4] = (char*)"��";
    Buffer[5] = (char*)"��";
    Buffer[6] = (char*)"��";
    Buffer[7] = (char*)"��";
    Buffer[8] = (char*)"��";
    Buffer[9] = (char*)"��";

    Hp = 550;

    if (pObject)
        pObject->SetScale(12.0f, 2.0f);

    Core = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_CORE)->front();
}

int Stage1_Boss_Shield_Right::Update()
{
    pObject->SetPosition(Core->GetPosition().x + 9, Core->GetPosition().y + 4);

    return 0;
}

void Stage1_Boss_Shield_Right::Render()
{
    if (pObject->GetPosition().y >= -1)
        for (int i = 0; i < 6; ++i)
            CursorManager::GetInstance()->WriteBuffer(
                pObject->GetPosition().x - pObject->GetScale().x * 0.5f - 2 + (i * 2),
                pObject->GetPosition().y + 1,
                Buffer[i + 4]
            );

    if (pObject->GetPosition().y >= 0)
        for (int i = 0; i < 4; ++i)
            CursorManager::GetInstance()->WriteBuffer(
                pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2),
                pObject->GetPosition().y,
                Buffer[i]
            );
}

void Stage1_Boss_Shield_Right::Release()
{
}

void Stage1_Boss_Shield_Right::ShootBullet()
{
}
