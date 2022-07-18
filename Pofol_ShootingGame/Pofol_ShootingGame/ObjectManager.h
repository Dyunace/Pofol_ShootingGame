#pragma once
#include "Headers.h"

class Object;
class Bridge;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;

		return Instance;
	}
private:
	ObjectManager();
public:
	~ObjectManager();
private:
	map<string, list<Object*>>* EnableList;
public:
	void AddBullet(string _Key, Bridge* _Bridge, Vector3 _Position);
	void AddObject(string _Key);
	list<Object*>* GetObjectList(string _strKey);
	list<Object*>::iterator ThrowObject(list<Object*>::iterator _Where, Object* _Object);
	void Update();
	void Render();
};

