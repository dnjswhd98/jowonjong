#pragma once
#include "gameNode.h"


class SceneCastleCorrior:public gameNode
{
private:
	image* CastleCorrior;
	RECT _map;
	RECT _block[34];
	RECT camera;
	RECT _temp[12];
	RECT _diagonalRect;
	RECT water;

	int _mapCount;

	float DMove;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void cameraMove(int leftX, int rightX, int topY, int bottomY);
	void startP();
	void Lobby1();
	void Lobby2();

	SceneCastleCorrior(){}
	~SceneCastleCorrior(){}
};

