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
		Kabe.Init("Assets/modelData/hekiga.tkm", stageLight);
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
			Ground_P[L][R].x = (L * 191.0f) + -865.0f;
			Ground_P[L][R].y = 0.0f;
			Ground_P[L][R].z = (R * 191.0f) + -865.0f;

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
			map.Weightboard->Link_on = true;
			map.Weightboard->Block_Link = true;
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
			Level[0][0][6].ice_on = true;

			Level[0][1][3].ice_on = true;
			Level[0][1][4].ice_on = true;
			Level[0][1][5].ice_on = true;
			Level[0][1][6].ice_on = true;

			Level[0][2][3].ice_on = true;
			Level[0][2][4].ice_on = true;
			Level[0][2][5].ice_on = true;
			Level[0][2][6].ice_on = true;

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

		Level[0][6][4].block_on = true;

		Level[0][7][5].block_on = true;

		Level[0][8][3].block_on = true;

		Level[0][9][5].block_on = true;
		}

		//落とし穴
		{

			Level[0][3][3].hole_on = true;
			Level[0][3][4].hole_on = true;
			Level[0][3][5].hole_on = true;
			Level[0][3][6].hole_on = true;


			Level[0][4][3].hole_on = true;
			Level[0][4][4].hole_on = true;
			Level[0][4][5].hole_on = true;
			Level[0][4][6].hole_on = true;
			Level[0][4][7].hole_on = true;
			Level[0][4][8].hole_on = true;
			Level[0][4][9].hole_on = true;

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
			Level[0][2][8].weightboard_count = 6;

			Level[0][8][6].weightboard_linknumber[1] = 75;
			Level[0][8][6].weightboard_linkobject[1] = L_BLOCK;
			Level[0][8][6].weightboard_linknumber[2] = 83;
			Level[0][8][6].weightboard_linkobject[2] = L_BLOCK;
			Level[0][8][6].weightboard_linknumber[3] = 95;
			Level[0][8][6].weightboard_linkobject[3] = L_BLOCK;
			Level[0][8][6].weightboard_linknumber[4] = 64;
			Level[0][8][6].weightboard_linkobject[4] = L_BLOCK;
			Level[0][8][6].weightboard_count = 4;
		}

		//階段
		{
			Level[0][8][0].kaidan_on = true;
		}

	}

	//レベル1
	{
		//ブロック
		{
			for (int L = 0; L < 10; L++)
			{
				for (int R = 0; R < 10; R++)
				{
					if (L == 0 || L == 2 || L == 3 || L == 4 || L == 5 || L == 6 || L == 7 || L == 9)
					{
						continue;
					}
					Level[1][L][R].block_on = true;
					Level[1][L][R].blockonly_on = true;
				}
			}

			for (int L = 2; L < 8; L++)
			{
				for (int R = 1; R < 3; R++)
				{
					Level[1][L][R].block_on = true;
				}
			}

			for (int L = 2; L < 8; L++)
			{
				for (int R = 4; R < 6; R++)
				{
					Level[1][L][R].block_on = true;
				}
			}

			for (int L = 2; L < 8; L++)
			{
				for (int R = 7; R < 9; R++)
				{
					Level[1][L][R].block_on = true;
				}
			}
			
		}

		//落とし穴
		{
			for (int L = 0; L < 10; L++)
			{
				for (int R = 0; R < 10; R++)
				{
					if (L == 2 || L == 3 || L == 4 || L == 5 || L == 6 || L == 7)
					{
						continue;

					}
					Level[1][L][R].hole_on = true;
				}
			}

			for (int L = 2; L < 8; L++)
			{
				for (int R = 1; R < 3; R++)
				{
					Level[1][L][R].hole_on = true;
				}
			}
			
			for (int L = 2; L < 8; L++)
			{
				for (int R = 4; R < 6; R++)
				{
					Level[1][L][R].hole_on = true;
				}
			}
		}

		//感圧板
		{
			Level[1][3][0].weightboard_map = true;
			Level[1][3][0].weightboard_linknumber[1] = 21;
			Level[1][3][0].weightboard_linkobject[1] = I_BLOCK;
			Level[1][3][0].weightboard_linknumber[2] = 31;
			Level[1][3][0].weightboard_linkobject[2] = I_BLOCK;
			Level[1][3][0].weightboard_linknumber[3] = 41;
			Level[1][3][0].weightboard_linkobject[3] = I_BLOCK;
			Level[1][3][0].weightboard_linknumber[4] = 51;
			Level[1][3][0].weightboard_linkobject[4] = I_BLOCK;
			Level[1][3][0].weightboard_linknumber[5] = 61;
			Level[1][3][0].weightboard_linkobject[5] = I_BLOCK;
			Level[1][3][0].weightboard_linknumber[6] = 71;
			Level[1][3][0].weightboard_linkobject[6] = I_BLOCK;
			Level[1][3][0].weightboard_count = 6;
			

			Level[1][5][0].weightboard_map = true;
			Level[1][5][0].weightboard_linknumber[1] = 22;
			Level[1][5][0].weightboard_linkobject[1] = I_BLOCK;
			Level[1][5][0].weightboard_linknumber[2] = 32;
			Level[1][5][0].weightboard_linkobject[2] = I_BLOCK;
			Level[1][5][0].weightboard_linknumber[3] = 42;
			Level[1][5][0].weightboard_linkobject[3] = I_BLOCK;
			Level[1][5][0].weightboard_linknumber[4] = 52;
			Level[1][5][0].weightboard_linkobject[4] = I_BLOCK;
			Level[1][5][0].weightboard_linknumber[5] = 62;
			Level[1][5][0].weightboard_linkobject[5] = I_BLOCK;
			Level[1][5][0].weightboard_linknumber[6] = 72;
			Level[1][5][0].weightboard_linkobject[6] = I_BLOCK;
			Level[1][5][0].weightboard_count = 6;

			Level[1][3][3].weightboard_map = true;
			Level[1][3][3].weightboard_linknumber[1] = 24;
			Level[1][3][3].weightboard_linkobject[1] = G_BLOCK;
			Level[1][3][3].weightboard_linknumber[2] = 34;
			Level[1][3][3].weightboard_linkobject[2] = G_BLOCK;
			Level[1][3][3].weightboard_linknumber[3] = 44;
			Level[1][3][3].weightboard_linkobject[3] = G_BLOCK;
			Level[1][3][3].weightboard_linknumber[4] = 54;
			Level[1][3][3].weightboard_linkobject[4] = G_BLOCK;
			Level[1][3][3].weightboard_linknumber[5] = 64;
			Level[1][3][3].weightboard_linkobject[5] = G_BLOCK;
			Level[1][3][3].weightboard_linknumber[6] = 74;
			Level[1][3][3].weightboard_linkobject[6] = G_BLOCK;
			Level[1][3][3].weightboard_count = 6;

			Level[1][5][3].weightboard_map = true;
			Level[1][5][3].weightboard_linknumber[1] = 25;
			Level[1][5][3].weightboard_linkobject[1] = G_BLOCK;
			Level[1][5][3].weightboard_linknumber[2] = 35;
			Level[1][5][3].weightboard_linkobject[2] = G_BLOCK;
			Level[1][5][3].weightboard_linknumber[3] = 45;
			Level[1][5][3].weightboard_linkobject[3] = G_BLOCK;
			Level[1][5][3].weightboard_linknumber[4] = 55;
			Level[1][5][3].weightboard_linkobject[4] = G_BLOCK;
			Level[1][5][3].weightboard_linknumber[5] = 65;
			Level[1][5][3].weightboard_linkobject[5] = G_BLOCK;
			Level[1][5][3].weightboard_linknumber[6] = 75;
			Level[1][5][3].weightboard_linkobject[6] = G_BLOCK;
			Level[1][5][3].weightboard_count = 6;

			Level[1][3][6].weightboard_map = true;
			Level[1][3][6].weightboard_linknumber[1] = 27;
			Level[1][3][6].weightboard_linkobject[1] = L_BLOCK;
			Level[1][3][6].weightboard_linknumber[2] = 37;
			Level[1][3][6].weightboard_linkobject[2] = L_BLOCK;
			Level[1][3][6].weightboard_linknumber[3] = 47;
			Level[1][3][6].weightboard_linkobject[3] = L_BLOCK;
			Level[1][3][6].weightboard_linknumber[4] = 57;
			Level[1][3][6].weightboard_linkobject[4] = L_BLOCK;
			Level[1][3][6].weightboard_linknumber[5] = 67;
			Level[1][3][6].weightboard_linkobject[5] = L_BLOCK;
			Level[1][3][6].weightboard_linknumber[6] = 77;
			Level[1][3][6].weightboard_linkobject[6] = L_BLOCK;
			Level[1][3][6].weightboard_count = 6;

			Level[1][5][6].weightboard_map = true;
			Level[1][5][6].weightboard_linknumber[1] = 28;
			Level[1][5][6].weightboard_linkobject[1] = H_BLOCK;
			Level[1][5][6].weightboard_linknumber[2] = 38;
			Level[1][5][6].weightboard_linkobject[2] = H_BLOCK;
			Level[1][5][6].weightboard_linknumber[3] = 48;
			Level[1][5][6].weightboard_linkobject[3] = H_BLOCK;
			Level[1][5][6].weightboard_linknumber[4] = 58;
			Level[1][5][6].weightboard_linkobject[4] = H_BLOCK;
			Level[1][5][6].weightboard_linknumber[5] = 68;
			Level[1][5][6].weightboard_linkobject[5] = H_BLOCK;
			Level[1][5][6].weightboard_linknumber[6] = 78;
			Level[1][5][6].weightboard_linkobject[6] = H_BLOCK;
			Level[1][5][6].weightboard_count = 6;
		}

		//階段
		{
			Level[1][2][9].kaidan_on = true;
		}
	}

	//レベル2
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
					Level[2][L][R].ice_on = true;
				}
			}

		}

		//壁
		{	
			Level[2][1][5].block_on = true;
			Level[2][1][5].blockonly_on = true;

			Level[2][1][9].block_on = true;
			Level[2][1][9].blockonly_on = true;

			Level[2][3][3].block_on = true;
			Level[2][3][3].blockonly_on = true;
			
			Level[2][7][2].block_on = true;
			Level[2][7][2].blockonly_on = true;

			Level[2][7][7].block_on = true;
			Level[2][7][7].blockonly_on = true;
			
			Level[2][7][9].block_on = true;
			Level[2][7][9].blockonly_on = true;

			Level[2][8][2].block_on = true;
			Level[2][8][2].blockonly_on = true;
			
			Level[2][8][7].block_on = true;
			Level[2][8][7].blockonly_on = true;

			Level[2][8][9].block_on = true;
			Level[2][8][9].blockonly_on = true;
			

			//零行目
			Level[2][0][6].block_on = true;

			//一行目
			Level[2][1][2].block_on = true;
			Level[2][1][8].block_on = true;

			//二行目
			Level[2][2][7].block_on = true;

			//四行目
			Level[2][4][7].block_on = true;

			//五行目
			Level[2][5][3].block_on = true;
			Level[2][5][8].block_on = true;

			//六行目
			Level[2][6][2].block_on = true;

			//七行目
			Level[2][7][4].block_on = true;
			Level[2][7][6].block_on = true;

			//九行目
			Level[2][9][3].block_on = true;
		}

		//落とし穴
		{
			for (int L = 0; L < 1; L++)
			{
				for (int R = 0; R < 10; R++)
				{
					Level[2][L][R].hole_on = true;
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
					Level[2][L][R].hole_on = true;
				}
			}

			Level[2][3][5].hole_on = true;
			Level[2][4][3].hole_on = true;
			Level[2][5][7].hole_on = true;
			Level[2][6][9].hole_on = true;
		}

		//感圧板
		{
			for (int L = 1; L < 9; L++)
			{
				if (L == 1 || L == 8)
				{
					continue;
				}
				if (L % 2 == 0)
				{
					Level[2][L][0].weightboard_map = true;
				}
				else
				{
					if (L % 2 == 1)
					{
						Level[2][L][1].weightboard_map = true;
					}
				}

			}

			Level[2][6][7].weightboard_map = true;
			Level[2][9][6].weightboard_map = true;

			Level[2][2][0].weightboard_linknumber[1] = 62;
			Level[2][2][0].weightboard_linkobject[1] = L_BLOCK;
			Level[2][2][0].weightboard_count = 1;

			Level[2][3][1].weightboard_linknumber[1] = 27;
			Level[2][3][1].weightboard_linkobject[1] = L_BLOCK;
			Level[2][3][1].weightboard_linknumber[2] = 58;
			Level[2][3][1].weightboard_linkobject[2] = L_BLOCK;
			Level[2][3][1].weightboard_count = 2;

			Level[2][4][0].weightboard_linknumber[1] = 74;
			Level[2][4][0].weightboard_linkobject[1] = L_BLOCK;
			Level[2][4][0].weightboard_count = 1;

			Level[2][5][1].weightboard_linknumber[1] = 47;
			Level[2][5][1].weightboard_linkobject[1] = L_BLOCK;
			Level[2][5][1].weightboard_count = 1;

			Level[2][6][0].weightboard_linknumber[1] = 53;
			Level[2][6][0].weightboard_linkobject[1] = L_BLOCK;
			Level[2][6][0].weightboard_count = 1;

			Level[2][7][1].weightboard_linknumber[1] = 76;
			Level[2][7][1].weightboard_linkobject[1] = L_BLOCK;
			Level[2][7][1].weightboard_count = 1;

			Level[2][6][7].weightboard_linknumber[1] = 93;
			Level[2][6][7].weightboard_linkobject[1] = L_BLOCK;
			Level[2][6][7].weightboard_count = 1;

			Level[2][9][6].weightboard_linknumber[1] = 6;
			Level[2][9][6].weightboard_linkobject[1] = L_BLOCK;
			Level[2][9][6].weightboard_count = 1;

		}

		//階段
		{
			Level[2][9][8].kaidan_on = true;
		}
	}

	//レベル3
	{
		//氷床
		{
			Level[3][0][1].ice_on = true;
			Level[3][0][2].ice_on = true;
			Level[3][0][3].ice_on = true;
			Level[3][0][4].ice_on = true;
			Level[3][0][7].ice_on = true;
			Level[3][0][8].ice_on = true;
			Level[3][0][9].ice_on = true;

			Level[3][1][0].ice_on = true;
			Level[3][1][4].ice_on = true;
			Level[3][1][5].ice_on = true;
			Level[3][1][7].ice_on = true;
			Level[3][1][8].ice_on = true;
			Level[3][1][9].ice_on = true;

			Level[3][2][1].ice_on = true;
			Level[3][2][2].ice_on = true;
			Level[3][2][3].ice_on = true;
			Level[3][2][4].ice_on = true;
			Level[3][2][5].ice_on = true;
			Level[3][2][6].ice_on = true;
			Level[3][2][7].ice_on = true;
			Level[3][2][8].ice_on = true;

			Level[3][3][6].ice_on = true;
			Level[3][3][7].ice_on = true;
			Level[3][3][8].ice_on = true;
			Level[3][3][9].ice_on = true;

			Level[3][4][6].ice_on = true;
			Level[3][4][7].ice_on = true;
			Level[3][4][8].ice_on = true;
			Level[3][4][9].ice_on = true;

			Level[3][5][5].ice_on = true;
			Level[3][5][6].ice_on = true;
			Level[3][5][7].ice_on = true;
			Level[3][5][9].ice_on = true;

			Level[3][6][5].ice_on = true;
			Level[3][6][6].ice_on = true;
			Level[3][6][7].ice_on = true;
			Level[3][6][8].ice_on = true;
			Level[3][6][9].ice_on = true;

			Level[3][7][5].ice_on = true;
			Level[3][7][7].ice_on = true;
			Level[3][7][8].ice_on = true;
			Level[3][7][9].ice_on = true;

			Level[3][8][6].ice_on = true;
			Level[3][8][7].ice_on = true;
			Level[3][8][8].ice_on = true;

			Level[3][9][5].ice_on = true;
			Level[3][9][6].ice_on = true;
			Level[3][9][8].ice_on = true;
			
		}

		//壁
		{
			Level[3][1][0].block_on = true;
			Level[3][1][0].blockonly_on = true;

			Level[3][2][6].block_on = true;
			Level[3][2][6].blockonly_on = true;

			Level[3][3][9].block_on = true;
			Level[3][3][9].blockonly_on = true;

			Level[3][4][7].block_on = true;
			Level[3][4][7].blockonly_on = true;


			Level[3][0][5].block_on = true;

			Level[3][1][1].block_on = true;
			Level[3][1][2].block_on = true;
			Level[3][1][3].block_on = true;
			Level[3][1][6].block_on = true;

			Level[3][2][9].block_on = true;

			Level[3][3][1].block_on = true;
			Level[3][3][4].block_on = true;
			Level[3][3][5].block_on = true;

			Level[3][4][5].block_on = true;

			Level[3][5][8].block_on = true;

			Level[3][7][6].block_on = true;

			Level[3][8][9].block_on = true;

			Level[3][9][7].block_on = true;
		}

		//落とし穴
		{
			Level[3][0][5].hole_on = true;

			Level[3][1][1].hole_on = true;
			Level[3][1][2].hole_on = true;
			Level[3][1][3].hole_on = true;
			Level[3][1][6].hole_on = true;

			Level[3][2][9].hole_on = true;


Level[3][3][1].hole_on = true;
Level[3][3][4].hole_on = true;
Level[3][3][5].hole_on = true;

Level[3][4][5].hole_on = true;

Level[3][5][8].hole_on = true;

Level[3][7][6].hole_on = true;

Level[3][8][5].hole_on = true;
Level[3][8][9].hole_on = true;

Level[3][9][7].hole_on = true;
		}

		//感圧板
		{
		Level[3][0][0].weightboard_map = true;
		Level[3][0][6].weightboard_map = true;
		Level[3][7][0].weightboard_map = true;
		Level[3][7][2].weightboard_map = true;
		Level[3][9][0].weightboard_map = true;
		Level[3][9][2].weightboard_map = true;

		Level[3][0][0].weightboard_linknumber[1] = 16;
		Level[3][0][0].weightboard_linkobject[1] = L_BLOCK;
		Level[3][0][0].weightboard_linknumber[2] = 97;
		Level[3][0][0].weightboard_linkobject[2] = L_BLOCK;
		Level[3][0][0].weightboard_count = 2;

		Level[3][0][6].weightboard_linknumber[1] = 76;
		Level[3][0][6].weightboard_linkobject[1] = L_BLOCK;
		Level[3][0][6].weightboard_linknumber[2] = 58;
		Level[3][0][6].weightboard_linkobject[2] = L_BLOCK;
		Level[3][0][6].weightboard_count = 2;

		Level[3][7][0].weightboard_linknumber[1] = 5;
		Level[3][7][0].weightboard_linkobject[1] = L_BLOCK;
		Level[3][7][0].weightboard_count = 1;

		Level[3][7][2].weightboard_linknumber[1] = 13;
		Level[3][7][2].weightboard_linkobject[1] = L_BLOCK;
		Level[3][7][2].weightboard_linknumber[2] = 35;
		Level[3][7][2].weightboard_linkobject[2] = L_BLOCK;
		Level[3][7][2].weightboard_count = 2;

		Level[3][9][0].weightboard_linknumber[1] = 12;
		Level[3][9][0].weightboard_linkobject[1] = L_BLOCK;
		Level[3][9][0].weightboard_linknumber[2] = 45;
		Level[3][9][0].weightboard_linkobject[2] = L_BLOCK;
		Level[3][9][0].weightboard_linknumber[3] = 89;
		Level[3][9][0].weightboard_linkobject[3] = L_BLOCK;
		Level[3][9][0].weightboard_count = 3;

		Level[3][9][2].weightboard_linknumber[1] = 34;
		Level[3][9][2].weightboard_linkobject[1] = L_BLOCK;
		Level[3][9][2].weightboard_linknumber[2] = 29;
		Level[3][9][2].weightboard_linkobject[2] = L_BLOCK;
		Level[3][9][2].weightboard_count = 2;
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

			Level[4][1][0].ice_on = true;
			Level[4][1][1].ice_on = true;
			Level[4][1][2].ice_on = true;
			Level[4][1][4].ice_on = true;
			Level[4][1][5].ice_on = true;
			Level[4][1][6].ice_on = true;
			Level[4][1][7].ice_on = true;

			Level[4][2][0].ice_on = true;
			Level[4][2][2].ice_on = true;
			Level[4][2][3].ice_on = true;
			Level[4][2][4].ice_on = true;
			Level[4][2][5].ice_on = true;
			Level[4][2][6].ice_on = true;
			Level[4][2][7].ice_on = true;
			Level[4][2][8].ice_on = true;
			Level[4][2][9].ice_on = true;

			Level[4][3][5].ice_on = true;
			Level[4][3][6].ice_on = true;
			Level[4][3][7].ice_on = true;
			Level[4][3][8].ice_on = true;
			Level[4][3][9].ice_on = true;

			Level[4][4][5].ice_on = true;
			Level[4][4][6].ice_on = true;
			Level[4][4][7].ice_on = true;
			Level[4][4][8].ice_on = true;
			Level[4][4][9].ice_on = true;

			Level[4][5][5].ice_on = true;
			Level[4][5][6].ice_on = true;
			Level[4][5][7].ice_on = true;
			Level[4][5][8].ice_on = true;
			Level[4][5][9].ice_on = true;

			Level[4][6][5].ice_on = true;
			Level[4][6][6].ice_on = true;
			Level[4][6][7].ice_on = true;
			Level[4][6][8].ice_on = true;
			Level[4][6][9].ice_on = true;

			Level[4][7][6].ice_on = true;
			Level[4][7][7].ice_on = true;
			Level[4][7][8].ice_on = true;
			Level[4][7][9].ice_on = true;

			Level[4][8][5].ice_on = true;
			Level[4][8][6].ice_on = true;

			Level[4][9][5].ice_on = true;
			Level[4][9][6].ice_on = true;
			Level[4][9][9].ice_on = true;
		}

		//感圧板
		{
			//壁
			Level[4][0][8].weightboard_map = true;
			Level[4][0][8].weightboard_linknumber[1] = 15;
			Level[4][0][8].weightboard_linkobject[1] = L_BLOCK;
			Level[4][0][8].weightboard_linknumber[2] = 78;
			Level[4][0][8].weightboard_linkobject[2] = L_BLOCK;
			Level[4][0][8].weightboard_linknumber[3] = 75;
			Level[4][0][8].weightboard_linkobject[3] = L_BLOCK;
			Level[4][0][8].weightboard_count = 3;

			//壁・氷の床
			Level[4][1][9].weightboard_map = true;
			Level[4][1][9].weightboard_linknumber[1] = 24;
			Level[4][1][9].weightboard_linkobject[1] = L_BLOCK;
			Level[4][1][9].weightboard_linknumber[2] = 64;
			Level[4][1][9].weightboard_linkobject[2] = I_BLOCK;
			Level[4][1][9].weightboard_count = 2;

			//壁
			Level[4][6][0].weightboard_map = true;
			Level[4][6][0].weightboard_linknumber[1] = 29;
			Level[4][6][0].weightboard_linkobject[1] = L_BLOCK;
			Level[4][6][0].weightboard_linknumber[2] = 39;
			Level[4][6][0].weightboard_linkobject[2] = L_BLOCK;
			Level[4][6][0].weightboard_count = 2;

			//壁・氷の床
			Level[4][5][1].weightboard_map = true;
			Level[4][5][1].weightboard_linknumber[1] = 16;
			Level[4][5][1].weightboard_linkobject[1] = I_BLOCK;
			Level[4][5][1].weightboard_linknumber[2] = 98;
			Level[4][5][1].weightboard_linkobject[2] = I_BLOCK;
			Level[4][5][1].weightboard_count = 2;

			//壁・穴
			Level[4][5][3].weightboard_map = true;
			Level[4][5][3].weightboard_linknumber[1] = 2;
			Level[4][5][3].weightboard_linkobject[1] = L_BLOCK;
			Level[4][5][3].weightboard_linknumber[2] = 6;
			Level[4][5][3].weightboard_linkobject[2] = I_BLOCK;
			Level[4][5][3].weightboard_count = 2;

			//穴
			Level[4][7][1].weightboard_map = true;
			Level[4][7][1].weightboard_linknumber[1] = 0;
			Level[4][7][1].weightboard_linkobject[1] = I_BLOCK;
			Level[4][7][1].weightboard_linknumber[2] = 21;
			Level[4][7][1].weightboard_linkobject[2] = I_BLOCK;
			Level[4][7][1].weightboard_count = 2;

			//壁・穴
			Level[4][6][2].weightboard_map = true;
			Level[4][6][2].weightboard_linknumber[1] = 13;
			Level[4][6][2].weightboard_linkobject[1] = I_BLOCK;
			Level[4][6][2].weightboard_linknumber[2] = 30;
			Level[4][6][2].weightboard_linkobject[2] = L_BLOCK;
			Level[4][6][2].weightboard_count = 2;

			//壁
			Level[4][8][0].weightboard_map = true;
			Level[4][8][0].weightboard_linknumber[1] = 36;
			Level[4][8][0].weightboard_linkobject[1] = L_BLOCK;
			Level[4][8][0].weightboard_linknumber[2] = 47;
			Level[4][8][0].weightboard_linkobject[2] = L_BLOCK;
			Level[4][8][0].weightboard_count = 2;

			//壁・穴
			Level[4][7][3].weightboard_map = true;
			Level[4][7][3].weightboard_linknumber[1] = 34;
			Level[4][7][3].weightboard_linkobject[1] = I_BLOCK;
			Level[4][7][3].weightboard_linknumber[2] = 67;
			Level[4][7][3].weightboard_linkobject[2] = L_BLOCK;
			Level[4][7][3].weightboard_count = 2;

			//氷の床
			Level[4][9][1].weightboard_map = true;
			Level[4][9][1].weightboard_linknumber[1] = 97;
			Level[4][9][1].weightboard_linkobject[1] = I_BLOCK;
			Level[4][9][1].weightboard_count = 1;

			//壁
			Level[4][8][2].weightboard_map = true;
			Level[4][8][2].weightboard_linknumber[1] = 49;
			Level[4][8][2].weightboard_linkobject[1] = L_BLOCK;
			Level[4][8][2].weightboard_linknumber[2] = 79;
			Level[4][8][2].weightboard_linkobject[2] = L_BLOCK;
			Level[4][8][2].weightboard_count = 2;

			//壁
			Level[4][4][2].weightboard_map = true;
			Level[4][4][2].weightboard_linknumber[1] = 55;
			Level[4][4][2].weightboard_linkobject[1] = L_BLOCK;
			Level[4][4][2].weightboard_count = 1;

			//壁
			Level[4][9][3].weightboard_map = true;
			Level[4][9][3].weightboard_linknumber[1] = 5;
			Level[4][9][3].weightboard_linkobject[1] = L_BLOCK;
			Level[4][9][3].weightboard_linknumber[2] = 7;
			Level[4][9][3].weightboard_linkobject[2] = L_BLOCK;
			Level[4][9][3].weightboard_count = 2;
		};

		//穴
		{
			Level[4][0][0].hole_on = true;
			Level[4][0][1].hole_on = true;
			Level[4][0][2].hole_on = true;
			Level[4][0][3].hole_on = true;
			Level[4][0][4].hole_on = true;
			Level[4][0][5].hole_on = true;
			Level[4][0][6].hole_on = true;
			Level[4][0][7].hole_on = true;

			Level[4][1][3].hole_on = true;

			Level[4][2][1].hole_on = true;

			Level[4][3][0].hole_on = true;
			Level[4][3][1].hole_on = true;
			Level[4][3][3].hole_on = true;
			Level[4][3][4].hole_on = true;

			Level[4][4][0].hole_on = true;
			Level[4][4][1].hole_on = true;
			Level[4][4][3].hole_on = true;
			Level[4][4][4].hole_on = true;

			Level[4][5][4].hole_on = true;

			Level[4][6][4].hole_on = true;

			Level[4][7][4].hole_on = true;
			Level[4][7][5].hole_on = true;

			Level[4][8][4].hole_on = true;
			Level[4][8][7].hole_on = true;
			Level[4][8][8].hole_on = true;
			Level[4][8][9].hole_on = true;

			Level[4][9][4].hole_on = true;
			Level[4][9][7].hole_on = true;
			Level[4][9][8].hole_on = true;
		}

		//壁
		{
			Level[4][0][0].block_on = true;
			Level[4][0][2].block_on = true;
			Level[4][0][5].block_on = true;
			Level[4][0][6].block_on = true;
			Level[4][0][7].block_on = true;

			Level[4][1][3].block_on = true;
			Level[4][1][5].block_on = true;
			Level[4][1][6].block_on = true;

			Level[4][2][1].block_on = true;
			Level[4][2][4].block_on = true;
			Level[4][2][9].block_on = true;

			Level[4][3][0].block_on = true;
			Level[4][3][4].block_on = true;
			Level[4][3][6].block_on = true;
			Level[4][3][9].block_on = true;

			Level[4][4][7].block_on = true;
			Level[4][4][9].block_on = true;

			Level[4][5][5].block_on = true;

			Level[4][6][4].block_on = true;
			Level[4][6][7].block_on = true;

			Level[4][7][5].block_on = true;
			Level[4][7][8].block_on = true;
			Level[4][7][9].block_on = true;

			Level[4][9][7].block_on = true;
			Level[4][9][8].block_on = true;

		}

		//階段
		{
			Level[4][9][9].kaidan_on = true;
		}

	}

	//レベル5
	{
		//氷床
		{

			Level[5][0][6].ice_on = true;
			Level[5][0][7].ice_on = true;
			Level[5][0][8].ice_on = true;
			Level[5][0][9].ice_on = true;

			Level[5][1][6].ice_on = true;
			Level[5][1][8].ice_on = true;
			Level[5][1][9].ice_on = true;

			Level[5][3][2].ice_on = true;
			Level[5][3][6].ice_on = true;
			Level[5][3][7].ice_on = true;
			Level[5][3][8].ice_on = true;

			Level[5][4][6].ice_on = true;
			Level[5][4][7].ice_on = true;
			Level[5][4][8].ice_on = true;
			Level[5][4][9].ice_on = true;

			Level[5][5][6].ice_on = true;
			Level[5][5][7].ice_on = true;
			Level[5][5][8].ice_on = true;
			Level[5][5][9].ice_on = true;

			Level[5][7][7].ice_on = true;
			Level[5][7][8].ice_on = true;
			Level[5][7][9].ice_on = true;

			Level[5][8][2].ice_on = true;
			Level[5][8][6].ice_on = true;
			Level[5][8][7].ice_on = true;
			Level[5][8][8].ice_on = true;

			Level[5][9][6].ice_on = true;
			Level[5][9][7].ice_on = true;
			Level[5][9][8].ice_on = true;
			Level[5][9][9].ice_on = true;
		}

		//感圧板
		{
			//壁
			Level[5][0][0].weightboard_map = true;
			Level[5][0][0].weightboard_linknumber[1] = 67;
			Level[5][0][0].weightboard_linkobject[1] = L_BLOCK;
			Level[5][0][0].weightboard_count = 1;

			Level[5][0][2].weightboard_map = true;
			Level[5][0][2].weightboard_linknumber[1] = 71;
			Level[5][0][2].weightboard_linkobject[1] = G_BLOCK;
			Level[5][0][2].weightboard_count = 1;

			Level[5][1][7].weightboard_map = true;
			Level[5][1][7].weightboard_linknumber[1] = 55;
			Level[5][1][7].weightboard_linkobject[1] = G_BLOCK;
			Level[5][1][7].weightboard_linknumber[2] = 83;
			Level[5][1][7].weightboard_linkobject[2] = G_BLOCK;
			Level[5][1][7].weightboard_count = 2;

			Level[5][3][9].weightboard_map = true;
			Level[5][3][9].weightboard_linknumber[1] = 35;
			Level[5][3][9].weightboard_linkobject[1] = L_BLOCK;
			Level[5][3][9].weightboard_linknumber[2] = 57;
			Level[5][3][9].weightboard_linkobject[2] = H_BLOCK;
			Level[5][3][9].weightboard_linknumber[3] = 95;
			Level[5][3][9].weightboard_linkobject[3] = G_BLOCK;
			Level[5][3][9].weightboard_count = 3;

			Level[5][4][0].weightboard_map = true;
			Level[5][4][0].weightboard_linknumber[1] = 5;
			Level[5][4][0].weightboard_linkobject[1] = G_BLOCK;
			Level[5][4][0].weightboard_linknumber[2] = 42;
			Level[5][4][0].weightboard_linkobject[2] = L_BLOCK;
			Level[5][4][0].weightboard_count = 2;

			Level[5][6][0].weightboard_map = true;
			Level[5][6][0].weightboard_linknumber[1] = 21;
			Level[5][6][0].weightboard_linkobject[1] = G_BLOCK;
			Level[5][6][0].weightboard_linknumber[2] = 26;
			Level[5][6][0].weightboard_linkobject[2] = L_BLOCK;
			Level[5][6][0].weightboard_count = 2;

			Level[5][6][4].weightboard_map = true;
			Level[5][6][4].weightboard_linknumber[1] = 33;
			Level[5][6][4].weightboard_linkobject[1] = G_BLOCK;
			Level[5][6][4].weightboard_linknumber[2] = 96;
			Level[5][6][4].weightboard_linkobject[2] = L_BLOCK;
			Level[5][6][4].weightboard_count = 2;

			Level[5][7][6].weightboard_map = true;
			Level[5][7][6].weightboard_linknumber[1] = 10;
			Level[5][7][6].weightboard_linkobject[1] = G_BLOCK;
			Level[5][7][6].weightboard_count = 1;

			Level[5][8][0].weightboard_map = true;
			Level[5][8][0].weightboard_linknumber[1] = 31;
			Level[5][8][0].weightboard_linkobject[1] = L_BLOCK;
			Level[5][8][0].weightboard_linknumber[2] = 69;
			Level[5][8][0].weightboard_linkobject[2] = L_BLOCK;
			Level[5][8][0].weightboard_linknumber[3] = 92;
			Level[5][8][0].weightboard_linkobject[3] = H_BLOCK;
			
			/*Level[5][8][0].weightboard_linknumber[3] = 92;
			Level[5][8][0].weightboard_linkobject[3] = H_BLOCK;*/
			Level[5][8][0].weightboard_count = 3;

			Level[5][9][1].weightboard_map = true;
			Level[5][9][1].weightboard_linknumber[1] = 99;
			Level[5][9][1].weightboard_linkobject[1] = L_BLOCK;
			Level[5][9][1].weightboard_count = 1;

			
		};

		//穴
		{
			Level[5][0][1].hole_on = true;
			Level[5][0][3].hole_on = true;
			Level[5][0][5].hole_on = true;

			Level[5][1][0].hole_on = true;
			Level[5][1][1].hole_on = true;
			Level[5][1][3].hole_on = true;
			Level[5][1][5].hole_on = true;

			Level[5][2][1].hole_on = true;
			Level[5][2][3].hole_on = true;
			Level[5][2][5].hole_on = true;
			Level[5][2][6].hole_on = true;
			Level[5][2][7].hole_on = true;
			Level[5][2][8].hole_on = true;

			Level[5][3][1].hole_on = true;
			Level[5][3][3].hole_on = true;
			Level[5][3][5].hole_on = true;

			Level[5][4][1].hole_on = true;
			Level[5][4][2].hole_on = true;
			Level[5][4][3].hole_on = true;
			Level[5][4][4].hole_on = true;
			Level[5][4][5].hole_on = true;

			Level[5][5][1].hole_on = true;
			Level[5][5][5].hole_on = true;

			Level[5][6][1].hole_on = true;
			Level[5][6][3].hole_on = true;
			Level[5][6][5].hole_on = true;
			Level[5][6][6].hole_on = true;
			Level[5][6][7].hole_on = true;
			Level[5][6][9].hole_on = true;

			Level[5][7][1].hole_on = true;
			Level[5][7][3].hole_on = true;
			Level[5][7][4].hole_on = true;
			Level[5][7][5].hole_on = true;

			Level[5][8][3].hole_on = true;
			Level[5][8][5].hole_on = true;
			Level[5][8][9].hole_on = true;

			Level[5][9][2].hole_on = true;
			Level[5][9][3].hole_on = true;
			Level[5][9][5].hole_on = true;
		}

		//壁
		{
			Level[5][2][9].block_on = true;
			Level[5][2][9].blockonly_on = true;

			Level[5][6][8].block_on = true;
			Level[5][6][8].blockonly_on = true;

			Level[5][8][1].block_on = true;
			Level[5][8][1].blockonly_on = true;

			Level[5][0][5].block_on = true;

			Level[5][1][0].block_on = true;

			Level[5][2][1].block_on = true;
			Level[5][2][6].block_on = true;

			Level[5][3][1].block_on = true;
			Level[5][3][3].block_on = true;
			Level[5][3][5].block_on = true;

			Level[5][4][2].block_on = true;

			Level[5][5][5].block_on = true;
			Level[5][5][6].block_on = true;
			Level[5][5][7].block_on = true;

			Level[5][6][7].block_on = true;
			Level[5][6][9].block_on = true;

			Level[5][7][1].block_on = true;

			Level[5][8][3].block_on = true;

			Level[5][9][2].block_on = true;
			Level[5][9][5].block_on = true;
			Level[5][9][6].block_on = true;
			Level[5][9][9].block_on = true;
		}

		//階段
		{
			Level[5][8][9].kaidan_on = true;
		}

	}

	//レベル6
	{
		//氷床
		{

			Level[6][0][3].ice_on = true;
			Level[6][0][4].ice_on = true;
			Level[6][0][5].ice_on = true;
			Level[6][0][6].ice_on = true;
			Level[6][0][7].ice_on = true;
			Level[6][0][8].ice_on = true;

			Level[6][1][4].ice_on = true;
			Level[6][1][9].ice_on = true;

			Level[6][2][4].ice_on = true;
			Level[6][2][5].ice_on = true;
			Level[6][2][6].ice_on = true;
			Level[6][2][7].ice_on = true;
			Level[6][2][9].ice_on = true;

			Level[6][3][0].ice_on = true;
			Level[6][3][1].ice_on = true;
			Level[6][3][2].ice_on = true;
			Level[6][3][3].ice_on = true;
			Level[6][3][9].ice_on = true;

			Level[6][5][0].ice_on = true;
			Level[6][5][2].ice_on = true;
			Level[6][5][3].ice_on = true;
			Level[6][5][4].ice_on = true;
			Level[6][5][5].ice_on = true;
			Level[6][5][7].ice_on = true;
			Level[6][5][8].ice_on = true;

			Level[6][6][0].ice_on = true;
			Level[6][6][2].ice_on = true;

			Level[6][7][0].ice_on = true;
			Level[6][7][2].ice_on = true;
			Level[6][7][3].ice_on = true;
			Level[6][7][5].ice_on = true;
			Level[6][7][6].ice_on = true;
			Level[6][7][7].ice_on = true;
			Level[6][7][8].ice_on = true;
			Level[6][7][9].ice_on = true;

			Level[6][8][0].ice_on = true;
			Level[6][8][9].ice_on = true;

			Level[6][9][1].ice_on = true;
			Level[6][9][2].ice_on = true;
			Level[6][9][3].ice_on = true;
			Level[6][9][4].ice_on = true;
			Level[6][9][5].ice_on = true;
			Level[6][9][6].ice_on = true;
			Level[6][9][7].ice_on = true;
			Level[6][9][8].ice_on = true;
		}

		//感圧板
		{
			//壁
			Level[6][0][9].weightboard_map = true;
			Level[6][0][9].weightboard_linknumber[1] = 23;
			Level[6][0][9].weightboard_linkobject[1] = L_BLOCK;
			Level[6][0][9].weightboard_linknumber[2] = 28;
			Level[6][0][9].weightboard_linkobject[2] = G_BLOCK;
			Level[6][0][9].weightboard_count = 2;

			Level[6][1][0].weightboard_map = true;
			Level[6][1][0].weightboard_linknumber[1] = 42;
			Level[6][1][0].weightboard_linkobject[1] = L_BLOCK;
			Level[6][1][0].weightboard_linknumber[2] = 49;
			Level[6][1][0].weightboard_linkobject[2] = L_BLOCK;
			Level[6][1][0].weightboard_linknumber[3] = 56;
			Level[6][1][0].weightboard_linkobject[3] = I_BLOCK;
			Level[6][1][0].weightboard_count = 3;

			Level[6][3][4].weightboard_map = true;
			Level[6][3][4].weightboard_linknumber[1] = 51;
			Level[6][3][4].weightboard_linkobject[1] = L_BLOCK;
			Level[6][3][4].weightboard_linknumber[2] = 66;
			Level[6][3][4].weightboard_linkobject[2] = L_BLOCK;
			Level[6][3][4].weightboard_count = 2;

			Level[6][3][8].weightboard_map = true;
			Level[6][3][8].weightboard_linknumber[1] = 27;
			Level[6][3][8].weightboard_linkobject[1] = L_BLOCK;
			Level[6][3][8].weightboard_count = 1;

			Level[6][4][0].weightboard_map = true;
			Level[6][4][0].weightboard_linknumber[1] = 3;
			Level[6][4][0].weightboard_linkobject[1] = L_BLOCK;
			Level[6][4][0].weightboard_count = 1;

			Level[6][4][6].weightboard_map = true;
			Level[6][4][6].weightboard_linknumber[1] = 20;
			Level[6][4][6].weightboard_linkobject[1] = L_BLOCK;
			Level[6][4][6].weightboard_linknumber[2] = 36;
			Level[6][4][6].weightboard_linkobject[2] = I_BLOCK;
			Level[6][4][6].weightboard_count = 2;

			Level[6][9][0].weightboard_map = true;
			Level[6][9][0].weightboard_linknumber[1] = 69;
			Level[6][9][0].weightboard_linkobject[1] = L_BLOCK;
			Level[6][9][0].weightboard_linknumber[2] = 82;
			Level[6][9][0].weightboard_linkobject[2] = L_BLOCK;
			Level[6][9][0].weightboard_count = 2;

Level[6][9][9].weightboard_map = true;
Level[6][9][9].weightboard_linknumber[1] = 71;
Level[6][9][9].weightboard_linkobject[1] = L_BLOCK;
Level[6][9][9].weightboard_linknumber[2] = 57;
Level[6][9][9].weightboard_linkobject[2] = L_BLOCK;
Level[6][9][9].weightboard_linknumber[3] = 14;
Level[6][9][9].weightboard_linkobject[3] = H_BLOCK;
Level[6][9][9].weightboard_count = 3;
		};

		//穴
		{
		Level[6][1][3].hole_on = true;
		Level[6][1][5].hole_on = true;
		Level[6][1][7].hole_on = true;
		Level[6][1][8].hole_on = true;

		Level[6][2][0].hole_on = true;
		Level[6][2][1].hole_on = true;
		Level[6][2][2].hole_on = true;
		Level[6][2][3].hole_on = true;
		Level[6][2][8].hole_on = true;

		Level[6][3][5].hole_on = true;
		Level[6][3][6].hole_on = true;
		Level[6][3][7].hole_on = true;

		Level[6][4][1].hole_on = true;
		Level[6][4][2].hole_on = true;
		Level[6][4][3].hole_on = true;
		Level[6][4][4].hole_on = true;
		Level[6][4][5].hole_on = true;
		Level[6][4][7].hole_on = true;
		Level[6][4][8].hole_on = true;
		Level[6][4][9].hole_on = true;

		Level[6][5][1].hole_on = true;
		Level[6][5][6].hole_on = true;

		Level[6][6][1].hole_on = true;
		Level[6][6][3].hole_on = true;
		Level[6][6][4].hole_on = true;
		Level[6][6][5].hole_on = true;
		Level[6][6][6].hole_on = true;
		Level[6][6][7].hole_on = true;
		Level[6][6][8].hole_on = true;
		Level[6][6][9].hole_on = true;

		Level[6][7][1].hole_on = true;

		Level[6][8][1].hole_on = true;
		Level[6][8][2].hole_on = true;
		Level[6][8][3].hole_on = true;
		Level[6][8][4].hole_on = true;
		Level[6][8][5].hole_on = true;
		Level[6][8][6].hole_on = true;
		Level[6][8][7].hole_on = true;
		Level[6][8][8].hole_on = true;
		}

		//壁
		{
			Level[6][1][6].block_on = true;
			Level[6][1][6].blockonly_on = true;

			Level[6][0][3].block_on = true;

			Level[6][1][4].block_on = true;

			Level[6][2][0].block_on = true;
			Level[6][2][3].block_on = true;
			Level[6][2][7].block_on = true;
			Level[6][2][8].block_on = true;

			Level[6][3][6].block_on = true;

			Level[6][4][2].block_on = true;
			Level[6][4][9].block_on = true;

			Level[6][5][1].block_on = true;
			Level[6][5][6].block_on = true;
			Level[6][5][7].block_on = true;

			Level[6][6][6].block_on = true;
			Level[6][6][9].block_on = true;

			Level[6][7][1].block_on = true;

			Level[6][8][2].block_on = true;
		}

		//階段
		{
			Level[6][5][9].kaidan_on = true;
		}

	}

	//レベル7
	{

		//氷床
		{
			Level[7][0][5].ice_on = true;
			Level[7][0][6].ice_on = true;
			Level[7][0][7].ice_on = true;
			Level[7][0][8].ice_on = true;

			Level[7][1][5].ice_on = true;

			Level[7][2][5].ice_on = true;
			Level[7][2][6].ice_on = true;
			Level[7][2][7].ice_on = true;
			Level[7][2][8].ice_on = true;
			Level[7][2][9].ice_on = true;

			Level[7][3][9].ice_on = true;

			Level[7][4][8].ice_on = true;
			Level[7][4][9].ice_on = true;

			Level[7][5][8].ice_on = true;

			Level[7][6][5].ice_on = true;
			Level[7][6][6].ice_on = true;
			Level[7][6][8].ice_on = true;

			Level[7][7][6].ice_on = true;
			Level[7][7][8].ice_on = true;

			Level[7][8][6].ice_on = true;
			Level[7][8][8].ice_on = true;

			Level[7][9][6].ice_on = true;
			Level[7][9][7].ice_on = true;
			Level[7][9][8].ice_on = true;
			Level[7][9][9].ice_on = true;
		}

		//感圧板
		{
			//壁
			Level[7][0][2].weightboard_map = true;
			Level[7][0][2].weightboard_linknumber[1] = 31;
			Level[7][0][2].weightboard_linkobject[1] = G_BLOCK;
			Level[7][0][2].weightboard_linknumber[2] = 32;
			Level[7][0][2].weightboard_linkobject[2] = G_BLOCK;
			Level[7][0][2].weightboard_linknumber[3] = 35;
			Level[7][0][2].weightboard_linkobject[3] = L_BLOCK;
			Level[7][0][2].weightboard_linknumber[4] = 46;
			Level[7][0][2].weightboard_linkobject[4] = L_BLOCK;
			Level[7][0][2].weightboard_count = 4;

			Level[7][4][7].weightboard_map = true;
			Level[7][4][7].weightboard_linknumber[1] = 19;
			Level[7][4][7].weightboard_linkobject[1] = L_BLOCK;
			Level[7][4][7].weightboard_linknumber[2] = 16;
			Level[7][4][7].weightboard_linkobject[2] = L_BLOCK;
			Level[7][4][7].weightboard_count = 2;

			Level[7][5][0].weightboard_map = true;
			Level[7][5][0].weightboard_linknumber[1] = 55;
			Level[7][5][0].weightboard_linkobject[1] = L_BLOCK;
			Level[7][5][0].weightboard_linknumber[2] = 67;
			Level[7][5][0].weightboard_linkobject[2] = L_BLOCK;
			Level[7][5][0].weightboard_count = 2;

			Level[7][5][2].weightboard_map = true;
			Level[7][5][2].weightboard_linknumber[1] = 85;
			Level[7][5][2].weightboard_linkobject[1] = L_BLOCK;
			Level[7][5][2].weightboard_linknumber[2] = 17;
			Level[7][5][2].weightboard_linkobject[2] = L_BLOCK;
			Level[7][5][2].weightboard_count = 2;

			Level[7][7][0].weightboard_map = true;
			Level[7][7][0].weightboard_linknumber[1] = 38;
			Level[7][7][0].weightboard_linkobject[1] = L_BLOCK;
			Level[7][7][0].weightboard_linknumber[2] = 45;
			Level[7][7][0].weightboard_linkobject[2] = L_BLOCK;
			Level[7][7][0].weightboard_linknumber[3] = 59;
			Level[7][7][0].weightboard_linkobject[3] = L_BLOCK;
			Level[7][7][0].weightboard_count = 3;

			Level[7][7][2].weightboard_map = true;
			Level[7][7][2].weightboard_linknumber[1] = 37;
			Level[7][7][2].weightboard_linkobject[1] = L_BLOCK;
			Level[7][7][2].weightboard_linknumber[2] = 69;
			Level[7][7][2].weightboard_linkobject[2] = L_BLOCK;
			Level[7][7][2].weightboard_linknumber[3] = 99;
			Level[7][7][2].weightboard_linkobject[3] = H_BLOCK;
			Level[7][7][2].weightboard_count = 3;

			Level[7][9][0].weightboard_map = true;
Level[7][9][0].weightboard_linknumber[1] = 36;
Level[7][9][0].weightboard_linkobject[1] = L_BLOCK;
Level[7][9][0].weightboard_linknumber[2] = 56;
Level[7][9][0].weightboard_linkobject[2] = L_BLOCK;
Level[7][9][0].weightboard_count = 2;

Level[7][9][2].weightboard_map = true;
Level[7][9][2].weightboard_linknumber[1] = 4;
Level[7][9][2].weightboard_linkobject[1] = L_BLOCK;
Level[7][9][2].weightboard_linknumber[2] = 24;
Level[7][9][2].weightboard_linkobject[2] = L_BLOCK;
Level[7][9][2].weightboard_linknumber[3] = 95;
Level[7][9][2].weightboard_linkobject[3] = L_BLOCK;
Level[7][9][2].weightboard_count = 3;
		}

		//穴
		{

		Level[7][0][4].hole_on = true;

		Level[7][1][4].hole_on = true;
		Level[7][1][6].hole_on = true;
		Level[7][1][7].hole_on = true;
		Level[7][1][8].hole_on = true;
		Level[7][1][9].hole_on = true;

		Level[7][2][4].hole_on = true;

		Level[7][3][0].hole_on = true;
		Level[7][3][1].hole_on = true;
		Level[7][3][2].hole_on = true;
		Level[7][3][3].hole_on = true;
		Level[7][3][4].hole_on = true;
		Level[7][3][5].hole_on = true;
		Level[7][3][6].hole_on = true;
		Level[7][3][7].hole_on = true;
		Level[7][3][8].hole_on = true;

		Level[7][4][5].hole_on = true;
		Level[7][4][6].hole_on = true;

		Level[7][5][5].hole_on = true;
		Level[7][5][6].hole_on = true;
		Level[7][5][7].hole_on = true;
		Level[7][5][9].hole_on = true;

		Level[7][6][7].hole_on = true;
		Level[7][6][9].hole_on = true;

		Level[7][7][5].hole_on = true;
		Level[7][7][7].hole_on = true;
		Level[7][7][9].hole_on = true;

		Level[7][8][5].hole_on = true;
		Level[7][8][7].hole_on = true;
		Level[7][8][9].hole_on = true;

		Level[7][9][5].hole_on = true;
		}

		//壁
		{
			Level[7][0][4].block_on = true;

			Level[7][1][6].block_on = true;
			Level[7][1][7].block_on = true;
			Level[7][1][9].block_on = true;

			Level[7][2][4].block_on = true;

			Level[7][3][1].block_on = true;
			Level[7][3][2].block_on = true;
			Level[7][3][5].block_on = true;
			Level[7][3][6].block_on = true;
			Level[7][3][7].block_on = true;
			Level[7][3][8].block_on = true;

			Level[7][4][5].block_on = true;
			Level[7][4][6].block_on = true;

			Level[7][5][5].block_on = true;
			Level[7][5][6].block_on = true;
			Level[7][5][9].block_on = true;

			Level[7][6][7].block_on = true;
			Level[7][6][9].block_on = true;

			Level[7][8][5].block_on = true;

			Level[7][9][5].block_on = true;
			Level[7][9][9].block_on = true;
		}

		//階段
		{
			Level[7][0][9].kaidan_on = true;
		}
	}

	//レベル8
	{
		//氷床
		{
			Level[8][0][2].ice_on = true;
			Level[8][0][3].ice_on = true;
			Level[8][0][4].ice_on = true;
			Level[8][0][5].ice_on = true;
			Level[8][0][6].ice_on = true;
			Level[8][0][8].ice_on = true;
			Level[8][0][9].ice_on = true;

			Level[8][1][2].ice_on = true;
			Level[8][1][3].ice_on = true;
			Level[8][1][4].ice_on = true;
			Level[8][1][5].ice_on = true;
			Level[8][1][6].ice_on = true;
			Level[8][1][7].ice_on = true;
			Level[8][1][8].ice_on = true;

			Level[8][2][0].ice_on = true;
			Level[8][2][1].ice_on = true;
			Level[8][2][5].ice_on = true;
			Level[8][2][6].ice_on = true;
			Level[8][2][7].ice_on = true;
			Level[8][2][8].ice_on = true;
			Level[8][2][9].ice_on = true;

			Level[8][3][0].ice_on = true;
			Level[8][3][3].ice_on = true;
			Level[8][3][4].ice_on = true;
			Level[8][3][5].ice_on = true;
			Level[8][3][6].ice_on = true;
			Level[8][3][7].ice_on = true;
			Level[8][3][8].ice_on = true;
			Level[8][3][9].ice_on = true;

			Level[8][4][0].ice_on = true;
			Level[8][4][1].ice_on = true;
			Level[8][4][2].ice_on = true;
			Level[8][4][3].ice_on = true;
			Level[8][4][6].ice_on = true;
			Level[8][4][7].ice_on = true;

			Level[8][5][0].ice_on = true;
			Level[8][5][1].ice_on = true;
			Level[8][5][2].ice_on = true;
			Level[8][5][3].ice_on = true;
			Level[8][5][6].ice_on = true;
			Level[8][5][7].ice_on = true;
			Level[8][5][8].ice_on = true;
			Level[8][5][9].ice_on = true;

			Level[8][6][0].ice_on = true;
			Level[8][6][1].ice_on = true;
			Level[8][6][2].ice_on = true;
			Level[8][6][3].ice_on = true;
			Level[8][6][4].ice_on = true;
			Level[8][6][5].ice_on = true;
			Level[8][6][6].ice_on = true;
			Level[8][6][7].ice_on = true;
			Level[8][6][8].ice_on = true;
			Level[8][6][9].ice_on = true;

			Level[8][7][1].ice_on = true;
			Level[8][7][2].ice_on = true;
			Level[8][7][3].ice_on = true;
			Level[8][7][4].ice_on = true;
			Level[8][7][5].ice_on = true;
			Level[8][7][6].ice_on = true;
			Level[8][7][7].ice_on = true;
			Level[8][7][8].ice_on = true;
			Level[8][7][9].ice_on = true;

			Level[8][8][0].ice_on = true;
			Level[8][8][1].ice_on = true;
			Level[8][8][2].ice_on = true;
			Level[8][8][4].ice_on = true;
			Level[8][8][6].ice_on = true;
			Level[8][8][7].ice_on = true;
			Level[8][8][8].ice_on = true;
			Level[8][8][9].ice_on = true;

			Level[8][9][0].ice_on = true;
			Level[8][9][2].ice_on = true;
			Level[8][9][3].ice_on = true;
			Level[8][9][5].ice_on = true;
			Level[8][9][6].ice_on = true;
			Level[8][9][7].ice_on = true;
			Level[8][9][8].ice_on = true;
		}

		//感圧板
		{
			//壁
			Level[8][0][7].weightboard_map = true;
			Level[8][0][7].weightboard_linknumber[1] = 2;
			Level[8][0][7].weightboard_linkobject[1] = L_BLOCK;
			Level[8][0][7].weightboard_linknumber[2] = 8;
			Level[8][0][7].weightboard_linkobject[2] = L_BLOCK;
			Level[8][0][7].weightboard_linknumber[3] = 67;
			Level[8][0][7].weightboard_linkobject[3] = H_BLOCK;
			Level[8][0][7].weightboard_linknumber[4] = 87;
			Level[8][0][7].weightboard_linkobject[4] = L_BLOCK;
			Level[8][0][7].weightboard_count = 4;

			Level[8][1][9].weightboard_map = true;
			Level[8][1][9].weightboard_linknumber[1] = 12;
			Level[8][1][9].weightboard_linkobject[1] = L_BLOCK;
			Level[8][1][9].weightboard_linknumber[2] = 59;
			Level[8][1][9].weightboard_linkobject[2] = L_BLOCK;
			Level[8][1][9].weightboard_count = 2;
			
			Level[8][2][3].weightboard_map = true;
			Level[8][2][3].weightboard_linknumber[1] = 31;
			Level[8][2][3].weightboard_linkobject[1] = H_BLOCK;
			Level[8][2][3].weightboard_linknumber[2] = 89;
			Level[8][2][3].weightboard_linkobject[2] = H_BLOCK;
			Level[8][2][3].weightboard_linknumber[3] = 98;
			Level[8][2][3].weightboard_linkobject[3] = H_BLOCK;
			Level[8][2][3].weightboard_linknumber[4] = 94;
			Level[8][2][3].weightboard_linkobject[4] = H_BLOCK;
			Level[8][2][3].weightboard_count = 4;

			Level[8][3][2].weightboard_map = true;
			Level[8][3][2].weightboard_linknumber[1] = 24;
			Level[8][3][2].weightboard_linkobject[1] = H_BLOCK;
			Level[8][3][2].weightboard_linknumber[2] = 79;
			Level[8][3][2].weightboard_linkobject[2] = H_BLOCK;
			Level[8][3][2].weightboard_linknumber[3] = 88;
			Level[8][3][2].weightboard_linkobject[3] = H_BLOCK;
			Level[8][3][2].weightboard_linknumber[4] = 97;
			Level[8][3][2].weightboard_linkobject[4] = H_BLOCK;
			Level[8][3][2].weightboard_count = 4;

			Level[8][4][8].weightboard_map = true;
			Level[8][4][8].weightboard_linknumber[1] = 50;
			Level[8][4][8].weightboard_linkobject[1] = L_BLOCK;
			Level[8][4][8].weightboard_count = 1;

			Level[8][7][0].weightboard_map = true;
			Level[8][7][0].weightboard_linknumber[1] = 20;
			Level[8][7][0].weightboard_linkobject[1] = L_BLOCK;
			Level[8][7][0].weightboard_linknumber[2] = 74;
			Level[8][7][0].weightboard_linkobject[2] = L_BLOCK;
			Level[8][7][0].weightboard_count = 2;

			Level[8][8][5].weightboard_map = true;
			Level[8][8][5].weightboard_linknumber[1] = 5;
			Level[8][8][5].weightboard_linkobject[1] = L_BLOCK;
			Level[8][8][5].weightboard_count = 1;

			Level[8][9][1].weightboard_map = true;
			Level[8][9][1].weightboard_linknumber[1] = 21;
			Level[8][9][1].weightboard_linkobject[1] = L_BLOCK;
			Level[8][9][1].weightboard_linknumber[2] = 37;
			Level[8][9][1].weightboard_linkobject[2] = L_BLOCK;
			Level[8][9][1].weightboard_count = 2;

			Level[8][9][9].weightboard_map = true;
			Level[8][9][9].weightboard_linknumber[1] = 64;
			Level[8][9][9].weightboard_linkobject[1] = H_BLOCK;
			Level[8][9][9].weightboard_linknumber[2] = 34;
			Level[8][9][9].weightboard_linkobject[2] = H_BLOCK;
			Level[8][9][9].weightboard_linknumber[3] = 35;
			Level[8][9][9].weightboard_linkobject[3] = H_BLOCK;
			Level[8][9][9].weightboard_linknumber[4] = 65;
			Level[8][9][9].weightboard_linkobject[4] = H_BLOCK;
			Level[8][9][9].weightboard_linknumber[5] = 43;
			Level[8][9][9].weightboard_linkobject[5] = H_BLOCK;
			Level[8][9][9].weightboard_linknumber[6] = 46;
			Level[8][9][9].weightboard_linkobject[6] = H_BLOCK;
			Level[8][9][9].weightboard_linknumber[7] = 53;
			Level[8][9][9].weightboard_linkobject[7] = H_BLOCK;
			Level[8][9][9].weightboard_linknumber[8] = 56;
			Level[8][9][9].weightboard_linkobject[8] = H_BLOCK;
			Level[8][9][9].weightboard_count = 8;
		}

		//穴
		{
			Level[8][2][4].hole_on = true;
			Level[8][3][1].hole_on = true;
			Level[8][9][4].hole_on = true;
		}

		//壁
		{
			Level[8][2][2].block_on = true;
			Level[8][2][2].blockonly_on = true;
			
			Level[8][4][9].block_on = true;
			Level[8][4][9].blockonly_on = true;
			
			Level[8][3][3].block_on = true;
			Level[8][3][3].blockonly_on = true;
			
			Level[8][3][6].block_on = true;
			Level[8][3][6].blockonly_on = true;
			
			Level[8][6][3].block_on = true;
			Level[8][6][3].blockonly_on = true;
			
			Level[8][6][6].block_on = true;
			Level[8][6][6].blockonly_on = true;

			Level[8][0][2].block_on = true;
			Level[8][0][5].block_on = true;
			Level[8][0][8].block_on = true;

			Level[8][1][2].block_on = true;

			Level[8][2][0].block_on = true;
			Level[8][2][1].block_on = true;
			Level[8][2][4].block_on = true;

			Level[8][3][1].block_on = true;
			Level[8][3][3].block_on = true;
			Level[8][3][4].block_on = true;
			Level[8][3][5].block_on = true;
			Level[8][3][6].block_on = true;
			Level[8][3][7].block_on = true;

			Level[8][4][3].block_on = true;
			Level[8][4][6].block_on = true;

			Level[8][5][0].block_on = true;
			Level[8][5][3].block_on = true;
			Level[8][5][6].block_on = true;
			Level[8][5][9].block_on = true;

			Level[8][6][3].block_on = true;
			Level[8][6][4].block_on = true;
			Level[8][6][5].block_on = true;
			Level[8][6][6].block_on = true;
			Level[8][6][7].block_on = true;

			Level[8][7][4].block_on = true;
			Level[8][7][9].block_on = true;

			Level[8][8][7].block_on = true;
			Level[8][8][8].block_on = true;
			Level[8][8][9].block_on = true;

			Level[8][9][4].block_on = true;
			Level[8][9][7].block_on = true;
			Level[8][9][8].block_on = true;
		}

		//階段
		{
			Level[8][5][5].kaidan_on = true;
		}
	}

	//レベル9
	{
		//氷床
		{
			for (int L = 3; L < 9; L++)
			{
				for (int R = 3 ; R < 9 ; R++)
				{
					if (L == 4 && R == 4)
					{
						continue;
					}
					Level[9][L][R].ice_on = true;
				}
			}
		}

		//感圧板
		{
			//壁
			Level[9][0][2].weightboard_map = true;
			Level[9][0][2].weightboard_linknumber[1] = 13;
			Level[9][0][2].weightboard_linkobject[1] = G_BLOCK;
			Level[9][0][2].weightboard_count = 1;

			Level[9][0][5].weightboard_map = true;
			Level[9][0][5].weightboard_linknumber[1] = 28;
			Level[9][0][5].weightboard_linkobject[1] = G_BLOCK;
			Level[9][0][5].weightboard_linknumber[2] = 32;
			Level[9][0][5].weightboard_linkobject[2] = L_BLOCK;
			Level[9][0][5].weightboard_count = 2;

			Level[9][0][7].weightboard_map = true;
			Level[9][0][7].weightboard_linknumber[1] = 38;
			Level[9][0][7].weightboard_linkobject[1] = L_BLOCK;
			Level[9][0][7].weightboard_linknumber[2] = 89;
			Level[9][0][7].weightboard_linkobject[2] = L_BLOCK;
			Level[9][0][7].weightboard_linknumber[3] = 95;
			Level[9][0][7].weightboard_linkobject[3] = L_BLOCK;
			Level[9][0][7].weightboard_count = 3;

			Level[9][0][9].weightboard_map = true;
			Level[9][0][9].weightboard_linknumber[1] = 52;
			Level[9][0][9].weightboard_linkobject[1] = G_BLOCK;
			Level[9][0][9].weightboard_count = 1;

			Level[9][2][0].weightboard_map = true;
			Level[9][2][0].weightboard_linknumber[1] = 31;
			Level[9][2][0].weightboard_linkobject[1] = G_BLOCK;
			Level[9][2][0].weightboard_count = 1;

			Level[9][5][0].weightboard_map = true;
			Level[9][5][0].weightboard_linknumber[1] = 23;
			Level[9][5][0].weightboard_linkobject[1] = L_BLOCK;
			Level[9][5][0].weightboard_linknumber[2] = 82;
			Level[9][5][0].weightboard_linkobject[2] = G_BLOCK;
			Level[9][5][0].weightboard_count = 2;

			Level[9][7][0].weightboard_map = true;
			Level[9][7][0].weightboard_linknumber[1] = 59;
			Level[9][7][0].weightboard_linkobject[1] = L_BLOCK;
			Level[9][7][0].weightboard_linknumber[2] = 98;
			Level[9][7][0].weightboard_linkobject[2] = L_BLOCK;
			Level[9][7][0].weightboard_linknumber[3] = 83;
			Level[9][7][0].weightboard_linkobject[3] = L_BLOCK;
			Level[9][7][0].weightboard_count = 3;

			Level[9][9][0].weightboard_map = true;
			Level[9][9][0].weightboard_linknumber[1] = 25;
			Level[9][9][0].weightboard_linkobject[1] = G_BLOCK;
			Level[9][9][0].weightboard_count = 1;

			Level[9][4][4].weightboard_map = true;
			Level[9][4][4].weightboard_linknumber[1] = 46;
			Level[9][4][4].weightboard_linkobject[1] = L_BLOCK;
			Level[9][4][4].weightboard_linknumber[2] = 64;
			Level[9][4][4].weightboard_linkobject[2] = L_BLOCK;
			Level[9][4][4].weightboard_count = 2;
		}

		//穴
		{
			Level[9][0][3].hole_on = true;

			Level[9][1][3].hole_on = true;

			Level[9][2][2].hole_on = true;
			Level[9][2][3].hole_on = true;
			Level[9][2][4].hole_on = true;
			Level[9][2][5].hole_on = true;
			Level[9][2][6].hole_on = true;
			Level[9][2][7].hole_on = true;
			Level[9][2][8].hole_on = true;
			Level[9][2][9].hole_on = true;

			Level[9][3][0].hole_on = true;
			Level[9][3][1].hole_on = true;
			Level[9][3][2].hole_on = true;
			Level[9][3][9].hole_on = true;
			
			Level[9][4][2].hole_on = true;
			Level[9][4][9].hole_on = true;

			Level[9][5][2].hole_on = true;
			Level[9][5][9].hole_on = true;

			Level[9][6][2].hole_on = true;
			Level[9][6][9].hole_on = true;

			Level[9][7][2].hole_on = true;
			Level[9][7][9].hole_on = true;

			Level[9][8][2].hole_on = true;
			Level[9][8][9].hole_on = true;

			Level[9][9][2].hole_on = true;
			Level[9][9][3].hole_on = true;
			Level[9][9][4].hole_on = true;
			Level[9][9][5].hole_on = true;
			Level[9][9][6].hole_on = true;
			Level[9][9][7].hole_on = true;
			Level[9][9][8].hole_on = true;
			Level[9][9][9].hole_on = true;
		}

		//壁
		{
			Level[9][1][3].block_on = true;

			Level[9][2][3].block_on = true;
			Level[9][2][5].block_on = true;
			Level[9][2][8].block_on = true;

			Level[9][3][1].block_on = true;
			Level[9][3][2].block_on = true;
			Level[9][3][8].block_on = true;

			Level[9][4][6].block_on = true;

			Level[9][5][2].block_on = true;
			Level[9][5][9].block_on = true;

			Level[9][6][4].block_on = true;

			Level[9][8][2].block_on = true;
			Level[9][8][3].block_on = true;
			Level[9][8][9].block_on = true;

			Level[9][9][5].block_on = true;
			Level[9][9][8].block_on = true;
		}
		//階段
		{
			Level[9][7][7].kaidan_on = true;
		}
	}

	StageOrder[0] = {0};
	StageOrder[1] = {1};
	StageOrder[2] = {7};
	StageOrder[3] = {3};
	StageOrder[4] = {2};
	StageOrder[5] = {4};
	StageOrder[6] = {8};
	StageOrder[7] = {9};
	StageOrder[8] = {5};
	StageOrder[9] = {6};
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
				mapdata[L][R].ice_on = Level[StageOrder[game->Level]][L][R].ice_on;

				//壁
				mapdata[L][R].block_on = Level[StageOrder[game->Level]][L][R].block_on;
				mapdata[L][R].blockonly_on = Level[StageOrder[game->Level]][L][R].blockonly_on;

				//落とし穴
				mapdata[L][R].hole_on = Level[StageOrder[game->Level]][L][R].hole_on;

				//感圧板
				mapdata[L][R].weightboard_map = Level[StageOrder[game->Level]][L][R].weightboard_map;

				//階段
				mapdata[L][R].kaidan_on = Level[StageOrder[game->Level]][L][R].kaidan_on;
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
				if (mapdata[L][R].hole_on == true)
				{
					mapdata[L][R].grounddata = HOLE;
					mapdata[L][R].hole_on = false;
					Map_SetGround[L][R] = true;
				}else {
				//氷
				if (mapdata[L][R].ice_on == true)
				{
					map.Ice->IceFloor_on[L][R] = true;
					mapdata[L][R].ice_on = false;
					map.Ice->IceFloor_P[L][R] = Ground_P[L][R];
					map.Ice->IceFloor_P[L][R].y -= 50.0f;
					mapdata[L][R].grounddata = ICE;
					Map_SetGround[L][R] = true;
				}else {
				//破壊床
				if (mapdata[L][R].breakfloar_on == true)
				{
					map.Breakfloar->Break_on[L][R] = true;
					mapdata[L][R].breakfloar_on = false;
					map.Breakfloar->BreakFloar_P[L][R] = Ground_P[L][R];
					mapdata[L][R].grounddata = BREAKFLOOR;
					Map_SetGround[L][R] = true;
				}else {
				//床
					map.Ground->Ground_on[L][R] = true;
					map.Ground->Ground_P[L][R] = Ground_P[L][R];
					map.Ground->Ground_P[L][R].y -= 50.0f;
					mapdata[L][R].grounddata = GROUND;
					Map_SetGround[L][R] = true;
					Count++;
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
					if (Level[StageOrder[game->Level]][L][R].weightboard_count > 0)
					{
						for (int W = 1; W < Level[StageOrder[game->Level]][L][R].weightboard_count + 1; W++)
						{
							map.Weightboard->Link_Number[L][R][W] = Level[StageOrder[game->Level]][L][R].weightboard_linknumber[W];
							map.Weightboard->Link[L][R][W] = Level[StageOrder[game->Level]][L][R].weightboard_linkobject[W];
						}
						map.Weightboard->Link_Count[L][R] = Level[StageOrder[game->Level]][L][R].weightboard_count;
					}

					mapdata[L][R].weightboard_map = false;
					map.Weightboard->WeightBoard_on[L][R] = true;
					map.Weightboard->Weightboard_P[L][R] = Ground_P[L][R];
					map.Weightboard->Weightboard_P[L][R].y = -20.0f;
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

	wchar_t clock[256];
	swprintf_s(clock, 256, L"地面の呼び出し数:%d", Count);
	Count_F.SetText(clock);
	Count_F.SetPosition(Vector3(-852.0f, 350.0f, 0.0f));
	Count_F.SetScale(1.0f);

}

void Stage::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
	Kabe.Draw(rc);
	//Count_F.Draw(rc);
}