#include "NormalEnemy.h"
#include "CursorManager.h"

NormalEnemy::NormalEnemy(){}
NormalEnemy::NormalEnemy(Transform _Info){}
NormalEnemy::~NormalEnemy(){}

Object* NormalEnemy::Initialize(string _Key)
{
    str = "NormalEnemy";

    Buffer[0] = (char*)"��";
    Buffer[1] = (char*)"��";
    Buffer[2] = (char*)"��";
    Buffer[3] = (char*)"��";

    TransInfo.Position = Vector3(0, 0);
    TransInfo.Rotation = Vector3(0, 0);
    TransInfo.Scale = Vector3(4, 2); // ���� ũ��

    return this;
}

int NormalEnemy::Update()
{
    return 0;
}

void NormalEnemy::Render()
{
    for (int i = 0; i < 4; ++i)
        CursorManager::GetInstance()->WriteBuffer(TransInfo.Position.x + (i % 2) * 2, TransInfo.Position.y + (i / 2), Buffer[i]);
}

void NormalEnemy::Release()
{
}

void NormalEnemy::ShootBullet()
{
}
