#include "stdafx.h"
#include "G_WeightBoard.h"
#include "Player.h"
#include "IronBall.h"
#include "G_Block.h"
#include "Stage.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

G_WeightBoard::G_WeightBoard()
{
	for (int L = 0 ; L < 10 ; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Weightboard[L][R].Init("Assets/modelData/ita.tkm", Light);
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

			if (stage == NULL)
			{
				stage = FindGO<Stage>("stage");
			}
			
			if (player == NULL)
			{
				player = FindGO<Player>("player");
			}

			if (stage->mapdata[(player->player_map / 10)][(player->player_map % 10)].skydata == WEIGHTBOARD)
			{
				PutFlag[(player->player_map / 10)][(player->player_map % 10)] = true;
				BgmSet[(player->player_map / 10)][(player->player_map % 10)] = true;
			}else{
				PutFlag[L][R] = false;
				BgmSet[L][R] = false;
				HitFlag[L][R] = false;
			}

			for (int W = 0; W < 5; W++)
			{
				if (
						ironBall->Ball_P[W].x < Weightboard_P[L][R].x + 60 &&
						ironBall->Ball_P[W].x > Weightboard_P[L][R].x - 60 &&
						ironBall->Ball_P[W].z < Weightboard_P[L][R].z + 60 &&
						ironBall->Ball_P[W].z > Weightboard_P[L][R].z - 60 ||
					    PutFlag[L][R] == true
					)
					{
						PutFlag[L][R] = true;
					}else {
						PutFlag[L][R] = false;
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
	
	if (BgmSet[(player->player_map / 10)][(player->player_map % 10)] == true && HitFlag[(player->player_map / 10)][(player->player_map % 10)] == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->Init(S_WEIGHTBOARD);
		SE->SetVolume(0.1f);
		SE->Play(false);
		HitFlag[(player->player_map / 10)][(player->player_map % 10)] = true;
	}
	Hit.SetText(L"è’ìÀ");
	Hit.SetPosition(Vector3(-852.0f, 350.0f, 0.0f));
	Hit.SetScale(1.0f);

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