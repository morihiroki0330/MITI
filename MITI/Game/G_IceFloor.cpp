#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"

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
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (player == NULL)
			{
				//�v���C���[��T��
				player = FindGO<Player>("player");
			}else{
				//�X�̏��Ƀv���C���[������Ă��鎞
			if (player->player_P.x<position[L][R].x + 130 && player->player_P.x > position[L][R].x - 130
				&& player->player_P.z<position[L][R].z + 130 && player->player_P.z > position[L][R].z - 130
				|| player->slipflag == true)
			{
				//�v���C���[�������Ă���t���O�𗧂Ă�
				player->slipflag = true;
			}else{
				//�����Ă���t���O��܂�
				player->slipflag = false;
			}
			}

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