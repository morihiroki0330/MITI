#include "stdafx.h"
#include "Box.h"
#include "Number_Storage.h"
#include "Player.h"
#include "Game.h"
bool Box::Start()
{
	KabeBoxSet();

	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			BlockBox[Y][X].CreateBox({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z}, Quaternion::Identity, Vector3::One * 270.0f);
		}
	}
	KabeBox[UP].CreateBox(Kabe_Position[UP],Kabe_Rotation[UP],Kabe_Size[UP]);
	KabeBox[DOWN].CreateBox(Kabe_Position[DOWN], Kabe_Rotation[DOWN], Kabe_Size[DOWN]);
	KabeBox[RIGHT].CreateBox(Kabe_Position[RIGHT], Kabe_Rotation[RIGHT], Kabe_Size[RIGHT]);
	KabeBox[LEFT].CreateBox(Kabe_Position[LEFT], Kabe_Rotation[LEFT], Kabe_Size[LEFT]);
	
	KaidanBox.CreateBox({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z}, Quaternion::Identity, Vector3::One * 150.0f);

	player = FindGO<Player>("player");
	game = FindGO<Game>("game");

	return true;
}

void Box::KabeBoxSet()
{
	Kabe_Position[UP] = { -1057.0f, NON, NON };
	Kabe_Rotation[UP] = { NON, NON, NON, 1.0f };
	Kabe_Size[UP] = { 270.0f, 270.0f, 1920.0f };
	
	Kabe_Position[DOWN] = { 1057.0f, 0.0, NON };
	Kabe_Rotation[DOWN] = { NON, NON, NON, 1.0f };
	Kabe_Size[DOWN] = { 270.0f, 270.0f, 1920.0f };

	Kabe_Position[RIGHT] = { NON, 0.0, 1057.0f };
	Kabe_Rotation[RIGHT] = { NON, 90.0f, NON, 1.0f };
	Kabe_Size[RIGHT] = { 1920.0f, 270.0f, 270.0f };

	Kabe_Position[LEFT] = { NON, 0.0, -1057.0f };
	Kabe_Rotation[LEFT] = { NON, 90.0f, NON, 1.0f };
	Kabe_Size[LEFT] = { 1920.0f, 270.0f, 270.0f };
}