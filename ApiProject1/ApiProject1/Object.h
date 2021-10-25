#pragma once
#include "Headers.h"

class Bitmap;
class Object
{
protected:
	Transform TransInfo;
	Transform Collider;
	Vector3 Offset;

	string strKey;
	bool Active;
	int Life;
	int Power;
	int Bomb;
	int Item;
	int Graze;
	int _Framex;
	int _Framey;
	int TCount;
	float Speed;

	ULONGLONG ATime;

	static map<string, Bitmap*>ImageList;

public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render(HDC _hdc) PURE;
	virtual void Release() PURE;

	virtual Object* Clone()PURE;

	static void SetImageList(const map<string, Bitmap*>& _ImageList) { ImageList = _ImageList; }

	static map<string, Bitmap*> GetImageList() { return ImageList; }

	string GetKey() const { return strKey; }

	void SetPosition(Vector3 _position) { TransInfo.Position = _position; }

	void SetPosition(float _x, float _y) { TransInfo.Position.x = _x; TransInfo.Position.y = _y; }
	
	void SetDirection(float _x, float _y) { TransInfo.Direction.x = _x; TransInfo.Direction.y = _y; }

	void SetScale(Vector3 _position) { TransInfo.Scale = _position; }

	void SetScale(float _x, float _y) { TransInfo.Scale.x = _x; TransInfo.Scale.y = _y; }

	int GetLife() { return Life; }
	void SetLife(int _life) { Life = _life; }
	int GetBomb() { return Bomb; }
	void SetBomb(int _bomb) { Bomb = _bomb; }
	int GetPower() { return Power; }
	void SetPower(int _power) { Power = _power; }
	int GetItem() { return Item; }
	void SetItem(int _item) { Item = _item; }
	int GetGraze() { return Graze; }
	void SetGraze(int _graze) { Graze = _graze; }
	float GetSpeed() { return Speed; }
	void SetSpeed(float _speed) { Speed = _speed; }
	int GetTimeCount() { return TCount; }
	void SetTime(ULONGLONG _time) { ATime = _time; }

	void SetFrame(float _framex, float _framey) { _Framex = _framex, _Framey = _framey; }
	
	Vector3 GetPosition() { return TransInfo.Position; }

	Vector3 GetScale() { return TransInfo.Scale; }

	Vector3 GetOffset() { return Offset; }

	RECT GetCollider();

	Vector3 GetColliderPosition() { return Collider.Position; }
	Transform GetColliderTransform() { return Collider; }

	void SetColliderPosition(float _x, float _y) { Collider.Position.x = _x; Collider.Position.y = _y; }

	float GetRectTop() { return TransInfo.Position.y - (TransInfo.Scale.y / 2); }
	float GetRectRight() { return TransInfo.Position.x + (TransInfo.Scale.x / 2); }

	bool GetActive() const { return Active; }

	void SetActive(const bool& _Active) { Active = _Active; }

	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	~Object();
};

