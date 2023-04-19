#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"

IronBall::IronBall()
{
	for (int i = 0; i < 5; i++)
	{
		ironRender[i].Init("Assets/modelData/tekyu/tekyu8.tkm",ironLight);

		ball_P[i] = { rand()%1200-600.0f,30.0f, rand() % 600-300.0f };
		showFlag[i] = true;
	}
}

IronBall::~IronBall()
{
	
}

void IronBall::Update()
{
	if (player == NULL)
	{
		//プレイヤークラスを探してくる
		player = FindGO<Player>("player");
	}
	else/* if(player != NULL)*/
	{
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
				if (player->player_P.x < ball_P[i].x + 45 + 30
					&& player->player_P.x > ball_P[i].x - 45 - 30
					&& player->player_P.z < ball_P[i].z + 45 + 30
					&& player->player_P.z > ball_P[i].z - 45 - 30
					&& showFlag[i] == true)
				{
					a = i;
					showFlag[a] = false;
					player->ironBall++;

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
	for (int i = 0; i < 5; i++)
	{
		if (showFlag[i] == true)
		{
			ironRender[i].Draw(rc);
		}
	}
}