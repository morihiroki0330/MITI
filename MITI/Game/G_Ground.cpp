#include "stdafx.h"
#include "G_Ground.h"
#include "Number_Storage.h"
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
			GroundModel[Y][X].Init("Assets/modelData/ground1.tkm", GroundLight);
			GroundModel[Y][X].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
			GroundOn[Y][X] = false;
		}
	}
}
void G_Ground::InitPhysicsStaticObject()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			GroundPhysicsStaticObject[Y][X].CreateFromModel(GroundModel[Y][X].GetModel(), GroundModel[Y][X].GetModel().GetWorldMatrix());
			GroundPhysicsStaticObject[Y][X].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
		}
	}
}

void G_Ground::GroundOnTrue(int Y, int X)
{
	GroundOn[Y][X] = true;
}
void G_Ground::GroundSetPosition(int Y, int X, Vector3 Position)
{
	GroundPosition[Y][X].x = Position.x;
	GroundPosition[Y][X].y = Position.y - 50.0f;
	GroundPosition[Y][X].z = Position.z;

	GroundSparePosition[Y][X].x = Position.x;
	GroundSparePosition[Y][X].y = Position.y - 50.0f;
	GroundSparePosition[Y][X].z = Position.z;
}

void G_Ground::Update()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (GroundOn[Y][X] == true)
			{
				if (GroundPosition[Y][X].x == NON || GroundPosition[Y][X].z == NON)
				{
					GroundModel[Y][X].SetPosition(GroundSparePosition[Y][X]);
					GroundPhysicsStaticObject[Y][X].SetPosition(GroundSparePosition[Y][X]);
					GroundModel[Y][X].Update();
				}else {
					GroundModel[Y][X].SetPosition(GroundPosition[Y][X]);
					GroundPhysicsStaticObject[Y][X].SetPosition(GroundPosition[Y][X]);
					GroundModel[Y][X].Update();
				}
			}else {
					GroundModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
					GroundPhysicsStaticObject[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
					GroundModel[Y][X].Update();
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
			if (GroundOn[Y][X] == true)
			{
				GroundModel[Y][X].Draw(rc);
			}
		}
	}

}