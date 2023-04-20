#include "stdafx.h"
#include "G_BreakFloar.h"
#include "Player.h"

G_BreakFloar::G_BreakFloar()
{
	//繧ｳ繝｡繝ｳ繝医い繧ｦ繝医☆繧九�
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
<<<<<<< HEAD
	AllLight Light;
	m_modelRender.Init("Assets/modelData/breakfloar/breakfloar2.tkm",Light);
=======

	m_modelRender.Init("Assets/modelData/breakfloar/breakfloar6.tkm",breakLight);

	position = { -300,-60,285 };

>>>>>>> 83cd96e40d24a972325bca99c8dc0ccef7eb3aec
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
		//プレイヤークラスを探してくる
		player = FindGO<Player>("player");
	}
	else
	{
		if (player->ironBall > 3
			&& player->player_P.x < position.x + 73 && player->player_P.x > position.x - 73
			&& player->player_P.z < position.z + 73 && player->player_P.z > position.z - 73)
		{
			DeleteGO(this);
		}
	}

	m_modelRender.SetPosition(position);
	m_physicsStaticObjectpos.SetPosition(position);
	m_modelRender.Update();
}

void G_BreakFloar::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}