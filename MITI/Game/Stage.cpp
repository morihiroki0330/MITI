#include "stdafx.h"
#include "Stage.h"

#include "G_IceFloor.h"
#include "G_BreakFloar.h"
#include "G_WeightBoard.h"
#include "G_Wall.h"
#include "Hole.h"

Stage::Stage()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	/*m_modelRender.Init("Assets/modelData/stage.tkm",stageLight);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());*/

	Kabe.Init("Assets/modelData/hekiga.tkm", stageLight);
	Kabe_P = { 0.0f,82.0f,0.0f };
	k_physicsStaticObjectpos.CreateFromModel(Kabe.GetModel(), Kabe.GetModel().GetWorldMatrix());
	Kabe.Update();
	Kabe.SetPosition(Kabe_P);

	//氷床
	{
		{
			//一行目
			map[0][4].ice_on = true;
			map[0][6].ice_on = true;
			map[0][7].ice_on = true;
		}
		{
			//二行目
			map[1][5].ice_on = true;
			map[1][6].ice_on = true;
			map[1][7].ice_on = true;
		}
		{
			//三行目
			map[2][4].ice_on = true;
			map[2][5].ice_on = true;
			map[2][7].ice_on = true;
			map[2][8].ice_on = true;
		}
		{
			//四行目
			map[3][4].ice_on = true;
			map[3][5].ice_on = true;
			map[3][7].ice_on = true;
			map[3][8].ice_on = true;
		}
		{
			//五行目
			map[4][4].ice_on = true;
			map[4][5].ice_on = true;
			map[4][8].ice_on = true;
		}
		{
			//六行目
			map[5][4].ice_on = true;
			map[5][7].ice_on = true;
			map[5][8].ice_on = true;
		}
		{
			//七行目
			map[6][4].ice_on = true;
			map[6][5].ice_on = true;
			map[6][6].ice_on = true;
			map[6][7].ice_on = true;
			map[6][8].ice_on = true;
		}
		{
			//八行目
			map[7][4].ice_on = true;
			map[7][5].ice_on = true;
			map[7][6].ice_on = true;
			map[7][7].ice_on = true;
		}
		{
			//九行目
			map[8][4].ice_on = true;
			map[8][6].ice_on = true;
			map[8][7].ice_on = true;
		}
		{
			//十行目
			map[9][4].ice_on = true;
			map[9][5].ice_on = true;
			map[9][7].ice_on = true;
			map[9][8].ice_on = true;
		}
	}

	//落とし穴
	{
		//一行目
		map[0][5].hole_on = true;
		map[0][8].hole_on = true;

		//二行目
		map[1][4].hole_on = true;
		map[1][8].hole_on = true;

		//三行目
		map[2][6].hole_on = true;

		//四行目
		map[3][6].hole_on = true;
		map[3][9].hole_on = true;

		//五行目
		map[4][6].hole_on = true;
		map[4][7].hole_on = true;

		//六行目
		map[5][5].hole_on = true;
		map[5][6].hole_on = true;

		//七行目


		//八行目
		map[7][5].hole_on = true;
		map[7][9].hole_on = true;

		//九行目
		map[8][5].hole_on = true;
		map[8][8].hole_on = true;
		map[8][9].hole_on = true;

		//十行目
		map[9][6].hole_on = true;

	}

	//感圧板
	{
		map[1][2].weightboard_on = true;

		map[3][0].weightboard_on = true;
		map[3][2].weightboard_on = true;
		
		map[5][0].weightboard_on = true;
		map[5][2].weightboard_on = true;
		
		map[7][0].weightboard_on = true;
		map[7][2].weightboard_on = true;
		
		map[9][0].weightboard_on = true;
		map[9][2].weightboard_on = true;

	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Ground_P[i][j].x = (i * 190.0f) + -874.0f;
			Ground_P[i][j].y = 0.0f;
			Ground_P[i][j].z = (j * 190.0f) + -865.0f;

			//氷の床
			if (map[i][j].ice_on == true)
			{

				map[i][j].ice = NewGO<G_IceFloor>(0);
				map[i][j].ice->position = Ground_P[i][j];
				map[i][j].ice->position.y = -20.0f;

			}else {
			//落とし穴
			if (map[i][j].hole_on == true)
			{

			}else {

			if (map[i][j].weightboard_on == true)
			{
				map[i][j].weightboard = NewGO<G_WeightBoard>(0);
				map[i][j].weightboard->position = Ground_P[i][j];
				map[i][j].weightboard->position.y = -20.0f;
				Ground[i][j].Init("Assets/modelData/ground.tkm", stageLight);
				Ground[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].Update();
			}else {
				Ground[i][j].Init("Assets/modelData/ground.tkm", stageLight);
				g_physicsStaticObjectpos[i][j].CreateFromModel(Ground[i][j].GetModel(), Ground[i][j].GetModel().GetWorldMatrix());
				g_physicsStaticObjectpos[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].SetPosition(Ground_P[i][j]);
				Ground[i][j].Update();
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
			if (map[i][j].ice_on == true)
			{
				DeleteGO(map[i][j].ice);
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