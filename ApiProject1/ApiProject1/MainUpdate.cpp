#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Player.h"

void MainUpdate::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
}

void MainUpdate::Update()
{
	SceneManager::GetInstance()->Update();

	InputManager::GetInstance()->CheckKey();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Release()
{
}

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
	Release();
}
