#include "stdafx.h"
#include "IronBall.h"
#include "Player.h"

IronBall::IronBall()
{
	for (int i = 0; i < 5; i++)
	{
		ironRender[i].Init("Assets/modelData/tekyu/tekyu8.tkm");

		ball_P[i] = { 0.0f,-1000.0f,0.0f };
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
		if (g_pad[0]->IsTrigger(enButtonB))
		{
			for (int i = 0; i < 5; i++)
			{
				if (ball_P[i].y == -1000.0f)
				{
					ball_P[i].x = player->player_P.x;
					ball_P[i].y = player->player_P.y;
					ball_P[i].z = player->player_P.z;

					break;
				}
			}
		}

		if (g_pad[0]->IsTrigger(enButtonA))
		{
			for (int i = 0; i < 5; i++)
			{
				if (ball_P[i].y != -1000)
				{
					ball_P[i].y = -1000.0f;

					break;
				}
			}
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
		if (ball_P[i].y != -1000.0f)
		{
			ironRender[i].Draw(rc);
		}
	}
}