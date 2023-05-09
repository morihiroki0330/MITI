#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"
#include "Game.h"

IronBall::IronBall()
{
	Set = true;

	IronBox.Init("Assets/test/tekyu-box.tkm", ironLight);

	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			SetPosition[L][R].x = (L * 192.0f) + -865.0f;
			SetPosition[L][R].y = 0.0f;
			SetPosition[L][R].z = (R * 192.0f) + -865.0f;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		ironRender[i].Init("Assets/modelData/tekyu/tekyu8.tkm",ironLight);
		//ball_P[i] = { rand() % 1200-600.0f,30.0f, rand() % 600-864.0f };
		ironRender[i].SetScale({ 1.5f, 1.5f, 1.5f });
		//showFlag[i] = true;
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
		IronBox.SetPosition(IronBox_P);
		IronBox.Update();
		Set = false;
	}

	IronBox.SetPosition(IronBox_P);
	IronBox.Update();

	if (player == NULL)
	{
		//プレイヤークラスを探してくる
		player = FindGO<Player>("player");
	}
	else/* if(player != NULL)*/
	{

		if (
			player->player_P.x < IronBox_P.x + 60 &&
			player->player_P.x > IronBox_P.x - 60 &&
			player->player_P.z < IronBox_P.z + 60 &&
			player->player_P.z > IronBox_P.z - 60 &&
			boxFlag == false
			)
		{
			player->ironBall = 5;
			boxFlag = true;
		}
		//めも、マス目は幅190

		//鉄球を置く座標を登録する処理
		if (player->put_Iron == true)
		{
			for (int i = 0; i < 5; i++)
			{
				if (showFlag[i] == false)
				{
					/*ball_P[i].x = player->player_P.x;
					ball_P[i].y = player->player_P.y;
					ball_P[i].z = player->player_P.z;*/

					int x, z;
					if (player->player_P.z < 0)
					{
						z = player->player_P.z / 190 - 1;
					}
					else
					{
						z = player->player_P.z / 190;
					}

					if (player->player_P.x < 0)
					{
						x = player->player_P.x / 190 - 1;
					}
					else
					{
						x = player->player_P.x / 190;
					}

					ball_P[i].x = 89 + 190 * x;
					ball_P[i].y = /*player->player_P.y + */25;
					ball_P[i].z = 95 + 190 * z;

					showFlag[i] = true;

					player->ironBall--;
					player->put_IronAnim = true;
					
					break;
				}
			}

			player->put_Iron = false;
		}

		//置いてある鉄球を回収する処理
		if (player->get_Iron == true)
		{
			int a = 0;

			for (int i = 0; i < 5; i++)
			{
				/*if (ball_P[i].y != -1000)
				{
					ball_P[i].y = -1000.0f;

					break;
				}*/

				//
				if (player->player_P.x < ball_P[i].x + 75
					&& player->player_P.x > ball_P[i].x - 75
					&& player->player_P.z < ball_P[i].z + 75
					&& player->player_P.z > ball_P[i].z - 75
					&& showFlag[i] == true)
				{
					a = i;
					showFlag[a] = false;
					player->ironBall++;
					player->get_IronAnim = true;
					ball_P[i].x = -2000.0f;
					ball_P[i].z = -2000.0f;
					break;
				}
			}

			//if (a != 0)
			//{
			//	
			//}

			player->get_Iron = false;
		}

		//ballCounter = player->ironBall;
	}

	for (int i = 0; i < 5; i++)
	{
		ironRender[i].SetPosition(ball_P[i]);
		ironRender[i].Update();
	}
}

void IronBall::Render(RenderContext& rc)
{
	if (boxFlag == false)
	{
		IronBox.Draw(rc);
	}
	for (int i = 0; i < 5; i++)
	{
		if (showFlag[i] == true)
		{
			if (boxFlag == true)
			{
				ironRender[i].Draw(rc);
			}
		}
	}
}