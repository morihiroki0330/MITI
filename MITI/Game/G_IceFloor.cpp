#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"
#include "Stage.h"
#include "Number_Storage.h"
G_IceFloor::G_IceFloor()
{
	InitModel();
	InitPhysicsStaticObject();
}
bool G_IceFloor::Start()
{
	player = FindGO<Player>("player");
	stage = FindGO<Stage>("stage");
	return true;
}

void G_IceFloor::InitModel()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			IceFloorModel[Y][X].Init("Assets/modelData/ice1.tkm", IceFloorLight);
		}
	}
}
void G_IceFloor::InitPhysicsStaticObject()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			IceFloorPhysicsStaticObject[Y][X].CreateFromModel(IceFloorModel[Y][X].GetModel(), IceFloorModel[Y][X].GetModel().GetWorldMatrix());
			IceFloorPhysicsStaticObject[Y][X].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
		}
	}
}

void G_IceFloor::IceFloorOnTrue(int Y, int X)
{
	IceFloorOn[Y][X] = true;
}
void G_IceFloor::IceFloorSetPosition(int Y, int X, Vector3 Position)
{
	IceFloorPosition[Y][X].x = Position.x;
	IceFloorPosition[Y][X].y = Position.y - 50.0f;
	IceFloorPosition[Y][X].z = Position.z;
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
			if (IceFloorOn[Y][X] == true)
			{
				IceFloorModel[Y][X].SetPosition(IceFloorPosition[Y][X]);
				IceFloorPhysicsStaticObject[Y][X].SetPosition(IceFloorPosition[Y][X]);
				IceFloorModel[Y][X].Update();
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
			if (IceFloorOn[Y][X] == true)
			{
				IceFloorModel[Y][X].Draw(rc);
			}
		}
	}
}



