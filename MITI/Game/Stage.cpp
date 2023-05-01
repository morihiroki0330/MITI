#include "stdafx.h"
#include "Stage.h"

#include "G_IceFloor.h"
#include "G_BreakFloar.h"
#include "G_WeightBoard.h"
#include "G_Wall.h"
#include "G_Hole.h"
#include "G_Block.h"
#include "G_Kaidan.h"
#include "G_Ground.h"

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
	
	weightboard_create = true;
	block_create = true;
	ice_create = true;
	hole_create = true;
	kaidan_create = true;
	ground_create = true;

	//ステージ生成
	{
		//地面の生成【穴・氷・床・破壊床】
			//穴
		if (hole_create == true)
		{
			map.Hole = NewGO<G_Hole>(0, "hole");
			hole_create = false;
		}
		//氷
		if (ice_create == true)
		{
			map.Ice = NewGO<G_IceFloor>(0, "ice");
			ice_create = false;
		}
		//床
		if (ground_create == true)
		{
			map.Ground = NewGO<G_Ground>(0, "ground");
			ground_create = false;
		}
		//破壊床
		if (break_create == true)
		{
			map.Breakfloar = NewGO<G_BreakFloar>(0, "break");
			break_create = false;
		}

		//床上の設置物【ゴール用の階段・感圧板・障壁ブロック・ゴール解放の扉】
			//ゴール用の階段
		if (kaidan_create == true)
		{
			map.Kaidan = NewGO<G_Kaidan>(0, "kaidan");
			kaidan_create = false;
		}
		//感圧板
		if (weightboard_create == true)
		{
			map.Weightboard = NewGO<G_WeightBoard>(0, "weightboard");
			weightboard_create = false;
			map.Weightboard->link = true;
			map.Weightboard->block_link = true;
		}
		//障壁ブロック
		if (block_create == true)
		{
			map.Block = NewGO<G_Block>(0, "block");
			block_create = false;
		}
		//ゴール解放の扉
		if (wall_create == true)
		{
			map.Wall = NewGO<G_Wall>(0, "wall");
			wall_create = false;
		}
	}


	//氷床
	{
		
		{
			//一行目
			mapdata[0][4].ice_on = true;
			mapdata[0][6].ice_on = true;
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
		mapdata[0][5].block_on = true;
		mapdata[0][7].block_on = true;
		mapdata[0][8].block_on = true;

		//二行目
		mapdata[1][4].block_on = true;
		mapdata[1][6].block_on = true;
		mapdata[1][8].block_on = true;

		//三行目
		mapdata[2][5].block_on = true;
		mapdata[2][6].block_on = true;
		map.Block->Block_only[2][6] = true;
		mapdata[2][8].block_on = true;

		//四行目
		mapdata[3][5].block_on = true;
		mapdata[3][6].block_on = true;
		map.Block->Block_only[3][6] = true;
		mapdata[3][9].block_on = true;

		//五行目
		mapdata[4][6].block_on = true;
		mapdata[4][7].block_on = true;

		//六行目
		mapdata[5][5].block_on = true;
		mapdata[5][6].block_on = true;
		mapdata[5][7].block_on = true;
		mapdata[5][8].block_on = true;

		//七行目

		mapdata[6][6].block_on = true;
		mapdata[6][7].block_on = true;
		map.Block->Block_only[6][7] = true;
		mapdata[6][8].block_on = true;

		//八行目
		mapdata[7][5].block_on = true;
		mapdata[7][6].block_on = true;
		mapdata[7][9].block_on = true;

		//九行目
		mapdata[8][5].block_on = true;
		mapdata[8][7].block_on = true;
		mapdata[8][8].block_on = true;
		mapdata[8][9].block_on = true;
		map.Block->Block_only[8][9] = true;

		//十行目
		mapdata[9][4].block_on = true;
		mapdata[9][6].block_on = true;
		mapdata[9][7].block_on = true;
		mapdata[9][9].block_on = true;

	}

	//落とし穴
	{
		
		//一行目
		mapdata[0][5].hole_on = true;
		mapdata[0][7].hole_on = true;
		mapdata[0][8].hole_on = true;

		//二行目
		mapdata[1][4].hole_on = true;
		mapdata[1][8].hole_on = true;

		//三行目
		mapdata[2][6].hole_on = true;

		//四行目
		//mapdata[3][5].hole_on = true;
		mapdata[3][6].hole_on = true;
		mapdata[3][9].hole_on = true;

		//五行目
		mapdata[4][6].hole_on = true;
		mapdata[4][7].hole_on = true;

		//六行目
		mapdata[5][5].hole_on = true;
		mapdata[5][6].hole_on = true;

		//七行目
		mapdata[6][7].hole_on = true;

		//八行目
		mapdata[7][5].hole_on = true;
		mapdata[7][6].hole_on = true;
		mapdata[7][9].hole_on = true;

		//九行目
		mapdata[8][5].hole_on = true;
		mapdata[8][8].hole_on = true;
		mapdata[8][9].hole_on = true;

		//十行目
		mapdata[9][6].hole_on = true;

	}

	//感圧板
	{
		

		mapdata[0][9].weightboard_map = true;
		map.Weightboard->link_number[0][9][1] = 99;
		map.Weightboard->link_count[0][9] = 1;

		mapdata[1][2].weightboard_map = true;
		map.Weightboard->link_number[1][2][1] = 47;
		map.Weightboard->link_number[1][2][2] = 56;
		map.Weightboard->link_number[1][2][3] = 55;
		map.Weightboard->link_count[1][2] = 3;

		mapdata[3][0].weightboard_map = true;
		map.Weightboard->link_number[3][0][1] = 16;
		map.Weightboard->link_number[3][0][2] = 7;
		map.Weightboard->link_number[3][0][3] = 58;
		map.Weightboard->link_count[3][0] = 3;

		mapdata[3][2].weightboard_map = true;
		map.Weightboard->link_number[3][2][1] = 8;
		map.Weightboard->link_number[3][2][2] = 46;
		map.Weightboard->link_number[3][2][3] = 88;
		map.Weightboard->link_count[3][2] = 3;

		mapdata[5][0].weightboard_map = true;
		map.Weightboard->link_number[5][0][1] = 28;
		map.Weightboard->link_number[5][0][2] = 97;
		map.Weightboard->link_number[5][0][3] = 35;
		map.Weightboard->link_count[5][0] = 3;

		mapdata[5][2].weightboard_map = true;
		map.Weightboard->link_number[5][2][1] = 68;
		map.Weightboard->link_number[5][2][2] = 57;
		map.Weightboard->link_number[5][2][3] = 94;
		map.Weightboard->link_count[5][2] = 3;

		mapdata[7][0].weightboard_map = true;
		map.Weightboard->link_number[7][0][1] = 14;
		map.Weightboard->link_number[7][0][2] = 18;
		map.Weightboard->link_number[7][0][3] = 79;
		map.Weightboard->link_count[7][0] = 3;

		mapdata[7][2].weightboard_map = true;
		map.Weightboard->link_number[7][2][1] = 5;
		map.Weightboard->link_number[7][2][2] = 75;
		map.Weightboard->link_number[7][2][3] = 96;
		map.Weightboard->link_count[7][2] = 3;

		mapdata[9][0].weightboard_map = true;
		map.Weightboard->link_number[9][0][1] = 87;
		map.Weightboard->link_number[9][0][2] = 25;
		map.Weightboard->link_number[9][0][3] = 66;
		map.Weightboard->link_count[9][0] = 3;

		mapdata[9][2].weightboard_map = true;
		map.Weightboard->link_number[9][2][1] = 39;
		map.Weightboard->link_number[9][2][2] = 85;
		map.Weightboard->link_number[9][2][3] = 76;
		map.Weightboard->link_count[9][2] = 3;
	}

	//階段
	{
		mapdata[9][9].kaidan_on = true;
	}

	//地面
	{
		
	}

//マップの取得


//座標の設定
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Ground_P[L][R].x = (L * 192.0f) + -865.0f;
			Ground_P[L][R].y = 0.0f;
			Ground_P[L][R].z = (R * 192.0f) + -865.0f;
		}
	}


//設定
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{

		//地面の設定【穴・氷・床・破壊床】
		//穴
		if (mapdata[L][R].hole_on == true)
		{
			mapdata[L][R].grounddata = HOLE;
		}else {
		//氷
		if (mapdata[L][R].ice_on == true)
		{
			map.Ice->ice_on[L][R] = true;
			map.Ice->position[L][R] = Ground_P[L][R];
			map.Ice->position[L][R].y -= 50.0f;
			mapdata[L][R].grounddata = ICE;
		}else {
		//破壊床
		if (mapdata[L][R].breakfloar_on == true)
		{
			map.Breakfloar->break_on[L][R] = true;
			map.Breakfloar->position[L][R] = Ground_P[L][R];
			mapdata[L][R].grounddata = BREAKFLOOR;
		}else {
		//床
			map.Ground->Ground_on[L][R] = true;
			map.Ground->Ground_P[L][R] = Ground_P[L][R];
			map.Ground->Ground_P[L][R].y -= 50.0f;
			mapdata[L][R].grounddata = GROUND;
		}
		}
		}

		//床上の設置物【ゴール用の階段・感圧板・障壁ブロック・ゴール解放の扉】
		//ゴール用の階段
		if (mapdata[L][R].kaidan_on == true)
		{
			map.Kaidan->Kaidan_P = Ground_P[L][R];
			map.Kaidan->Kaidan_P.y = 20.0f;
			mapdata[L][R].grounddata = KAIDAN;
		}else {
		//感圧板
		if (mapdata[L][R].weightboard_map == true)
		{
			map.Weightboard->WeightBoard_on[L][R] = true;
			map.Weightboard->position[L][R] = Ground_P[L][R];
			map.Weightboard->position[L][R].y = -20.0f;
			mapdata[L][R].grounddata = WEIGHTBOARD;
		}else {
		//障壁ブロック
		if (mapdata[L][R].block_on == true)
		{
			map.Block->Block_on[L][R] = true;
			map.Block->Block_P[L][R] = Ground_P[L][R];
			map.Block->Block_P[L][R].y = 150.0f;
			mapdata[L][R].grounddata = BLOCK;
		}else {
		//ゴール解放の扉
			/*map.Ground->Ground_on[L][R] = true;
			map.Ground->Ground_P[L][R] = Ground_P[L][R];*/
			//mapdata[L][R].grounddata = WALL;
		}
		}
		}
		
		
		////感圧板
		//	if (weightboard_create == true)
		//	{
		//		map.weightboard = NewGO<G_WeightBoard>(0, "weightboard");
		//		weightboard_create = false;
		//	}else {
		//	if (mapdata[L][R].kaidan_on == true)
		//	{
		//		mapdata[L][R].kaidan = NewGO<G_Kaidan>(0, "kaidan");
		//		mapdata[L][R].kaidan->Kaidan_P = Ground_P[L][R];
		//		mapdata[L][R].kaidan->Kaidan_P.y = 20.0f;
		//		Ground[L][R].Init("Assets/test/ground.tkm", stageLight);
		//		Ground[L][R].SetPosition(Ground_P[L][R]);
		//		Ground[L][R].Update();
		//	}else {
		//		Ground[L][R].Init("Assets/test/ground.tkm", stageLight);
		//		g_physicsStaticObjectpos[L][R].CreateFromModel(Ground[L][R].GetModel(), Ground[L][R].GetModel().GetWorldMatrix());
		//		g_physicsStaticObjectpos[L][R].SetPosition(Ground_P[L][R]);
		//		Ground[L][R].SetPosition(Ground_P[L][R]);
		//		Ground[L][R].Update();
		//	}
		//	}
		//	}
			////氷の床
			//if (mapdata[L][R].ice_on == true)
			//{

			//	mapdata[L][R].ice = NewGO<G_IceFloor>(0);
			//	mapdata[L][R].ice->position = Ground_P[L][R];
			//	mapdata[L][R].ice->position.y = -20.0f;

			//}
			//else {
			//	//落とし穴
			//	if (mapdata[L][R].hole_on == true)
			//	{

			//	}
			//	else {
			//感圧板
			/*if (mapdata[L][R].weightboard_map == true)
			{
				map.weightboard->position[L][R] = Ground_P[L][R];
				map.weightboard->position[L][R].y = -20.0f;
				map.weightboard->WeightBoard_on[L][R] = true;
				Ground[L][R].Init("Assets/test/ground.tkm", stageLight);
				Ground[L][R].SetPosition(Ground_P[L][R]);
				Ground[L][R].Update();
			}*/
			//		else {
			//			if (mapdata[L][R].kaidan_on == true)
			//			{
			//				mapdata[L][R].kaidan = NewGO<G_Kaidan>(0, "kaidan");
			//				mapdata[L][R].kaidan->Kaidan_P = Ground_P[L][R];
			//				mapdata[L][R].kaidan->Kaidan_P.y = 20.0f;
			//				Ground[L][R].Init("Assets/test/ground.tkm", stageLight);
			//				Ground[L][R].SetPosition(Ground_P[L][R]);
			//				Ground[L][R].Update();
			//			}
			//			else {
			//				Ground[L][R].Init("Assets/test/ground.tkm", stageLight);
			//				g_physicsStaticObjectpos[L][R].CreateFromModel(Ground[L][R].GetModel(), Ground[L][R].GetModel().GetWorldMatrix());
			//				g_physicsStaticObjectpos[L][R].SetPosition(Ground_P[L][R]);
			//				Ground[L][R].SetPosition(Ground_P[L][R]);
			//				Ground[L][R].Update();
			//			}
			//		}
			//	}
			//}

	//		if (mapdata[L][R].block_on == true)
	//		{
	//			mapdata[L][R].block = NewGO<G_Block>(0, "block");
	//			mapdata[L][R].block->Block_P[0] = Ground_P[L][R];
	//			mapdata[L][R].block->Block_P[0].y = 200.0f;
	//			mapdata[L][R].block->block = true;

	//		}
	//		else

	//		//壁
	//		if (mapdata[L][R].weightboard_map == true && mapdata[L][R].weightboard_block_link == true)
	//		{
	//			mapdata[L][R].block = NewGO<G_Block>(0, "block");

	//			for (int a = 0; a < 10; a++)
	//			{
	//				for (int b = 0; b < 1; b++)
	//				{
	//					if (mapdata[L][R].weightboard_block_map[a][b] == 0 && mapdata[L][R].weightboard_block_map[a][b + 1] == 0)
	//					{
	//						continue;
	//					}
	//					mapdata[L][R].block->Block_P[a] = Ground_P[mapdata[L][R].weightboard_block_map[a][b]][mapdata[L][R].weightboard_block_map[a][b + 1]];
	//					mapdata[L][R].block->Block_P[a].y = 200.0f;
	//					mapdata[L][R].block->blockcount += 1;
	//				}
	//			}
	}
	}
}

Stage::~Stage()
{
	DeleteGO(map.Ice);
	DeleteGO(map.Ground);
	DeleteGO(map.Hole);
	DeleteGO(map.Block);
	DeleteGO(map.Kaidan);
	DeleteGO(map.Breakfloar);
	DeleteGO(map.Weightboard);
	DeleteGO(map.Wall);
}

void Stage::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
	Kabe.Draw(rc);
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Ground[L][R].Draw(rc);
		}
	}
}