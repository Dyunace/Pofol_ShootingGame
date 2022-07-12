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
	/// UI용 보드 만들기
	/// 가로 길이는 절반 값으로 넣을 것 (2바이트 계산)
	/// </summary>
	/// <param name="_x">x 시작 위치</param>
	/// <param name="_y">y 시작 위치</param>
	/// <param name="_Width">가로 길이 / 2</param>
	/// <param name="_Height">세로 길이 == 원소 갯수</param>
	virtual void MakeBorder(float _x, float _y, float _Width, float _Height);
};