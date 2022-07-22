#pragma once
#include "Bridge.h"
#include "Object.h"

class EnemyBridge : public Bridge
{
protected:
	int ShootDelay;
	int Hp;
	float MoveSpeed;
	int MoveType;
	int MoveCount;
public:
	EnemyBridge() : ShootDelay(0), Hp(0), MoveSpeed(0.0f), MoveType(0), MoveCount(0) {};
	virtual ~EnemyBridge() {};

public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	virtual void ShootBullet() PURE;
	virtual void SetMovement(int _Type) PURE;
public:
	int GetHP() { return Hp; }
	int GetMoveType() { return MoveType; }
	void TakeDamage(int _Damage) { Hp -= _Damage; }

protected:
	bool BufferCheck()
	{
		if (pObject->GetPosition().y <= 0 || pObject->GetPosition().y + pObject->GetScale().y >= ConsoleHeightSize - 1 ||
			pObject->GetPosition().x <= 0 || pObject->GetPosition().x + pObject->GetScale().x >= ConsoleWidthSize - 1)
			return true;

		return false;
	};

	void Movement()
	{
		float PosX = pObject->GetPosition().x;
		float PosY = pObject->GetPosition().y;

		// 등장 후 일정 시간이 지나면 강제 퇴장
		if (MoveCount > 1000)
			MoveType = 99;

		switch (MoveType)
		{
			// 기본 이동
			{
		case 0:
			// 정지
			break;
		case 1:
		{
			// 아래로 쭉 이동
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		}
		break;
			}

			// 아래로 이동 후 정지
			{
		case 11:
		{
			if (MoveCount < 30)
				pObject->SetPosition(PosX, PosY + MoveSpeed);
		}
		break;
		case 12:
		{
			if (MoveCount < 60)
				pObject->SetPosition(PosX, PosY + MoveSpeed);
		}
		break;
		case 13:
		{
			if (MoveCount < 90)
				pObject->SetPosition(PosX, PosY + MoveSpeed);
		}
		break;
			}
			{
		case 99:
		{
			// 옆으로 퇴장
			if (PosX < 40)
				pObject->SetPosition(PosX - MoveSpeed, PosY);
			else if (PosX >= 40)
				pObject->SetPosition(PosX + MoveSpeed, PosY);
		}
		break;
			}
		default:
			break;
		}

		++MoveCount;
	}
};