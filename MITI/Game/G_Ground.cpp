#include "stdafx.h"
#include "G_Ground.h"
#include "NumberStorage.h"
G_Ground::G_Ground()
{
	InitModel();
	InitPhysicsStaticObject();
}

void G_Ground::InitModel()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_GroundModel[Y][X].Init("Assets/modelData/ground1.tkm", M_GroundLight);
			M_GroundModel[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
			M_GroundOn[Y][X] = false;
		}
	}
}
void G_Ground::InitPhysicsStaticObject()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_GroundPhysicsStaticObject[Y][X].CreateFromModel(M_GroundModel[Y][X].GetModel(), M_GroundModel[Y][X].GetModel().GetWorldMatrix());
			M_GroundPhysicsStaticObject[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
		}
	}
}
void G_Ground::GroundOnTrue(int Y, int X)
{
	M_GroundOn[Y][X] = true;
}
void G_Ground::GroundSetPosition(int Y, int X, Vector3 Position)
{
	M_GroundPosition[Y][X].x = Position.x;
	M_GroundPosition[Y][X].y = Position.y - 50.0f;
	M_GroundPosition[Y][X].z = Position.z;

	M_GroundSparePosition[Y][X].x = Position.x;
	M_GroundSparePosition[Y][X].y = Position.y - 50.0f;
	M_GroundSparePosition[Y][X].z = Position.z;
}
void G_Ground::Update()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (M_GroundOn[Y][X] == true)
			{
				if (M_GroundPosition[Y][X].x == 0.0f || M_GroundPosition[Y][X].z == 0.0f)
				{
					M_GroundModel[Y][X].SetPosition(M_GroundSparePosition[Y][X]);
					M_GroundPhysicsStaticObject[Y][X].SetPosition(M_GroundSparePosition[Y][X]);
					M_GroundModel[Y][X].Update();
				}else {
					M_GroundModel[Y][X].SetPosition(M_GroundPosition[Y][X]);
					M_GroundPhysicsStaticObject[Y][X].SetPosition(M_GroundPosition[Y][X]);
					M_GroundModel[Y][X].Update();
				}
			}else {
				M_GroundModel[Y][X].SetPosition({S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ});
				M_GroundPhysicsStaticObject[Y][X].SetPosition({S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ});
				M_GroundModel[Y][X].Update();
			}
		}
	}
}
void G_Ground::Render(RenderContext& rc)
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (M_GroundOn[Y][X] == true)
			{
				M_GroundModel[Y][X].Draw(rc);
			}
		}
	}

}