#pragma once
#include "Scene.h"

class WeaponSelect : public Scene
{
public:
	WeaponSelect();
	WeaponSelect(string* _str);
	virtual ~WeaponSelect();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

