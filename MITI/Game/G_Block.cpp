#include "stdafx.h"
#include "G_Block.h"
#include "G_WeightBoard.h"

G_Block::G_Block()
{

	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Block[L][R].Init("Assets/test/isi.tkm", light);
			m_physicsStaticObjectpos[L][R].CreateFromModel(Block[L][R].GetModel(), Block[L][R].GetModel().GetWorldMatrix());
			m_physicsStaticObjectpos[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
		}
	}
}	

G_Block::~G_Block()
{

}

void G_Block::Update()
{

	if (weightboard == NULL)
	{
		weightboard = FindGO<G_WeightBoard>("weightboard");
	}

	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Block_only[L][R] == true)
			{
				Block[L][R].SetPosition(Block_P[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(Block_P[L][R]);
				Block[L][R].Update();
			}else {

			if (weightboard->link == true)
			{
				if (weightboard->block_link == true)
				{
					if (weightboard->putFlag[L][R] == true)
					{
						for (int count = 1; count <= weightboard->link_count[L][R]; count++)
						{
							Block[weightboard->link_number[L][R][count / 10]][weightboard->link_number[L][R][count % 10]].SetPosition(Block_P[weightboard->link_number[L][R][count / 10]][weightboard->link_number[L][R][count % 10]]);
							m_physicsStaticObjectpos[weightboard->link_number[L][R][count / 10]][weightboard->link_number[L][R][count % 10]].SetPosition(Block_P[weightboard->link_number[L][R][count / 10]][weightboard->link_number[L][R][count % 10]]);
							Block[weightboard->link_number[L][R][count / 10]][weightboard->link_number[L][R][count % 10]].Update();
						}
					}else {
					if (weightboard->putFlag[L][R] == false)
					{
						for (int count = 1; count <= weightboard->link_count[L][R]; count++)
						{
							m_physicsStaticObjectpos[weightboard->link_number[L][R][count / 10]][weightboard->link_number[L][R][count % 10]].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
						}
					}
					}
					}
				}
			}
		}
	}


	/*for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Block_on[L][R] == true)
			{
				Block[L][R].SetPosition(Block_P[L][R]);
				Block[L][R].Update();
			}
		}
	}*/
}

void G_Block::Render(RenderContext& rc)
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if(Block_only[L][R]==true)
			{ 
				Block[L][R].Draw(rc);
			}else{
			if (weightboard->link == true)
			{
				if (weightboard->block_link == true)
				{
					if (weightboard->putFlag[L][R] == true)
					{
						for (int count = 1; count <= weightboard->link_count[L][R] ; count++)
						{
							Block[weightboard->link_number[L][R][count / 10]] [weightboard->link_number[L][R][count % 10]].Draw(rc);
						}
					}
				}
			}
			}
		}
	}
	
}