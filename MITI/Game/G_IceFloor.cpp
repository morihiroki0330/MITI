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
		//�v���C���[��T��
		player = FindGO<Player>("player");
	}

	if (stage == NULL)
	{
		stage = FindGO<Stage>("stage");
	}

	//�X�̏��Ƀv���C���[������Ă��鎞
	if (
			stage->mapdata[(player->player_map / 10)][(player->player_map % 10)].grounddata == ICE
		)
	{
		//�v���C���[�������Ă���t���O�𗧂Ă�
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



