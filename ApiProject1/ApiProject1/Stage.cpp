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
	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

void Stage::Update()
{
	_pPlayer->Update();

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); )
	{
		int iResult = (*iter)->Update();
		
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}
}

void Stage::Render(HDC _hdc)
{
	_StageBack->Render(_hdc);
	_pPlayer->Render(_hdc);

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(_hdc);
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
