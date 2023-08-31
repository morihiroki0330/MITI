#include "stdafx.h"
#include "Box.h"
Box::Box()
{
	InitKabeBox();
	InitKaidanBox();
	InitBlock();
}

void Box::InitKabeBox()
{
	M_KabePosition[STAGEBEHIND_UP]    = { -1057.0f, 0.0f , 0.0f };
	M_KabePosition[STAGEBEHIND_DOWN]  = { 1057.0f , 0.0f , 0.0f };
	M_KabePosition[STAGEBEHIND_RIGHT] = { 0.0f    , 0.0  , 1057.0f };
	M_KabePosition[STAGEBEHIND_LEFT]  = { 0.0f    , 0.0  , -1057.0f };

	M_KabeRotation[STAGEBEHIND_UP]    = { 0.0f , 0.0f  , 0.0f , 1.0f };
	M_KabeRotation[STAGEBEHIND_DOWN]  = { 0.0f , 0.0f  , 0.0f , 1.0f };
	M_KabeRotation[STAGEBEHIND_RIGHT] = { 0.0f , 90.0f , 0.0f , 1.0f };
	M_KabeRotation[STAGEBEHIND_LEFT]  = { 0.0f , 90.0f , 0.0f , 1.0f };

	M_KabeScale[STAGEBEHIND_UP]    = { 270.0f  , 270.0f , 1920.0f };
	M_KabeScale[STAGEBEHIND_DOWN]  = { 270.0f  , 270.0f , 1920.0f };
	M_KabeScale[STAGEBEHIND_RIGHT] = { 1920.0f , 270.0f , 270.0f };
	M_KabeScale[STAGEBEHIND_LEFT]  = { 1920.0f , 270.0f , 270.0f };
	
	M_KabeBox[STAGEBEHIND_UP].CreateBox(M_KabePosition[STAGEBEHIND_UP], M_KabeRotation[STAGEBEHIND_UP], M_KabeScale[STAGEBEHIND_UP]);
	M_KabeBox[STAGEBEHIND_DOWN].CreateBox(M_KabePosition[STAGEBEHIND_DOWN], M_KabeRotation[STAGEBEHIND_DOWN], M_KabeScale[STAGEBEHIND_DOWN]);
	M_KabeBox[STAGEBEHIND_RIGHT].CreateBox(M_KabePosition[STAGEBEHIND_RIGHT], M_KabeRotation[STAGEBEHIND_RIGHT], M_KabeScale[STAGEBEHIND_RIGHT]);
	M_KabeBox[STAGEBEHIND_LEFT].CreateBox(M_KabePosition[STAGEBEHIND_LEFT], M_KabeRotation[STAGEBEHIND_LEFT], M_KabeScale[STAGEBEHIND_LEFT]);
}
void Box::InitKaidanBox()
{
	M_KaidanBox.CreateBox
	(
		{
			S_GridPosition.M_GridExemptPositionX,
			S_GridPosition.M_GridExemptPositionY, 
			S_GridPosition.M_GridExemptPositionZ
		}	
			,Quaternion::Identity,
			 Vector3::One * 150.0f
	);
}
void Box::InitBlock()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_BlockBox[Y][X].CreateBox
			(
				{
					S_GridPosition.M_GridExemptPositionX,
					S_GridPosition.M_GridExemptPositionY,
					S_GridPosition.M_GridExemptPositionZ
				}	
					,Quaternion::Identity,
					 Vector3::One * 270.0f
			);
		}
	}
}