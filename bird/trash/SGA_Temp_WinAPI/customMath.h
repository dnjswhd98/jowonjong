#pragma once

#define PI 3.141592f		//180��
#define PI2 (PI * 2)			//360��

#define PI_2 (PI / 2)		//90��
#define PI_4 (PI / 4)		//45��
#define PI_8 (PI / 8)		//22.5��

//����� ���� ���ӽ����̽�
namespace Util
{
	//�� �� ������ �Ÿ�
	float getDistance(float startX, float startY,float endX, float endY);
	
	//�� �� ������ ����
	float getAngle(float startX, float startY, float endX, float endY);
}