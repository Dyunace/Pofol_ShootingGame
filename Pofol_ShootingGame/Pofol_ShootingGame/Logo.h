#pragma once
#include "Scene.h"

class LogoImage;
class Logo : public Scene
{
private:
	SHORT Image_Count;
	bool LogoEnd;
	LogoImage* lLogoImage;
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