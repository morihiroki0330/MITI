#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"
#include "Stage.h"
#include "Number_Storage.h"
bool G_IceFloor::Start()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			IceFloor[Y][X].Init("Assets/modelData/ice1.tkm", Light);
			IceFloor_PSO[Y][X].CreateFromModel(IceFloor[Y][X].GetModel(), IceFloor[Y][X].GetModel().GetWorldMatrix());
			IceFloor_PSO[Y][X].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
		}
	}
	
	player = FindGO<Player>("player");
	stage = FindGO<Stage>("stage");
	return true;
}

void G_IceFloor::Map_On(int Y, int X)
{
	IceFloor_On[Y][X] = true;
}

void G_IceFloor::Map_SetPosition(int Y, int X, Vector3 Position)
{
	IceFloor_Position[Y][X].x = Position.x;
	IceFloor_Position[Y][X].y = Position.y - 50.0f;
	IceFloor_Position[Y][X].z = Position.z;
}

void G_IceFloor::IceFloorOnPlayer()
{
	if (stage->MapData[(player->PlayerMap / 10)][(player->PlayerMap % 10)].GroundData == ICE) { player->SlipFlag = true; }
}

void G_IceFloor::Update()
{
	IceFloorOnPlayer();

	for (int Y = 0; Y < 10; Y ++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (IceFloor_On[Y][X] == true)
			{
				IceFloor[Y][X].SetPosition(IceFloor_Position[Y][X]);
				IceFloor_PSO[Y][X].SetPosition(IceFloor_Position[Y][X]);
				IceFloor[Y][X].Update();
			}
		}
	}

}

void G_IceFloor::Render(RenderContext& rc)
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (IceFloor_On[Y][X] == true)
			{
				IceFloor[Y][X].Draw(rc);
			}
		}
	}
}



