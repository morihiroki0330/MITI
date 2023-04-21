#include "stdafx.h"
#include "G_IceFloor.h"
#include "Player.h"

G_IceFloor::G_IceFloor()
{
	m_modelRender.Init("Assets/modelData/ice1.tkm",icefloorLight);

	//position = {-680,-20,95};
	position = {-190,-20,0};

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
		//�v���C���[��T��
		player = FindGO<Player>("player");
	}
	else
	{
		    //�X�̏��Ƀv���C���[������Ă��鎞
		if (player->player_P.x<position.x + 157 && player->player_P.x > position.x - 157
			&& player->player_P.z<position.z + 157 && player->player_P.z > position.z - 157
			|| player->slipflag == true)
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

	m_modelRender.SetPosition(position);
	m_physicsStaticObjectpos.SetPosition(position);
	m_modelRender.Update();
}

void G_IceFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}