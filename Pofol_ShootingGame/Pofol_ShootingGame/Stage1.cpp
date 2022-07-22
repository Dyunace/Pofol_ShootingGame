#include "Stage1.h"
#include "Player.h"
#include "NormalBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "UserInstance.h"
#include "NormalEnemy.h"

Stage1::Stage1() : pEnemy(nullptr) {}
Stage1::~Stage1(){}

void Stage1::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->SetPosition(40, 40);

	// Player�� Bullet ����
	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
	// Laser Bullet �ߺ� ����
	if (((Player*)pPlayer)->GetBullet() == LASERBULLET)
		isLaser = true;

	// �׽�Ʈ�� Enemy
	Bridge* enemy = new NormalEnemy;
	ObjectManager::GetInstance()->AddBridge(NORMALENEMY, enemy, Vector3(40, 10));
	pEnemy = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY)->front();
	((EnemyBridge*)enemy)->SetMovement(0);

	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());

	// ������Ʈ ���� ��������
	GetObjectLists();
}

void Stage1::Update()
{
	ObjectManager::GetInstance()->Update();

	CollisionCheck();

	++SceneCount;

	if (SceneCount == 60)
	{
		Bridge* EnemyBridge = new NormalEnemy;
		ObjectManager::GetInstance()->AddBridge(NORMALENEMY, EnemyBridge, Vector3(20, 15));
		((NormalEnemy*)EnemyBridge)->SetMovement(11);
	}

	if (SceneCount == 90)
	{
		Bridge* EnemyBridge = new NormalEnemy;
		ObjectManager::GetInstance()->AddBridge(NORMALENEMY, EnemyBridge, Vector3(60, 10));
		((NormalEnemy*)EnemyBridge)->SetMovement(99);
	}
}

void Stage1::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage1::Release()
{
}
