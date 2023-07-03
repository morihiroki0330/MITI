#include "stdafx.h"
#include "Box.h"
#include "Number_Storage.h"
#include "Player.h"
#include "Game.h"
Box::Box()
{
	InitKabeBox();
	InitKaidanBox();
	InitBlock();
}
bool Box::Start()
{
	player = FindGO<Player>("player");
	game = FindGO<Game>("game");
	return true;
}

void Box::InitKabeBox()
{
	KabePosition[StageBehindUp] = { -1057.0f, 0.0f, 0.0f };
	KabeRotation[StageBehindUp] = { 0.0f, 0.0f, 0.0f, 1.0f };
	KabeScale[StageBehindUp] = { 270.0f, 270.0f, 1920.0f };
	
	KabePosition[StageBehindDown] = { 1057.0f, 0.0, 0.0f };
	KabeRotation[StageBehindDown] = { 0.0f, 0.0f, 0.0f, 1.0f };
	KabeScale[StageBehindDown] = { 270.0f, 270.0f, 1920.0f };

	KabePosition[StageBehindRight] = { 0.0f, 0.0, 1057.0f };
	KabeRotation[StageBehindRight] = { 0.0f, 90.0f, 0.0f, 1.0f };
	KabeScale[StageBehindRight] = { 1920.0f, 270.0f, 270.0f };

	KabePosition[StageBehindLeft] = { 0.0f, 0.0, -1057.0f };
	KabeRotation[StageBehindLeft] = { 0.0f, 90.0f, 0.0f, 1.0f };
	KabeScale[StageBehindLeft] = { 1920.0f, 270.0f, 270.0f };
	
	KabeBox[StageBehindUp].CreateBox(KabePosition[StageBehindUp], KabeRotation[StageBehindUp], KabeScale[StageBehindUp]);
	KabeBox[StageBehindDown].CreateBox(KabePosition[StageBehindDown], KabeRotation[StageBehindDown], KabeScale[StageBehindDown]);
	KabeBox[StageBehindRight].CreateBox(KabePosition[StageBehindRight], KabeRotation[StageBehindRight], KabeScale[StageBehindRight]);
	KabeBox[StageBehindLeft].CreateBox(KabePosition[StageBehindLeft], KabeRotation[StageBehindLeft], KabeScale[StageBehindLeft]);
}
void Box::InitKaidanBox()
{
	KaidanBox.CreateBox({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z }, Quaternion::Identity, Vector3::One * 150.0f);
}
void Box::InitBlock()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			BlockBox[Y][X].CreateBox({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z }, Quaternion::Identity, Vector3::One * 270.0f);
		}
	}
}