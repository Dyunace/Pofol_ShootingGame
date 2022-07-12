#pragma once
#include "Headers.h"

class Scene
{
protected:
	string str;
public:
	Scene();
	Scene(string* _str);
	virtual ~Scene();
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	virtual void MakeBorder(float _x, float _y, float _Width, float _Height);
};