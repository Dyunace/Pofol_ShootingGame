#pragma once
#include "Headers.h"

class CursorManager
{
private:
	static CursorManager* Instance;
public:
	static CursorManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CursorManager;

		return Instance;
	}
private:
	bool BufferIndex;	// ������ �ε��� ������ ���� ����
	HANDLE hBuffer[2];	// 2���� ����
private:
	CursorManager();
public:
	~CursorManager();
public:
	void CreateBuffer(const int& _Width, const int& _Height);		// ���۸� ����
	void WriteBuffer(float _x, float _y, char* _str, int _Color = 15);	// �׸��� ����
	void WriteBuffer(Vector3 _Position, char* _str, int _Color = 15);	// �׸��� ����
	void FlipingBuffer();	// ���� ��ȯ
	void ClearBuffer();		// �׷��� ���� ����
	void DestroyBuffer();	// ���� ����
	void SetColor(int _Color);	// ���ڿ� ���� ����
};

