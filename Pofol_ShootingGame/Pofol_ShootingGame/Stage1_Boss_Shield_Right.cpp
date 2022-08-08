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
    Buffer[0] = (char*)"¢Ö";
    Buffer[1] = (char*)"£þ";
    Buffer[2] = (char*)"£þ";
    Buffer[3] = (char*)"¢Ø";

    Buffer[4] = (char*)"¡Â";
    Buffer[5] = (char*)"¢Ç";
    Buffer[6] = (char*)"¢Ç";
    Buffer[7] = (char*)"¢Ç";
    Buffer[8] = (char*)"¢Ç";
    Buffer[9] = (char*)"¡Ã";

    Hp = ShieldHp;
    BulletType = 1;

    Score = 500;

    if (pObject)
        pObject->SetScale(12.0f, 2.0f);

    Core = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_CORE)->front();
}

int Stage1_Boss_Shield_Right::Update()
{
    if (ShootDelay < 0)
    {
        ShootBullet(Vector3(pObject->GetPosition().x, pObject->GetPosition().y + 2));
        ShootDelay = ShielShootDelay;
    }

    --ShootDelay;

    pObject->SetPosition(Core->GetPosition().x + 9, Core->GetPosition().y + 4);

    return 0;
}

void Stage1_Boss_Shield_Right::Render()
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

    CursorManager::GetInstance()->WriteBuffer(
        pObject->GetPosition().x,
        pObject->GetPosition().y,
        Hp
    );
}

void Stage1_Boss_Shield_Right::Release()
{
}