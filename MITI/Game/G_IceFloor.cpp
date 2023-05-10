#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"
#include "G_Block.h"
#include "Stage.h"
#include "G_WeightBoard.h"

G_IceFloor::G_IceFloor()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			m_modelRender[L][R].Init("Assets/test/ice1.tkm", icefloorLight);
			m_physicsStaticObjectpos[L][R].CreateFromModel(m_modelRender[L][R].GetModel(), m_modelRender[L][R].GetModel().GetWorldMatrix());
			m_physicsStaticObjectpos[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
		}
	}
}

G_IceFloor::~G_IceFloor()
{

}

void G_IceFloor::Update()
{

	if (player == NULL)
	{
		//プレイヤーを探す
		player = FindGO<Player>("player");
	}

	if (block == NULL)
	{
		block = FindGO<G_Block>("block");
	}

	if (stage == NULL)
	{
		stage = FindGO<Stage>("stage");
	}

	if (weightboard == NULL)
	{
		weightboard = FindGO<G_WeightBoard>("weightboard");
	}

	//氷の床にプレイヤーが乗っている時
	if (
			stage->mapdata[(player->player_map / 10)][(player->player_map % 10)].grounddata == ICE
		)
	{
		//プレイヤーが滑っているフラグを立てる
		player->slipflag = true;
	}

	for (int L = 0; L < 10; L ++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (ice_on[L][R] == true)
			{
				m_modelRender[L][R].SetPosition(position[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(position[L][R]);
				m_modelRender[L][R].Update();
			}
		}
	}

}

void G_IceFloor::Render(RenderContext& rc)
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (ice_on[L][R] == true)
			{
				m_modelRender[L][R].Draw(rc);
			}
		}
	}
}



