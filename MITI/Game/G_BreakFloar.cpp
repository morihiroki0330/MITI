#include "stdafx.h"
#include "G_BreakFloar.h"
#include "Player.h"

G_BreakFloar::G_BreakFloar()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	position = { -300,-50,290 };

	m_modelRender.Init("Assets/modelData/breakfloar/breakfloar6.tkm");
	m_modelRender.Update();
	m_physicsStaticObjectpos.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
}

G_BreakFloar::~G_BreakFloar()
{

}

void G_BreakFloar::Update()
{
	if (player == NULL)
	{
		//プレイヤーを探してくる
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
	m_modelRender.Draw(rc);
}