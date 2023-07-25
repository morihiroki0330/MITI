#include "stdafx.h"
#include "G_Block.h"
#include "G_WeightBoard.h"
#include "Box.h"
#include "Stage.h"
#include "NumberStorage.h"
G_Block::G_Block()
{
	InitModel();
}
bool G_Block::Start()
{
	M_WeightBoard = FindGO<G_WeightBoard>("weightboard");
	M_Box = FindGO<Box>("box");
	M_Stage = FindGO<Stage>("stage");
	return true;
}

void G_Block::InitModel()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_BlockModel[Y][X].Init("Assets/modelData/isi.tkm", M_BlockLight);
			M_IceBlockModel[Y][X].Init("Assets/modelData/ice1.tkm", M_BlockLight);
			M_GroundBlockModel[Y][X].Init("Assets/modelData/ground1.tkm", M_BlockLight);
			M_DeleteBlockModel[Y][X].Init("Assets/modelData/DeleteBlock.tkm", M_BlockLight);

			M_SkeletonBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Block.tkm", M_BlockLight);
			M_SkeletonIceBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Ice.tkm", M_BlockLight);
			M_SkeletonGroundBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Ground.tkm", M_BlockLight);
			M_SkeletonDeleteBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Delete.tkm", M_BlockLight);

			M_BlockPhysicsStaticObject[Y][X].CreateFromModel(M_BlockModel[Y][X].GetModel(), M_BlockModel[Y][X].GetModel().GetWorldMatrix());

			M_BlockModel[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });
			M_IceBlockModel[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });
			M_GroundBlockModel[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });
			M_DeleteBlockModel[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });

			M_SkeletonBlockModel[Y][X].SetPosition({S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ});
			M_SkeletonIceBlockModel[Y][X].SetPosition({S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ});
			M_SkeletonGroundBlockModel[Y][X].SetPosition({S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ});
			M_SkeletonDeleteBlockModel[Y][X].SetPosition({S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ});

			M_BlockPhysicsStaticObject[Y][X].SetPosition({S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ});

			M_BlockModel[Y][X].Update();
			M_IceBlockModel[Y][X].Update();
			M_GroundBlockModel[Y][X].Update();
			M_DeleteBlockModel[Y][X].Update();

			M_SkeletonBlockModel[Y][X].Update();
			M_SkeletonIceBlockModel[Y][X].Update();
			M_SkeletonGroundBlockModel[Y][X].Update();
			M_SkeletonDeleteBlockModel[Y][X].Update();
		}
	}
	
}
void G_Block::BlockOn(int Y, int X)
{
	M_NonBlock[Y][X] = true;
}
void G_Block::BlockSetPosition(int Y, int X, Vector3 Position)
{
	M_BlockPosition[Y][X].x = Position.x;
	M_BlockPosition[Y][X].y = 150.0f;
	M_BlockPosition[Y][X].z = Position.z;
}
void G_Block::NonBlockUpdate()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (M_NonBlock[Y][X] == true)
			{
				M_BlockModel[Y][X].SetPosition(M_BlockPosition[Y][X]);
				M_BlockPhysicsStaticObject[Y][X].SetPosition(M_BlockPosition[Y][X]);
				M_Box->BlockBoxSetPosition(Y, X, M_BlockPosition[Y][X]);
				M_BlockModel[Y][X].Update();
			}
		}
	}
}
void G_Block::WeightBoardOnUpdate()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (M_WeightBoard->GetSwitchOnFlag(Y, X) == true)
			{
				for (int Count = 1; Count <= M_WeightBoard->GetLinkCount(Y,X); Count++)
				{
					if (M_WeightBoard->GetLinkObject(Y, X, Count) == NONBLOCK)
					{
						M_WeightBoard->GetLinkNumberY(Y, X, Count);
						M_BlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition(M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)]);
						M_BlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Update();
						M_BlockPhysicsStaticObject[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition(M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)]);
						M_Box->BlockBoxSetPosition(M_WeightBoard->GetLinkNumberY(Y, X, Count), M_WeightBoard->GetLinkNumberX(Y, X, Count), M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)]);
					}else {
					if (M_WeightBoard->GetLinkObject(Y, X, Count) == ICEBLOCK)
					{
						M_Stage->GroundDataSet(M_WeightBoard->GetLinkNumberY(Y, X, Count), M_WeightBoard->GetLinkNumberX(Y, X, Count), ICE);
						M_IceBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].x,-55.0f,M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].z });
						M_IceBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Update();
						M_BlockPhysicsStaticObject[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].x,-50.0f,M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].z });
					}else {
					if (M_WeightBoard->GetLinkObject(Y, X, Count) == GROUNDBLOCK)
					{
						M_Stage->GroundDataSet(M_WeightBoard->GetLinkNumberY(Y, X, Count), M_WeightBoard->GetLinkNumberX(Y, X, Count), GROUND);
						M_GroundBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].x,-55.0f,M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].z });
						M_GroundBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Update();
						M_BlockPhysicsStaticObject[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].x,-50.0f,M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].z });
						
					}else
					{
					if (M_WeightBoard->GetLinkObject(Y, X, Count) == DELETEBLOCK)
					{
						M_SkeletonDeleteBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition(M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)]);
						M_SkeletonDeleteBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Update();
						M_BlockPhysicsStaticObject[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
						M_Box->BlockBoxSetPosition(M_WeightBoard->GetLinkNumberY(Y, X, Count), M_WeightBoard->GetLinkNumberX(Y, X, Count), { S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });
					}
					}
					}
					}
				}
			}
		}
	}

}
void G_Block::WeightBoardOffUpdate()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (M_WeightBoard->GetSwitchOnFlag(Y, X) == false)
			{
				for (int Count = 1; Count <= M_WeightBoard->GetLinkCount(Y,X); Count++)
				{
					if (M_WeightBoard->GetLinkObject(Y, X, Count) == NONBLOCK)
					{
						M_SkeletonBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition(M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)]);
						M_SkeletonBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Update();
						M_BlockPhysicsStaticObject[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
						M_Box->BlockBoxSetPosition(M_WeightBoard->GetLinkNumberY(Y, X, Count), M_WeightBoard->GetLinkNumberX(Y, X, Count), { S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });
					}else {
					if (M_WeightBoard->GetLinkObject(Y, X, Count) == ICEBLOCK)
					{
						M_Stage->GroundDataSet(M_WeightBoard->GetLinkNumberY(Y, X, Count), M_WeightBoard->GetLinkNumberX(Y, X, Count), HOLE);
						M_SkeletonIceBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].x,-50.0f,M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].z });
						M_SkeletonIceBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Update();
						M_BlockPhysicsStaticObject[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
					}else {
					if (M_WeightBoard->GetLinkObject(Y, X, Count) == GROUNDBLOCK)
					{
						M_Stage->GroundDataSet(M_WeightBoard->GetLinkNumberY(Y, X, Count), M_WeightBoard->GetLinkNumberX(Y, X, Count), HOLE);
						M_SkeletonGroundBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].x,-50.0f,M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].z });
						M_SkeletonGroundBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Update();
						M_BlockPhysicsStaticObject[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
					}else {
					if (M_WeightBoard->GetLinkObject(Y, X, Count) == DELETEBLOCK)
					{
						M_DeleteBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition(M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)]);
						M_DeleteBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Update();
						M_BlockPhysicsStaticObject[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].SetPosition(M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)]);
						M_Box->BlockBoxSetPosition(M_WeightBoard->GetLinkNumberY(Y, X, Count), M_WeightBoard->GetLinkNumberX(Y, X, Count), M_BlockPosition[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)]);
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
	WeightBoardOnUpdate();
	WeightBoardOffUpdate();
}
void G_Block::Render(RenderContext& rc)
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if(M_NonBlock[Y][X]==true)
			{ 
				M_BlockModel[Y][X].Draw(rc);
			}else{
				if (M_WeightBoard->GetSwitchOnFlag(Y, X) == true)
				{
					for (int Count = 1; Count <= M_WeightBoard->GetLinkCount(Y,X); Count++)
					{	
						if (M_WeightBoard->GetLinkObject(Y, X, Count) == NONBLOCK)
						{
							M_BlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (M_WeightBoard->GetLinkObject(Y, X, Count) == ICEBLOCK)
						{
							M_IceBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (M_WeightBoard->GetLinkObject(Y, X, Count) == GROUNDBLOCK)
						{
							M_GroundBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (M_WeightBoard->GetLinkObject(Y, X, Count) == DELETEBLOCK)
						{
							M_SkeletonDeleteBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}
						}
						}
						}
						
					}
				}else {
				if (M_WeightBoard->GetSwitchOnFlag(Y, X) == false)
				{
					for (int Count = 1; Count <= M_WeightBoard->GetLinkCount(Y,X); Count++)
					{
						if (M_WeightBoard->GetLinkObject(Y, X, Count) == DELETEBLOCK)
						{
							M_DeleteBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (M_WeightBoard->GetLinkObject(Y, X, Count) == NONBLOCK)
						{
							M_SkeletonBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (M_WeightBoard->GetLinkObject(Y, X, Count) == ICEBLOCK)
						{
							M_SkeletonIceBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Draw(rc);
						}else {
						if (M_WeightBoard->GetLinkObject(Y, X, Count) == GROUNDBLOCK)
						{
							M_SkeletonGroundBlockModel[M_WeightBoard->GetLinkNumberY(Y, X, Count)][M_WeightBoard->GetLinkNumberX(Y, X, Count)].Draw(rc);
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