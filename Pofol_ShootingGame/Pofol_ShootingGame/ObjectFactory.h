#pragma once
#include"Headers.h"
#include "Object.h"

template <typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		Object* pObject = new T;
		pObject->Initialize("Bullet");

		return pObject;
	}

	static Object* CreateObject(float _x, float _y)
	{
		Object* pObject = new T;
		pObject->Initialize("Bullet");

		pObject->SetPosition(_x, _y);

		return pObject;
	}

	static Object* CreateObject(Vector3 _Position)
	{
		Object* pObject = new T;
		pObject->Initialize("Bullet");

		pObject->SetPosition(_Position);

		return pObject;
	}
};