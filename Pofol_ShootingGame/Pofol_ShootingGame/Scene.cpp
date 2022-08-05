#include "Scene.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Object.h"

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

void Scene::RemoveBullet(list<Object*>* _BulletList)
{
	for (auto iter = _BulletList->begin(); iter != _BulletList->end();)
	{
		if (*iter)
		{
			// Remove Bullet Data
			::Safe_Delete((*iter)->GetBridge());

			// Save in Disable List
			iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
		}
		else
			++iter;
	}
}
