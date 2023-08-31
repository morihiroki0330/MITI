#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"
#include "Game.h"
#include "Stage.h"
#include "Bgm.h"
IronBall::IronBall()
{
	InitModel();
	InitSetPosition();
}
bool IronBall::Start()
{
	P_Game = FindGO<Game>("game");
	P_Player = FindGO<Player>("player");
	LevelSet();
	return true;
}

void IronBall::InitModel()
{
	for (int i = 0; i < 5; i++)
	{
		M_IronBallModel[i].Init("Assets/modelData/tekyu/tekyu8.tkm", M_IronBallLight);
		M_IronBallModel[i].SetScale({ 1.5f, 1.5f, 1.5f });
		M_IronBallMap[i] = M_Ymas * M_Xmas;
		M_IronBallFlag[i] = false;
	}
		M_IronBoxModel.Init("Assets/modelData/tekyu-box.tkm", M_IronBoxLight);
}
void IronBall::InitSetPosition()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_IronBoxSetPosition[Y][X].x = (Y * 192.0f) + -865.0f;
			M_IronBoxSetPosition[Y][X].y = 25.0f;
			M_IronBoxSetPosition[Y][X].z = (X * 192.0f) + -865.0f;
		}
	}
}
void IronBall::LevelSet()
{
	switch (P_Game->GetLevel())
	{
	case LEVEL0:
		M_IronBoxPosition = M_IronBoxSetPosition[4][1];
		M_IronBoxMap = 41;
		break;
	case LEVEL1:
		M_IronBoxPosition = M_IronBoxSetPosition[3][0];
		M_IronBoxMap = 30;
		break;
	case LEVEL2:
		M_IronBoxPosition = M_IronBoxSetPosition[1][0];
		M_IronBoxMap = 10;
		break;
	case LEVEL3:
		M_IronBoxPosition = M_IronBoxSetPosition[3][0];
		M_IronBoxMap = 30;
		break;
	case LEVEL4:
		M_IronBoxPosition = M_IronBoxSetPosition[1][1];
		M_IronBoxMap = 11;
		break;
	case LEVEL5:
		M_IronBoxPosition = M_IronBoxSetPosition[9][1];
		M_IronBoxMap = 91;
		break;
	case LEVEL6:
		M_IronBoxPosition = M_IronBoxSetPosition[0][1];
		M_IronBoxMap = 1;
		break;
	case LEVEL7:
		M_IronBoxPosition = M_IronBoxSetPosition[0][1];
		M_IronBoxMap = 1;
		break;
	case LEVEL8:
		M_IronBoxPosition = M_IronBoxSetPosition[3][0];
		M_IronBoxMap = 30;
		break;
	case LEVEL9:
		M_IronBoxPosition = M_IronBoxSetPosition[0][1];
		M_IronBoxMap = 1;
		break;
	default:
		break;
	}
}

void IronBall::IronBoxToGet()
{
	if (M_IronBoxMap == P_Player->GetPlayerMap() && !M_IronBoxFlag)
	{
		SoundSource* P_Se = NewGO<SoundSource>(0, "se");
		P_Se->SoundSet(SE_BOXGET , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_LoopNot);
		P_Player->InitIronBallCount(M_IronBallMax);
		M_IronBoxFlag = true;
	}
}

bool IronBall::GetBallMap(int PlayerMap)
{
	for (int i = 0; i < 5; i++)
	{
		if (M_IronBallMap[i] == PlayerMap)
		{
			return true;
		}
	}
	return false;
}
bool IronBall::WeightBoardOn(int Y, int X)
{
	for (int i = 0; i < 5; i++)
	{
		if (M_IronBallMap[i] == (Y * 10) + X)
		{
			return true;
		}
	}
	return false;
}

void IronBall::IronBallPut()
{
	if (P_Player->GetIronBallPutFlag())
	{
		for (int i = 0; i < 5; i++)
		{
			if (!M_ShowFlag[i])
			{
				M_IronBallPosition[i].x = M_IronBoxSetPosition[P_Player->GetPlayerMap() / 10][P_Player->GetPlayerMap() % 10].x;
				M_IronBallPosition[i].y = M_IronBoxSetPosition[P_Player->GetPlayerMap() / 10][P_Player->GetPlayerMap() % 10].y;
				M_IronBallPosition[i].z = M_IronBoxSetPosition[P_Player->GetPlayerMap() / 10][P_Player->GetPlayerMap() % 10].z;

				M_ShowFlag[i] = true;
				P_Player->IronBallCountMinus();
				P_Player->IronBallPutAnimationFlagSet(true);
				break;
			}
		}
		P_Player->IronBallPutFlagSet(false);
	}
}
void IronBall::IronBallGet()
{
	if (P_Player->GetIronBallGetFlag())
		{
			int Number = 0;

			for (int i = 0; i < 5; i++)
			{
				if (
					P_Player->GetPlayerPositionX() < M_IronBallPosition[i].x + S_IronBallInformation.IronBallRange &&
					P_Player->GetPlayerPositionX() > M_IronBallPosition[i].x - S_IronBallInformation.IronBallRange &&
					P_Player->GetPlayerPositionZ() < M_IronBallPosition[i].z + S_IronBallInformation.IronBallRange &&
					P_Player->GetPlayerPositionZ() > M_IronBallPosition[i].z - S_IronBallInformation.IronBallRange &&
					M_ShowFlag[i]
					)
				{
					Number = i;
					M_ShowFlag[Number] = false;
					P_Player->IronBallCountPlus();
					P_Player->IronBallGetAnimationFlagSet(true);
					M_IronBallPosition[i].x = S_GridPosition.M_GridExemptPositionX;
					M_IronBallPosition[i].z = S_GridPosition.M_GridExemptPositionZ;
					break;
				}
			}

			P_Player->IronBallGetFlagSet(false);
		}
}
void IronBall::IronBallMapSet(int PlayerMap,bool Flag)
{
	if (!Flag)
	{
		for (int i = 0; i < 5; i++)
		{
			if (M_IronBallFlag[i] && M_IronBallMap[i] == PlayerMap)
			{
				M_IronBallMap[i] = M_Ymas * M_Xmas;
				M_IronBallFlag[i] = false;
				break;
			}
		}
	}else {
		if (Flag)
		{
			for (int i = 0; i < 5; i++)
			{
				if (!M_IronBallFlag[i])
				{
					M_IronBallMap[i] = PlayerMap;
					M_IronBallFlag[i] = true;
					break;
				}
			}
		}
	}
}

void IronBall::Update()
{
	
	IronBoxToGet();
	IronBallPut();
	IronBallGet();
		
	for (int i = 0; i < 5; i++)
	{
		M_IronBallModel[i].SetPosition(M_IronBallPosition[i]);
		M_IronBallModel[i].Update();
	}
	M_IronBoxModel.SetPosition(M_IronBoxPosition);
	M_IronBoxModel.Update();
}
void IronBall::Render(RenderContext& rc)
{
	if (!M_IronBoxFlag)
	{
		M_IronBoxModel.Draw(rc);
	}

	for (int i = 0; i < 5; i++)
	{
		if (M_ShowFlag[i])
		{
			if (M_IronBoxFlag)
			{
				M_IronBallModel[i].Draw(rc);
			}
		}
	}
}

