#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	SHORT Image_Count;
	bool LogoEnd;
public:
	Logo();
	virtual ~Logo();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};