#include "Menu.h"
#include "LogoImage.h"

Menu::Menu() {}
Menu::Menu(string* _str){}
Menu::~Menu(){}

void Menu::Initialize()
{
}

void Menu::Update()
{
}

void Menu::Render()
{
	LogoImage::GetInstance()->RenderLogoImage(46);
}

void Menu::Release()
{
}
