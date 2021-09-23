#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "Player.h"

void Stage::Initialize()
{
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	_pPlayer->Initialize();
}

void Stage::Update()
{
	//_pPlayer->Update();
}

void Stage::Render(HDC _hdc)
{
	//_pPlayer->Render(_hdc);
}

void Stage::Release()
{
}

Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}
