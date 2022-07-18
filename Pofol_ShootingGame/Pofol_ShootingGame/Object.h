#pragma once
#include "Headers.h"

class Bridge;
class Object
{
protected:
	Transform TransInfo;
	string str;

	// 총알
	Bridge* pBridge;

	// 공통 기본 정보
	int hp;
	float Speed;

	// 플레이어의 현재 총알
	string pBullet;

	// 딜레이 카운트
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

	// 총알 브릿지
	Bridge* GetBridge() { return pBridge; }
	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }

	// 플레이어의 총알
	string GetBullet() { return pBullet; }	// 현재 총알 이름 가져오기
	void SetBullet(string _Bullet) { pBullet = _Bullet; }	// 총알 교체하기
};

