#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"

#include "StageBack.h"
#include "Player.h"

void Stage::Initialize()
{
	_StageBack = new StageBack;
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
}

void Stage::Update()
{
	_pPlayer->Update();
}

void Stage::Render(HDC _hdc)
{
	_StageBack->Render(_hdc);
	_pPlayer->Render(_hdc);
}

void Stage::Release()
{
}

Stage::Stage() : _pPlayer(nullptr)
{
}

Stage::~Stage()
{
	Release();
}
