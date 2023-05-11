#include "stdafx.h"
#include "G_WeightBoard.h"
#include "Player.h"
#include "IronBall.h"
#include "G_Block.h"
#include "Bgm.h"

G_WeightBoard::G_WeightBoard()
{
	for (int L = 0 ; L < 10 ; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Weightboard[L][R].Init("Assets/test/ita.tkm", Light);
			Weightboard[L][R].SetScale({ 0.6f,0.6f,0.6f });
			m_physicsStaticObjectpos[L][R].CreateFromModel(Weightboard[L][R].GetModel(), Weightboard[L][R].GetModel().GetWorldMatrix());
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
				
			if (bgm == NULL)
			{
				bgm = FindGO<Bgm>("bgm");
			}

			if (player == NULL)
			{
				player = FindGO<Player>("player");
			}

			if (
				player->Character_P.x < Weightboard_P[L][R].x + 60 &&
				player->Character_P.x > Weightboard_P[L][R].x - 60 &&
				player->Character_P.z < Weightboard_P[L][R].z + 60 &&
				player->Character_P.z > Weightboard_P[L][R].z - 60
				)
				{
					putFlag[L][R] = true;
					//bgm->PlaySE(S_WEIGHTBOARD);
				}else{
					putFlag[L][R] = false;
				}
				for (int i = 0; i < 5; i++)
				{
					if (
						ironBall->Ball_P[i].x < Weightboard_P[L][R].x + 60 && 
						ironBall->Ball_P[i].x > Weightboard_P[L][R].x - 60 &&
						ironBall->Ball_P[i].z < Weightboard_P[L][R].z + 60 && 
						ironBall->Ball_P[i].z > Weightboard_P[L][R].z - 60 ||
						putFlag[L][R] == true
						)
						{
							putFlag[L][R] = true;
							//bgm->PlaySE(S_WEIGHTBOARD);
						}else {
							putFlag[L][R] = false;
						}
				}

			if (WeightBoard_on[L][R] == true)
			{
				Weightboard[L][R].SetPosition(Weightboard_P[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(Weightboard_P[L][R]);
				Weightboard[L][R].Update();
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
				Weightboard[L][R].Draw(rc);
			}
		}
	}
	
}