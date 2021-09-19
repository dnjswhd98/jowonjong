#include "MainUpdate.h"

void MainUpdate::Initialize()
{
	m_hdc = GetDC(g_hWnd);
}

void MainUpdate::Update()
{
}

void MainUpdate::Render()
{
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
