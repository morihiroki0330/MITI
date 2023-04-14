#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"

G_IceFloor::G_IceFloor()
{
	//m_modelRender.Init("Assets/modelData");
	position = {-900,0,0};
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
}

void G_IceFloor::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}