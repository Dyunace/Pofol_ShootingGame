#pragma once
#include "Headers.h"
#include "CursorManager.h"

class LogoImage
{
public:
	LogoImage() {};
	~LogoImage() {};
public:
	void RenderLogoImage(const int _Count)
	{
		// �׵θ� ���ֱ� + �ΰ� �̹��� �Ʒ��� ������ -> ������ ��

	if (_Count > 3)
	CursorManager::GetInstance()->WriteBuffer(0,   0,(char*)"�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�");
	if (_Count > 6)
	CursorManager::GetInstance()->WriteBuffer(0,  1, (char*)"�ˡ�����������������������������������������������������������������������������");
	if (_Count > 9)
	CursorManager::GetInstance()->WriteBuffer(0,  2, (char*)"�ˡ������ˢˢˡ������ˡ��������ˡ��������ˡ������������ˡ��������ˢˢˢˢˡ�����");
	if (_Count > 12)
	CursorManager::GetInstance()->WriteBuffer(0,  3, (char*)"�ˡ����ˡ������ˡ����ˡ��������ˡ������ˡ��ˡ��������ˡ��ˡ����������ˡ���������");
	if (_Count > 15)
	CursorManager::GetInstance()->WriteBuffer(0,  4, (char*)"�ˡ����ˡ������������ˡ��������ˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (_Count > 18)
	CursorManager::GetInstance()->WriteBuffer(0,  5, (char*)"�ˡ����ˡ������������ˡ��������ˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (_Count > 21)
	CursorManager::GetInstance()->WriteBuffer(0,  6, (char*)"�ˡ������ˢˢˡ������ˢˢˢˢˢˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (_Count > 24)
	CursorManager::GetInstance()->WriteBuffer(0,  7, (char*)"�ˡ������������ˡ����ˡ��������ˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (_Count > 27)
	CursorManager::GetInstance()->WriteBuffer(0,  8, (char*)"�ˡ������������ˡ����ˡ��������ˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (_Count > 30)
	CursorManager::GetInstance()->WriteBuffer(0,  9, (char*)"�ˡ����ˡ������ˡ����ˡ��������ˡ������ˡ��ˡ��������ˡ��ˡ����������ˡ���������");
	if (_Count > 33)
	CursorManager::GetInstance()->WriteBuffer(0, 10, (char*)"�ˡ������ˢˢˡ������ˡ��������ˡ��������ˡ������������ˡ������������ˡ���������");
	if (_Count > 36)
	CursorManager::GetInstance()->WriteBuffer(0, 11, (char*)"�ˡ�����������������������������������������������������������������������������");
	if (_Count > 39)
	CursorManager::GetInstance()->WriteBuffer(0, 12, (char*)"�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�");
	if (_Count > 42)
	CursorManager::GetInstance()->WriteBuffer(0, 13, (char*)"�ˡ�����������������������������������������������������������������������������");
	if (_Count > 45)
	CursorManager::GetInstance()->WriteBuffer(0, 14, (char*)"�ˡ��������������ˢˢˡ������ˢˢˢˢˡ��������ˡ��������ˢˢˡ�����������������");
	if (_Count > 48)
	CursorManager::GetInstance()->WriteBuffer(0, 15, (char*)"�ˡ������������ˡ������ˡ��������ˡ������������ˡ��������ˡ����ˡ���������������");
	if (_Count > 51)
	CursorManager::GetInstance()->WriteBuffer(0, 16, (char*)"�ˡ������������ˡ����������������ˡ����������ˡ��ˡ������ˡ������ˡ�������������");
	if (_Count > 54)
	CursorManager::GetInstance()->WriteBuffer(0, 17, (char*)"�ˡ������������ˡ����������������ˡ����������ˡ��ˡ������ˡ����ˡ���������������");
	if (_Count > 57)
	CursorManager::GetInstance()->WriteBuffer(0, 18, (char*)"�ˡ��������������ˢˢˡ����������ˡ����������ˢˢˡ������ˢˢˡ�����������������");
	if (_Count > 60)
	CursorManager::GetInstance()->WriteBuffer(0, 19, (char*)"�ˡ��������������������ˡ��������ˡ��������ˡ������ˡ����ˡ����ˡ���������������");
	if (_Count > 63)
	CursorManager::GetInstance()->WriteBuffer(0, 20, (char*)"�ˡ��������������������ˡ��������ˡ��������ˡ������ˡ����ˡ������ˡ�������������");
	if (_Count > 66)
	CursorManager::GetInstance()->WriteBuffer(0, 21, (char*)"�ˡ������������ˡ������ˡ��������ˡ��������ˡ������ˡ����ˡ������ˡ�������������");
	if (_Count > 69)
	CursorManager::GetInstance()->WriteBuffer(0, 22, (char*)"�ˡ��������������ˢˢˡ����������ˡ��������ˡ������ˡ����ˡ������ˡ�������������");
	if (_Count > 72)
	CursorManager::GetInstance()->WriteBuffer(0, 23, (char*)"�ˡ�����������������������������������������������������������������������������");
	if (_Count > 75)
	CursorManager::GetInstance()->WriteBuffer(0, 24, (char*)"�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�");

	if (_Count > 78 && TextVisible)
	CursorManager::GetInstance()->WriteBuffer(30, 30, (char*)"Push Enter to Start");

	if (GetTickCount64() % 6 == 0)
		TextToggle();
	}
private:
	bool TextVisible = false;

	void TextToggle()
	{
		TextVisible = !TextVisible;
	}
};