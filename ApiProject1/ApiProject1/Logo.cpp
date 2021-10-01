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