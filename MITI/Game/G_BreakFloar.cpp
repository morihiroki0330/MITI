#include "stdafx.h"
#include "G_BreakFloar.h"
#include "Player.h"
#include "Stage.h"
#include "Number_Storage.h"
bool G_BreakFloar::Start()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			BreakFloar[Y][X].Init("Assets/modelData/hole.tkm", Light);
			BreakFloar_PSO[Y][X].CreateFromModel(BreakFloar[Y][X].GetModel(), BreakFloar[Y][X].GetModel().GetWorldMatrix());
			BreakFloar_PSO[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
		}
	}
	player = FindGO<Player>("player");
	stage = FindGO<Stage>("stage");
	return true;
}

void G_BreakFloar::Update()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (stage->MapData[(player->PlayerMap / 10)][(player->PlayerMap % 10)].GroundData == BREAKFLOOR){DeleteGO(this);}

			if (BreakFloar_On[Y][X] == true)
			{
				BreakFloar[Y][X].SetPosition(BreakFloar_Position[Y][X]);
				BreakFloar_PSO[Y][X].SetPosition(BreakFloar_Position[Y][X]);
				BreakFloar[Y][X].Update();
			}
		}
	}
}

void G_BreakFloar::Map_On(int Y , int X)
{
	BreakFloar_On[Y][X] = true;
}

void G_BreakFloar::Map_SetPosition(int Y , int X , Vector3 Position)
{
	BreakFloar_Position[Y][X] = Position;
}

void G_BreakFloar::Render(RenderContext& rc)
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (BreakFloar_On[Y][X] == true)
			{
				BreakFloar[Y][X].Draw(rc);
			}
		}
	}
}