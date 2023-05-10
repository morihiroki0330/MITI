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

	//レベル0
	{
		//氷床
		{
			Level[0][0][3].ice_on = true;
			Level[0][0][4].ice_on = true;
			Level[0][0][5].ice_on = true;

			Level[0][1][3].ice_on = true;
			Level[0][1][4].ice_on = true;
			Level[0][1][5].ice_on = true;

			Level[0][2][3].ice_on = true;
			Level[0][2][4].ice_on = true;
			Level[0][2][5].ice_on = true;

			Level[0][3][7].ice_on = true;
			Level[0][3][8].ice_on = true;
			Level[0][3][9].ice_on = true;

			Level[0][6][7].ice_on = true;
			Level[0][6][8].ice_on = true;
			Level[0][6][9].ice_on = true;

			Level[0][7][3].ice_on = true;
			Level[0][7][4].ice_on = true;

			Level[0][8][4].ice_on = true;
			Level[0][8][5].ice_on = true;

			Level[0][9][3].ice_on = true;
			Level[0][9][4].ice_on = true;
		}

		//ブロック
		{
			//四行目
			Level[0][4][7].block_on = true;
			Level[0][4][8].block_on = true;
			Level[0][4][9].block_on = true;

			//五行目
			Level[0][5][7].block_on = true;
			Level[0][5][8].block_on = true;
			Level[0][5][9].block_on = true;

			Level[0][7][5].block_on = true;

			Level[0][8][3].block_on = true;

			Level[0][9][5].block_on = true;
		}

		//落とし穴
		{
			Level[0][3][0].hole_on = true;
			Level[0][3][1].hole_on = true;
			Level[0][3][2].hole_on = true;
			Level[0][3][3].hole_on = true;
			Level[0][3][4].hole_on = true;
			Level[0][3][5].hole_on = true;
			Level[0][3][6].hole_on = true;

			Level[0][4][0].hole_on = true;
			Level[0][4][1].hole_on = true;
			Level[0][4][2].hole_on = true;
			Level[0][4][3].hole_on = true;
			Level[0][4][4].hole_on = true;
			Level[0][4][5].hole_on = true;
			Level[0][4][6].hole_on = true;
			Level[0][4][7].hole_on = true;
			Level[0][4][8].hole_on = true;
			Level[0][4][9].hole_on = true;

			Level[0][5][0].hole_on = true;
			Level[0][5][1].hole_on = true;
			Level[0][5][2].hole_on = true;
			Level[0][5][3].hole_on = true;
			Level[0][5][4].hole_on = true;
			Level[0][5][5].hole_on = true;
			Level[0][5][6].hole_on = true;
			Level[0][5][7].hole_on = true;
			Level[0][5][8].hole_on = true;
			Level[0][5][9].hole_on = true;

			Level[0][6][0].hole_on = true;
			Level[0][6][1].hole_on = true;
			Level[0][6][2].hole_on = true;
			Level[0][6][3].hole_on = true;
			Level[0][6][4].hole_on = true;
			Level[0][6][5].hole_on = true;
			Level[0][6][6].hole_on = true;

			Level[0][7][5].hole_on = true;

			Level[0][8][3].hole_on = true;

			Level[0][9][5].hole_on = true;
		}

		//感圧板
		{
			
			Level[0][2][8].weightboard_map = true;
			Level[0][8][6].weightboard_map = true;

			Level[0][2][8].weightboard_linknumber[1] = 47;
			Level[0][2][8].weightboard_linkobject[1] = I_BLOCK;
			Level[0][2][8].weightboard_linknumber[2] = 48;
			Level[0][2][8].weightboard_linkobject[2] = I_BLOCK;
			Level[0][2][8].weightboard_linknumber[3] = 49;
			Level[0][2][8].weightboard_linkobject[3] = I_BLOCK;
			Level[0][2][8].weightboard_linknumber[4] = 57;
			Level[0][2][8].weightboard_linkobject[4] = I_BLOCK;
			Level[0][2][8].weightboard_linknumber[5] = 58;
			Level[0][2][8].weightboard_linkobject[5] = I_BLOCK;
			Level[0][2][8].weightboard_linknumber[6] = 59;
			Level[0][2][8].weightboard_linkobject[6] = I_BLOCK;
			Level[0][2][1].weightboard_count = 6;

			Level[0][8][6].weightboard_linknumber[1] = 75;
			Level[0][8][6].weightboard_linkobject[1] = L_BLOCK;
			Level[0][8][6].weightboard_linknumber[2] = 83;
			Level[0][8][6].weightboard_linkobject[2] = L_BLOCK;
			Level[0][8][6].weightboard_linknumber[3] = 95;
			Level[0][8][6].weightboard_linkobject[3] = L_BLOCK;
			Level[0][8][6].weightboard_count = 6;
		}

		//階段
		{
			Level[0][8][0].kaidan_on = true;
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
			Level[1][1][1].weightboard_linkobject[1] = L_BLOCK;
			Level[1][1][1].weightboard_linknumber[2] = 34;
			Level[1][1][1].weightboard_linkobject[2] = L_BLOCK;
			Level[1][1][1].weightboard_count = 2;

			Level[1][2][0].weightboard_linknumber[1] = 62;
			Level[1][2][0].weightboard_linkobject[1] = L_BLOCK;
			Level[1][2][0].weightboard_count = 1;

			Level[1][3][1].weightboard_linknumber[1] = 27;
			Level[1][3][1].weightboard_linkobject[1] = L_BLOCK;
			Level[1][3][1].weightboard_linknumber[2] = 58;
			Level[1][3][1].weightboard_linkobject[2] = L_BLOCK;
			Level[1][3][1].weightboard_count = 2;

			Level[1][4][0].weightboard_linknumber[1] = 74;
			Level[1][4][0].weightboard_linkobject[1] = L_BLOCK;
			Level[1][4][0].weightboard_count = 1;

			Level[1][5][1].weightboard_linknumber[1] = 47;
			Level[1][5][1].weightboard_linkobject[1] = L_BLOCK;
			Level[1][5][1].weightboard_count = 1;

			Level[1][6][0].weightboard_linknumber[1] = 53;
			Level[1][6][0].weightboard_linkobject[1] = L_BLOCK;
			Level[1][6][0].weightboard_count = 1;

			Level[1][7][1].weightboard_linknumber[1] = 76;
			Level[1][7][1].weightboard_linkobject[1] = L_BLOCK;
			Level[1][7][1].weightboard_count = 1;

			Level[1][8][0].weightboard_linknumber[1] = 64;
			Level[1][8][0].weightboard_linkobject[1] = L_BLOCK;
			Level[1][8][0].weightboard_count = 1;

			Level[1][6][7].weightboard_linknumber[1] = 93;
			Level[1][6][7].weightboard_linkobject[1] = L_BLOCK;
			Level[1][6][7].weightboard_count = 1;

			Level[1][9][6].weightboard_linknumber[1] = 6;
			Level[1][9][6].weightboard_linkobject[1] = L_BLOCK;
			Level[1][9][6].weightboard_count = 1;

		}

		//階段
		{
			Level[1][9][8].kaidan_on = true;
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
		Level[2][0][0].weightboard_linkobject[1] = L_BLOCK;
		Level[2][0][0].weightboard_linknumber[2] = 97;
		Level[2][0][0].weightboard_linkobject[2] = L_BLOCK;
		Level[2][0][0].weightboard_count = 2;

		Level[2][0][6].weightboard_linknumber[1] = 76;
		Level[2][0][6].weightboard_linkobject[1] = L_BLOCK;
		Level[2][0][6].weightboard_linknumber[2] = 58;
		Level[2][0][6].weightboard_linkobject[2] = L_BLOCK;
		Level[2][0][6].weightboard_count = 2;

		Level[2][7][0].weightboard_linknumber[1] = 5;
		Level[2][7][0].weightboard_linkobject[1] = L_BLOCK;
		Level[2][7][0].weightboard_count = 1;

		Level[2][7][2].weightboard_linknumber[1] = 13;
		Level[2][7][2].weightboard_linkobject[1] = L_BLOCK;
		Level[2][7][2].weightboard_linknumber[2] = 35;
		Level[2][7][2].weightboard_linkobject[2] = L_BLOCK;
		Level[2][7][2].weightboard_count = 2;

		Level[2][9][0].weightboard_linknumber[1] = 12;
		Level[2][9][0].weightboard_linkobject[1] = L_BLOCK;
		Level[2][9][0].weightboard_linknumber[2] = 45;
		Level[2][9][0].weightboard_linkobject[2] = L_BLOCK;
		Level[2][9][0].weightboard_linknumber[3] = 89;
		Level[2][9][0].weightboard_linkobject[3] = L_BLOCK;
		Level[2][9][0].weightboard_count = 3;

		Level[2][9][2].weightboard_linknumber[1] = 34;
		Level[2][9][2].weightboard_linkobject[1] = L_BLOCK;
		Level[2][9][2].weightboard_linknumber[2] = 29;
		Level[2][9][2].weightboard_linkobject[2] = L_BLOCK;
		Level[2][9][2].weightboard_count = 2;
		}

		//階段
		{
			Level[2][9][9].kaidan_on = true;
		}

	}

	//レベル3
	{
		//氷床
		{

			Level[3][1][0].ice_on = true;
			Level[3][1][1].ice_on = true;
			Level[3][1][2].ice_on = true;
			Level[3][1][4].ice_on = true;
			Level[3][1][5].ice_on = true;
			Level[3][1][6].ice_on = true;
			Level[3][1][7].ice_on = true;

			Level[3][2][0].ice_on = true;
			Level[3][2][2].ice_on = true;
			Level[3][2][3].ice_on = true;
			Level[3][2][4].ice_on = true;
			Level[3][2][5].ice_on = true;
			Level[3][2][6].ice_on = true;
			Level[3][2][7].ice_on = true;
			Level[3][2][8].ice_on = true;
			Level[3][2][9].ice_on = true;

			Level[3][3][5].ice_on = true;
			Level[3][3][6].ice_on = true;
			Level[3][3][7].ice_on = true;
			Level[3][3][8].ice_on = true;
			Level[3][3][9].ice_on = true;

			Level[3][4][5].ice_on = true;
			Level[3][4][6].ice_on = true;
			Level[3][4][7].ice_on = true;
			Level[3][4][8].ice_on = true;
			Level[3][4][9].ice_on = true;

			Level[3][5][5].ice_on = true;
			Level[3][5][6].ice_on = true;
			Level[3][5][7].ice_on = true;
			Level[3][5][8].ice_on = true;
			Level[3][5][9].ice_on = true;

			Level[3][6][5].ice_on = true;
			Level[3][6][6].ice_on = true;
			Level[3][6][7].ice_on = true;
			Level[3][6][8].ice_on = true;
			Level[3][6][9].ice_on = true;

			Level[3][7][6].ice_on = true;
			Level[3][7][7].ice_on = true;
			Level[3][7][8].ice_on = true;
			Level[3][7][9].ice_on = true;

			Level[3][8][5].ice_on = true;
			Level[3][8][6].ice_on = true;

			Level[3][9][5].ice_on = true;
			Level[3][9][6].ice_on = true;
			Level[3][9][9].ice_on = true;
		}

		//感圧板
		{
			//壁
			Level[3][0][8].weightboard_map = true;
			Level[3][0][8].weightboard_linknumber[1] = 15;
			Level[3][0][8].weightboard_linkobject[1] = L_BLOCK;
			Level[3][0][8].weightboard_linknumber[2] = 78;
			Level[3][0][8].weightboard_linkobject[2] = L_BLOCK;
			Level[3][0][8].weightboard_linknumber[3] = 75;
			Level[3][0][8].weightboard_linkobject[3] = L_BLOCK;
			Level[3][0][8].weightboard_count = 3;

			//壁・氷の床
			Level[3][0][9].weightboard_map = true;
			Level[3][0][9].weightboard_linknumber[1] = 24;
			Level[3][0][9].weightboard_linkobject[1] = L_BLOCK;
			Level[3][0][9].weightboard_linknumber[2] = 64;
			Level[3][0][9].weightboard_linkobject[2] = I_BLOCK;
			Level[3][0][9].weightboard_count = 2;

			//壁
			Level[3][5][0].weightboard_map = true;
			Level[3][5][0].weightboard_linknumber[1] = 29;
			Level[3][5][0].weightboard_linkobject[1] = L_BLOCK;
			Level[3][5][0].weightboard_linknumber[2] = 39;
			Level[3][5][0].weightboard_linkobject[2] = L_BLOCK;
			Level[3][5][0].weightboard_count = 2;

			//壁・氷の床
			Level[3][5][1].weightboard_map = true;
			Level[3][5][1].weightboard_linknumber[1] = 16;
			Level[3][5][1].weightboard_linkobject[1] = I_BLOCK;
			Level[3][5][1].weightboard_linknumber[2] = 98;
			Level[3][5][1].weightboard_linkobject[2] = I_BLOCK;
			Level[3][5][1].weightboard_count = 2;

			//壁・穴
			Level[3][5][3].weightboard_map = true;
			Level[3][5][3].weightboard_linknumber[1] = 2;
			Level[3][5][3].weightboard_linkobject[1] = L_BLOCK;
			Level[3][5][3].weightboard_linknumber[2] = 6;
			Level[3][5][3].weightboard_linkobject[2] = I_BLOCK;
			Level[3][5][3].weightboard_count = 2;

			//穴
			Level[3][6][0].weightboard_map = true;
			Level[3][6][0].weightboard_linknumber[1] = 0;
			Level[3][6][0].weightboard_linkobject[1] = I_BLOCK;
			Level[3][6][0].weightboard_linknumber[2] = 21;
			Level[3][6][0].weightboard_linkobject[2] = I_BLOCK;
			Level[3][6][0].weightboard_count = 2;

			//壁・穴
			Level[3][6][3].weightboard_map = true;
			Level[3][6][3].weightboard_linknumber[1] = 13;
			Level[3][6][3].weightboard_linkobject[1] = I_BLOCK;
			Level[3][6][3].weightboard_linknumber[2] = 30;
			Level[3][6][3].weightboard_linkobject[2] = L_BLOCK;
			Level[3][6][3].weightboard_count = 2;

			//壁
			Level[3][7][0].weightboard_map = true;
			Level[3][7][0].weightboard_linknumber[1] = 36;
			Level[3][7][0].weightboard_linkobject[1] = L_BLOCK;
			Level[3][7][0].weightboard_linknumber[2] = 47;
			Level[3][7][0].weightboard_linkobject[2] = L_BLOCK;
			Level[3][7][0].weightboard_count = 2;

			//壁・穴
			Level[3][7][3].weightboard_map = true;
			Level[3][7][3].weightboard_linknumber[1] = 34;
			Level[3][7][3].weightboard_linkobject[1] = I_BLOCK;
			Level[3][7][3].weightboard_linknumber[2] = 67;
			Level[3][7][3].weightboard_linkobject[2] = L_BLOCK;
			Level[3][7][3].weightboard_count = 2;

			//氷の床
			Level[3][8][0].weightboard_map = true;
			Level[3][8][0].weightboard_linknumber[1] = 97;
			Level[3][8][0].weightboard_linkobject[1] = I_BLOCK;
			Level[3][8][0].weightboard_count = 1;

			//壁
			Level[3][8][3].weightboard_map = true;
			Level[3][8][3].weightboard_linknumber[1] = 49;
			Level[3][8][3].weightboard_linkobject[1] = L_BLOCK;
			Level[3][8][3].weightboard_linknumber[2] = 79;
			Level[3][8][3].weightboard_linkobject[2] = L_BLOCK;
			Level[3][8][3].weightboard_count = 2;

			//壁
			Level[3][9][2].weightboard_map = true;
			Level[3][9][2].weightboard_linknumber[1] = 55;
			Level[3][9][2].weightboard_linkobject[1] = L_BLOCK;
			Level[3][9][2].weightboard_count = 1;

			//壁
			Level[3][9][3].weightboard_map = true;
			Level[3][9][3].weightboard_linknumber[1] = 5;
			Level[3][9][3].weightboard_linkobject[1] = L_BLOCK;
			Level[3][9][3].weightboard_linknumber[2] = 7;
			Level[3][9][3].weightboard_linkobject[2] = L_BLOCK;
			Level[3][9][3].weightboard_count = 2;
		};

		//穴
		{
			Level[3][0][0].hole_on = true;
			Level[3][0][1].hole_on = true;
			Level[3][0][2].hole_on = true;
			Level[3][0][3].hole_on = true;
			Level[3][0][4].hole_on = true;
			Level[3][0][5].hole_on = true;
			Level[3][0][6].hole_on = true;
			Level[3][0][7].hole_on = true;

			Level[3][1][3].hole_on = true;

			Level[3][2][1].hole_on = true;

			Level[3][3][0].hole_on = true;
			Level[3][3][1].hole_on = true;
			Level[3][3][3].hole_on = true;
			Level[3][3][4].hole_on = true;

			Level[3][4][0].hole_on = true;
			Level[3][4][1].hole_on = true;
			Level[3][4][3].hole_on = true;
			Level[3][4][4].hole_on = true;

			Level[3][5][4].hole_on = true;

			Level[3][6][4].hole_on = true;

			Level[3][7][4].hole_on = true;
			Level[3][7][5].hole_on = true;

			Level[3][8][4].hole_on = true;
			Level[3][8][7].hole_on = true;
			Level[3][8][8].hole_on = true;
			Level[3][8][9].hole_on = true;

			Level[3][9][4].hole_on = true;
			Level[3][9][7].hole_on = true;
			Level[3][9][8].hole_on = true;
		}

		//壁
		{
			Level[3][0][0].block_on = true;
			Level[3][0][2].block_on = true;
			Level[3][0][5].block_on = true;
			Level[3][0][6].block_on = true;
			Level[3][0][7].block_on = true;

			Level[3][1][3].block_on = true;
			Level[3][1][5].block_on = true;
			Level[3][1][6].block_on = true;

			Level[3][2][1].block_on = true;
			Level[3][2][4].block_on = true;
			Level[3][2][9].block_on = true;

			Level[3][3][0].block_on = true;
			Level[3][3][4].block_on = true;
			Level[3][3][6].block_on = true;
			Level[3][3][9].block_on = true;

			Level[3][4][7].block_on = true;
			Level[3][4][9].block_on = true;

			Level[3][5][5].block_on = true;

			Level[3][6][4].block_on = true;
			Level[3][6][7].block_on = true;

			Level[3][7][5].block_on = true;
			Level[3][7][8].block_on = true;
			Level[3][7][9].block_on = true;

			Level[3][9][7].block_on = true;
			Level[3][9][8].block_on = true;

		}

		//階段
		{
			Level[3][9][9].kaidan_on = true;
		}

	}

	//レベル4
	{
		//氷床
		{

			Level[4][0][6].ice_on = true;
			Level[4][0][7].ice_on = true;
			Level[4][0][8].ice_on = true;
			Level[4][0][9].ice_on = true;

			Level[4][1][6].ice_on = true;
			Level[4][1][8].ice_on = true;
			Level[4][1][9].ice_on = true;

			Level[4][3][2].ice_on = true;
			Level[4][3][6].ice_on = true;
			Level[4][3][7].ice_on = true;
			Level[4][3][8].ice_on = true;

			Level[4][4][6].ice_on = true;
			Level[4][4][7].ice_on = true;
			Level[4][4][8].ice_on = true;
			Level[4][4][9].ice_on = true;

			Level[4][5][6].ice_on = true;
			Level[4][5][7].ice_on = true;
			Level[4][5][8].ice_on = true;
			Level[4][5][9].ice_on = true;

			Level[4][7][7].ice_on = true;
			Level[4][7][8].ice_on = true;
			Level[4][7][9].ice_on = true;

			Level[4][8][2].ice_on = true;
			Level[4][8][6].ice_on = true;
			Level[4][8][7].ice_on = true;
			Level[4][8][8].ice_on = true;

			Level[4][9][6].ice_on = true;
			Level[4][9][7].ice_on = true;
			Level[4][9][8].ice_on = true;
			Level[4][9][9].ice_on = true;
		}

		//感圧板
		{
			//壁
			Level[4][0][0].weightboard_map = true;
			Level[4][0][0].weightboard_linknumber[1] = 89;
			Level[4][0][0].weightboard_linkobject[1] = G_BLOCK;
			Level[4][0][0].weightboard_count = 1;

			Level[4][0][2].weightboard_map = true;
			Level[4][0][2].weightboard_linknumber[1] = 71;
			Level[4][0][2].weightboard_linkobject[1] = G_BLOCK;
			Level[4][0][2].weightboard_count = 1;

			Level[4][1][7].weightboard_map = true;
			Level[4][1][7].weightboard_linknumber[1] = 55;
			Level[4][1][7].weightboard_linkobject[1] = G_BLOCK;
			Level[4][1][7].weightboard_count = 1;

			Level[4][3][9].weightboard_map = true;
			Level[4][3][9].weightboard_linknumber[1] = 35;
			Level[4][3][9].weightboard_linkobject[1] = L_BLOCK;
			Level[4][3][9].weightboard_linknumber[2] = 57;
			Level[4][3][9].weightboard_linkobject[2] = H_BLOCK;
			Level[4][3][9].weightboard_linknumber[3] = 95;
			Level[4][3][9].weightboard_linkobject[3] = G_BLOCK;
			Level[4][3][9].weightboard_count = 3;

			Level[4][4][0].weightboard_map = true;
			Level[4][4][0].weightboard_linknumber[1] = 5;
			Level[4][4][0].weightboard_linkobject[1] = G_BLOCK;
			Level[4][4][0].weightboard_linknumber[2] = 42;
			Level[4][4][0].weightboard_linkobject[2] = L_BLOCK;
			Level[4][4][0].weightboard_count = 2;

			Level[4][6][0].weightboard_map = true;
			Level[4][6][0].weightboard_linknumber[1] = 21;
			Level[4][6][0].weightboard_linkobject[1] = G_BLOCK;
			Level[4][6][0].weightboard_linknumber[2] = 26;
			Level[4][6][0].weightboard_linkobject[2] = L_BLOCK;
			Level[4][6][0].weightboard_count = 2;

			Level[4][6][4].weightboard_map = true;
			Level[4][6][4].weightboard_linknumber[1] = 33;
			Level[4][6][4].weightboard_linkobject[1] = G_BLOCK;
			Level[4][6][4].weightboard_linknumber[2] = 96;
			Level[4][6][4].weightboard_linkobject[2] = L_BLOCK;
			Level[4][6][4].weightboard_count = 2;

			Level[4][7][6].weightboard_map = true;
			Level[4][7][6].weightboard_linknumber[1] = 10;
			Level[4][7][6].weightboard_linkobject[1] = G_BLOCK;
			Level[4][7][6].weightboard_count = 1;

			Level[4][8][0].weightboard_map = true;
			Level[4][8][0].weightboard_linknumber[1] = 31;
			Level[4][8][0].weightboard_linkobject[1] = L_BLOCK;
			Level[4][8][0].weightboard_linknumber[2] = 69;
			Level[4][8][0].weightboard_linkobject[2] = L_BLOCK;
			Level[4][8][0].weightboard_linknumber[3] = 92;
			Level[4][8][0].weightboard_linkobject[3] = H_BLOCK;
			Level[4][8][0].weightboard_count = 3;

			Level[4][9][1].weightboard_map = true;
			Level[4][9][1].weightboard_linknumber[1] = 99;
			Level[4][9][1].weightboard_linkobject[1] = L_BLOCK;
			Level[4][9][1].weightboard_count = 1;

			
		};

		//穴
		{
			Level[4][0][1].hole_on = true;
			Level[4][0][3].hole_on = true;
			Level[4][0][5].hole_on = true;

			Level[4][1][0].hole_on = true;
			Level[4][1][1].hole_on = true;
			Level[4][1][3].hole_on = true;
			Level[4][1][5].hole_on = true;

			Level[4][2][1].hole_on = true;
			Level[4][2][3].hole_on = true;
			Level[4][2][5].hole_on = true;
			Level[4][2][6].hole_on = true;
			Level[4][2][7].hole_on = true;
			Level[4][2][8].hole_on = true;

			Level[4][3][1].hole_on = true;
			Level[4][3][3].hole_on = true;
			Level[4][3][5].hole_on = true;

			Level[4][4][1].hole_on = true;
			Level[4][4][2].hole_on = true;
			Level[4][4][3].hole_on = true;
			Level[4][4][4].hole_on = true;
			Level[4][4][5].hole_on = true;

			Level[4][5][1].hole_on = true;
			Level[4][5][5].hole_on = true;

			Level[4][6][1].hole_on = true;
			Level[4][6][3].hole_on = true;
			Level[4][6][5].hole_on = true;
			Level[4][6][6].hole_on = true;
			Level[4][6][7].hole_on = true;
			Level[4][6][9].hole_on = true;

			Level[4][7][1].hole_on = true;
			Level[4][7][3].hole_on = true;
			Level[4][7][4].hole_on = true;
			Level[4][7][5].hole_on = true;

			Level[4][8][3].hole_on = true;
			Level[4][8][5].hole_on = true;
			Level[3][8][9].hole_on = true;

			Level[4][9][2].hole_on = true;
			Level[4][9][3].hole_on = true;
			Level[4][9][5].hole_on = true;
		}

		//壁
		{
			Level[4][2][9].block_on = true;
			Level[4][2][9].blockonly_on = true;

			Level[4][6][8].block_on = true;
			Level[4][6][8].blockonly_on = true;

			Level[4][8][1].block_on = true;
			Level[4][8][1].blockonly_on = true;

			Level[4][0][5].block_on = true;

			Level[4][1][0].block_on = true;

			Level[4][2][1].block_on = true;
			Level[4][2][6].block_on = true;

			Level[4][3][1].block_on = true;
			Level[4][3][3].block_on = true;
			Level[4][3][5].block_on = true;

			Level[4][4][2].block_on = true;

			Level[4][5][5].block_on = true;
			Level[4][5][6].block_on = true;
			Level[4][5][7].block_on = true;

			Level[4][6][9].block_on = true;

			Level[4][7][1].block_on = true;

			Level[4][8][3].block_on = true;
			Level[4][8][9].block_on = true;

			Level[4][9][2].block_on = true;
			Level[4][9][5].block_on = true;
			Level[4][9][6].block_on = true;
			Level[4][9][9].block_on = true;
		}

		//階段
		{
			Level[4][8][9].kaidan_on = true;
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
				Map_SetGround[L][R] = true;
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
							map.Weightboard->Link[L][R][W] = Level[game->Level][L][R].weightboard_linkobject[W];
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