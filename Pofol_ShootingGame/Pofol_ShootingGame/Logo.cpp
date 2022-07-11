#include "Logo.h"
#include "CursorManager.h"
#include "LogoImage.h"
#include "InputManager.h"
#include "SceneManager.h"

Logo::Logo() : Image_Count(0), LogoEnd(false){}
Logo::Logo(string* _str) {}
Logo::~Logo() { Render(); }

void Logo::Initialize()
{
	LogoEnd = false;
}

void Logo::Update()
{
	++Image_Count;

	if (InputManager::GetInstance()->GetKey() & KEY_ENTER && (LogoEnd == true))
		SceneManager::GetInstance()->SetScene(MENU);

	if (InputManager::GetInstance()->GetKey() & KEY_ENTER && (LogoEnd == false))
	{
		LogoEnd = true;
		Image_Count = 48;
	}
}

void Logo::Render()
{
	LogoImage::GetInstance()->RenderLogoImage(Image_Count);
}

void Logo::Release()
{
}
