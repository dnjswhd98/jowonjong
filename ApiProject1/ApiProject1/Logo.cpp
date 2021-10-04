#include "Logo.h"
#include "Player.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

void Logo::Initialize()
{
	ObjectManager::GetInstance()->Initialize();

	ObjectManager::GetInstance()->SetPlayer(ObjectFactory<Player>::CreateObject());

	ImageList["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");
	ImageList["BackGround"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround.bmp");
	ImageList["Marisa"] = (new Bitmap)->LoadBmp(L"../Resource/player01.bmp");
	ImageList["MarisaSide"] = (new Bitmap)->LoadBmp(L"../Resource/Side.bmp");
	ImageList["MarisaBullet"] = (new Bitmap)->LoadBmp(L"../Resource/MBullet.bmp");
	ImageList["MarisaLazer"] = (new Bitmap)->LoadBmp(L"../Resource/Lazer.bmp");
	ImageList["Enemy"] = (new Bitmap)->LoadBmp(L"../Resource/stg2boss.bmp");
	ImageList["StageUI"] = (new Bitmap)->LoadBmp(L"../Resource/Ui.bmp");

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