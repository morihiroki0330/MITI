#include "stdafx.h"
#include "G_WeightBoard.h"
#include "Player.h"
#include "IronBall.h"
#include "G_Block.h"
#include "Stage.h"
#include "Bgm.h"
#include "Number_Storage.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
G_WeightBoard::G_WeightBoard()
{
	InitModel();
	InitPhysicsStaticObject();
}
bool G_WeightBoard::Start()
{
	weightboard = FindGO<G_WeightBoard>("weightboard");
	ironball = FindGO<IronBall>("ironball");
	stage = FindGO<Stage>("stage");
	player = FindGO<Player>("player");
	return true;
}

void G_WeightBoard::InitModel()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			WeightBoardModel[Y][X].Init("Assets/modelData/ita.tkm", WeightBoardLight);
			WeightBoardModel[Y][X].SetScale(WeightBoardScale);
		}
	}
}
void G_WeightBoard::InitPhysicsStaticObject()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			WeightBoardPhysicsStaticObject[Y][X].CreateFromModel(WeightBoardModel[Y][X].GetModel(), WeightBoardModel[Y][X].GetModel().GetWorldMatrix());
			WeightBoardPhysicsStaticObject[Y][X].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
		}
	}
}

void G_WeightBoard::WeightBoardOnTrue(int Y, int X)
{
	WeightBoardOn[Y][X] = true;
}
void G_WeightBoard::WeightBoardSetPosition(int Y, int X, Vector3 Position)
{
	WeightBoardPosition[Y][X].x = Position.x;
	WeightBoardPosition[Y][X].y = Position.y - 20.0f;
	WeightBoardPosition[Y][X].z = Position.z;
}

void G_WeightBoard::Sound()
{
	if (BgmSet[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] == true && HitFlag[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_WEIGHTBOARD, BgmVolume , LoopNot);
		HitFlag[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] = true;
	}
}
void G_WeightBoard::WeightBoardOnPlayer()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (WeightBoardOn[Y][X] == true)
			{
				if (stage->GetSkyData(player->GetPlayerMap()) == WEIGHTBOARD)
				{
					SwitchOnFlag[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] = true;
					BgmSet[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] = true;
				}else {
					SwitchOnFlag[Y][X] = false;
					BgmSet[Y][X] = false;
					HitFlag[Y][X] = false;
				}

				for (int W = 0; W < 5; W++)
				{
					if (ironball->WeightBoardOn(Y, X) == true)
					{
						SwitchOnFlag[Y][X] = true;
						break;
					}
				}

			}
		}
	}

}

void G_WeightBoard::LinkCountSet(int Y, int X, int Count)
{
	LinkCount[Y][X] = Count;
}
void G_WeightBoard::LinkObjectSet(int Y, int X, int W, int Object)
{
	LinkObject[Y][X][W] = Object;
}
void G_WeightBoard::LinkNumberSet(int Y, int X, int W, int Number)
{
	LinkNumber[Y][X][W] = Number;
}

void G_WeightBoard::Update()
{
	WeightBoardOnPlayer();
	Sound();
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (WeightBoardOn[Y][X] == true)
			{
				WeightBoardModel[Y][X].SetPosition(WeightBoardPosition[Y][X]);
				WeightBoardPhysicsStaticObject[Y][X].SetPosition(WeightBoardPosition[Y][X]);
				WeightBoardModel[Y][X].Update();
			}
		}
	}
}
void G_WeightBoard::Render(RenderContext& rc)
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (WeightBoardOn[Y][X] == true)
			{
				WeightBoardModel[Y][X].Draw(rc);
			}
		}
	}
}