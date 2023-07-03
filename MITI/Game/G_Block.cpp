#include "stdafx.h"
#include "G_Block.h"
#include "G_WeightBoard.h"
#include "Box.h"
#include "Stage.h"
#include "Number_Storage.h"
G_Block::G_Block()
{
	InitModel();
}
bool G_Block::Start()
{
	weightboard = FindGO<G_WeightBoard>("weightboard");
	box = FindGO<Box>("box");
	stage = FindGO<Stage>("stage");
	return true;
}

void G_Block::InitModel()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			BlockModel[Y][X].Init("Assets/modelData/isi.tkm", BlockLight);
			IceBlockModel[Y][X].Init("Assets/modelData/ice1.tkm", BlockLight);
			GroundBlockModel[Y][X].Init("Assets/modelData/ground1.tkm", BlockLight);
			DeleteBlockModel[Y][X].Init("Assets/modelData/DeleteBlock.tkm", BlockLight);

			SkeletonBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Block.tkm", BlockLight);
			SkeletonIceBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Ice.tkm", BlockLight);
			SkeletonGroundBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Ground.tkm", BlockLight);
			SkeletonDeleteBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Delete.tkm", BlockLight);

			BlockPhysicsStaticObject[Y][X].CreateFromModel(BlockModel[Y][X].GetModel(), BlockModel[Y][X].GetModel().GetWorldMatrix());

			BlockModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
			IceBlockModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
			GroundBlockModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
			DeleteBlockModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});

			SkeletonBlockModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
			SkeletonIceBlockModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
			SkeletonGroundBlockModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});
			SkeletonDeleteBlockModel[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});

			BlockPhysicsStaticObject[Y][X].SetPosition({Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z});

			BlockModel[Y][X].Update();
			IceBlockModel[Y][X].Update();
			GroundBlockModel[Y][X].Update();
			DeleteBlockModel[Y][X].Update();

			SkeletonBlockModel[Y][X].Update();
			SkeletonIceBlockModel[Y][X].Update();
			SkeletonGroundBlockModel[Y][X].Update();
			SkeletonDeleteBlockModel[Y][X].Update();
		}
	}
	
}

void G_Block::BlockOn(int Y, int X)
{
	NonBlock[Y][X] = true;
}
void G_Block::BlockSetPosition(int Y, int X, Vector3 Position)
{
	BlockPosition[Y][X].x = Position.x;
	BlockPosition[Y][X].y = 150.0f;
	BlockPosition[Y][X].z = Position.z;
}

void G_Block::NonBlockUpdate()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (NonBlock[Y][X] == true)
			{
				BlockModel[Y][X].SetPosition(BlockPosition[Y][X]);
				BlockPhysicsStaticObject[Y][X].SetPosition(BlockPosition[Y][X]);
				box->BlockBoxSetPosition(Y, X, BlockPosition[Y][X]);
				BlockModel[Y][X].Update();
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
			if (weightboard->GetSwitchOnFlag(Y, X) == true)
			{
				for (int Count = 1; Count <= weightboard->GetLinkCount(Y,X); Count++)
				{
					if (weightboard->GetLinkObject(Y, X, Count) == L_BLOCK)
					{
						weightboard->GetLinkNumberY(Y, X, Count);
						BlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						BlockPhysicsStaticObject[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						box->BlockBoxSetPosition(weightboard->GetLinkNumberY(Y, X, Count), weightboard->GetLinkNumberX(Y, X, Count), BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						BlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == I_BLOCK)
					{
						stage->MapData[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].GroundData = ICE;
						IceBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-55.0f,BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						BlockPhysicsStaticObject[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-50.0f,BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						IceBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == G_BLOCK)
					{
						stage->MapData[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].GroundData = GROUND;
						GroundBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-55.0f,BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						BlockPhysicsStaticObject[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-50.0f,BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						GroundBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
					}else
					{
					if (weightboard->GetLinkObject(Y, X, Count) == H_BLOCK)
					{
						SkeletonDeleteBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						SkeletonDeleteBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
						BlockPhysicsStaticObject[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
						box->BlockBoxSetPosition(weightboard->GetLinkNumberY(Y, X, Count), weightboard->GetLinkNumberX(Y, X, Count), { Grid_ExemptPosition_X, Grid_ExemptPosition_Y, Grid_ExemptPosition_Z });
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
			if (weightboard->GetSwitchOnFlag(Y, X) == false)
			{
				for (int Count = 1; Count <= weightboard->GetLinkCount(Y,X); Count++)
				{
					if (weightboard->GetLinkObject(Y, X, Count) == L_BLOCK)
					{
						SkeletonBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						SkeletonBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
						BlockPhysicsStaticObject[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
						box->BlockBoxSetPosition(weightboard->GetLinkNumberY(Y, X, Count), weightboard->GetLinkNumberX(Y, X, Count), { Grid_ExemptPosition_X, Grid_ExemptPosition_Y, Grid_ExemptPosition_Z });
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == I_BLOCK)
					{
						SkeletonIceBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-50.0f,BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						SkeletonIceBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
						stage->MapData[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].GroundData = HOLE;
						BlockPhysicsStaticObject[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == G_BLOCK)
					{
						SkeletonGroundBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].x,-50.0f,BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].z });
						SkeletonGroundBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
						stage->MapData[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].GroundData = HOLE;
						BlockPhysicsStaticObject[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition({ Grid_ExemptPosition_X,Grid_ExemptPosition_Y,Grid_ExemptPosition_Z });
					}else {
					if (weightboard->GetLinkObject(Y, X, Count) == H_BLOCK)
					{
						DeleteBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						BlockPhysicsStaticObject[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].SetPosition(BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						box->BlockBoxSetPosition(weightboard->GetLinkNumberY(Y, X, Count), weightboard->GetLinkNumberX(Y, X, Count), BlockPosition[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)]);
						DeleteBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Update();
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
				BlockModel[Y][X].Draw(rc);
			}else{
				if (weightboard->GetSwitchOnFlag(Y, X) == true)
				{
					for (int Count = 1; Count <= weightboard->GetLinkCount(Y,X); Count++)
					{	
						if (weightboard->GetLinkObject(Y, X, Count) == L_BLOCK)
						{
							BlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == I_BLOCK)
						{
							IceBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == G_BLOCK)
						{
							GroundBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == H_BLOCK)
						{
							SkeletonDeleteBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}
						}
						}
						}
						
					}
				}else {
				if (weightboard->GetSwitchOnFlag(Y, X) == false)
				{
					for (int Count = 1; Count <= weightboard->GetLinkCount(Y,X); Count++)
					{
						if (weightboard->GetLinkObject(Y, X, Count) == H_BLOCK)
						{
							DeleteBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == L_BLOCK)
						{
							SkeletonBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == I_BLOCK)
						{
							SkeletonIceBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (weightboard->GetLinkObject(Y, X, Count) == G_BLOCK)
						{
							SkeletonGroundBlockModel[weightboard->GetLinkNumberY(Y, X, Count)][weightboard->GetLinkNumberX(Y, X, Count)].Draw(rc);
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