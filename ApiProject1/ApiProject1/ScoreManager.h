#pragma once
#include "Headers.h"

class ScoreManager
{
private:
	static ScoreManager* Instance;
public:
	static ScoreManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ScoreManager;

		return Instance;
	}
private:
	UINT Score;
	vector<int> NumberList;
	//list<int> NumberList;
	Bitmap* Image;
	Vector3 Position;
	int Frame[10];
public:
	void Initialize();
	UINT GetScore() { return Score; }
	void SetScore(int _Score) { Score = _Score; }
	void SetImage(Bitmap* _Image) { Image = _Image; }
	void SetScorePosition(Vector3 _position) { Position = _position; }

	vector<int>* GetScoreNumber() { return &NumberList; }

	void MakeScoreNumber();

	void Render(HDC _hdc);
};



