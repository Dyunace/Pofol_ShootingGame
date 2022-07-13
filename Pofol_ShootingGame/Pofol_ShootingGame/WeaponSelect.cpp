#include "WeaponSelect.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "NormalBullet.h"

// 할 일 : 무기 선택 창에서 무기에 따라 총알 발사하게 하기

WeaponSelect::WeaponSelect() : pPlayer(nullptr) {}
WeaponSelect::WeaponSelect(string* _str) : pPlayer(nullptr){}
WeaponSelect::~WeaponSelect(){}

void WeaponSelect::Initialize()
{
	pPlayer = new Player();
	pPlayer->Initialize("Player");
	pPlayer->SetPosition(39, 23);
}

void WeaponSelect::Update()
{
	if (InputManager::GetInstance()->GetKey() & KEY_ESC)
		SceneManager::GetInstance()->SetScene(MENU);
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
