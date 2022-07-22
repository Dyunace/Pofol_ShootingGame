#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "WeaponSelect.h"
#include "Stage1.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr) {}
SceneManager::~SceneManager() {}

void SceneManager::SetScene(SCENEID _SceneState)
{
	if (SceneState != nullptr)
		::Safe_Delete(SceneState);

	switch (_SceneState)
	{
	case LOGO:
		SceneState = new Logo;
		break;
	case MENU:
		SceneState = new Menu;
		break;
	case WEAPON:
		SceneState = new WeaponSelect;
		break;
	case STAGE1:
		SceneState = new Stage1;
		break;
	case EXIT:
		exit(NULL);
		break;
	default:
		break;
	}

	SceneState->Initialize();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	::Safe_Delete(SceneState);
}
