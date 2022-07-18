#include "ObjectPool.h"
#include "Object.h"
#include "CursorManager.h"
#include "ObjectManager.h"

ObjectPool* ObjectPool::Instance = nullptr;
map<string, list<Object*>> ObjectPool::EnableList;

ObjectPool::ObjectPool(){}
ObjectPool::~ObjectPool(){}

void ObjectPool::CatchObject(Object* _Object)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Object->GetKey());

	if (Disableiter == DisableList.end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		DisableList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		Disableiter->second.push_back(_Object);
}

Object* ObjectPool::ThrowObject(string _Key)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Key);

	if (Disableiter != DisableList.end() && Disableiter->second.size())
	{
		Object* pObject = Disableiter->second.front();
		Disableiter->second.pop_front();

		pObject->Initialize(_Key);
		return pObject;
	}

	return nullptr;
}

void ObjectPool::Update()
{
	CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"DisNormalBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 0.0f, (int)DisableList["NormalBullet"].size());

	CursorManager::GetInstance()->WriteBuffer(0.0f, 1.0f, (char*)"EnNormalBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 1.0f, (int)EnableList["NormalBullet"].size());

	CursorManager::GetInstance()->WriteBuffer(0.0f, 2.0f, (char*)"DisLaserBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 2.0f, (int)DisableList["LaserBullet"].size());

	CursorManager::GetInstance()->WriteBuffer(0.0f, 3.0f, (char*)"EnLaserBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 3.0f, (int)EnableList["LaserBullet"].size());
	
	for (map<string, list<Object*>>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); )
		{
			int result = (*iter2)->Update();
	
			if (result == BUFFER_OVER)
			{
				::Safe_Delete((*iter2)->GetBridge());
	
				CatchObject(*iter2);
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;
		}
	}
}
