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
		//�v���C���[��T��
		player = FindGO<Player>("player");
	}
	else
	{
		//�X�̏��Ƀv���C���[������Ă��鎞
		if (player->player_P.x<position.x + 95 && player->player_P.x > position.x - 95
			&& player->player_P.z<position.z + 95 && player->player_P.z > position.z - 95)
		{
			//�v���C���[�������Ă���t���O�𗧂Ă�
				player->slipflag = true;
		}
		else
		{
			//�����Ă���t���O��܂�
			player->slipflag = false;
		}
	}
}

void G_IceFloor::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}