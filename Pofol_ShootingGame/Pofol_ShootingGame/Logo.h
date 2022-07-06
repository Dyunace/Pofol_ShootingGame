#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	SHORT Image_Count;
public:
	Logo();
	Logo(string* _str);
	virtual ~Logo();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};