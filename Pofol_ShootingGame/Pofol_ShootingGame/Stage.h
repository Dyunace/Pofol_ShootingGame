#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
protected:
	Object* pPlayer;
	bool isLaser;

	list<Object*>* NormalEnemyList;
	list<Object*>* SmallEnemyList;
	list<Object*>* BigEnemyList;
	
	list<Object*>* PlayerBulletList;
	list<Object*>* ENormalBulletList;

protected:
	int CurStage;
	int StageWave;
	int StageCount;

public:
	Stage();
	virtual ~Stage();
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

protected:
	void GetObjectLists();
	void CollisionCheck();
	void DamageCheck(list<Object*>* _CurrentList);

	void GetUserInstance();

	void MakeEnemy(string _EnemyType, Vector3 _Position, int _MoveType);
	void MakeEnemy(string _EnemyType, float _x, float _y, int _MoveType);

	bool WaveCheck();
};

