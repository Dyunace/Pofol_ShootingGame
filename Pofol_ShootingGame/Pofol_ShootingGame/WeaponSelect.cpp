#include "WeaponSelect.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "SceneManager.h"
#include "Player.h"

WeaponSelect::WeaponSelect() : pPlayer(nullptr) {}
WeaponSelect::WeaponSelect(string* _str) : pPlayer(nullptr){}
WeaponSelect::~WeaponSelect(){}

void WeaponSelect::Initialize()
{
	pPlayer = new Player;
	pPlayer->Initialize();
	pPlayer->SetPosition(39, 23);
}

void WeaponSelect::Update()
{
}

void WeaponSelect::Render()
{
	MakeBorder(10, 3, 30, 15);
	CursorManager::GetInstance()->WriteBuffer(31, 5, (char*)"Select Start Weapon");

	MakeBorder(16, 7, 24, 5);
	pPlayer->Render();
}

void WeaponSelect::Release()
{
}
