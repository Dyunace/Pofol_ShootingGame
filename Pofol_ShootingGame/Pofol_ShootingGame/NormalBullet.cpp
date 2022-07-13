#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"

NormalBullet::NormalBullet() {}
NormalBullet::NormalBullet(Transform _Info) : Bullet(_Info) {}
NormalBullet::~NormalBullet(){}

Object* NormalBullet::Initialize(string _Key)
{
    str = "NormalBullet";

    Buffer[0] = (char*)"¢Á";

    Speed = 1;
    Color = 13;

    return this;
}

int NormalBullet::Update()
{
    TransInfo.Direction = MathManager::GetDirection(TransInfo.Position, Vector3(60.0f, 15.0f));

    TransInfo.Position.y -= Speed;

    if (TransInfo.Position.y < 0)
        return BUFFER_OVER;

    return 0;
}

void NormalBullet::Render()
{
    CursorManager::GetInstance()->WriteBuffer(
        TransInfo.Position.x,
        TransInfo.Position.y,
        Buffer[0], Color);
}

void NormalBullet::Release()
{
}
