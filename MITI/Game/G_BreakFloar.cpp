#include "stdafx.h"
#include "G_BreakFloar.h"
#include "Player.h"

G_BreakFloar::G_BreakFloar()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			m_modelRender[L][R].Init("Assets/test/hole.tkm", breakLight);
			m_physicsStaticObjectpos[L][R].CreateFromModel(m_modelRender[L][R].GetModel(), m_modelRender[L][R].GetModel().GetWorldMatrix());
			m_physicsStaticObjectpos[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
		}
	}
}

G_BreakFloar::~G_BreakFloar()
{

}

void G_BreakFloar::Update()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{

			if (player == NULL)
			{
				player = FindGO<Player>("player");
			}
			else
			{
				if (player->ironBall > 3
					&& player->player_P.x < position[L][R].x + 73 && player->player_P.x > position[L][R].x - 73
					&& player->player_P.z < position[L][R].z + 73 && player->player_P.z > position[L][R].z - 73)
				{
					DeleteGO(this);
				}
			}

			if (break_on[L][R] == true)
			{
				m_modelRender[L][R].SetPosition(position[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(position[L][R]);
				m_modelRender[L][R].Update();
			}
		}
	}
}

void G_BreakFloar::Render(RenderContext& rc)
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (break_on[L][R] == true)
			{
				m_modelRender[L][R].Draw(rc);
			}
		}
	}
}