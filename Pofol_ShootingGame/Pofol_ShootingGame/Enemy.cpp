#include "Enemy.h"
#include "Bridge.h"

Enemy::Enemy() {}
Enemy::Enemy(Transform _Info) : Object(_Info) {}
Enemy::~Enemy(){}

Object* Enemy::Initialize(string _Key)
{
	str = _Key;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2, 1);

    return this;
}

int Enemy::Update()
{
	int result = pBridge->Update();

    return result;
}

void Enemy::Render()
{
	pBridge->Render();
}

void Enemy::Release()
{
}
