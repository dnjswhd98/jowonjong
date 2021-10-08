#include "Logo.h"
#include "Player.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ScoreManager.h"

void Logo::Initialize()
{
	ObjectManager::GetInstance()->Initialize();

	ObjectManager::GetInstance()->SetPlayer(ObjectFactory<Player>::CreateObject());

	ImageList["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");
	ImageList["BackGround"] = (new Bitmap)->LoadBmp(L"../Resource/Stage2BGy2.bmp");
	ImageList["Marisa"] = (new Bitmap)->LoadBmp(L"../Resource/player01.bmp");
	ImageList["MarisaSide"] = (new Bitmap)->LoadBmp(L"../Resource/Side.bmp");
	ImageList["MarisaBullet"] = (new Bitmap)->LoadBmp(L"../Resource/MBullet.bmp");
	ImageList["MarisaLazer"] = (new Bitmap)->LoadBmp(L"../Resource/Lazer.bmp");
	ImageList["Enemy"] = (new Bitmap)->LoadBmp(L"../Resource/stg2boss.bmp");
	ImageList["StageUI"] = (new Bitmap)->LoadBmp(L"../Resource/Ui.bmp");
	ImageList["HpBar"] = (new Bitmap)->LoadBmp(L"../Resource/hpbar4.bmp");
	ImageList["EnemyFont"] = (new Bitmap)->LoadBmp(L"../Resource/Enemy.bmp");
	ImageList["ScoreFont"] = (new Bitmap)->LoadBmp(L"../Resource/ScoreF.bmp");

	ScoreManager::GetInstance()->SetImage((new Bitmap)->LoadBmp(L"../Resource/Score.bmp"));

	Object::SetImageList(ImageList);
}

void Logo::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
	}
}

void Logo::Render(HDC _hdc)
{
}

void Logo::Release()
{
}

Logo::Logo()
{
}

Logo::~Logo()
{
}