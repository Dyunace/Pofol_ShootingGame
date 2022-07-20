#include "Prototype.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

Prototype* Prototype::Instance = nullptr;
Prototype::Prototype(){}
Prototype::~Prototype(){}

void Prototype::Initialize()
{
	Transform Info;

	// �÷��̾�
	string Key = PLAYER;
	ProtoTypeList[Key] = (new Player(Info))->Initialize(Key);

	// ��
	Key = NORMALENEMY;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	// �Ѿ�
	Key = NORMALBULLET;
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);
	Key = LASERBULLET;
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);
}

Object* Prototype::ProtoTypeObject(string _Key)
{
	map<string, Object*>::iterator iter = ProtoTypeList.find(_Key);

	if (iter == ProtoTypeList.end())
		return nullptr;

	return iter->second;
}
