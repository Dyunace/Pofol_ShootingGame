#pragma once
#include "Headers.h"

class Object;
class ObjectPool
{
private:
	static ObjectPool* Instance;
public:
	static ObjectPool* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPool;
		return Instance;
	}
private:
	ObjectPool();
public:
	~ObjectPool();
private:
	static map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;
public:
	static map<string, list<Object*>>* GetEnableList() { return &EnableList; }
	void CatchObject(Object* _Object);
	Object* ThrowObject(string _Key);
	void Update();
};