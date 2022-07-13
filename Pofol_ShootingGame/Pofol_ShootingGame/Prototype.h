#pragma once
#include "Headers.h"

class Bridge;
class Object;
class Prototype
{
private:
	static Prototype* Instance;
public:
	static Prototype* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Prototype;

		return Instance;
	}
private:
	Prototype();
public:
	~Prototype();
private:
	map<string, Object*> ProtoTypeList;
public:
	void Initialize();
	Object* ProtoTypeObject(string _Key);
};

