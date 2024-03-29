#pragma once
#include "Headers.h"
#include "ObjectManager.h"
#include "UserInstance.h"

#include "Object.h"
#include "EnemyBridge.h"
#include "BulletBridge.h"

#include "Explosion.h"

class DamageManager
{
public:
	static int TakeDamage(Object* _Current, Object* _Target)
	{
		auto Target = ((EnemyBridge*)_Target->GetBridge());
		auto Damage = ((BulletBridge*)_Current->GetBridge())->GetDamage();

		// 데미지 계산
		Target->SetHp(Target->GetHP() - Damage);

		// 점수 계산
		UserInstance::GetInstance()->AddScore(Damage);

		// 데미지 이펙트
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

		// 점수 계산
		UserInstance::GetInstance()->AddScore(Target->GetScore());

		// 폭발 이펙트
		ObjectManager::GetInstance()->AddObject(EXPLOSION);
		auto explo = ObjectManager::GetInstance()->GetObjectList(EXPLOSION);
		explo->back()->SetPosition(_Target->GetPosition());

		// 적 정보 삭제
		::Safe_Delete(Target);

		// DisableList에 보관
		_iter = ObjectManager::GetInstance()->ThrowObject(_iter, (*_iter));

		return true;
	}
};