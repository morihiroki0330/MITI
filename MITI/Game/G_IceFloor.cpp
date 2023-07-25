#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"
#include "Stage.h"
G_IceFloor::G_IceFloor()
{
	InitModel();
	InitPhysicsStaticObject();
}
bool G_IceFloor::Start()
{
	P_Player = FindGO<Player>("player");
	P_Stage = FindGO<Stage>("stage");
	return true;
}

void G_IceFloor::InitModel()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_IceFloorModel[Y][X].Init("Assets/modelData/ice1.tkm", M_IceFloorLight);
		}
	}
}
void G_IceFloor::InitPhysicsStaticObject()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_IceFloorPhysicsStaticObject[Y][X].CreateFromModel(M_IceFloorModel[Y][X].GetModel(), M_IceFloorModel[Y][X].GetModel().GetWorldMatrix());
			M_IceFloorPhysicsStaticObject[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
		}
	}
}
void G_IceFloor::IceFloorOnTrue(int Y, int X)
{
	M_IceFloorOn[Y][X] = true;
}
void G_IceFloor::IceFloorSetPosition(int Y, int X, Vector3 Position)
{
	M_IceFloorPosition[Y][X].x = Position.x;
	M_IceFloorPosition[Y][X].y = Position.y - 50.0f;
	M_IceFloorPosition[Y][X].z = Position.z;
}
void G_IceFloor::IceFloorOnPlayer()
{
	if (P_Stage->GetGroundData(P_Player->GetPlayerMap()) == ICE) { P_Player->PlayerSlipFlagSet(true); }
}

void G_IceFloor::Update()
{
	IceFloorOnPlayer();

	for (int Y = 0; Y < 10; Y ++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (M_IceFloorOn[Y][X] == true)
			{
				M_IceFloorModel[Y][X].SetPosition(M_IceFloorPosition[Y][X]);
				M_IceFloorPhysicsStaticObject[Y][X].SetPosition(M_IceFloorPosition[Y][X]);
				M_IceFloorModel[Y][X].Update();
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
			if (M_IceFloorOn[Y][X] == true)
			{
				M_IceFloorModel[Y][X].Draw(rc);
			}
		}
	}
}



