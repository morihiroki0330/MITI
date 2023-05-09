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

#include "Player.h"
#include "Game.h"

Stage::Stage()
{
	//壁画
	{
		Kabe.Init("Assets/test/hekiga.tkm", stageLight);
		Kabe_P = { 0.0f,82.0f,0.0f };
		k_physicsStaticObjectpos.CreateFromModel(Kabe.GetModel(), Kabe.GetModel().GetWorldMatrix());
		Kabe.Update();
		Kabe.SetPosition(Kabe_P);
	}

	//座標の設定
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Ground_P[L][R].x = (L * 192.0f) + -865.0f;
			Ground_P[L][R].y = 0.0f;
			Ground_P[L][R].z = (R * 192.0f) + -865.0f;

			Reset_P.x = -2000.0f;
			Reset_P.y = -2000.0f;
			Reset_P.z = -2000.0f;
		}
	}

	//マップに設定を付与したか
	//tureはしている。falseはしていない。
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Map_SetGround[L][R] = false;
			Map_SetSky[L][R] = false;
		}
	}

	//レベルごとのマップに設定
	//trueはした。falseはしていない。
	Level_Set = false;

	Map_Set = false;

	//ステージ生成
	{
		//穴
		hole_create = true;
		if (hole_create == true)
		{
			map.Hole = NewGO<G_Hole>(0, "hole");
			hole_create = false;
		}

		//氷
		ice_create = true;
		if (ice_create == true)
		{
			map.Ice = NewGO<G_IceFloor>(0, "ice");
			ice_create = false;
		}

		//床
		ground_create = true;
		if (ground_create == true)
		{
			map.Ground = NewGO<G_Ground>(0, "ground");
			ground_create = false;
		}

		//破壊床
		break_create = true;
		if (break_create == true)
		{
			map.Breakfloar = NewGO<G_BreakFloar>(0, "break");
			break_create = false;
		}

		//ゴール用の階段
		kaidan_create = true;
		if (kaidan_create == true)
		{
			map.Kaidan = NewGO<G_Kaidan>(0, "kaidan");
			kaidan_create = false;
		}

		//感圧板
		weightboard_create = true;
		if (weightboard_create == true)
		{
			map.Weightboard = NewGO<G_WeightBoard>(0, "weightboard");
			weightboard_create = false;
			map.Weightboard->link = true;
			map.Weightboard->block_link = true;
		}

		//障壁ブロック
		block_create = true;
		if (block_create == true)
		{
			map.Block = NewGO<G_Block>(0, "block");
			block_create = false;
		}

		//ゴール解放の扉
		//wall_create = true;
		if (wall_create == true)
		{
			map.Wall = NewGO<G_Wall>(0, "wall");
			wall_create = false;
		}
	}

	//レベル1
	{
		//氷床
		{

			for (int L = 1; L < 9; L++)
			{
				for (int R = 2; R < 10; R++)
				{
					if ((L == 3 && R == 5) || (L == 4 && R == 3) || (L == 5 && R == 7) || (L == 6 && R == 7) || (L == 6 && R == 9))
					{
						continue;
					}
					Level[1][L][R].ice_on = true;
				}
			}

		}

		//壁
		{	
			Level[1][1][5].block_on = true;
			Level[1][1][5].blockonly_on = true;

			Level[1][1][9].block_on = true;
			Level[1][1][9].blockonly_on = true;

			Level[1][3][3].block_on = true;
			Level[1][3][3].blockonly_on = true;

			Level[1][7][7].block_on = true;
			Level[1][7][7].blockonly_on = true;
			
			Level[1][7][9].block_on = true;
			Level[1][7][9].blockonly_on = true;

			Level[1][8][2].block_on = true;
			Level[1][8][2].blockonly_on = true;
			
			Level[1][8][7].block_on = true;
			Level[1][8][7].blockonly_on = true;

			Level[1][8][9].block_on = true;
			Level[1][8][9].blockonly_on = true;
			

			//零行目
			Level[1][0][6].block_on = true;

			//一行目
			Level[1][1][2].block_on = true;
			Level[1][1][8].block_on = true;

			//二行目
			Level[1][2][2].block_on = true;
			Level[1][2][7].block_on = true;

			//三行目
			Level[1][3][4].block_on = true;

			//四行目
			Level[1][4][7].block_on = true;

			//五行目
			Level[1][5][3].block_on = true;
			Level[1][5][8].block_on = true;

			//六行目
			Level[1][6][2].block_on = true;
			Level[1][6][4].block_on = true;

			//七行目
			Level[1][7][4].block_on = true;
			Level[1][7][6].block_on = true;

			//九行目
			Level[1][9][3].block_on = true;
		}

		//落とし穴
		{
			for (int L = 0; L < 1; L++)
			{
				for (int R = 0; R < 10; R++)
				{
					Level[1][L][R].hole_on = true;
				}
			}

			for (int L = 9; L < 10; L++)
			{
				for (int R = 0; R < 10; R++)
				{
					if (R == 8 || R == 6)
					{
						continue;
					}
					Level[1][L][R].hole_on = true;
				}
			}

			Level[1][3][5].hole_on = true;
			Level[1][4][3].hole_on = true;
			Level[1][5][7].hole_on = true;
			Level[1][6][9].hole_on = true;
		}

		//感圧板
		{
			for (int L = 1; L < 9; L++)
			{

				if (L % 2 == 0)
				{
					Level[1][L][0].weightboard_map = true;
				}
				else
				{
					if (L % 2 == 1)
					{
						Level[1][L][1].weightboard_map = true;
					}
				}

			}

			Level[1][6][7].weightboard_map = true;
			Level[1][9][6].weightboard_map = true;

			Level[1][1][1].weightboard_linknumber[1] = 22;
			Level[1][1][1].weightboard_linknumber[2] = 34;
			Level[1][1][1].weightboard_count = 2;

			Level[1][2][0].weightboard_linknumber[1] = 62;
			Level[1][2][0].weightboard_count = 1;

			Level[1][3][1].weightboard_linknumber[1] = 27;
			Level[1][3][1].weightboard_linknumber[2] = 58;
			Level[1][3][1].weightboard_count = 2;

			Level[1][4][0].weightboard_linknumber[1] = 74;
			Level[1][4][0].weightboard_count = 1;

			Level[1][5][1].weightboard_linknumber[1] = 47;
			Level[1][5][1].weightboard_count = 1;

			Level[1][6][0].weightboard_linknumber[1] = 53;
			Level[1][6][0].weightboard_count = 1;

			Level[1][7][1].weightboard_linknumber[1] = 76;
			Level[1][7][1].weightboard_count = 1;

			Level[1][8][0].weightboard_linknumber[1] = 64;
			Level[1][8][0].weightboard_count = 1;

			Level[1][6][7].weightboard_linknumber[1] = 93;
			Level[1][6][7].weightboard_count = 1;

			Level[1][9][6].weightboard_linknumber[1] = 6;
			Level[1][9][6].weightboard_count = 1;

		}

		//階段
		{
			Level[1][9][8].kaidan_on = true;
		}

		//地面
		{

		}

		//扉
		{

		}
	}

	//レベル2
	{
		//氷床
		{
			Level[2][0][1].ice_on = true;
			Level[2][0][2].ice_on = true;
			Level[2][0][3].ice_on = true;
			Level[2][0][4].ice_on = true;
			Level[2][0][7].ice_on = true;
			Level[2][0][8].ice_on = true;
			Level[2][0][9].ice_on = true;

			Level[2][1][0].ice_on = true;
			Level[2][1][4].ice_on = true;
			Level[2][1][5].ice_on = true;
			Level[2][1][7].ice_on = true;
			Level[2][1][8].ice_on = true;
			Level[2][1][9].ice_on = true;

			Level[2][2][1].ice_on = true;
			Level[2][2][2].ice_on = true;
			Level[2][2][3].ice_on = true;
			Level[2][2][4].ice_on = true;
			Level[2][2][5].ice_on = true;
			Level[2][2][6].ice_on = true;
			Level[2][2][7].ice_on = true;
			Level[2][2][8].ice_on = true;

			Level[2][3][6].ice_on = true;
			Level[2][3][7].ice_on = true;
			Level[2][3][8].ice_on = true;
			Level[2][3][9].ice_on = true;

			Level[2][4][6].ice_on = true;
			Level[2][4][7].ice_on = true;
			Level[2][4][8].ice_on = true;
			Level[2][4][9].ice_on = true;

			Level[2][5][5].ice_on = true;
			Level[2][5][6].ice_on = true;
			Level[2][5][7].ice_on = true;
			Level[2][5][9].ice_on = true;

			Level[2][6][5].ice_on = true;
			Level[2][6][6].ice_on = true;
			Level[2][6][7].ice_on = true;
			Level[2][6][8].ice_on = true;
			Level[2][6][9].ice_on = true;

			Level[2][7][5].ice_on = true;
			Level[2][7][7].ice_on = true;
			Level[2][7][8].ice_on = true;
			Level[2][7][9].ice_on = true;

			Level[2][8][6].ice_on = true;
			Level[2][8][7].ice_on = true;
			Level[2][8][8].ice_on = true;

			Level[2][9][5].ice_on = true;
			Level[2][9][6].ice_on = true;
			Level[2][9][8].ice_on = true;
			
		}

		//壁
		{
			Level[2][1][0].block_on = true;
			Level[2][1][0].blockonly_on = true;

			Level[2][2][6].block_on = true;
			Level[2][2][6].blockonly_on = true;

			Level[2][3][9].block_on = true;
			Level[2][3][9].blockonly_on = true;

			Level[2][4][7].block_on = true;
			Level[2][4][7].blockonly_on = true;


			Level[2][0][5].block_on = true;

			Level[2][1][1].block_on = true;
			Level[2][1][2].block_on = true;
			Level[2][1][3].block_on = true;
			Level[2][1][6].block_on = true;

			Level[2][2][9].block_on = true;

			Level[2][3][1].block_on = true;
			Level[2][3][4].block_on = true;
			Level[2][3][5].block_on = true;

			Level[2][4][5].block_on = true;

			Level[2][5][8].block_on = true;

			Level[2][7][6].block_on = true;

			Level[2][8][9].block_on = true;

			Level[2][9][7].block_on = true;
		}

		//落とし穴
		{
			Level[2][0][5].hole_on = true;

			Level[2][1][1].hole_on = true;
			Level[2][1][2].hole_on = true;
			Level[2][1][3].hole_on = true;
			Level[2][1][6].hole_on = true;

			Level[2][2][9].hole_on = true;


			Level[2][3][1].hole_on = true;
			Level[2][3][4].hole_on = true;
			Level[2][3][5].hole_on = true;

			Level[2][4][5].hole_on = true;

			Level[2][5][8].hole_on = true;

			Level[2][7][6].hole_on = true;

			Level[2][8][5].hole_on = true;
			Level[2][8][9].hole_on = true;

			Level[2][9][7].hole_on = true;
		}

		//感圧板
		{
			Level[2][0][0].weightboard_map = true;
			Level[2][0][6].weightboard_map = true;
			Level[2][7][0].weightboard_map = true;
			Level[2][7][2].weightboard_map = true;
			Level[2][9][0].weightboard_map = true;
			Level[2][9][2].weightboard_map = true;

			Level[2][0][0].weightboard_linknumber[1] = 16;
			Level[2][0][0].weightboard_linknumber[2] = 97;
			Level[2][0][0].weightboard_count = 2;

			Level[2][0][6].weightboard_linknumber[1] = 76;
			Level[2][0][6].weightboard_linknumber[2] = 58;
			Level[2][0][6].weightboard_count = 2;

			Level[2][7][0].weightboard_linknumber[1] = 5;
			Level[2][7][0].weightboard_count = 1;

			Level[2][7][2].weightboard_linknumber[1] = 13;
			Level[2][7][2].weightboard_linknumber[2] = 35;
			Level[2][7][2].weightboard_count = 2;

			Level[2][9][0].weightboard_linknumber[1] = 12;
			Level[2][9][0].weightboard_linknumber[2] = 45;
			Level[2][9][0].weightboard_linknumber[3] = 89;
			Level[2][9][0].weightboard_count = 3;

			Level[2][9][2].weightboard_linknumber[1] = 34;
			Level[2][9][2].weightboard_linknumber[2] = 29;
			Level[2][9][2].weightboard_count = 2;
			/*map.Weightboard->link_number[1][1][1] = 12;
			map.Weightboard->link_number[1][1][2] = 32;
			map.Weightboard->link_count[1][1] = 2;

			map.Weightboard->link_number[2][0][1] = 43;
			map.Weightboard->link_number[2][0][2] = 58;
			map.Weightboard->link_count[2][0] = 2;

			map.Weightboard->link_number[3][1][1] = 18;
			map.Weightboard->link_number[3][1][2] = 27;
			map.Weightboard->link_count[3][1] = 2;

			map.Weightboard->link_number[4][0][1] = 25;
			map.Weightboard->link_number[4][0][2] = 54;
			map.Weightboard->link_count[4][0] = 2;

			map.Weightboard->link_number[5][1][1] = 72;
			map.Weightboard->link_number[5][1][2] = 77;
			map.Weightboard->link_count[5][1] = 2;

			map.Weightboard->link_number[6][0][1] = 39;
			map.Weightboard->link_number[6][0][2] = 56;
			map.Weightboard->link_count[6][0] = 2;

			map.Weightboard->link_number[7][1][1] = 75;
			map.Weightboard->link_number[7][1][2] = 83;
			map.Weightboard->link_count[7][1] = 2;

			map.Weightboard->link_number[8][0][1] = 29;
			map.Weightboard->link_number[8][0][2] = 47;
			map.Weightboard->link_count[8][0] = 2;*/
		}

		//階段
		{
			Level[2][9][9].kaidan_on = true;
		}

		//地面
		{

		}

		//扉
		{

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

void Stage::Update()
{
	//プレイヤークラスの検索
	if (game == NULL)
	{
		game = FindGO<Game>("game");
	}

	//レベルごとのマップ設定
	if (Level_Set == false)
	{
		for (int L = 0; L < 10; L++)
		{
			for (int R = 0; R < 10; R++)
			{
				//氷床
				mapdata[L][R].ice_on = Level[game->Level][L][R].ice_on;

				//壁
				mapdata[L][R].block_on = Level[game->Level][L][R].block_on;
				mapdata[L][R].blockonly_on = Level[game->Level][L][R].blockonly_on;

				//落とし穴
				mapdata[L][R].hole_on = Level[game->Level][L][R].hole_on;

				//感圧板
				mapdata[L][R].weightboard_map = Level[game->Level][L][R].weightboard_map;

				//階段
				mapdata[L][R].kaidan_on = Level[game->Level][L][R].kaidan_on;
			}
		}


		Level_Set = true;
	}

	//マップの設定
	if (Map_Set == false)
	{
		for (int L = 0; L < 10; L++)
		{
			for (int R = 0; R < 10; R++)
			{

				//地面の設定【穴・氷・床・破壊床】
				//穴
				if (mapdata[L][R].hole_on == true && Map_SetGround[L][R] == false)
				{
					mapdata[L][R].grounddata = HOLE;
					mapdata[L][R].hole_on = false;
					Map_SetGround[L][R] = true;
				}else {
				//氷
				if (mapdata[L][R].ice_on == true && Map_SetGround[L][R] == false)
				{
					map.Ice->ice_on[L][R] = true;
					mapdata[L][R].ice_on = false;
					map.Ice->position[L][R] = Ground_P[L][R];
					map.Ice->position[L][R].y -= 50.0f;
					mapdata[L][R].grounddata = ICE;
					Map_SetGround[L][R] = true;
				}else {
				//破壊床
				if (mapdata[L][R].breakfloar_on == true && Map_SetGround[L][R] == false)
				{
					map.Breakfloar->break_on[L][R] = true;
					mapdata[L][R].breakfloar_on = false;
					map.Breakfloar->position[L][R] = Ground_P[L][R];
					mapdata[L][R].grounddata = BREAKFLOOR;
					Map_SetGround[L][R] = true;
				}else {
				//床
				if (Map_SetGround[L][R] == false)
					map.Ground->Ground_on[L][R] = true;
					map.Ground->Ground_P[L][R] = Ground_P[L][R];
					map.Ground->Ground_P[L][R].y -= 50.0f;
					mapdata[L][R].grounddata = GROUND;
					Map_SetGround[L][R] = true;
				}
				}
				}

				//床上の設置物【ゴール用の階段・感圧板・障壁ブロック・ゴール解放の扉】
				//ゴール用の階段
				if (mapdata[L][R].kaidan_on == true && Map_SetSky[L][R] == false)
				{
					mapdata[L][R].kaidan_on = false;
					map.Kaidan->Kaidan_P = Ground_P[L][R];
					map.Kaidan->Kaidan_P.y = 20.0f;
					mapdata[L][R].skydata = KAIDAN;
					Map_SetSky[L][R] = true;
				}else {
				//感圧板
				if (mapdata[L][R].weightboard_map == true && Map_SetSky[L][R] == false)
				{
					if (Level[game->Level][L][R].weightboard_count > 0)
					{
						for (int W = 1; W < Level[game->Level][L][R].weightboard_count + 1; W++)
						{
							map.Weightboard->link_number[L][R][W] = Level[game->Level][L][R].weightboard_linknumber[W];
						}
						map.Weightboard->link_count[L][R] = Level[game->Level][L][R].weightboard_count;
					}

					mapdata[L][R].weightboard_map = false;
					map.Weightboard->WeightBoard_on[L][R] = true;
					map.Weightboard->position[L][R] = Ground_P[L][R];
					map.Weightboard->position[L][R].y = -20.0f;
					mapdata[L][R].skydata = WEIGHTBOARD;
					Map_SetSky[L][R] = true;
				}else {
				//障壁ブロック
				if (mapdata[L][R].block_on == true && Map_SetSky[L][R] == false)
				{
					if (mapdata[L][R].blockonly_on == true)
					{
						map.Block->Block_only[L][R] = true;
					}
					mapdata[L][R].block_on = false;
					map.Block->Block_on[L][R] = true;
					map.Block->Block_P[L][R] = Ground_P[L][R];
					map.Block->Block_P[L][R].y = 150.0f;
					mapdata[L][R].skydata = BLOCK;
					Map_SetSky[L][R] = true;
				}
		}
		}
		}
		}
		Map_Set = true;
	}


}

void Stage::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
	Kabe.Draw(rc);
	
}