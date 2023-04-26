#include "stdafx.h"
#include "G_WeightBoard.h"
#include "Player.h"
#include "IronBall.h"
#include "G_Tekyu.h"
#include "G_Block.h"

G_WeightBoard::G_WeightBoard()
{
	for (int L = 0 ; L < 10 ; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			m_modelRender[L][R].Init("Assets/test/ita.tkm", boardLight);
			m_modelRender[L][R].SetScale({ 0.6f,0.6f,0.6f });
			m_physicsStaticObjectpos[L][R].CreateFromModel(m_modelRender[L][R].GetModel(), m_modelRender[L][R].GetModel().GetWorldMatrix());
			m_physicsStaticObjectpos[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
		}
	}
}

G_WeightBoard::~G_WeightBoard()
{

}

void G_WeightBoard::Update()
{
	
	
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			
				if (ironBall == NULL)
				{
					ironBall = FindGO<IronBall>("ironball");
				}
				/*
				if (g_tekyu == NULL)
				{
					g_tekyu = FindGO<G_Tekyu>("g_tekyu");
				}*/

				if (block == NULL)
				{
					block = FindGO<G_Block>("block");
				}
				
				if (player == NULL)
				{
					player = FindGO<Player>("player");
				}


			/*	if (player != NULL && ironBall != NULL && g_tekyu != NULL)
				{*/
					if (player->player_P.x < position[L][R].x + 60 &&
						player->player_P.x > position[L][R].x - 60 &&
						player->player_P.z < position[L][R].z + 60 &&
						player->player_P.z > position[L][R].z - 60
						)
					{
						putFlag[L][R] = true;
					}else {
						putFlag[L][R] = false;
					}
					
					for (int i = 0; i < 5; i++)
						{
							if (ironBall->ball_P[i].x < position[L][R].x + 60 && 
								ironBall->ball_P[i].x > position[L][R].x - 60 &&
								ironBall->ball_P[i].z < position[L][R].z + 60 && 
								ironBall->ball_P[i].z > position[L][R].z - 60 ||
								putFlag[L][R] == true
								)
							{
								putFlag[L][R] = true;
							}else {
								putFlag[L][R] = false;
							}
						}
				/*}*/

			if (WeightBoard_on[L][R] == true)
			{
				m_modelRender[L][R].SetPosition(position[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(position[L][R]);
				m_modelRender[L][R].Update();
			}
		}
	}
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