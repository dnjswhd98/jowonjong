#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
private:
	int EnemyHp;
	int EnemyHpMax;
	int S;
	int playerLife;
	int HitCount;
	int Tcount;
	float MaxHpBar;
	float count;
	ULONGLONG _BTime;
	Vector3 Epos;

	Object* _StageBack;
	Object* _StageFront;
	Object* _pPlayer;
	Object* _pPSide[2];
	Object* _EnemyHpBar;
	Object* _PlayerBome;
	Object* _PowerN;
	Object* _ScoreIN;
	Object* _GrazeN;
	Object* _GrazeZone;
	Object* _ShockWave;

	vector<Object*>* BulletList;
	vector<Object*>* EnemyList;
	vector<Object*>* ItemList;
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

