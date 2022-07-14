#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform TransInfo;
	string str;

	// ���� �⺻ ����
	int hp;
	float Speed;

	// źȯ
	string Bullet;
	int BulletDamage;

	// ������ ī��Ʈ
	int DelayCount;
public:
	Object();
	Object(Transform _Info);
	virtual ~Object();
public:
	virtual Object* Initialize(string _Key) PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	virtual Object* Clone() PURE;
public:
	string GetKey() const { return str; }

	Vector3 GetPosition() const { return TransInfo.Position; }
	void SetPosition(float _x, float _y) { TransInfo.Position = Vector3(_x, _y); }
	void SetPosition(Vector3 _Position) { TransInfo.Position = _Position; }

	Vector3 GetScale() const { return TransInfo.Scale; }
	void SetScale(float _x, float _y) { TransInfo.Scale = Vector3(_x, _y); }

	string GetBullet() { return Bullet; }
	void SetBullet(string _Bullet) { Bullet = _Bullet; } // �÷��̾��� źȯ ��ü
protected:
	virtual void ShootBullet() PURE;
};

