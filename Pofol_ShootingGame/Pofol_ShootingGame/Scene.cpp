#include "Scene.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "UserInstance.h"
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

void Scene::RemovePlayerBullet()
{
	// Remove All Bullets in Screen
	auto BulletList =
		ObjectManager::GetInstance()->GetObjectList(
			UserInstance::GetInstance()->GetBullet());

	if (BulletList)
		RemoveObject(BulletList);
}

void Scene::RemoveObject(list<Object*>* _TargetList)
{
	for (auto iter = _TargetList->begin(); iter != _TargetList->end();)
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

void Scene::RemoveObject(list<Object*>::iterator& _TargetIter)
{
	if (*_TargetIter)
	{
		// Remove Bullet Data
		::Safe_Delete((*_TargetIter)->GetBridge());

		// Save in Disable List
		_TargetIter = ObjectManager::GetInstance()->ThrowObject(_TargetIter, (*_TargetIter));
	}
	else
		++_TargetIter;
}
