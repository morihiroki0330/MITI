#include "stdafx.h"
#include "Stage.h"

#include "G_IceFloor.h"
#include "G_BreakFloar.h"
#include "G_WeightBoard.h"
#include "G_Wall.h"
#include "Hole.h"
#include "G_Block.h"
#include "G_Kaidan.h"

Stage::Stage()
{
	//コメントアウトする。
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	/*m_modelRender.Init("Assets/modelData/stage.tkm",stageLight);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());*/

	Kabe.Init("Assets/test/hekiga.tkm", stageLight);
	Kabe_P = { 0.0f,82.0f,0.0f };
	k_physicsStaticObjectpos.CreateFromModel(Kabe.GetModel(), Kabe.GetModel().GetWorldMatrix());
	Kabe.Update();
	Kabe.SetPosition(Kabe_P);

	//氷床
	{
		{
			//一行目
			mapdata[0][4].ice_on = true;
			mapdata[0][6].ice_on = true;
			mapdata[0][7].ice_on = true;
		}
		{
			//二行目
			mapdata[1][5].ice_on = true;
			mapdata[1][6].ice_on = true;
			mapdata[1][7].ice_on = true;
		}
		{
			//三行目
			mapdata[2][4].ice_on = true;
			mapdata[2][5].ice_on = true;
			mapdata[2][7].ice_on = true;
			mapdata[2][8].ice_on = true;
		}
		{
			//四行目
			mapdata[3][4].ice_on = true;
			mapdata[3][5].ice_on = true;
			mapdata[3][7].ice_on = true;
			mapdata[3][8].ice_on = true;
		}
		{
			//五行目
			mapdata[4][4].ice_on = true;
			mapdata[4][5].ice_on = true;
			mapdata[4][8].ice_on = true;
		}
		{
			//六行目
			mapdata[5][4].ice_on = true;
			mapdata[5][7].ice_on = true;
			mapdata[5][8].ice_on = true;
		}
		{
			//七行目
			mapdata[6][4].ice_on = true;
			mapdata[6][5].ice_on = true;
			mapdata[6][6].ice_on = true;
			mapdata[6][8].ice_on = true;
		}
		{
			//八行目
			mapdata[7][4].ice_on = true;
			mapdata[7][7].ice_on = true;
			mapdata[7][8].ice_on = true;
		}
		{
			//九行目
			mapdata[8][4].ice_on = true;
			mapdata[8][6].ice_on = true;
			mapdata[8][7].ice_on = true;
		}
		{
			//十行目
			mapdata[9][4].ice_on = true;
			mapdata[9][5].ice_on = true;
			mapdata[9][6].ice_on = true;
			mapdata[9][7].ice_on = true;
			mapdata[9][8].ice_on = true;
		}
	}

	//壁
	{
		//一行目
		/*mapdata[0][5].block_on = true;
		mapdata[0][8].block_on = true;*/

		//二行目
		/*mapdata[1][4].block_on = true;
		mapdata[1][8].block_on = true;*/

		//三行目
		mapdata[2][6].block_on = true;

		//四行目
		mapdata[3][6].block_on = true;
		//mapdata[3][9].block_on = true;

		//五行目
		/*mapdata[4][6].block_on = true;
		mapdata[4][7].block_on = true;*/

		//六行目
		/*mapdata[5][5].block_on = true;
		mapdata[5][6].block_on = true;*/

		//七行目

		mapdata[6][7].block_on = true;

		//八行目
		/*mapdata[7][5].block_on = true;
		mapdata[7][9].block_on = true;*/

		//九行目
		//mapdata[8][5].block_on = true;
		//mapdata[8][8].block_on = true;
		mapdata[8][9].block_on = true;

		//十行目
		//mapdata[9][6].block_on = true;

	}

	//落とし穴
	{
		//一行目
		mapdata[0][5].hole_on = true;
		mapdata[0][8].hole_on = true;

		//二行目
		mapdata[1][4].hole_on = true;
		mapdata[1][8].hole_on = true;

		//三行目
		//mapdata[2][6].hole_on = true;

		//四行目
		//mapdata[3][6].hole_on = true;
		mapdata[3][9].hole_on = true;

		//五行目
		mapdata[4][6].hole_on = true;
		mapdata[4][7].hole_on = true;

		//六行目
		mapdata[5][5].hole_on = true;
		mapdata[5][6].hole_on = true;

		//七行目
		//mapdata[6][7].hole_on = true;

		//八行目
		mapdata[7][5].hole_on = true;
		mapdata[7][6].hole_on = true;
		mapdata[7][9].hole_on = true;

		//九行目
		mapdata[8][5].hole_on = true;
		mapdata[8][8].hole_on = true;
		//mapdata[8][9].hole_on = true;

		//十行目
		//mapdata[9][6].hole_on = true;

	}

	//感圧板
	{
		weightblock_create = true;

		mapdata[0][9].weightboard_map = true;

		mapdata[1][2].weightboard_map = true;
		mapdata[1][2].weightboard_block_link = true;
		//一個目
		mapdata[1][2].weightboard_block_map[0][0] = 4;
		mapdata[1][2].weightboard_block_map[0][1] = 7;
		//二個目
		mapdata[1][2].weightboard_block_map[1][0] = 5;
		mapdata[1][2].weightboard_block_map[1][1] = 5;
		//三個目
		mapdata[1][2].weightboard_block_map[2][0] = 5;
		mapdata[1][2].weightboard_block_map[2][1] = 6;

		mapdata[3][0].weightboard_map = true;

		mapdata[3][2].weightboard_map = true;
		mapdata[3][2].weightboard_block_link = true;
		//一個目
		mapdata[3][2].weightboard_block_map[0][0] = 0;
		mapdata[3][2].weightboard_block_map[0][1] = 8;
		//二個目
		mapdata[3][2].weightboard_block_map[1][0] = 4;
		mapdata[3][2].weightboard_block_map[1][1] = 6;
		//三個目
		mapdata[3][2].weightboard_block_map[2][0] = 8;
		mapdata[3][2].weightboard_block_map[2][1] = 8;

		mapdata[5][0].weightboard_map = true;
		mapdata[5][2].weightboard_map = true;

		mapdata[7][0].weightboard_map = true;
		mapdata[7][0].weightboard_block_link = true;
		//一個目
		mapdata[7][0].weightboard_block_map[0][0] = 1;
		mapdata[7][0].weightboard_block_map[0][1] = 4;
		//二個目
		mapdata[7][0].weightboard_block_map[1][0] = 1;
		mapdata[7][0].weightboard_block_map[1][1] = 8;
		//三個目
		mapdata[7][0].weightboard_block_map[2][0] = 7;
		mapdata[7][0].weightboard_block_map[2][1] = 9;


		mapdata[7][2].weightboard_map = true;
		mapdata[7][2].weightboard_block_link = true;
		//一個目
		mapdata[7][2].weightboard_block_map[0][0] = 0;
		mapdata[7][2].weightboard_block_map[0][1] = 5;
		//二個目
		mapdata[7][2].weightboard_block_map[1][0] = 7;
		mapdata[7][2].weightboard_block_map[1][1] = 5;
		//三個目
		mapdata[7][2].weightboard_block_map[2][0] = 9;
		mapdata[7][2].weightboard_block_map[2][1] = 6;

		mapdata[9][0].weightboard_map = true;

		mapdata[9][2].weightboard_map = true;
		mapdata[9][2].weightboard_block_link = true;
		//一個目
		mapdata[9][2].weightboard_block_map[0][0] = 3;
		mapdata[9][2].weightboard_block_map[0][1] = 9;
		//二個目
		mapdata[9][2].weightboard_block_map[1][0] = 8;
		mapdata[9][2].weightboard_block_map[1][1] = 5;
		//三個目
		mapdata[9][2].weightboard_block_map[2][0] = 7;
		mapdata[9][2].weightboard_block_map[2][1] = 6;
	}

	//階段
	{
		mapdata[9][9].kaidan_on = true;
	}

	//座標の設定
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Ground_P[i][j].x = (i * 190.0f) + -874.0f;
			Ground_P[i][j].y = 0.0f;
			Ground_P[i][j].z = (j * 190.0f) + -865.0f;
		}
	}

	//床の設定
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
		//地面の生成
			//氷の床
			if (mapdata[i][j].ice_on == true)
			{
				mapdata[i][j].ice = NewGO<G_IceFloor>(0);
				mapdata[i][j].ice->position = Ground_P[i][j];
				mapdata[i][j].ice->position.y = -20.0f;
			}else {
			//落とし穴
			if (mapdata[i][j].hole_on == true)
			{

			}else {
			//感圧板
			if (mapdata[i][j].weightboard_map == true)
			{
				mapdata[i][j].weightboard = NewGO<G_WeightBoard>(0, "weightboard");
				mapdata[i][j].weightboard->position = Ground_P[i][j];
				mapdata[i][j].weightboard->position.y = -20.0f;
				Ground[i][j].Init("Assets/test/ground.tkm", stageLight);
				Ground[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].Update();
			}else {
			if (mapdata[i][j].kaidan_on == true)
			{
				mapdata[i][j].kaidan = NewGO<G_Kaidan>(0, "kaidan");
				mapdata[i][j].kaidan->Kaidan_P = Ground_P[i][j];
				mapdata[i][j].kaidan->Kaidan_P.y = 20.0f;
				Ground[i][j].Init("Assets/test/ground.tkm", stageLight);
				Ground[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].Update();
			}else {
				Ground[i][j].Init("Assets/test/ground.tkm", stageLight);
				g_physicsStaticObjectpos[i][j].CreateFromModel(Ground[i][j].GetModel(), Ground[i][j].GetModel().GetWorldMatrix());
				g_physicsStaticObjectpos[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].Update();
			}
			}
			}
			}
		
			////氷の床
			//if (mapdata[i][j].ice_on == true)
			//{

			//	mapdata[i][j].ice = NewGO<G_IceFloor>(0);
			//	mapdata[i][j].ice->position = Ground_P[i][j];
			//	mapdata[i][j].ice->position.y = -20.0f;

			//}
			//else {
			//	//落とし穴
			//	if (mapdata[i][j].hole_on == true)
			//	{

			//	}
			//	else {
			//		//感圧板
			/*if (mapdata[i][j].weightboard_map == true)
			{
				mapdata[i][j].weightboard = NewGO<G_WeightBoard>(0, "weightboard");
				mapdata[i][j].weightboard->position = Ground_P[i][j];
				mapdata[i][j].weightboard->position.y = -20.0f;
				Ground[i][j].Init("Assets/test/ground.tkm", stageLight);
				Ground[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].Update();
			}*/
			//		else {
			//			if (mapdata[i][j].kaidan_on == true)
			//			{
			//				mapdata[i][j].kaidan = NewGO<G_Kaidan>(0, "kaidan");
			//				mapdata[i][j].kaidan->Kaidan_P = Ground_P[i][j];
			//				mapdata[i][j].kaidan->Kaidan_P.y = 20.0f;
			//				Ground[i][j].Init("Assets/test/ground.tkm", stageLight);
			//				Ground[i][j].SetPosition(Ground_P[i][j]);
			//				Ground[i][j].Update();
			//			}
			//			else {
			//				Ground[i][j].Init("Assets/test/ground.tkm", stageLight);
			//				g_physicsStaticObjectpos[i][j].CreateFromModel(Ground[i][j].GetModel(), Ground[i][j].GetModel().GetWorldMatrix());
			//				g_physicsStaticObjectpos[i][j].SetPosition(Ground_P[i][j]);
			//				Ground[i][j].SetPosition(Ground_P[i][j]);
			//				Ground[i][j].Update();
			//			}
			//		}
			//	}
			//}

			//感圧板
			if (mapdata[i][j].weightboard_map == true)
			{
				mapdata[i][j].weightboard = NewGO<G_WeightBoard>(0, "weightboard");
				mapdata[i][j].weightboard->position = Ground_P[i][j];
				mapdata[i][j].weightboard->position.y = -20.0f;
				Ground[i][j].Init("Assets/test/ground.tkm", stageLight);
				Ground[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].Update();
			}
			
			if (mapdata[i][j].block_on == true)
			{
				mapdata[i][j].block = NewGO<G_Block>(0, "block");
				mapdata[i][j].block->Block_P[0] = Ground_P[i][j];
				mapdata[i][j].block->Block_P[0].y = 200.0f;
				mapdata[i][j].block->block = true;

			}
			else

			//壁
			if (mapdata[i][j].weightboard_map == true && mapdata[i][j].weightboard_block_link == true)
			{
				mapdata[i][j].block = NewGO<G_Block>(0, "block");

				for (int a = 0; a < 10; a++)
				{
					for (int b = 0; b < 1; b++)
					{
						if (mapdata[i][j].weightboard_block_map[a][b] == 0 && mapdata[i][j].weightboard_block_map[a][b + 1] == 0)
						{
							continue;
						}
						mapdata[i][j].block->Block_P[a] = Ground_P[mapdata[i][j].weightboard_block_map[a][b]][mapdata[i][j].weightboard_block_map[a][b + 1]];
						mapdata[i][j].block->Block_P[a].y = 200.0f;
						mapdata[i][j].block->blockcount += 1;
					}
				}
			}
			}
	}
}

Stage::~Stage()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			//氷の床
			if (mapdata[i][j].ice_on == true)
			{
				DeleteGO(mapdata[i][j].ice);
			}

			if (mapdata[i][j].weightboard_map == true)
			{
				DeleteGO(mapdata[i][j].weightboard);
			}

			if (mapdata[i][j].block_on == true)
			{
				DeleteGO(mapdata[i][j].block);
			}
			
			if (mapdata[i][j].kaidan_on == true)
			{
				DeleteGO(mapdata[i][j].kaidan);
			}


		}
	}
}

void Stage::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
	Kabe.Draw(rc);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Ground[i][j].Draw(rc);
		}
	}
}