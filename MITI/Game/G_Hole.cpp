#include "stdafx.h"
#include "G_Hole.h"

G_Hole::G_Hole()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Hole[L][R].Init("Assets/test/hole.tkm", Hole_L);
			m_physicsStaticObjectpos[L][R].CreateFromModel(Hole[L][R].GetModel(), Hole[L][R].GetModel().GetWorldMatrix());
		}
	}
}

G_Hole::~G_Hole()
{

}

void G_Hole::Update()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Hole_on[L][R] == true)
			{
				Hole[L][R].SetPosition(Hole_P[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(Hole_P[L][R]);
				Hole[L][R].Update();
			}
		}
	}
}

void G_Hole::Render(RenderContext& rc)
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Hole_on[L][R] == true)
			{
				Hole[L][R].Draw(rc);
			}
		}
	}

}