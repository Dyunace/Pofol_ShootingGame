#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
public:
	Stage();
	virtual ~Stage();
private:
	Object* pPlayer;
	Object* pEnemy;
	bool isLaser;
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

