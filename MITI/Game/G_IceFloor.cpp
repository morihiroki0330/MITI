#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"
#include "Stage.h"

G_IceFloor::G_IceFloor()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			IceFloor[L][R].Init("Assets/modelData/ice1.tkm", Light);
			m_physicsStaticObjectpos[L][R].CreateFromModel(IceFloor[L][R].GetModel(), IceFloor[L][R].GetModel().GetWorldMatrix());
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

	if (stage == NULL)
	{
		stage = FindGO<Stage>("stage");
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
			if (IceFloor_on[L][R] == true)
			{
				IceFloor[L][R].SetPosition(IceFloor_P[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(IceFloor_P[L][R]);
				IceFloor[L][R].Update();
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
			if (IceFloor_on[L][R] == true)
			{
				IceFloor[L][R].Draw(rc);
			}
		}
	}
}



