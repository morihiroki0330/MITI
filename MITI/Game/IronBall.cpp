#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"
#include "Game.h"
#include "Stage.h"
#include "Number_Storage.h"
#include "Bgm.h"
#include "G_WeightBoard.h"
#include "G_Kaidan.h"
bool IronBall::Start()
{
	game = FindGO<Game>("game");
	stage = FindGO<Stage>("stage");
	player = FindGO<Player>("player");
	for (int count = 0; count < 5; count++)
	{
		IronBall[count].Init("Assets/modelData/tekyu/tekyu8.tkm",Light);
		IronBall[count].SetScale({ 1.5f, 1.5f, 1.5f });
	}
	IronBox.Init("Assets/modelData/tekyu-box.tkm", Light);

	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			SetPosition[Y][X].x = (Y * 192.0f) + -865.0f;
			SetPosition[Y][X].y = 25.0f;
			SetPosition[Y][X].z = (X * 192.0f) + -865.0f;
		}
	}

	LightSet();
	LevelSet();
	return true;
}
bool IronBall::GetBallMap(int PlayerMap)
{

	for (int count = 0; count < 5; count++)
	{
		if (IronBall_Map[count] == PlayerMap)
		{
			return true;
		}
	}
	return false;
}
bool IronBall::WeightBoardOn(int Y, int X)
{
	for (int count = 0; count < 5; count++)
	{
		if (IronBall_Map[count] == (Y * 10) + X)
		{
			return true;
		}
	}
	return false;
}

void IronBall::LightSet()
{
	Light.DirectionLight_D.x = NON;
	Light.DirectionLight_D.y = -1.0f;
	Light.DirectionLight_D.z = NON;

	Light.DirectionLight_C.x = 1.8f;
	Light.DirectionLight_C.y = 1.8f;
	Light.DirectionLight_C.z = 1.8f;
}

void IronBall::LevelSet()
{
	switch (game->GetLevel())
	{
		case Level0:
			IronBox_Position = SetPosition[4][1];
			IronBox_Map = 41;
			break;
		case Level1:
			IronBox_Position = SetPosition[3][0];
			IronBox_Map = 30;
			break;
		case Level2:
			IronBox_Position = SetPosition[1][0];
			IronBox_Map = 10;
			break;
		case Level3:
			IronBox_Position = SetPosition[3][0];
			IronBox_Map = 30;
			break;
		case Level4:
			IronBox_Position = SetPosition[1][1];
			IronBox_Map = 11;
			break;
		case Level5:
			IronBox_Position = SetPosition[9][1];
			IronBox_Map = 30;
			break;
		case Level6:
			IronBox_Position = SetPosition[0][1];
			IronBox_Map = 1;
			break;
		case Level7:
			IronBox_Position = SetPosition[0][1];
			IronBox_Map = 1;
			break;
		case Level8:
			IronBox_Position = SetPosition[3][0];
			IronBox_Map = 30;
			break;
		case Level9:
			IronBox_Position = SetPosition[0][1];
			IronBox_Map = 1;
			break;
		default:
			break;
	}
}
void IronBall::IronBoxToGet()
{
	if (IronBox_Map == player->PlayerMap && BoxFlag == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0, "se");
		SE->SoundSet(S_BOXGET , Bgm_Volume , LoopNot);
		player->ironBall = 5;
		BoxFlag = true;
	}
}
void IronBall::IronBallPut()
{
	if (player->IronPut == true)
	{
		for (int count = 0; count < 5; count++)
		{
			if (ShowFlag[count] == false)
			{
				IronBall_Position[count].x = SetPosition[player->PlayerMap / 10][player->PlayerMap % 10].x;
				IronBall_Position[count].y = SetPosition[player->PlayerMap / 10][player->PlayerMap % 10].y;
				IronBall_Position[count].z = SetPosition[player->PlayerMap / 10][player->PlayerMap % 10].z;

				ShowFlag[count] = true;
				player->ironBall--;
				player->IronPutAnim = true;

				break;
			}
		}

		player->IronPut = false;
	}
}
void IronBall::IronBallGet()
{
	if (player->IronGet == true)
		{
			int a = 0;

			for (int count = 0; count < 5; count++)
			{
				if (
					player->PlayerPosition.x < IronBall_Position[count].x + 75 && 
					player->PlayerPosition.x > IronBall_Position[count].x - 75 && 
					player->PlayerPosition.z < IronBall_Position[count].z + 75 &&
					player->PlayerPosition.z > IronBall_Position[count].z - 75 &&
					ShowFlag[count] == true
					)
				{
					a = count;
					ShowFlag[a] = false;
					player->ironBall++;
					player->IronGetAnim = true;
					IronBall_Position[count].x = -2000.0f;
					IronBall_Position[count].z = -2000.0f;
					break;
				}
			}

			player->IronGet = false;
		}
}
void IronBall::BallMapSet(int PlayerMap)
{
	for (int count = 4; count >= 0; count--)
	{
		if (PlayerMap == 0 && IronBall_Map[count] != 0)
		{
			IronBall_Map[count] = PlayerMap;
			break;
		}

	}

	for (int count = 0; count < 5; count++)
	{
		if (IronBall_Map[count] == 0)
		{
			IronBall_Map[count] = PlayerMap;
			break;
		}
		
	}
	
}
void IronBall::Update()
{
	
	IronBoxToGet();
	IronBallPut();
	IronBallGet();
		
	for (int count = 0; count < 5; count++)
	{
		IronBall[count].SetPosition(IronBall_Position[count]);
		IronBall[count].Update();
	}
	IronBox.SetPosition(IronBox_Position);
	IronBox.Update();
}
void IronBall::Render(RenderContext& rc)
{
	if (BoxFlag == false)
	{
		IronBox.Draw(rc);
	}
	for (int count = 0; count < 5; count++)
	{
		if (ShowFlag[count] == true)
		{
			if (BoxFlag == true)
			{
				IronBall[count].Draw(rc);
			}
		}
	}
}

