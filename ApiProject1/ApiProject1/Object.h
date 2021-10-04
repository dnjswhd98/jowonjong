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
	float Speed;

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
	
	Vector3 GetPosition() { return TransInfo.Position; }

	Vector3 GetScale() { return TransInfo.Scale; }

	Vector3 GetOffset() { return Offset; }

	RECT GetCollider();

	Vector3 GetColliderPosition() { return Collider.Position; }
	Transform GetColliderTransform() { return Collider; }

	void SetColliderPosition(float _x, float _y) { Collider.Position.x = _x; Collider.Position.y = _y; }

	float GetRectTop() { return TransInfo.Position.y - (TransInfo.Scale.y / 2); }

	bool GetActive() const { return Active; }

	void SetActive(const bool& _Active) { Active = _Active; }

	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	~Object();
};

