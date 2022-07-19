#pragma once
#include "Headers.h"

class Bridge;
class Object
{
protected:
	Transform TransInfo;
	string str;

	// ÃÑ¾Ë
	Bridge* pBridge;

	// °øÅë ±âº» Á¤º¸
	int hp;
	float Speed;

	// µô·¹ÀÌ Ä«¿îÆ®
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

	// ÃÑ¾Ë ºê¸´Áö
	Bridge* GetBridge() { return pBridge; }
	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
};

