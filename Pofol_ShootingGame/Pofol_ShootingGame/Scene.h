#pragma once
#include "Headers.h"

class Object;
class Scene
{
public:
	Scene();
	virtual ~Scene();
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

protected:
	bool SelectionAccept();


	void RemovePlayerBullet();
	void RemoveObject(list<Object*>* _TargetList);
	void RemoveObject(list<Object*>::iterator& _TargetIter);
};