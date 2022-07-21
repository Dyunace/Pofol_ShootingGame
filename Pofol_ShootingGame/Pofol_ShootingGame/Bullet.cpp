#include "Bullet.h"
#include "Bridge.h"

Bullet::Bullet() : Color(13), Speed(1) {}
Bullet::Bullet(Transform _Info){}
Bullet::~Bullet(){}

Object* Bullet::Initialize(string _Key)
{
	str = _Key;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2, 1);

	return this;
}

int Bullet::Update()
{
	int result = pBridge->Update();

	return result;
}

void Bullet::Render()
{
	pBridge->Render();
}

void Bullet::Release()
{
}
