#pragma once
#include "Headers.h"

class Scene
{
protected:
	string str;
public:
	Scene();
	Scene(string* _str);
	virtual ~Scene();
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	/// <summary>
	/// UI�� ���� �����
	/// ���� ���̴� ���� ������ ���� �� (2����Ʈ ���)
	/// </summary>
	/// <param name="_x">x ���� ��ġ</param>
	/// <param name="_y">y ���� ��ġ</param>
	/// <param name="_Width">���� ���� / 2</param>
	/// <param name="_Height">���� ���� == ���� ����</param>
	virtual void MakeBorder(float _x, float _y, float _Width, float _Height);
};