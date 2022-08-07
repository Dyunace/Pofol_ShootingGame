#include "Stage1_Boss_Shield_Left.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Object.h"


Stage1_Boss_Shield_Left::Stage1_Boss_Shield_Left()
{
    for (int i = 0; i < 10; ++i)
        Buffer[i] = nullptr;
}
Stage1_Boss_Shield_Left::~Stage1_Boss_Shield_Left(){}

void Stage1_Boss_Shield_Left::Initialize()
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

    Hp = ShieldHp;
    BulletType = 1;

    if (pObject)
        pObject->SetScale(12.0f, 2.0f);

    Core = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_CORE)->front();
}

int Stage1_Boss_Shield_Left::Update()
{
    if (ShootDelay < 0)
    {
        ShootBullet(Vector3(pObject->GetPosition().x, pObject->GetPosition().y + 2));
        ShootDelay = ShielShootDelay;
    }

    --ShootDelay;

    pObject->SetPosition(Core->GetPosition().x - 5, Core->GetPosition().y + 4);

    return 0;
}

void Stage1_Boss_Shield_Left::Render()
{
    if (DamageEfect != 3)
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

    if (DamageEfect != 0)
        --DamageEfect;
}

void Stage1_Boss_Shield_Left::Release()
{
}
