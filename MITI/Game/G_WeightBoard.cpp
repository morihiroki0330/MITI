#include "stdafx.h"
#include "G_WeightBoard.h"
#include "Player.h"
#include "IronBall.h"
#include "Stage.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
G_WeightBoard::G_WeightBoard()
{
	InitModel();
}
bool G_WeightBoard::Start()
{
	P_IronBall = FindGO<IronBall>("ironball");
	P_Stage = FindGO<Stage>("stage");
	P_Player = FindGO<Player>("player");
	return true;
}
void G_WeightBoard::InitModel()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_WeightBoardModel[Y][X].Init("Assets/modelData/ita.tkm", M_WeightBoardLight);
			M_WeightBoardModel[Y][X].SetScale(M_WeightBoardScale);
			M_WeightBoardPhysicsStaticObject[Y][X].CreateFromModel(M_WeightBoardModel[Y][X].GetModel(), M_WeightBoardModel[Y][X].GetModel().GetWorldMatrix());
			M_WeightBoardPhysicsStaticObject[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
		}
	}
}

void G_WeightBoard::WeightBoardOnTrue(int Y, int X)
{
	M_WeightBoardOn[Y][X] = true;
}
void G_WeightBoard::WeightBoardSetPosition(int Y, int X, Vector3 Position)
{
	M_WeightBoardPosition[Y][X].x = Position.x;
	M_WeightBoardPosition[Y][X].y = Position.y - 20.0f;
	M_WeightBoardPosition[Y][X].z = Position.z;
}

void G_WeightBoard::LinkCountSet(int Y, int X, int Count)
{
	M_LinkCount[Y][X] = Count;
}
void G_WeightBoard::LinkObjectSet(int Y, int X, int W, int Object)
{
	M_LinkObject[Y][X][W] = Object;
}
void G_WeightBoard::LinkNumberSet(int Y, int X, int W, int Number)
{
	M_LinkNumber[Y][X][W] = Number;
}

void G_WeightBoard::Sound()
{
	if (M_BgmSet[(P_Player->GetPlayerMap() / 10)][(P_Player->GetPlayerMap() % 10)] && !M_HitFlag[(P_Player->GetPlayerMap() / 10)][(P_Player->GetPlayerMap() % 10)])
	{
		SoundSource* P_Se = NewGO<SoundSource>(0);
		P_Se->SoundSet(SE_WEIGHTBOARD, S_SoundSetting.M_BgmVolume , S_SoundSetting.M_LoopNot);
		M_HitFlag[(P_Player->GetPlayerMap() / 10)][(P_Player->GetPlayerMap() % 10)] = true;
	}
}
void G_WeightBoard::WeightBoardOnPlayer()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (M_WeightBoardOn[Y][X])
			{
				if (P_Stage->GetSkyData(P_Player->GetPlayerMap()) == WEIGHTBOARD)
				{
					M_SwitchOnFlag[(P_Player->GetPlayerMap() / 10)][(P_Player->GetPlayerMap() % 10)] = true;
					M_BgmSet[(P_Player->GetPlayerMap() / 10)][(P_Player->GetPlayerMap() % 10)] = true;
				}else {
					M_SwitchOnFlag[Y][X] = false;
					M_BgmSet[Y][X] = false;
					M_HitFlag[Y][X] = false;
				}

				for (int i = 0; i < 5; i++)
				{
					if (P_IronBall->WeightBoardOn(Y, X))
					{
						M_SwitchOnFlag[Y][X] = true;
						break;
					}
				}

			}
		}
	}

}

void G_WeightBoard::Update()
{
	WeightBoardOnPlayer();
	Sound();
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (M_WeightBoardOn[Y][X])
			{
				M_WeightBoardModel[Y][X].SetPosition(M_WeightBoardPosition[Y][X]);
				M_WeightBoardPhysicsStaticObject[Y][X].SetPosition(M_WeightBoardPosition[Y][X]);
				M_WeightBoardModel[Y][X].Update();
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
			if (M_WeightBoardOn[Y][X])
			{
				M_WeightBoardModel[Y][X].Draw(rc);
			}
		}
	}
}