// Shooting v1.13.1 End Phase
/*
	주요 변경점:
		보스 총알 구현
			총알은 ENormalBullet 그대로 사용
			유사 소용돌이 모양. 약간 아쉽지만 그래도 만족한다.

		보스 페이즈 체크
			보스에 스테이지의 페이즈를 받아오는 함수 추가
			각 보스 파츠는 자신의 페이즈에서 공격하도록 설정

		Player의 Bullet 탐색 방식 변경
			Player와 UserInstance의 기능이 일부 겹치기 때문에 UserInstance의 함수로 통합.
			기존의 Player 함수 및 변수는 삭제
		
		WeaponItem의 아이템 교체 방식 변경
			ItemType을 int에서 string으로 변경
			이것으로 Player의 무기 변경 함수의 코드량을 줄임

		Bullet, Boom, Enemy Hp 값 조정
			슬슬 최종 단계이니 조금씩 밸런스 세팅을 할 것

	다음 할 일 (우선 순위 순서) :
		연출 추가하기
		{
			스테이지 시작 시 화면에 Stage 1 Start 띄우기
				화면이 화면이라 작을 것 같음...
				한 글자씩 띄우고 깜빡이는 그 정도라도 해야할 듯

			보스 클리어 후 (BossPhase == 99) Stage Clear!!! 띄우기
				이후 점수 정산 하고 점수 보여주기
					점수 정산은 대충 목숨, 폭탄, 무기 레벨 당 1000점
				끝나고 메뉴로 다시 돌아가기
		}

		플레이어 피격 구현
			1. 맞으면 즉시 플레이어 캐릭터 처치 (unVisible로 잠시 숨기는게 확실함)
				ㄴ unVisible 동안 행동 조작 불능
			2. 잠시 후 UserInstance에서 Life 차감시키고 화면 중앙에 깜빡이며 부활

		스테이지 웨이브 늘리기
			한 10웨이브 정도는 있어야 하지 않나?

		UI 화면에 알잘딱하게 꾸미기

	기타 할 일 :
		폭탄 데미지, 레이저 데미지 조정
			아직 많이 쌘거 같음
			이거 안될거 같으면 적들 체력이랑 노멀 불릿 데미지 늘릴 것

		다음 웨이브로 넘어갈 때까지 필요한 타이머 증가
			폭탄 깔고 웨이브를 처리하자마자 다음 웨이브까지 박살나버림.

		BufferCheck 위치 옮기기?
			현재 ObjectPool에서 각 객체를 참조하고, 각 객체 내부에서 자신의 Pos값으로 반환하며 삭제.
			이게 삭제가 느려지는 원인이 될 수도 있다.
			마지막에 구현할 기능 중 하나.

*/
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
	system("title LSW - Shoot Star");

	system("mode con cols=80 lines=55");

	auto Time = GetTickCount64();

	MainUpdate main;
	main.Initialize();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			main.Update();
			main.Render();
		}
	}
}