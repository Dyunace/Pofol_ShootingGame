#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
protected:
	Object* pPlayer;
	bool isLaser;

	list<Object*>* CurrentEnemyList;

	list<Object*>* NormalEnemyList;
	list<Object*>* SmallEnemyList;
	list<Object*>* BigEnemyList;
	list<Object*>* BossList;
	
	list<Object*>* PlayerBulletList;
	list<Object*>* PlayerBoomList;
	list<Object*>* ENormalBulletList;

protected:
	int CurStage;
	int StageWave;
	int StageCount;
	int BossPhase;
	int PhaseCount;

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
	virtual void TakeBossDamage() PURE;

	void GetUserInstance();

	void MakeEnemy(string _EnemyType, float _x, float _y, int _MoveType);

	bool WaveCheck();
};

