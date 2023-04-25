#include "stdafx.h"
#include "G_Block.h"
#include "G_WeightBoard.h"

G_Block::G_Block()
{

	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Block[L][R].Init("Assets/test/kabe.tkm", light);
			m_physicsStaticObjectpos[L][R].CreateFromModel(Block[L][R].GetModel(), Block[L][R].GetModel().GetWorldMatrix());
		}
	}
}	

G_Block::~G_Block()
{

}

void G_Block::Update()
{

	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Block_on[L][R] == true)
			{
				Block[L][R].SetPosition(Block_P[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(Block_P[L][R]);
				Block[L][R].Update();
			}
		}
	}
}

void G_Block::Render(RenderContext& rc)
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Block_on[L][R] == true)
			{
				Block[L][R].Draw(rc);
			}
		}
	}
	
}