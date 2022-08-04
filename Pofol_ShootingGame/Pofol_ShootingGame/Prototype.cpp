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

	// 플레이어
	string Key = PLAYER;
	ProtoTypeList[Key] = (new Player(Info))->Initialize(Key);

	// 적
	Key = NORMALENEMY;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);
	Key = SMALLENEMY;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);
	Key = BIGENEMY;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	// 총알
	Key = NORMALBULLET;
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);
	Key = LASERBULLET;
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);
	Key = BOOM;
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);

	Key = ENORMALBULLET;
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);
	Key = ESPECIALBULLET;
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);

	// 보스
	Key = STAGE1_BOSS_CORE;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);
	Key = STAGE1_BOSS_HEAD;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);
	Key = STAGE1_BOSS_ARM_LEFT;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);
	Key = STAGE1_BOSS_ARM_RIGHT;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);
	Key = STAGE1_BOSS_SHIELD_LEFT;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);
	Key = STAGE1_BOSS_SHIELD_RIGHT;
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);
}

Object* Prototype::ProtoTypeObject(string _Key)
{
	map<string, Object*>::iterator iter = ProtoTypeList.find(_Key);

	if (iter == ProtoTypeList.end())
		return nullptr;

	return iter->second;
}
