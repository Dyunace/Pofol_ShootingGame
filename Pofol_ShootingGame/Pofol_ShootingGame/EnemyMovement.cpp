#include "EnemyMovement.h"
#include "Object.h"
#include "Bridge.h"

#include "NormalEnemy.h"

EnemyMovement::EnemyMovement(){}
EnemyMovement::~EnemyMovement(){}

void EnemyMovement::Movement(int _MoveType, Vector3& _Position, int& _MoveCount, float _MoveSpeed)
{
	// 등장 후 일정 시간이 지나면 강제 퇴장
	if (_MoveCount < 1000)
		_MoveType = 99;

	switch (_MoveType)
	{
	// 기본 이동
	{
		case 0:
		{
			// 아래로 쭉 이동
			_Position.y -= _MoveSpeed;
		}
		break;
	}
	// 아래로 이동 후 정지
	{
		case 11:
		{
			if (_MoveCount < 10)
				_Position.y -= _MoveSpeed;
		}
		break;
		case 12:
		{
			if (_MoveCount < 20)
				_Position.y -= _MoveSpeed;
		}
		break;
		case 13:
		{
			if (_MoveCount < 30)
				_Position.y -= _MoveSpeed;
		}
		break;
	}
	{
		case 99:
		{
			// 옆으로 퇴장
			if (_Position.x < 40)
				_Position.x -= _MoveSpeed;
			else if (_Position.x >= 40)
				_Position.x += _MoveSpeed;
		}
		break;
	}
	default:
		break;
	}

	++_MoveCount;
}
