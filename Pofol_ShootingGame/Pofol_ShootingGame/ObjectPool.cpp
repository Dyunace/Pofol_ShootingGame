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
	DedugRender();

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

void ObjectPool::DedugRender()
{
	CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"DisNormalBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 0.0f, (int)DisableList[NORMALBULLET].size());
	CursorManager::GetInstance()->WriteBuffer(0.0f, 1.0f, (char*)"EnNormalBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 1.0f, (int)EnableList[NORMALBULLET].size());

	CursorManager::GetInstance()->WriteBuffer(0.0f, 3.0f, (char*)"DisLaserBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 3.0f, (int)DisableList[LASERBULLET].size());
	CursorManager::GetInstance()->WriteBuffer(0.0f, 4.0f, (char*)"EnLaserBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 4.0f, (int)EnableList[LASERBULLET].size());

	CursorManager::GetInstance()->WriteBuffer(0.0f, 6.0f, (char*)"DisNormalEnemy : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 6.0f, (int)DisableList[NORMALENEMY].size());
	CursorManager::GetInstance()->WriteBuffer(0.0f, 7.0f, (char*)"EnNormalEnemy : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 7.0f, (int)EnableList[NORMALENEMY].size());

	CursorManager::GetInstance()->WriteBuffer(0.0f, 9.0f, (char*)"DisSmallEnemy : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 9.0f, (int)DisableList[SMALLENEMY].size());
	CursorManager::GetInstance()->WriteBuffer(0.0f, 10.0f, (char*)"EnSmallEnemy : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 10.0f, (int)EnableList[SMALLENEMY].size());

	CursorManager::GetInstance()->WriteBuffer(0.0f, 12.0f, (char*)"DisBigEnemy : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 12.0f, (int)DisableList[BIGENEMY].size());
	CursorManager::GetInstance()->WriteBuffer(0.0f, 13.0f, (char*)"EnBigEnemy : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 13.0f, (int)EnableList[BIGENEMY].size());

	CursorManager::GetInstance()->WriteBuffer(0.0f, 15.0f, (char*)"DisEnemyBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 15.0f, (int)DisableList[ENORMALBULLET].size());
	CursorManager::GetInstance()->WriteBuffer(0.0f, 16.0f, (char*)"EnEnemyBullet : ");
	CursorManager::GetInstance()->WriteBuffer(20.0f, 16.0f, (int)EnableList[ENORMALBULLET].size());
}
