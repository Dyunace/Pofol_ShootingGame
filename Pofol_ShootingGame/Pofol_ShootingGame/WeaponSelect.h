#pragma once
#include "Scene.h"

class Object;
class WeaponSelect : public Scene
{
private:
	Object* pPlayer;
	int Selection;
public:
	WeaponSelect();
	virtual ~WeaponSelect();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	void SwitchBullet();
	void ReleaseBullet();
};

