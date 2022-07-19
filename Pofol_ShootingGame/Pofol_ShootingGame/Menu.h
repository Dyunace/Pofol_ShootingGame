#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	Menu();
	virtual ~Menu();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
private:
	bool isWarning;
	int Selection;
};

