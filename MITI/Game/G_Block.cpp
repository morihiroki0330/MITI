#include "stdafx.h"
#include "G_Block.h"
#include "G_WeightBoard.h"
#include "Box.h"
#include "Stage.h"
G_Block::G_Block()
{
	InitModel();
}
bool G_Block::Start()
{
	P_WeightBoard = FindGO<G_WeightBoard>("weightboard");
	P_Box = FindGO<Box>("box");
	P_Stage = FindGO<Stage>("stage");
	return true;
}
void G_Block::InitModel()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_BlockModel[Y][X].Init("Assets/modelData/isi.tkm", M_BlockLight);
			M_BlockPhysicsStaticObject[Y][X].CreateFromModel(M_BlockModel[Y][X].GetModel(), M_BlockModel[Y][X].GetModel().GetWorldMatrix());
			M_BlockPhysicsStaticObject[Y][X].SetPosition({ S_GridPosition.M_GridExemptPositionX,S_GridPosition.M_GridExemptPositionY,S_GridPosition.M_GridExemptPositionZ });
			M_BlockModel[Y][X].SetPosition(
			{ 
				S_GridPosition.M_GridExemptPositionX,
				S_GridPosition.M_GridExemptPositionY,
				S_GridPosition.M_GridExemptPositionZ 
			});
			M_BlockModel[Y][X].Update();

			M_IceBlockModel[Y][X].Init("Assets/modelData/ice1.tkm", M_BlockLight);
			M_IceBlockModel[Y][X].SetPosition(
			{ 
				S_GridPosition.M_GridExemptPositionX,
				S_GridPosition.M_GridExemptPositionY,
				S_GridPosition.M_GridExemptPositionZ 
			});
			M_IceBlockModel[Y][X].Update();

			M_GroundBlockModel[Y][X].Init("Assets/modelData/ground1.tkm", M_BlockLight);
			M_GroundBlockModel[Y][X].SetPosition(
			{
				S_GridPosition.M_GridExemptPositionX,
				S_GridPosition.M_GridExemptPositionY,
				S_GridPosition.M_GridExemptPositionZ 
			});
			M_GroundBlockModel[Y][X].Update();

			M_DeleteBlockModel[Y][X].Init("Assets/modelData/DeleteBlock.tkm", M_BlockLight);
			M_DeleteBlockModel[Y][X].SetPosition(
			{
				S_GridPosition.M_GridExemptPositionX,
				S_GridPosition.M_GridExemptPositionY,
				S_GridPosition.M_GridExemptPositionZ 
			});
			M_DeleteBlockModel[Y][X].Update();

			M_SkeletonBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Block.tkm", M_BlockLight);
			M_SkeletonBlockModel[Y][X].SetPosition(
			{
				S_GridPosition.M_GridExemptPositionX,
				S_GridPosition.M_GridExemptPositionY,
				S_GridPosition.M_GridExemptPositionZ
			});
			M_SkeletonBlockModel[Y][X].Update();

			M_SkeletonIceBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Ice.tkm", M_BlockLight);
			M_SkeletonIceBlockModel[Y][X].SetPosition(
			{
				S_GridPosition.M_GridExemptPositionX,
				S_GridPosition.M_GridExemptPositionY,
				S_GridPosition.M_GridExemptPositionZ
			});
			M_SkeletonIceBlockModel[Y][X].Update();

			M_SkeletonGroundBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Ground.tkm", M_BlockLight);
			M_SkeletonGroundBlockModel[Y][X].SetPosition(
			{
				S_GridPosition.M_GridExemptPositionX,
				S_GridPosition.M_GridExemptPositionY,
				S_GridPosition.M_GridExemptPositionZ
			});
			M_SkeletonGroundBlockModel[Y][X].Update();

			M_SkeletonDeleteBlockModel[Y][X].Init("Assets/modelData/SkeletonBlock/S_Delete.tkm", M_BlockLight);
			M_SkeletonDeleteBlockModel[Y][X].SetPosition(
			{
				S_GridPosition.M_GridExemptPositionX,
				S_GridPosition.M_GridExemptPositionY,
				S_GridPosition.M_GridExemptPositionZ
			});
			M_SkeletonDeleteBlockModel[Y][X].Update();
		}
	}
	
}

void G_Block::BlockOn(int Y, int X)
{
	M_NonBlockDecision[Y][X] = true;
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
			if (M_NonBlockDecision[Y][X])
			{
				P_Stage->SkyDataSet(Y, X, BLOCK);
				M_BlockModel[Y][X].SetPosition(M_BlockPosition[Y][X]);
				M_BlockPhysicsStaticObject[Y][X].SetPosition(M_BlockPosition[Y][X]);
				P_Box->BlockBoxSetPosition(Y, X, M_BlockPosition[Y][X]);
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
			if (P_WeightBoard->GetSwitchOnFlag(Y, X))
			{
				for (int i = 1; i <= P_WeightBoard->GetLinkCount(Y,X); i++)
				{
					if (P_WeightBoard->GetLinkObject(Y, X, i) == NONBLOCK)
					{
						P_WeightBoard->GetLinkNumberY(Y, X, i);

						P_Stage->SkyDataSet
						(
							P_WeightBoard->GetLinkNumberY(Y, X, i),
							P_WeightBoard->GetLinkNumberX(Y, X, i), BLOCK
						);

						M_BlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition
						(
							M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)]
						);

						M_BlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Update();

						/*M_BlockPhysicsStaticObject[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition
						(
							M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)]
						);*/

						P_Box->BlockBoxSetPosition
						(
							P_WeightBoard->GetLinkNumberY(Y, X, i),
							P_WeightBoard->GetLinkNumberX(Y, X, i),
							M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)]
						);

					}else {
						if (P_WeightBoard->GetLinkObject(Y, X, i) == ICEBLOCK)
						{
							P_Stage->GroundDataSet(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), ICE);

							M_IceBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
							{ 
								M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].x,
								-50.0f,
								M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].z 
							});
							M_IceBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Update();

							M_BlockPhysicsStaticObject[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
							{ 
								M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].x,
								-50.0f,
								M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].z 
							});

						}else {
							if (P_WeightBoard->GetLinkObject(Y, X, i) == GROUNDBLOCK)
							{
								P_Stage->GroundDataSet(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), GROUND);

								M_GroundBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
								{
									M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].x,
									-50.0f,
									M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].z 
								});

								M_GroundBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Update();

								/*M_BlockPhysicsStaticObject[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
								{
									M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].x,
									-50.0f,
									M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].z 
								});*/
						
							}else{
								if (P_WeightBoard->GetLinkObject(Y, X, i) == DELETEBLOCK)
								{
									P_Stage->SkyDataSet(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), NOTBLOCK);

									M_SkeletonDeleteBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition
									(
										M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)]
									);
		
									M_SkeletonDeleteBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Update();

									/*M_BlockPhysicsStaticObject[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
									{ 
										S_GridPosition.M_GridExemptPositionX,
										S_GridPosition.M_GridExemptPositionY,
										S_GridPosition.M_GridExemptPositionZ
									});*/

									P_Box->BlockBoxSetPosition(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), { S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });
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
			if (!P_WeightBoard->GetSwitchOnFlag(Y, X))
			{
				for (int i = 1; i <= P_WeightBoard->GetLinkCount(Y,X); i++)
				{
					if (P_WeightBoard->GetLinkObject(Y, X, i) == NONBLOCK)
					{
						P_Stage->SkyDataSet(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), NOTBLOCK);

						M_SkeletonBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition
						(
							M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)]
						);

						M_SkeletonBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Update();

						/*M_BlockPhysicsStaticObject[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
						{
							S_GridPosition.M_GridExemptPositionX,
							S_GridPosition.M_GridExemptPositionY,
							S_GridPosition.M_GridExemptPositionZ 
						});*/

						P_Box->BlockBoxSetPosition(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), { S_GridPosition.M_GridExemptPositionX, S_GridPosition.M_GridExemptPositionY, S_GridPosition.M_GridExemptPositionZ });
					}else {
						if (P_WeightBoard->GetLinkObject(Y, X, i) == ICEBLOCK)
						{
							P_Stage->GroundDataSet(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), HOLE);

							M_SkeletonIceBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
							{ 
								M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].x,
								-50.0f,
								M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].z 
							});
	
							M_SkeletonIceBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Update();

							/*M_BlockPhysicsStaticObject[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
							{ 
								S_GridPosition.M_GridExemptPositionX,
								S_GridPosition.M_GridExemptPositionY,
								S_GridPosition.M_GridExemptPositionZ
							});*/

						}else {
							if (P_WeightBoard->GetLinkObject(Y, X, i) == GROUNDBLOCK)
							{
								P_Stage->GroundDataSet(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), HOLE);
	
								M_SkeletonGroundBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
								{ 
									M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].x,
									-50.0f,
									M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].z 
								});

								M_SkeletonGroundBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Update();

								/*M_BlockPhysicsStaticObject[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition(
								{ 
									S_GridPosition.M_GridExemptPositionX,
									S_GridPosition.M_GridExemptPositionY,
									S_GridPosition.M_GridExemptPositionZ 
								});*/
							}else {
								if (P_WeightBoard->GetLinkObject(Y, X, i) == DELETEBLOCK)
								{
									P_Stage->SkyDataSet(P_WeightBoard->GetLinkNumberY(Y, X, i), P_WeightBoard->GetLinkNumberX(Y, X, i), BLOCK);

									M_DeleteBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition
									(
										M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)]
									);

									M_DeleteBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Update();
	
									/*M_BlockPhysicsStaticObject[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].SetPosition
									(
										M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)]
									);*/

									P_Box->BlockBoxSetPosition
									(
										P_WeightBoard->GetLinkNumberY(Y, X, i),
										P_WeightBoard->GetLinkNumberX(Y, X, i),
										M_BlockPosition[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)]
									);
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
			if(M_NonBlockDecision[Y][X]==true)
			{ 
				M_BlockModel[Y][X].Draw(rc);
			}else{
				if (P_WeightBoard->GetSwitchOnFlag(Y, X))
				{
					for (int i = 1; i <= P_WeightBoard->GetLinkCount(Y,X); i++)
					{	
						if (P_WeightBoard->GetLinkObject(Y, X, i) == NONBLOCK)
						{
							M_BlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Draw(rc);
						}else {
							if (P_WeightBoard->GetLinkObject(Y, X, i) == ICEBLOCK)
							{
								M_IceBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Draw(rc);
							}else {
								if (P_WeightBoard->GetLinkObject(Y, X, i) == GROUNDBLOCK)
								{
									M_GroundBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Draw(rc);
								}else {
									if (P_WeightBoard->GetLinkObject(Y, X, i) == DELETEBLOCK)
									{
										M_SkeletonDeleteBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Draw(rc);
									}
								}
							}
						}
					}
				}else {
					if (!P_WeightBoard->GetSwitchOnFlag(Y, X))
					{
						for (int i = 1; i <= P_WeightBoard->GetLinkCount(Y,X); i++)
						{
							if (P_WeightBoard->GetLinkObject(Y, X, i) == DELETEBLOCK)
							{
								M_DeleteBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Draw(rc);
							}else {
								if (P_WeightBoard->GetLinkObject(Y, X, i) == NONBLOCK)
								{
								M_SkeletonBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Draw(rc);
								}else {
									if (P_WeightBoard->GetLinkObject(Y, X, i) == ICEBLOCK)
									{
										M_SkeletonIceBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Draw(rc);
									}else {
										if (P_WeightBoard->GetLinkObject(Y, X, i) == GROUNDBLOCK)
										{
											M_SkeletonGroundBlockModel[P_WeightBoard->GetLinkNumberY(Y, X, i)][P_WeightBoard->GetLinkNumberX(Y, X, i)].Draw(rc);
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