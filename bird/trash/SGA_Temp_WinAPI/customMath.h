#pragma once

#define PI 3.141592f		//180도
#define PI2 (PI * 2)			//360도

#define PI_2 (PI / 2)		//90도
#define PI_4 (PI / 4)		//45도
#define PI_8 (PI / 8)		//22.5도

//사용자 정의 네임스페이스
namespace Util
{
	//두 점 사이의 거리
	float getDistance(float startX, float startY,float endX, float endY);
	
	//두 점 사이의 각도
	float getAngle(float startX, float startY, float endX, float endY);
}