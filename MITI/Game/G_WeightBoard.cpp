#include "stdafx.h"
#include "G_WeightBoard.h"
#include "Player.h"
#include "IronBall.h"
#include "G_Tekyu.h"

G_WeightBoard::G_WeightBoard()
{
	for (int L = 0 ; L < 10 ; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			m_modelRender[L][R].Init("Assets/modelData/WeightBoard.tkm", boardLight);
			m_modelRender[L][R].SetScale({ 0.6f,0.6f,0.6f });
			m_physicsStaticObjectpos[L][R].CreateFromModel(m_modelRender[L][R].GetModel(), m_modelRender[L][R].GetModel().GetWorldMatrix());
		}
	}
}

G_WeightBoard::~G_WeightBoard()
{

}

void G_WeightBoard::Update()
{
	/*if (player == NULL)
	{
		//プレイヤークラスを探してくる
		player = FindGO<Player>("player");
	}*/
	//if (ironBall == NULL)
	//{
	//	//プレイヤークラスを探してくる
	//	ironBall = FindGO<IronBall>("ironball");
	//}
	//if (g_tekyu == NULL)
	//{
	//	//プレイヤークラスを探してくる
	//	g_tekyu = FindGO<G_Tekyu>("g_tekyu");
	//}

	//if (player != NULL && ironBall != NULL && g_tekyu != NULL)
	//{
	//	if (player->player_P.x < position.x + 120 && player->player_P.x > position.x - 120
	//		&& player->player_P.z < position.z + 120 && player->player_P.z > position.z - 120 ||
	//		g_tekyu->Tpos.x < position.x + 120 && g_tekyu->Tpos.x > position.x - 120
	//		&& g_tekyu->Tpos.z < position.z + 120 && g_tekyu->Tpos.z > position.z - 120)
	//	{
	//		putFlag = true;
	//	}
	//	else
	//	{
	//		for (int i = 0; i < 5; i++)
	//		{
	//			if (ironBall->ball_P[i].x < position.x + 120 && ironBall->ball_P[i].x > position.x - 120
	//				&& ironBall->ball_P[i].z < position.z + 120 && ironBall->ball_P[i].z > position.z - 120)
	//			{
	//				putFlag = true;
	//				break;
	//			}
	//			else
	//			{
	//				putFlag = false;
	//			}
	//		}
	//	}
	//}
	if (player == NULL)
	{
		//プレイヤーを探す
		player = FindGO<Player>("player");
	}
	
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (WeightBoard_on[L][R] == true)
			{
				m_modelRender[L][R].SetPosition(position[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(position[L][R]);
				m_modelRender[L][R].Update();
			}
		}
	}
	//if (player->player_P.x<position.x + 80 && player->player_P.x > position.x - 80
	//	&& player->player_P.z<position.z + 80 && player->player_P.z > position.z - 80)
	//{
	//	//プレイヤーが滑っているフラグを立てる
	//	putFlag = true;
	//}
	//else
	//{
	//	//滑っているフラグを折る
	//	putFlag = false;
	//}

	
}

void G_WeightBoard::Render(RenderContext& rc)
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (WeightBoard_on[L][R] == true)
			{
				m_modelRender[L][R].Draw(rc);
			}
		}
	}
	
}