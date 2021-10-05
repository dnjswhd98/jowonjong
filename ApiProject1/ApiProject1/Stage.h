#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
private:
	int TileWidthCnt;
	int TileHeightCnt;
	int EnemyHp;

	Object* _StageBack;
	Object* _StageFront;
	Object* _pPlayer;
	Object* _pPSide[2];

	vector<Object*>* BulletList;
	vector<Object*>* EnemyList;
	vector<Object*>* EnemyHpL;
	vector<Object*>* TileList;
	map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	Stage();
	virtual ~Stage();
};

