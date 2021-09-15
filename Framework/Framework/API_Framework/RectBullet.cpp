#include "RectBullet.h"
#include "Object.h"

void RectBullet::Initialize()
{
    Speed = 3.0f;

    DrawKey = "HomingBullet";
}

int RectBullet::Update(Transform& _rTransInfo)
{
    _rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
    _rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

    if (_rTransInfo.Position.x >= (WindowsWidth - 100))
        return 1;


    return 0;
}

void RectBullet::Render(HDC _hdc)
{
    Rectangle(_hdc,
        int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
        int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));
}

void RectBullet::Release()
{
}

RectBullet::RectBullet()
{
}

RectBullet::~RectBullet()
{
}
