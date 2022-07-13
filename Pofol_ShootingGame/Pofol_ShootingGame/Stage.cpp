#include "Stage.h"
#include "Player.h"
#include "NormalBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"

Stage::Stage(){}
Stage::Stage(string* _str){}
Stage::~Stage(){}

void Stage::Initialize()
{
	pPlayer = new Player;
	pPlayer->Initialize("Player");
	pPlayer->SetPosition(40, 40);
}

void Stage::Update()
{
	pPlayer->Update();
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	pPlayer->Render();
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}
