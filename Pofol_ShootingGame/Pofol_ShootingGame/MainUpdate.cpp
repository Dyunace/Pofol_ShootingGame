#include "MainUpdate.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "BackGround.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}

void MainUpdate::Initialize()
{
	CursorManager::GetInstance()->CreateBuffer(ConsoleWidthSize, ConsoleHeightSize);
	BackGround::GetInstance()->Initialize();
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	BackGround::GetInstance()->Update();
	InputManager::GetInstance()->InputKey();
	SceneManager::GetInstance()->Update();

	if (InputManager::GetInstance()->GetInputDelay() != 0)
		InputManager::GetInstance()->MinusInputDelay();

	CursorManager::GetInstance()->FlipingBuffer();
}

void MainUpdate::Render()
{
	BackGround::GetInstance()->Render();
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}
