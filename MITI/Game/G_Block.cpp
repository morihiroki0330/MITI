#include "stdafx.h"
#include "G_Block.h"
#include "G_WeightBoard.h"
#include "Box.h"
#include "Stage.h"
#include "Number_Storage.h"
bool G_Block::Start()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			SetModel(Y,X);
			SetModelPosition(Y,X);
			SetModelUpdate(Y,X);
		}
	}
	weightboard = FindGO<G_WeightBoard>("weightboard");
	box = FindGO<Box>("box");
	stage = FindGO<Stage>("stage");
	return true;
}

void G_Block::SetModel(int Y , int X)
{
	Block[Y][X].Init("Assets/modelData/isi.tkm", Light);
	IceBlock[Y][X].Init("Assets/modelData/ice1.tkm", Light);
	GroundBlock[Y][X].Init("Assets/modelData/ground1.tkm", Light);
	DeleteBlock[Y][X].Init("Assets/modelData/DeleteBlock.tkm", Light);

	SkeletonBlock[Y][X].Init("Assets/modelData/SkeletonBlock/S_Block.tkm", Light);
	SkeletonIceBlock[Y][X].Init("Assets/modelData/SkeletonBlock/S_Ice.tkm", Light);
	SkeletonGroundBlock[Y][X].Init("Assets/modelData/SkeletonBlock/S_Ground.tkm", Light);
	SkeletonDeleteBlock[Y][X].Init("Assets/modelData/SkeletonBlock/S_Delete.tkm", Light);

	Block_PSO[Y][X].CreateFromModel(Block[Y][X].GetModel(), Block[Y][X].GetModel().GetWorldMatrix());
}
void G_Block::SetModelPosition(int Y, int X)
{
	Block[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
	IceBlock[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
	GroundBlock[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
	DeleteBlock[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});

	SkeletonBlock[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
	SkeletonIceBlock[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
	SkeletonGroundBlock[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
	SkeletonDeleteBlock[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});

	Block_PSO[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
}
void G_Block::SetModelUpdate(int Y, int X)
{
	Block[Y][X].Update();
	IceBlock[Y][X].Update();
	GroundBlock[Y][X].Update();
	DeleteBlock[Y][X].Update();

	SkeletonBlock[Y][X].Update();
	SkeletonIceBlock[Y][X].Update();
	SkeletonGroundBlock[Y][X].Update();
	SkeletonDeleteBlock[Y][X].Update();
}

void G_Block::Map_On(int Y, int X)
{
	NonBlock[Y][X] = true;
}
void G_Block::Map_SetPosition(int Y, int X, Vector3 Position)
{
	Block_Position[Y][X].x = Position.x;
	Block_Position[Y][X].y = 150.0f;
	Block_Position[Y][X].z = Position.z;
}

void G_Block::NonBlockUpdate()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (NonBlock[Y][X] == true)
			{
				Block[Y][X].SetPosition(Block_Position[Y][X]);
				Block_PSO[Y][X].SetPosition(Block_Position[Y][X]);
				box->BlockBox_SetPosition(Y, X, Block_Position[Y][X]);
				Block[Y][X].Update();
			}
		}
	}
}
void G_Block::WeightBoardOn_Update()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (weightboard->GetPutFlag(Y, X) == true)
			{
				for (int Count = 1; Count <= weightboard->GetLinkCount(Y,X); Count++)
				{
					if (weightboard->GetLinkObject(Y, X, Count) == L_BLOCK)
					{
						weightboard->GetLinkNumberY(Y, X, Count);
						Block[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						Block_PSO[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						box->BlockBox_SetPosition(weightboard->GetLinkNumberY(Y, X, Count), weightboard->GetLinkNumberX(Y, X, Count), Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						Block[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == I_BLOCK)
					{
						stage->MapData[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].GroundData = ICE;
						IceBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-55.0f,Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						Block_PSO[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-50.0f,Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						IceBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == G_BLOCK)
					{
						stage->MapData[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].GroundData = GROUND;
						GroundBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-55.0f,Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						Block_PSO[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-50.0f,Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						GroundBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
					}else
					{
					if (weightboard->GetLinkObject(Y, X, Count) == H_BLOCK)
					{
						SkeletonDeleteBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						SkeletonDeleteBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
						Block_PSO[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
						box->BlockBox_SetPosition(weightboard->GetLinkNumberY(Y, X, Count), weightboard->GetLinkNumberX(Y, X, Count), { Grid_ExemptPosition_X, Grid_ExemptPosition_Y, Grid_ExemptPosition_Z });
					}
					}
					}
					}
				}
			}
		}
	}

}
void G_Block::WeightBoardOff_Update()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (weightboard->GetPutFlag(Y, X) == false)
			{
				for (int Count = 1; Count <= weightboard->GetLinkCount(Y,X); Count++)
				{
					if (weightboard->GetLinkObject(Y, X, Count) == L_BLOCK)
					{
						SkeletonBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						SkeletonBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
						Block_PSO[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
						box->BlockBox_SetPosition(weightboard->GetLinkNumberY(Y, X, Count), weightboard->GetLinkNumberX(Y, X, Count), { Grid_ExemptPosition_X, Grid_ExemptPosition_Y, Grid_ExemptPosition_Z });
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == I_BLOCK)
					{
						SkeletonIceBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-50.0f,Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						SkeletonIceBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
						stage->MapData[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].GroundData = HOLE;
						Block_PSO[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == G_BLOCK)
					{
						SkeletonGroundBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-50.0f,Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						SkeletonGroundBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
						stage->MapData[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].GroundData = HOLE;
						Block_PSO[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == H_BLOCK)
					{
						DeleteBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						Block_PSO[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						box->BlockBox_SetPosition(weightboard->GetLinkNumberY(Y, X, Count), weightboard->GetLinkNumberX(Y, X, Count), Block_Position[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						DeleteBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
					}
					}
					}
					}
				}

			}
		}
	}
}
void G_Block::Update()
{
	NonBlockUpdate();
	WeightBoardOn_Update();
	WeightBoardOff_Update();
}

void G_Block::Render(RenderContext& rc)
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if(NonBlock[Y][X]==true)
			{ 
				Block[Y][X].Draw(rc);
			}else{
				if (weightboard->GetPutFlag(Y, X) == true)
				{
					for (int Count = 1; Count <= weightboard->GetLinkCount(Y,X); Count++)
					{	
						if (weightboard->GetLinkObject(Y, X, Count) == L_BLOCK)
						{
							Block[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == I_BLOCK)
						{
							IceBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == G_BLOCK)
						{
							GroundBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == H_BLOCK)
						{
							SkeletonDeleteBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}
						}
						}
						}
						
					}
				}else {
				if (weightboard->GetPutFlag(Y, X) == false)
				{
					for (int Count = 1; Count <= weightboard->GetLinkCount(Y,X); Count++)
					{
						if (weightboard->GetLinkObject(Y, X, Count) == H_BLOCK)
						{
							DeleteBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == L_BLOCK)
						{
							SkeletonBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == I_BLOCK)
						{
							SkeletonIceBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == G_BLOCK)
						{
							SkeletonGroundBlock[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
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