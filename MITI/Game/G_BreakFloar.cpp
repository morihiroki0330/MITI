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
			BreakFloar[L][R].Init("Assets/modelData/hole.tkm", Light);
			m_physicsStaticObjectpos[L][R].CreateFromModel(BreakFloar[L][R].GetModel(), BreakFloar[L][R].GetModel().GetWorldMatrix());
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
			}else{
			if (
				player->ironBall > 3 && 
				player->Character_P.x < BreakFloar_P[L][R].x + 73 && 
				player->Character_P.x > BreakFloar_P[L][R].x - 73 && 
				player->Character_P.z < BreakFloar_P[L][R].z + 73 && 
				player->Character_P.z > BreakFloar_P[L][R].z - 73
				)
			{
				DeleteGO(this);
			}
			}

			if (Break_on[L][R] == true)
			{
				BreakFloar[L][R].SetPosition(BreakFloar_P[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(BreakFloar_P[L][R]);
				BreakFloar[L][R].Update();
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
			if (Break_on[L][R] == true)
			{
				BreakFloar[L][R].Draw(rc);
			}
		}
	}
}