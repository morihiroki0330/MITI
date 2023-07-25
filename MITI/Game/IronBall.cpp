#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"
#include "Game.h"
#include "Stage.h"
#include "NumberStorage.h"
#include "Bgm.h"
#include "G_WeightBoard.h"
IronBall::IronBall()
{
	InitModel();
	InitSetPosition();
	InitLight();
}
bool IronBall::Start()
{
	P_Game = FindGO<Game>("game");
	P_Stage = FindGO<Stage>("stage");
	P_Player = FindGO<Player>("player");
	LevelSet();
	return true;
}

void IronBall::InitModel()
{
	for (int Count = 0; Count < 5; Count++)
	{
		M_IronBallModel[Count].Init("Assets/modelData/tekyu/tekyu8.tkm", M_IronBallLight);
		M_IronBallModel[Count].SetScale({ 1.5f, 1.5f, 1.5f });
		M_IronBallMap[Count] = 100;
		M_IronBallFlag[Count] = false;
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
void IronBall::InitLight()
{
	M_IronBallLight.DirectionLight_D.x = 0.0f;
	M_IronBallLight.DirectionLight_D.y = -1.0f;
	M_IronBallLight.DirectionLight_D.z = 0.0f;

	M_IronBallLight.DirectionLight_C.x = 1.8f;
	M_IronBallLight.DirectionLight_C.y = 1.8f;
	M_IronBallLight.DirectionLight_C.z = 1.8f;
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
	if (M_IronBoxMap == P_Player->GetPlayerMap() && M_IronBoxFlag == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0, "se");
		SE->SoundSet(SE_BOXGET , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_LoopNot);
		P_Player->InitIronBallCount(M_IronBallMax);
		M_IronBoxFlag = true;
	}
}

bool IronBall::GetBallMap(int PlayerMap)
{
	for (int Count = 0; Count < 5; Count++)
	{
		if (M_IronBallMap[Count] == PlayerMap)
		{
			return true;
		}
	}
	return false;
}
bool IronBall::WeightBoardOn(int Y, int X)
{
	for (int Count = 0; Count < 5; Count++)
	{
		if (M_IronBallMap[Count] == (Y * 10) + X)
		{
			return true;
		}
	}
	return false;
}

void IronBall::IronBallPut()
{
	if (P_Player->GetIronBallPutFlag() == true)
	{
		for (int Count = 0; Count < 5; Count++)
		{
			if (M_ShowFlag[Count] == false)
			{
				M_IronBallPosition[Count].x = M_IronBoxSetPosition[P_Player->GetPlayerMap() / 10][P_Player->GetPlayerMap() % 10].x;
				M_IronBallPosition[Count].y = M_IronBoxSetPosition[P_Player->GetPlayerMap() / 10][P_Player->GetPlayerMap() % 10].y;
				M_IronBallPosition[Count].z = M_IronBoxSetPosition[P_Player->GetPlayerMap() / 10][P_Player->GetPlayerMap() % 10].z;

				M_ShowFlag[Count] = true;
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
	if (P_Player->GetIronBallGetFlag() == true)
		{
			int Number = 0;

			for (int Count = 0; Count < 5; Count++)
			{
				if (
					P_Player->GetPlayerPositionX() < M_IronBallPosition[Count].x + S_IronBallInformation.IronBallRange &&
					P_Player->GetPlayerPositionX() > M_IronBallPosition[Count].x - S_IronBallInformation.IronBallRange &&
					P_Player->GetPlayerPositionZ() < M_IronBallPosition[Count].z + S_IronBallInformation.IronBallRange &&
					P_Player->GetPlayerPositionZ() > M_IronBallPosition[Count].z - S_IronBallInformation.IronBallRange &&
					M_ShowFlag[Count] == true
					)
				{
					Number = Count;
					M_ShowFlag[Number] = false;
					P_Player->IronBallCountPlus();
					P_Player->IronBallGetAnimationFlagSet(true);
					M_IronBallPosition[Count].x = S_GridPosition.M_GridExemptPositionX;
					M_IronBallPosition[Count].z = S_GridPosition.M_GridExemptPositionZ;
					break;
				}
			}

			P_Player->IronBallGetFlagSet(false);
		}
}
void IronBall::IronBallMapSet(int PlayerMap,bool Flag)
{
	if (Flag == false)
	{
		for (int Count = 0; Count < 5; Count++)
		{
			if (M_IronBallFlag[Count] == true && M_IronBallMap[Count] == PlayerMap)
			{
				M_IronBallMap[Count] = 100;
				M_IronBallFlag[Count] = false;
				break;
			}
		}
	}else {
	if (Flag == true)
	{
		for (int Count = 0; Count < 5; Count++)
		{
			if (M_IronBallFlag[Count] == false)
			{
				M_IronBallMap[Count] = PlayerMap;
				M_IronBallFlag[Count] = true;
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
		
	for (int Count = 0; Count < 5; Count++)
	{
		M_IronBallModel[Count].SetPosition(M_IronBallPosition[Count]);
		M_IronBallModel[Count].Update();
	}
	M_IronBoxModel.SetPosition(M_IronBoxPosition);
	M_IronBoxModel.Update();
}
void IronBall::Render(RenderContext& rc)
{
	if (M_IronBoxFlag == false)
	{
		M_IronBoxModel.Draw(rc);
	}

	for (int Count = 0; Count < 5; Count++)
	{
		if (M_ShowFlag[Count] == true)
		{
			if (M_IronBoxFlag == true)
			{
				M_IronBallModel[Count].Draw(rc);
			}
		}
	}
}

