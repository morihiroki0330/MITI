#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"
#include "Game.h"

IronBall::IronBall()
{
	Set = true;

	IronBox.Init("Assets/test/tekyu-box.tkm", Light);

	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			SetPosition[L][R].x = (L * 192.0f) + -865.0f;
			SetPosition[L][R].y = 0.0f;
			SetPosition[L][R].z = (R * 192.0f) + -865.0f;
		}
	}

	Light.DirectionLight_D.x = 1.0f;
	Light.DirectionLight_D.y = 1.0f;
	Light.DirectionLight_D.z = 1.0f;

	Light.DirectionLight_C.x = 1.0f;
	Light.DirectionLight_C.y = 1.0f;
	Light.DirectionLight_C.z = 1.0f;

	for (int i = 0; i < 5; i++)
	{
		Ball[i].Init("Assets/modelData/tekyu/tekyu8.tkm",Light);
		Ball[i].SetScale({ 1.5f, 1.5f, 1.5f });
	}
}

IronBall::~IronBall()
{
	
}

void IronBall::Update()
{
	game = FindGO<Game>("game");

	if (Set == true)
	{

		if (game->Level == 0)
		{
			IronBox_P = SetPosition[1][1];
		}

		if (game->Level == 1)
		{
			IronBox_P = SetPosition[1][1];
		}

		if (game->Level == 2)
		{
			IronBox_P = SetPosition[3][0];
		}
		
		if (game->Level == 3)
		{
			IronBox_P = SetPosition[9][1];
		}
		
		if (game->Level == 4)
		{
			IronBox_P = SetPosition[3][0];
		}
		IronBox.SetPosition(IronBox_P);
		IronBox.Update();
		Set = false;
	}

	IronBox.SetPosition(IronBox_P);
	IronBox.Update();

	if (player == NULL)
	{
		player = FindGO<Player>("player");
	}
	else
	{

		if (
			player->Character_P.x < IronBox_P.x + 60 &&
			player->Character_P.x > IronBox_P.x - 60 &&
			player->Character_P.z < IronBox_P.z + 60 &&
			player->Character_P.z > IronBox_P.z - 60 &&
			BoxFlag == false
			)
		{
			player->ironBall = 5;
			BoxFlag = true;
		}
		

		if (player->put_Iron == true)
		{
			for (int i = 0; i < 5; i++)
			{
				if (ShowFlag[i] == false)
				{
					int x, z;
					if (player->Character_P.z < 0)
					{
						z = player->Character_P.z / 190 - 1;
					}
					else
					{
						z = player->Character_P.z / 190;
					}

					if (player->Character_P.x < 0)
					{
						x = player->Character_P.x / 190 - 1;
					}
					else
					{
						x = player->Character_P.x / 190;
					}

					Ball_P[i].x = 89 + 190 * x;
					Ball_P[i].y = 25;
					Ball_P[i].z = 95 + 190 * z;

					ShowFlag[i] = true;

					player->ironBall--;
					player->put_IronAnim = true;
					
					break;
				}
			}

			player->put_Iron = false;
		}

		if (player->get_Iron == true)
		{
			int a = 0;

			for (int i = 0; i < 5; i++)
			{
				if (
					player->Character_P.x < Ball_P[i].x + 75 && 
					player->Character_P.x > Ball_P[i].x - 75 && 
					player->Character_P.z < Ball_P[i].z + 75 &&
					player->Character_P.z > Ball_P[i].z - 75 &&
					ShowFlag[i] == true
					)
				{
					a = i;
					ShowFlag[a] = false;
					player->ironBall++;
					player->get_IronAnim = true;
					Ball_P[i].x = -2000.0f;
					Ball_P[i].z = -2000.0f;
					break;
				}
			}

			player->get_Iron = false;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		Ball[i].SetPosition(Ball_P[i]);
		Ball[i].Update();
	}
}

void IronBall::Render(RenderContext& rc)
{
	if (BoxFlag == false)
	{
		IronBox.Draw(rc);
	}
	for (int i = 0; i < 5; i++)
	{
		if (ShowFlag[i] == true)
		{
			if (BoxFlag == true)
			{
				Ball[i].Draw(rc);
			}
		}
	}
}