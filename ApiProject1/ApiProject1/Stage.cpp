#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"

#include "StageBack.h"
#include "Player.h"
#include "PlayerSide.h"
#include "PlayerSide2.h"

void Stage::Initialize()
{
	_StageBack = new StageBack;
	_StageBack->Initialize();
	_pPSide[0] = new PlayerSide;
	_pPSide[0]->Initialize();
	_pPSide[1] = new PlayerSide2;
	_pPSide[1]->Initialize();

	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	ImageList = Object::GetImageList();
}

void Stage::Update()
{
	_pPlayer->Update();
	_pPSide[0]->Update();
	_pPSide[1]->Update();

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
	_StageBack->Render(ImageList["Buffer"]->GetMemDC());

	//_StageBack->Render(_hdc);
	_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	_pPSide[0]->Render(_hdc);
	_pPSide[1]->Render(_hdc);

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(_hdc);

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
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
