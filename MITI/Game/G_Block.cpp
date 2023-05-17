#include "stdafx.h"
#include "G_Block.h"
#include "G_WeightBoard.h"
#include "Box.h"
#include "Stage.h"

G_Block::G_Block()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Block[L][R].Init("Assets/modelData/isi.tkm", Light);
			SkeletonBlock_ICE[L][R].Init("Assets/modelData/SkeletonBlock/S_Ice.tkm", Light);
			SkeletonBlock_GROUND[L][R].Init("Assets/modelData/SkeletonBlock/S_Ground.tkm", Light);
			SkeletonBlock_BLOCK[L][R].Init("Assets/modelData/SkeletonBlock/S_Block.tkm", Light);
			
			SkeletonBlock_ICE[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
			SkeletonBlock_GROUND[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
			SkeletonBlock_BLOCK[L][R].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
			
			SkeletonBlock_ICE[L][R].Update();
			SkeletonBlock_GROUND[L][R].Update();
			SkeletonBlock_BLOCK[L][R].Update();

			m_physicsStaticObjectpos[L][R].CreateFromModel(Block[L][R].GetModel(), Block[L][R].GetModel().GetWorldMatrix());
			m_physicsStaticObjectpos[L][R].SetPosition({-2000.0f,-2000.0f,-2000.0f});
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
	
	if (box == NULL)
	{
		box = FindGO<Box>("box");
	}
	
	if (stage == NULL)
	{
		stage = FindGO<Stage>("stage");
	}
	
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (Block_only[L][R] == true)
			{
				Block[L][R].SetPosition(Block_P[L][R]);
				m_physicsStaticObjectpos[L][R].SetPosition(Block_P[L][R]);
				box->box[L][R].SetPosition(Block_P[L][R]);
				Block[L][R].Update();
			}else {
			if (weightboard->Link_on == true)
			{
				if (weightboard->Block_Link == true)
				{
					if (weightboard->PutFlag[L][R] == true)
					{
							
						for (int count = 1; count <= weightboard->Link_Count[L][R]; count++)
						{
							if (weightboard->Link[L][R][count] == L_BLOCK)
							{
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition(Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]]);
								m_physicsStaticObjectpos[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition(Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]]);
								box->box[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition(Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]]);
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Update();
							}else {
							if (weightboard->Link[L][R][count] == I_BLOCK)
							{
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Init("Assets/modelData/ice1.tkm", Light);
								stage->mapdata[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].grounddata = ICE;
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].x,-55.0f,Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].z });
								m_physicsStaticObjectpos[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].x,-50.0f,Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].z});
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Update();
							}else {
							if (weightboard->Link[L][R][count] == G_BLOCK)
							{
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Init("Assets/modelData/ground1.tkm", Light);
								stage->mapdata[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].grounddata = GROUND;
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].x,-55.0f,Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].z });
								m_physicsStaticObjectpos[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].x,-50.0f,Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].z });
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Update();
							}else
							{
							if (weightboard->Link[L][R][count] == H_BLOCK)
							{
								stage->mapdata[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].grounddata = HOLE;
								m_physicsStaticObjectpos[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
							}
							}
							}
							}
							}

					}else {
					if (weightboard->PutFlag[L][R] == false)
					{
						for (int count = 1; count <= weightboard->Link_Count[L][R]; count++)
						{
							if (weightboard->Link[L][R][count] == L_BLOCK)
							{
								SkeletonBlock_BLOCK[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition(Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]]);
								SkeletonBlock_BLOCK[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Update();
								m_physicsStaticObjectpos[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
								box->box[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
							}else {
							if (weightboard->Link[L][R][count] == I_BLOCK)
							{
								SkeletonBlock_ICE[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].x,-50.0f,Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].z });
								SkeletonBlock_ICE[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Update();
								stage->mapdata[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].grounddata = HOLE;
								m_physicsStaticObjectpos[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
							}else {
							if (weightboard->Link[L][R][count] == G_BLOCK)
							{
								SkeletonBlock_GROUND[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].x,-50.0f,Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].z });
								SkeletonBlock_GROUND[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Update();
								stage->mapdata[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].grounddata = HOLE;
								m_physicsStaticObjectpos[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition({ -2000.0f,-2000.0f,-2000.0f });
							}else {
							if (weightboard->Link[L][R][count] == H_BLOCK)
							{
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition(Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]]);
								m_physicsStaticObjectpos[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition(Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]]);
								box->box[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].SetPosition(Block_P[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]]);
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Update();
							}
							}
							}
							}
						}
	
					}
					}
				}
				}
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
			if(Block_only[L][R]==true)
			{ 
				Block[L][R].Draw(rc);
			}else{
			if (weightboard->Link_on == true)
			{
				if (weightboard->Block_Link == true)
				{
					if (weightboard->PutFlag[L][R] == true)
					{
						for (int count = 1; count <= weightboard->Link_Count[L][R]; count++)
						{	
							if (weightboard->Link[L][R][count] == L_BLOCK)
							{
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Draw(rc);
							}else {
							if (weightboard->Link[L][R][count] == I_BLOCK)
							{
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Draw(rc);
							}else {
							if (weightboard->Link[L][R][count] == G_BLOCK)
							{
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Draw(rc);
							}
							}
							}
							
						}
					}else {
						for (int count = 1; count <= weightboard->Link_Count[L][R]; count++)
						{
							if (weightboard->Link[L][R][count] == H_BLOCK)
							{
								Block[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Draw(rc);
							}else {
							if(weightboard->Link[L][R][count] == L_BLOCK)
							{
								SkeletonBlock_BLOCK[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Draw(rc);
							}else {
							if (weightboard->Link[L][R][count] == I_BLOCK)
							{
								SkeletonBlock_ICE[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Draw(rc);
							}else {
							if (weightboard->Link[L][R][count] == G_BLOCK)
							{
								SkeletonBlock_GROUND[weightboard->Link_Number[L][R][count / 10]][weightboard->Link_Number[L][R][count % 10]].Draw(rc);
							}
							}
							}
							}
						}
					}
				}
			}
			}
		}
	}
	
}