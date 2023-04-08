#include "stdafx.h"
#include "G_BreakFloar.h"
#include "Player.h"

G_BreakFloar::G_BreakFloar()
{
	//�R�����g�A�E�g����B
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	position = { -325,-10,260 };
	
	m_modelRender.Init("Assets/modelData/breakfloar/breakfloar2.tkm");
	m_modelRender.Update();
	m_physicsStaticObjectpos.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix(),10.0f);
}

G_BreakFloar::~G_BreakFloar()
{

}

void G_BreakFloar::Update()
{
	return;
	if (player == NULL)
	{
		//�v���C���[�N���X��T���Ă���
		player = FindGO<Player>("player");
	}

	if (player->ironBall > 3 &&
		player->player_P.x > position.x - 40 && player->player_P.x < position.x + 40 &&
		player->player_P.z > position.z - 40 && player->player_P.z < position.z + 40)
	{
		DeleteGO(this);
	}

	m_modelRender.SetPosition(position);
	m_physicsStaticObjectpos.SetPosition(position);
	m_modelRender.Update();
}

void G_BreakFloar::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}