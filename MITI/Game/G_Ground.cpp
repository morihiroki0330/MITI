#include "stdafx.h"
#include "G_Ground.h"
#include "Number_Storage.h"
bool G_Ground::Start()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			Ground[Y][X].Init("Assets/modelData/ground1.tkm", Light);
			Ground_PSO[Y][X].CreateFromModel(Ground[Y][X].GetModel(), Ground[Y][X].GetModel().GetWorldMatrix());
			Ground_PSO[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
			Ground[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
			Ground_On[Y][X] = false;
		}
	}
	return true;
}

void G_Ground::Map_On(int Y, int X)
{
	Ground_On[Y][X] = true;
}

void G_Ground::Map_SetPosition(int Y, int X, Vector3 Position)
{
	Ground_Position[Y][X].x = Position.x;
	Ground_Position[Y][X].y = Position.y - 50.0f;
	Ground_Position[Y][X].z = Position.z;
}

void G_Ground::Update()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (Ground_On[Y][X] == true)
			{
				if (Ground_Position[Y][X].x == NON)
				{
					Ground[Y][X].SetPosition(Ground_SparePosition[Y][X]);
					Ground_PSO[Y][X].SetPosition(Ground_SparePosition[Y][X]);
					Ground[Y][X].Update();
				}else {
					Ground[Y][X].SetPosition(Ground_Position[Y][X]);
					Ground_PSO[Y][X].SetPosition(Ground_Position[Y][X]);
					Ground[Y][X].Update();
				}
			}else {
					Ground[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
					Ground_PSO[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
					Ground[Y][X].Update();
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
			if (Ground_On[Y][X] == true)
			{
				Ground[Y][X].Draw(rc);
			}
		}
	}

}