#pragma once
#include "Headers.h"

class Bridge;
class Object;
class EnemyMovement
{
public:
	EnemyMovement();
	~EnemyMovement();
public:
	void Movement(int _MoveType, Vector3& _Position, int& _MoveCount, float _MoveSpeed);
};

