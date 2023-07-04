#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"
#include "Game.h"
#include "Stage.h"
#include "Number_Storage.h"
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
	game = FindGO<Game>("game");
	stage = FindGO<Stage>("stage");
	player = FindGO<Player>("player");
	LevelSet();
	return true;
}

void IronBall::InitModel()
{
	for (int Count = 0; Count < 5; Count++)
	{
		IronBallModel[Count].Init("Assets/modelData/tekyu/tekyu8.tkm",IronBallLight);
		IronBallModel[Count].SetScale({ 1.5f, 1.5f, 1.5f });
		IronBallMap[Count] = 100;
		IronBallFlag[Count] = false;
	}
		IronBoxModel.Init("Assets/modelData/tekyu-box.tkm", IronBoxLight);
}
void IronBall::InitSetPosition()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			IronBoxSetPosition[Y][X].x = (Y * 192.0f) + -865.0f;
			IronBoxSetPosition[Y][X].y = 25.0f;
			IronBoxSetPosition[Y][X].z = (X * 192.0f) + -865.0f;
		}
	}
}
void IronBall::InitLight()
{
	IronBallLight.DirectionLight_D.x = 0.0f;
	IronBallLight.DirectionLight_D.y = -1.0f;
	IronBallLight.DirectionLight_D.z = 0.0f;

	IronBallLight.DirectionLight_C.x = 1.8f;
	IronBallLight.DirectionLight_C.y = 1.8f;
	IronBallLight.DirectionLight_C.z = 1.8f;
}
void IronBall::LevelSet()
{
	switch (game->GetLevel())
	{
	case Level0:
		IronBoxPosition = IronBoxSetPosition[4][1];
		IronBoxMap = 41;
		break;
	case Level1:
		IronBoxPosition = IronBoxSetPosition[3][0];
		IronBoxMap = 30;
		break;
	case Level2:
		IronBoxPosition = IronBoxSetPosition[1][0];
		IronBoxMap = 10;
		break;
	case Level3:
		IronBoxPosition = IronBoxSetPosition[3][0];
		IronBoxMap = 30;
		break;
	case Level4:
		IronBoxPosition = IronBoxSetPosition[1][1];
		IronBoxMap = 11;
		break;
	case Level5:
		IronBoxPosition = IronBoxSetPosition[9][1];
		IronBoxMap = 91;
		break;
	case Level6:
		IronBoxPosition = IronBoxSetPosition[0][1];
		IronBoxMap = 1;
		break;
	case Level7:
		IronBoxPosition = IronBoxSetPosition[0][1];
		IronBoxMap = 1;
		break;
	case Level8:
		IronBoxPosition = IronBoxSetPosition[3][0];
		IronBoxMap = 30;
		break;
	case Level9:
		IronBoxPosition = IronBoxSetPosition[0][1];
		IronBoxMap = 1;
		break;
	default:
		break;
	}
}

void IronBall::IronBoxToGet()
{
	if (IronBoxMap == player->GetPlayerMap() && IronBoxFlag == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0, "se");
		SE->SoundSet(S_BOXGET , BgmVolume , LoopNot);
		player->InitIronBallCount(IronBallMax);
		IronBoxFlag = true;
	}
}

bool IronBall::GetBallMap(int PlayerMap)
{
	for (int Count = 0; Count < 5; Count++)
	{
		if (IronBallMap[Count] == PlayerMap)
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
		if (IronBallMap[Count] == (Y * 10) + X)
		{
			return true;
		}
	}
	return false;
}

void IronBall::IronBallPut()
{
	if (player->GetIronBallPutFlag() == true)
	{
		for (int Count = 0; Count < 5; Count++)
		{
			if (ShowFlag[Count] == false)
			{
				IronBallPosition[Count].x = IronBoxSetPosition[player->GetPlayerMap() / 10][player->GetPlayerMap() % 10].x;
				IronBallPosition[Count].y = IronBoxSetPosition[player->GetPlayerMap() / 10][player->GetPlayerMap() % 10].y;
				IronBallPosition[Count].z = IronBoxSetPosition[player->GetPlayerMap() / 10][player->GetPlayerMap() % 10].z;

				ShowFlag[Count] = true;
				player->IronBallCountMinus();
				player->IronBallPutAnimationFlagSet(true);
				break;
			}
		}
		player->IronBallPutFlagSet(false);
	}
}
void IronBall::IronBallGet()
{
	if (player->GetIronBallGetFlag() == true)
		{
			int Number = 0;

			for (int Count = 0; Count < 5; Count++)
			{
				if (
					player->GetPlayerPositionX() < IronBallPosition[Count].x + IronBallRange &&
					player->GetPlayerPositionX() > IronBallPosition[Count].x - IronBallRange &&
					player->GetPlayerPositionZ() < IronBallPosition[Count].z + IronBallRange &&
					player->GetPlayerPositionZ() > IronBallPosition[Count].z - IronBallRange &&
					ShowFlag[Count] == true
					)
				{
					Number = Count;
					ShowFlag[Number] = false;
					player->IronBallCountPlus();
					player->IronBallGetAnimationFlagSet(true);
					IronBallPosition[Count].x = Grid_ExemptPosition_X;
					IronBallPosition[Count].z = Grid_ExemptPosition_Z;
					break;
				}
			}

			player->IronBallGetFlagSet(false);
		}
}
void IronBall::IronBallMapSet(int PlayerMap,bool Flag)
{
	if (Flag == Get)
	{
		for (int Count = 0; Count < 5; Count++)
		{
			if (IronBallFlag[Count] == true && IronBallMap[Count] == PlayerMap)
			{
				IronBallMap[Count] = 100;
				IronBallFlag[Count] = false;
				break;
			}
		}
	}else {
	if (Flag == Put)
	{
		for (int Count = 0; Count < 5; Count++)
		{
			if (IronBallFlag[Count] == false)
			{
				IronBallMap[Count] = PlayerMap;
				IronBallFlag[Count] = true;
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
		IronBallModel[Count].SetPosition(IronBallPosition[Count]);
		IronBallModel[Count].Update();
	}
	IronBoxModel.SetPosition(IronBoxPosition);
	IronBoxModel.Update();
}
void IronBall::Render(RenderContext& rc)
{
	if (IronBoxFlag == false)
	{
		IronBoxModel.Draw(rc);
	}

	for (int Count = 0; Count < 5; Count++)
	{
		if (ShowFlag[Count] == true)
		{
			if (IronBoxFlag == true)
			{
				IronBallModel[Count].Draw(rc);
			}
		}
	}
}

