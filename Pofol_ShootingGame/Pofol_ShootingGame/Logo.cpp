#include "Logo.h"
#include "CursorManager.h"

Logo::Logo() : Image_Count(0) {}
Logo::Logo(string* _str){}
Logo::~Logo(){}

void Logo::Initialize()
{
}

void Logo::Update()
{
	if (Image_Count != 240)
		++Image_Count;
}

void Logo::Render()
{
	if (Image_Count > 3)
	CursorManager::GetInstance()->WriteBuffer(0,  0, (char*)"�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�");
	if (Image_Count > 6)
	CursorManager::GetInstance()->WriteBuffer(0,  1, (char*)"��������������������������������������������������������������������������������");
	if (Image_Count > 9)
	CursorManager::GetInstance()->WriteBuffer(0,  2, (char*)"���������ˢˢˡ������ˡ��������ˡ��������ˡ������������ˡ��������ˢˢˢˢˡ�����");
	if (Image_Count > 12)
	CursorManager::GetInstance()->WriteBuffer(0,  3, (char*)"�������ˡ������ˡ����ˡ��������ˡ������ˡ��ˡ��������ˡ��ˡ����������ˡ���������");
	if (Image_Count > 15)
	CursorManager::GetInstance()->WriteBuffer(0,  4, (char*)"�������ˡ������������ˡ��������ˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (Image_Count > 18)
	CursorManager::GetInstance()->WriteBuffer(0,  5, (char*)"�������ˡ������������ˡ��������ˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (Image_Count > 21)
	CursorManager::GetInstance()->WriteBuffer(0,  6, (char*)"���������ˢˢˡ������ˢˢˢˢˢˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (Image_Count > 24)
	CursorManager::GetInstance()->WriteBuffer(0,  7, (char*)"���������������ˡ����ˡ��������ˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (Image_Count > 27)
	CursorManager::GetInstance()->WriteBuffer(0,  8, (char*)"���������������ˡ����ˡ��������ˡ����ˡ������ˡ����ˡ������ˡ��������ˡ���������");
	if (Image_Count > 30)
	CursorManager::GetInstance()->WriteBuffer(0,  9, (char*)"�������ˡ������ˡ����ˡ��������ˡ������ˡ��ˡ��������ˡ��ˡ����������ˡ���������");
	if (Image_Count > 33)
	CursorManager::GetInstance()->WriteBuffer(0, 10, (char*)"���������ˢˢˡ������ˡ��������ˡ��������ˡ������������ˡ������������ˡ���������");
	if (Image_Count > 36)
	CursorManager::GetInstance()->WriteBuffer(0, 11, (char*)"��������������������������������������������������������������������������������");
	if (Image_Count > 39)
	CursorManager::GetInstance()->WriteBuffer(0, 12, (char*)"�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�");
	if (Image_Count > 42)
	CursorManager::GetInstance()->WriteBuffer(0, 13, (char*)"��������������������������������������������������������������������������������");
	if (Image_Count > 45)
	CursorManager::GetInstance()->WriteBuffer(0, 14, (char*)"�����������������ˢˢˡ������ˢˢˢˢˡ��������ˡ��������ˢˢˡ�����������������");
	if (Image_Count > 48)
	CursorManager::GetInstance()->WriteBuffer(0, 15, (char*)"���������������ˡ������ˡ��������ˡ������������ˡ��������ˡ����ˡ���������������");
	if (Image_Count > 51)
	CursorManager::GetInstance()->WriteBuffer(0, 16, (char*)"���������������ˡ����������������ˡ����������ˡ��ˡ������ˡ������ˡ�������������");
	if (Image_Count > 54)
	CursorManager::GetInstance()->WriteBuffer(0, 17, (char*)"���������������ˡ����������������ˡ����������ˡ��ˡ������ˡ����ˡ���������������");
	if (Image_Count > 57)
	CursorManager::GetInstance()->WriteBuffer(0, 18, (char*)"�����������������ˢˢˡ����������ˡ����������ˢˢˡ������ˢˢˡ�����������������");
	if (Image_Count > 60)
	CursorManager::GetInstance()->WriteBuffer(0, 19, (char*)"�����������������������ˡ��������ˡ��������ˡ������ˡ����ˡ����ˡ���������������");
	if (Image_Count > 63)
	CursorManager::GetInstance()->WriteBuffer(0, 20, (char*)"�����������������������ˡ��������ˡ��������ˡ������ˡ����ˡ������ˡ�������������");
	if (Image_Count > 66)
	CursorManager::GetInstance()->WriteBuffer(0, 21, (char*)"���������������ˡ������ˡ��������ˡ��������ˡ������ˡ����ˡ������ˡ�������������");
	if (Image_Count > 69)
	CursorManager::GetInstance()->WriteBuffer(0, 22, (char*)"�����������������ˢˢˡ����������ˡ��������ˡ������ˡ����ˡ������ˡ�������������");
	if (Image_Count > 72)
	CursorManager::GetInstance()->WriteBuffer(0, 23, (char*)"��������������������������������������������������������������������������������");
	if (Image_Count > 75)
	CursorManager::GetInstance()->WriteBuffer(0, 24, (char*)"�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�");

	if (Image_Count > 75)
		CursorManager::GetInstance()->WriteBuffer(30, 30, (char*)"Push Enter to Start");
}

void Logo::Release()
{
}
