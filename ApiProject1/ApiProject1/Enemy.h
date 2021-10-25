#pragma once
#include"Object.h"

class Bridge;
class Enemy : public Object
{
private:
	Bridge* BridgeObject;
	int EnemyFrame;
	int FrameX;
	int FrameY;
	int Count;
	ULONGLONG Time;
	ULONGLONG FTime;

	Object* _pPlayer;

	vector<Object*>* BulletList;
	Vector3 direc;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy(*this); }
	void SetBridge(Bridge* _pBridge) { BridgeObject = _pBridge; }

	template<typename T>
	Object* CreateBullet();

	template<typename T>
	Object* CreateBullet(Vector3 _pos);

	Enemy();
	Enemy(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	~Enemy();
};

