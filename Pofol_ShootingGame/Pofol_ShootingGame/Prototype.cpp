#include "Prototype.h"

#include "Player.h"
#include "NormalEnemy.h"
#include "Bullet.h"

Prototype* Prototype::Instance = nullptr;
Prototype::Prototype(){}
Prototype::~Prototype(){}

void Prototype::Initialize()
{
	Transform Info;

	// �÷��̾�
	string Key = "Player";
	ProtoTypeList[Key] = (new Player(Info))->Initialize(Key);

	// ��
	Key = "NormalEnemy";
	ProtoTypeList[Key] = (new NormalEnemy(Info))->Initialize(Key);

	// �Ѿ�
	Key = "NormalBullet";
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);
	Key = "LaserBullet";
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);
}

Object* Prototype::ProtoTypeObject(string _Key)
{
	map<string, Object*>::iterator iter = ProtoTypeList.find(_Key);

	if (iter == ProtoTypeList.end())
		return nullptr;

	return iter->second;
}
