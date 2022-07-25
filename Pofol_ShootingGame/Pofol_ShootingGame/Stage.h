#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
protected:
	Object* pPlayer;
	bool isLaser;

	list<Object*>* NormalEnemyList;
	
	list<Object*>* PlayerBulletList;
	list<Object*>* ENormalBulletList;
public:
	Stage();
	virtual ~Stage();
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	void GetObjectLists();
	void CollisionCheck();

	void GetUserInstance();
};

