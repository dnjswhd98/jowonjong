#include "PlayerBome.h"
#include "ObjectManager.h"
#include "Player.h"
void PlayerBome::Initialize()
{
    TransInfo.Position = Vector3(470, 105);
    TransInfo.Scale = Vector3(15, 14);

    strKey = "LifeBome";
    
    _pPlayer = ObjectManager::GetInstance()->GetPlayer();
    PLife = _pPlayer->GetLife();
    PBomb = _pPlayer->GetBomb();
}

int PlayerBome::Update()
{
    PLife = _pPlayer->GetLife();
    PBomb = _pPlayer->GetBomb();
    return 0;
}

void PlayerBome::Render(HDC _hdc)
{
    for (int i = 0; i < PLife; ++i)
    {
        TransparentBlt(_hdc,
            int(TransInfo.Position.x + (TransInfo.Scale.x * i)),
            int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
            float(TransInfo.Scale.x),
            int(TransInfo.Scale.y),
            ImageList[strKey]->GetMemDC(),
            int(TransInfo.Scale.x * 0),
            int(TransInfo.Scale.y * 0),
            int(TransInfo.Scale.x),
            int(TransInfo.Scale.y),
            RGB(0, 0, 0));
    }
    for (int i = 0; i < PBomb; ++i)
    {
        TransparentBlt(_hdc,
            int(TransInfo.Position.x + (TransInfo.Scale.x * i)),
            int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + 22),
            float(TransInfo.Scale.x),
            int(TransInfo.Scale.y),
            ImageList[strKey]->GetMemDC(),
            int(TransInfo.Scale.x * 1),
            int(TransInfo.Scale.y * 0),
            int(TransInfo.Scale.x),
            int(TransInfo.Scale.y),
            RGB(0, 0, 0));
    }
}

void PlayerBome::Release()
{
}

PlayerBome::PlayerBome()
{
}

PlayerBome::~PlayerBome()
{
}
