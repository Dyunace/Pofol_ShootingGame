#include "Scene.h"
#include "InputManager.h"

Scene::Scene() { }
Scene::~Scene(){}

bool Scene::SelectionAccept()
{
	if (InputManager::GetInstance()->GetKey() & KEY_ENTER || 
		InputManager::GetInstance()->GetKey() & KEY_F ||
		InputManager::GetInstance()->GetKey() & KEY_SPACE)
		return true;
	return false;
}
