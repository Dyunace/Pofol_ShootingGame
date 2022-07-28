#pragma once
#include "Headers.h"
#include "ObjectManager.h"

#include "Object.h"
#include "EnemyBridge.h"
#include "BulletBridge.h"

#include "NormalBullet.h"

class DamageManager
{
public:
	static int TakeDamage(Object* _Current, Object* _Target)
	{
		auto Target = ((EnemyBridge*)_Target->GetBridge());
		auto Damage = ((BulletBridge*)_Current->GetBridge())->GetDamage();

		Target->SetHp(
			Target->GetHP() - Damage);

		if (Target->GetDamageEfect() == 0)
			Target->SetDamageEfect(3);

		return Target->GetHP();
	}
	
	static bool DeathCheck(list<Object*>::iterator& _iter, Object* _Target)
	{
		auto Target = ((EnemyBridge*)_Target->GetBridge());

		if (Target->GetHP() > 0)
		{
			++_iter;
			return false;
		}

		// 적 정보 삭제
		::Safe_Delete(Target);

		// DisableList에 보관
		_iter = ObjectManager::GetInstance()->ThrowObject(_iter, (*_iter));

		return true;
	}
};