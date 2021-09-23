#include "Object.h"

RECT Object::GetCollider()
{
	return RECT{
		  LONG(Collider.Position.x - (Collider.Scale.y / 2)),
		  LONG(Collider.Position.y - (Collider.Scale.y / 2)),
		  LONG(Collider.Position.x + (Collider.Scale.y / 2)),
		  LONG(Collider.Position.y + (Collider.Scale.y / 2))};
}

Object::Object()
{
}

Object::~Object()
{
}
