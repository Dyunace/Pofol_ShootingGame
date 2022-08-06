#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
protected:
	Object* pPlayer;

	list<Object*>* CurrentEnemyList;

	list<Object*>* NormalEnemyList;
	list<Object*>* SmallEnemyList;
	list<Object*>* BigEnemyList;
	
	list<Object*>* PlayerBulletList;
	list<Object*>* PlayerBoomList;
	list<Object*>* ENormalBulletList;

	list<Object*>* BoomItemList;
	list<Object*>* WeaponItemList;

protected:
	bool isLaser;

	int CurStage;
	int StageWave;
	int StageCount;

	int BossPhase;
	int PhaseCount;

	bool isBoomItemDrop;
	bool isWeaponItemDrop;
public:
	Stage();
	virtual ~Stage();
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
protected:
	void CatchObjectLists();
	void CollisionCheck();
	void DamageCheck(list<Object*>* _CurrentList);

	void BoomDamage(list<Object*>* _CurrentList);
	void BoomRemoveBullet();
	virtual void TakeBossDamage() PURE;

	void GetPlayerBullet();
	void RenderUserInterface();

	void MakeEnemy(string _EnemyType, float _x, float _y, int _MoveType);
	void MakeItem(int _ItemType, Vector3 _Positioln);

	void ItemDropCheck(list<Object*>::iterator& _iter);
	void ItemWeaponUpgrade(list<Object*>::iterator& _iter);

	bool WaveCheck();

	list<Object*>::iterator RemoveObject(list<Object*>::iterator& _iter);
};

