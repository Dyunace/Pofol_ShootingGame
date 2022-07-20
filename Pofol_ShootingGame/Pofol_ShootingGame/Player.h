#pragma once
#include "Object.h"

class Player : public Object
{
private:
	char* Buffer[6];
	string pBullet;
public:
	Player();
	Player(Transform _Info);
	virtual ~Player();

	virtual Object* Clone() override { return new Player(*this); };
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	// �÷��̾��� �Ѿ�
	string GetBullet() { return pBullet; }	// ���� �Ѿ� �̸� ��������
	void SetBullet(string _Bullet) { pBullet = _Bullet; }	// �Ѿ� ��ü�ϱ�

public:
	void ShootBullet(float _LimitY = 0);
};

