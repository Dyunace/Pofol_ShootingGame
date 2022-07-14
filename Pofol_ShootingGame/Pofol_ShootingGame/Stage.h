#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
public:
	Stage();
	Stage(string* _str);
	virtual ~Stage();
private:
	Object* pPlayer;
	Object* pEnemy;
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

