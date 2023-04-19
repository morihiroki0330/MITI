#include "stdafx.h"
#include "G_WeightBoard.h"
#include "Player.h"
#include "IronBall.h"
#include "G_Tekyu.h"

G_WeightBoard::G_WeightBoard()
{
	m_modelRender.Init("Assets/modelData/WeightBoard.tkm",boardLight);

	position = { -300,10,475 };
}

G_WeightBoard::~G_WeightBoard()
{

}

void G_WeightBoard::Update()
{
	if (player == NULL)
	{
		//プレイヤークラスを探してくる
		player = FindGO<Player>("player");
	}
	if (ironBall == NULL)
	{
		//プレイヤークラスを探してくる
		ironBall = FindGO<IronBall>("ironball");
	}
	if (g_tekyu == NULL)
	{
		//プレイヤークラスを探してくる
		g_tekyu = FindGO<G_Tekyu>("g_tekyu");
	}

	if (player != NULL && ironBall != NULL && g_tekyu != NULL)
	{
		if (player->player_P.x < position.x + 60 && player->player_P.x > position.x - 60
			&& player->player_P.z < position.z + 60 && player->player_P.z > position.z - 60 ||
			g_tekyu->Tpos.x < position.x + 60 && g_tekyu->Tpos.x > position.x - 60
			&& g_tekyu->Tpos.z < position.z + 60 && g_tekyu->Tpos.z > position.z - 60)
		{
			putFlag = true;
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (ironBall->ball_P[i].x < position.x + 60 && ironBall->ball_P[i].x > position.x - 60
					&& ironBall->ball_P[i].z < position.z + 60 && ironBall->ball_P[i].z > position.z - 60)
				{
					putFlag = true;
					break;
				}
				else
				{
					putFlag = false;
				}
			}
		}
	}
	m_modelRender.SetPosition(position);
	//m_physicsStaticObjectpos.SetPosition(position);
	m_modelRender.Update();
}

void G_WeightBoard::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}