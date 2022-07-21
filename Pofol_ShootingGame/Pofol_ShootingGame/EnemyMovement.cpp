#include "EnemyMovement.h"
#include "Object.h"
#include "Bridge.h"

#include "NormalEnemy.h"

EnemyMovement::EnemyMovement(){}
EnemyMovement::~EnemyMovement(){}

void EnemyMovement::Movement(int _MoveType, Vector3& _Position, int& _MoveCount, float _MoveSpeed)
{
	// ���� �� ���� �ð��� ������ ���� ����
	if (_MoveCount < 1000)
		_MoveType = 99;

	switch (_MoveType)
	{
	// �⺻ �̵�
	{
		case 0:
		{
			// �Ʒ��� �� �̵�
			_Position.y -= _MoveSpeed;
		}
		break;
	}
	// �Ʒ��� �̵� �� ����
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
			// ������ ����
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
