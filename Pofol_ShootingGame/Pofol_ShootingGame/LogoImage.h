#pragma once
#include "Headers.h"
#include "CursorManager.h"

class LogoImage
{
private:
	static LogoImage* Instance;
public:
	static LogoImage* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new LogoImage;

		return Instance;
	}
private:
	LogoImage();
public:
	~LogoImage();
public:
	void RenderLogoImage(const int _Count);
private:
	bool TextVisible = false;

	void TextToggle()
	{
		TextVisible = !TextVisible;
	}
};

// 원본 이미지

//                                      /\\                 /\\                   
//        /\\                           /\\                 /\\                   
//  /\\\\ /\\        /\\       /\\    /\/\ /\       /\\\\ /\/\ /\   /\\    /\ /\\\
// /\\    /\ /\    /\\  /\\  /\\  /\\   /\\        /\\      /\\   /\\  /\\  /\\   
//   /\\\ /\\  /\\/\\    /\\/\\    /\\  /\\          /\\\   /\\  /\\   /\\  /\\   
//     /\\/\   /\\ /\\  /\\  /\\  /\\   /\\            /\\  /\\  /\\   /\\  /\\   
// /\\ /\\/\\  /\\   /\\       /\\       /\\       /\\ /\\   /\\   /\\ /\\\/\\\   
                                                                                                              