#include "Logo.h"
#include "CursorManager.h"
#include "LogoImage.h"
#include "InputManager.h"

Logo::Logo() : Image_Count(0), LogoEnd(false), lLogoImage(nullptr){}
Logo::Logo(string* _str) {}
Logo::~Logo() { Render(); }

void Logo::Initialize()
{
	lLogoImage = new LogoImage;
}

void Logo::Update()
{
	if (Image_Count < 80)
		++Image_Count;

	if (InputManager::GetInstance()->GetKey() & KEY_ENTER)
	{
		LogoEnd = true;
		Image_Count = 80;
	}

	
}

void Logo::Render()
{
	lLogoImage->RenderLogoImage(Image_Count);
}

void Logo::Release()
{
	::Safe_Delete(lLogoImage);
}
