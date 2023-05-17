#include "stdafx.h"
#include "G_Ground.h"

G_Ground::G_Ground()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Ground[L][R].Init("Assets/modelData/ground1.tkm", Light);
			m_physicsStaticObjectpos[L][R].CreateFromModel(Ground[L][R].GetModel(), Ground[L][R].GetModel().GetWorldMatrix());
			m_physicsStaticObjectpos[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
			Ground[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });

			SetPosition[L][R].x = (L * 191.0f) + -865.0f;
			SetPosition[L][R].y = -50.0f;
			SetPosition[L][R].z = (R * 191.0f) + -865.0f;

			Ground_on[L][R] = false;
		}
	}
}

G_Ground::~G_Ground()
{

}

void G_Ground::Update()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Ground_on[L][R] == true)
			{
				if (Ground_P[L][R].x == 0.0f)
				{
					Ground[L][R].SetPosition(SetPosition[L][R]);
					m_physicsStaticObjectpos[L][R].SetPosition(SetPosition[L][R]);
					Ground[L][R].Update();
				}else {
					Ground[L][R].SetPosition(Ground_P[L][R]);
					m_physicsStaticObjectpos[L][R].SetPosition(Ground_P[L][R]);
					Ground[L][R].Update();
				}
			}else {
				Ground[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
				m_physicsStaticObjectpos[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
				Ground[L][R].Update();
			}
		}
	}
}

void G_Ground::Render(RenderContext& rc)
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Ground_on[L][R] == true)
			{
				Ground[L][R].Draw(rc);
			}
		}
	}

}