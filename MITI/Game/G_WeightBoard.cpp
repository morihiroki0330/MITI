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
bool G_WeightBoard::Start()
{
	for (int Y = 0 ; Y < 10 ; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			WeightBoard[Y][X].Init("Assets/modelData/ita.tkm", Light);
			WeightBoard[Y][X].SetScale(WeightBoard_Scale);
			WeightBoard_PSO[Y][X].CreateFromModel(WeightBoard[Y][X].GetModel(), WeightBoard[Y][X].GetModel().GetWorldMatrix());
			WeightBoard_PSO[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
		}
	}

	weightboard = FindGO<G_WeightBoard>("weightboard");
	ironball = FindGO<IronBall>("ironball");
	stage = FindGO<Stage>("stage");
	player = FindGO<Player>("player");

	return true;
}

void G_WeightBoard::Map_On(int Y, int X)
{
	WeightBoard_On[Y][X] = true;
}

void G_WeightBoard::Map_SetPosition(int Y, int X, Vector3 Position)
{
	WeightBoard_Position[Y][X].x = Position.x;
	WeightBoard_Position[Y][X].y = Position.y - 20.0f;
	WeightBoard_Position[Y][X].z = Position.z;
}

void G_WeightBoard::Sound()
{
	if (BgmSet[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] == true && HitFlag[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_WEIGHTBOARD, Bgm_Volume , LoopNot);
		HitFlag[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] = true;
	}
}

void G_WeightBoard::WeightBoardOnPlayer()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (WeightBoard_On[Y][X] == true)
			{
				if (stage->GetSkyData(player->GetPlayerMap()) == WEIGHTBOARD)
				{
					PutFlag[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] = true;
					BgmSet[(player->GetPlayerMap() / 10)][(player->GetPlayerMap() % 10)] = true;
				}else {
					PutFlag[Y][X] = false;
					BgmSet[Y][X] = false;
					HitFlag[Y][X] = false;
				}

				for (int W = 0; W < 5; W++)
				{
					if (ironball->WeightBoardOn(Y, X) == true)
					{
						PutFlag[Y][X] = true;
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
			if (WeightBoard_On[Y][X] == true)
			{
				WeightBoard[Y][X].SetPosition(WeightBoard_Position[Y][X]);
				WeightBoard_PSO[Y][X].SetPosition(WeightBoard_Position[Y][X]);
				WeightBoard[Y][X].Update();
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
			if (WeightBoard_On[Y][X] == true)
			{
				WeightBoard[Y][X].Draw(rc);
			}
		}
	}
}