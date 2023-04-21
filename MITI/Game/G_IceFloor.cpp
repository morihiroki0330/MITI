#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"

G_IceFloor::G_IceFloor()
{
	m_modelRender.Init("Assets/modelData/ice1.tkm",icefloorLight);

	position = {-870,-20,95};

	m_modelRender.Update();
	m_physicsStaticObjectpos.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
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
	else
	{
		//氷の床にプレイヤーが乗っている時
		if (player->player_P.x<position.x + 95 && player->player_P.x > position.x - 95
			&& player->player_P.z<position.z + 95 && player->player_P.z > position.z - 95)
		{
			//プレイヤーが滑っているフラグを立てる
				player->slipflag = true;
		}
		else
		{
			//滑っているフラグを折る
			player->slipflag = false;
		}
	}

	m_modelRender.SetPosition(position);
	m_physicsStaticObjectpos.SetPosition(position);
	m_modelRender.Update();
}

void G_IceFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}