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
	//�R�����g�A�E�g����B
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	/*m_modelRender.Init("Assets/modelData/stage.tkm",stageLight);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());*/

	Kabe.Init("Assets/test/hekiga.tkm", stageLight);
	Kabe_P = { 0.0f,82.0f,0.0f };
	k_physicsStaticObjectpos.CreateFromModel(Kabe.GetModel(), Kabe.GetModel().GetWorldMatrix());
	Kabe.Update();
	Kabe.SetPosition(Kabe_P);

	//�X��
	{
		ice_create = true;
		{
			//��s��
			mapdata[0][4].ice_on = true;
			mapdata[0][6].ice_on = true;
			mapdata[0][7].ice_on = true;
		}
		{
			//��s��
			mapdata[1][5].ice_on = true;
			mapdata[1][6].ice_on = true;
			mapdata[1][7].ice_on = true;
		}
		{
			//�O�s��
			mapdata[2][4].ice_on = true;
			mapdata[2][5].ice_on = true;
			mapdata[2][7].ice_on = true;
			mapdata[2][8].ice_on = true;
		}
		{
			//�l�s��
			mapdata[3][4].ice_on = true;
			mapdata[3][5].ice_on = true;
			mapdata[3][7].ice_on = true;
			mapdata[3][8].ice_on = true;
		}
		{
			//�܍s��
			mapdata[4][4].ice_on = true;
			mapdata[4][5].ice_on = true;
			mapdata[4][8].ice_on = true;
		}
		{
			//�Z�s��
			mapdata[5][4].ice_on = true;
			mapdata[5][7].ice_on = true;
			mapdata[5][8].ice_on = true;
		}
		{
			//���s��
			mapdata[6][4].ice_on = true;
			mapdata[6][5].ice_on = true;
			mapdata[6][6].ice_on = true;
			mapdata[6][8].ice_on = true;
		}
		{
			//���s��
			mapdata[7][4].ice_on = true;
			mapdata[7][7].ice_on = true;
			mapdata[7][8].ice_on = true;
		}
		{
			//��s��
			mapdata[8][4].ice_on = true;
			mapdata[8][6].ice_on = true;
			mapdata[8][7].ice_on = true;
		}
		{
			//�\�s��
			mapdata[9][4].ice_on = true;
			mapdata[9][5].ice_on = true;
			mapdata[9][6].ice_on = true;
			mapdata[9][7].ice_on = true;
			mapdata[9][8].ice_on = true;
		}
	}

	//��
	{
		block_create = true;

		//��s��
		mapdata[0][5].block_on = true;
		mapdata[0][8].block_on = true;

		//��s��
		mapdata[1][4].block_on = true;
		mapdata[1][8].block_on = true;

		//�O�s��
		mapdata[2][6].block_on = true;

		//�l�s��
		mapdata[3][6].block_on = true;
		mapdata[3][9].block_on = true;

		//�܍s��
		mapdata[4][6].block_on = true;
		mapdata[4][7].block_on = true;

		//�Z�s��
		mapdata[5][5].block_on = true;
		mapdata[5][6].block_on = true;

		//���s��

		mapdata[6][7].block_on = true;

		//���s��
		mapdata[7][5].block_on = true;
		mapdata[7][6].block_on = true;
		mapdata[7][9].block_on = true;

		//��s��
		mapdata[8][5].block_on = true;
		mapdata[8][8].block_on = true;
		mapdata[8][9].block_on = true;

		//�\�s��
		mapdata[9][6].block_on = true;

	}

	//���Ƃ���
	{
		hole_create = true;

		/*for (int L = 0; L < 10; L++)
		{
			for (int R = 0; R < 10; R++)
			{
				mapdata[L][R].hole_on = true;
			}
		}*/
		//��s��
		mapdata[0][5].hole_on = true;
		mapdata[0][8].hole_on = true;

		//��s��
		mapdata[1][4].hole_on = true;
		mapdata[1][8].hole_on = true;

		//�O�s��
		mapdata[2][6].hole_on = true;

		//�l�s��
		mapdata[3][6].hole_on = true;
		mapdata[3][9].hole_on = true;

		//�܍s��
		mapdata[4][6].hole_on = true;
		mapdata[4][7].hole_on = true;

		//�Z�s��
		mapdata[5][5].hole_on = true;
		mapdata[5][6].hole_on = true;

		//���s��
		//mapdata[6][7].hole_on = true;

		//���s��
		mapdata[7][5].hole_on = true;
		mapdata[7][6].hole_on = true;
		mapdata[7][9].hole_on = true;

		//��s��
		mapdata[8][5].hole_on = true;
		mapdata[8][8].hole_on = true;
		mapdata[8][9].hole_on = true;

		//�\�s��
		mapdata[9][6].hole_on = true;

	}

	//������
	{
		weightboard_create = true;

		mapdata[0][9].weightboard_map = true;

		mapdata[1][2].weightboard_map = true;
		mapdata[1][2].weightboard_block_link = true;
		//���
		mapdata[1][2].weightboard_block_map[0][0] = 4;
		mapdata[1][2].weightboard_block_map[0][1] = 7;
		//���
		mapdata[1][2].weightboard_block_map[1][0] = 5;
		mapdata[1][2].weightboard_block_map[1][1] = 5;
		//�O��
		mapdata[1][2].weightboard_block_map[2][0] = 5;
		mapdata[1][2].weightboard_block_map[2][1] = 6;

		mapdata[3][0].weightboard_map = true;

		mapdata[3][2].weightboard_map = true;
		mapdata[3][2].weightboard_block_link = true;
		//���
		mapdata[3][2].weightboard_block_map[0][0] = 0;
		mapdata[3][2].weightboard_block_map[0][1] = 8;
		//���
		mapdata[3][2].weightboard_block_map[1][0] = 4;
		mapdata[3][2].weightboard_block_map[1][1] = 6;
		//�O��
		mapdata[3][2].weightboard_block_map[2][0] = 8;
		mapdata[3][2].weightboard_block_map[2][1] = 8;

		mapdata[5][0].weightboard_map = true;
		mapdata[5][2].weightboard_map = true;

		mapdata[7][0].weightboard_map = true;
		mapdata[7][0].weightboard_block_link = true;
		//���
		mapdata[7][0].weightboard_block_map[0][0] = 1;
		mapdata[7][0].weightboard_block_map[0][1] = 4;
		//���
		mapdata[7][0].weightboard_block_map[1][0] = 1;
		mapdata[7][0].weightboard_block_map[1][1] = 8;
		//�O��
		mapdata[7][0].weightboard_block_map[2][0] = 7;
		mapdata[7][0].weightboard_block_map[2][1] = 9;


		mapdata[7][2].weightboard_map = true;
		mapdata[7][2].weightboard_block_link = true;
		//���
		mapdata[7][2].weightboard_block_map[0][0] = 0;
		mapdata[7][2].weightboard_block_map[0][1] = 5;
		//���
		mapdata[7][2].weightboard_block_map[1][0] = 7;
		mapdata[7][2].weightboard_block_map[1][1] = 5;
		//�O��
		mapdata[7][2].weightboard_block_map[2][0] = 9;
		mapdata[7][2].weightboard_block_map[2][1] = 6;

		mapdata[9][0].weightboard_map = true;

		mapdata[9][2].weightboard_map = true;
		mapdata[9][2].weightboard_block_link = true;
		//���
		mapdata[9][2].weightboard_block_map[0][0] = 3;
		mapdata[9][2].weightboard_block_map[0][1] = 9;
		//���
		mapdata[9][2].weightboard_block_map[1][0] = 8;
		mapdata[9][2].weightboard_block_map[1][1] = 5;
		//�O��
		mapdata[9][2].weightboard_block_map[2][0] = 7;
		mapdata[9][2].weightboard_block_map[2][1] = 6;
	}

	//�K�i
	{
		kaidan_create = true;
		mapdata[9][9].kaidan_on = true;
	}

	//�n��
	{
		ground_create = true;
	}

//���W�̐ݒ�
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			Ground_P[L][R].x = (L * 192.0f) + -874.0f;
			Ground_P[L][R].y = 0.0f;
			Ground_P[L][R].z = (R * 192.0f) + -865.0f;
		}
	}

//�X�e�[�W����
	{
	//�n�ʂ̐����y���E�X�E���E�j�󏰁z
		//��
		if (hole_create == true)
		{
			map.Hole = NewGO<G_Hole>(0, "hole");
			hole_create = false;
		}
		//�X
		if (ice_create == true)
		{
			map.Ice = NewGO<G_IceFloor>(0, "ice");
			ice_create = false;
		}
		//��
		if (ground_create == true)
		{
			map.Ground = NewGO<G_Ground>(0, "ground");
			ground_create = false;
		}
		//�j��
		if (break_create == true)
		{
			map.Breakfloar = NewGO<G_BreakFloar>(0, "break");
			break_create = false;
		}

	//����̐ݒu���y�S�[���p�̊K�i�E�����E��ǃu���b�N�E�S�[������̔��z
		//�S�[���p�̊K�i
		if (kaidan_create == true)
		{
			map.Kaidan = NewGO<G_Kaidan>(0, "kaidan");
			kaidan_create = false;
		}
		//������
		if (weightboard_create == true)
		{
			map.Weightboard = NewGO<G_WeightBoard>(0, "weightboard");
			weightboard_create = false;
		}
		//��ǃu���b�N
		if (block_create == true)
		{
			map.Block = NewGO<G_Block>(0, "block");
			block_create = false;
		}
		//�S�[������̔�
		if (wall_create == true)
		{
			map.Wall = NewGO<G_Wall>(0, "wall");
			wall_create = false;
		}
	}

//�ݒ�
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{

		//�n�ʂ̐ݒ�y���E�X�E���E�j�󏰁z
		//��
		if (mapdata[L][R].hole_on == true)
		{
			map.Hole->Hole_on[L][R] = true;
			map.Hole->Hole_P[L][R] = Ground_P[L][R];
			map.Hole->Hole_P[L][R].y = -120.0f;
		}else {
		//�X
		if (mapdata[L][R].ice_on == true)
		{
			map.Ice->ice_on[L][R] = true;
			map.Ice->position[L][R] = Ground_P[L][R];
			map.Ice->position[L][R].y = -20.0f;
		}else {
		//�j��
		if (mapdata[L][R].breakfloar_on == true)
		{
			map.Breakfloar->break_on[L][R] = true;
			map.Breakfloar->position[L][R] = Ground_P[L][R];
		}else {
		//��
			map.Ground->Ground_on[L][R] = true;
			map.Ground->Ground_P[L][R] = Ground_P[L][R];
		}
		}
		}

		//����̐ݒu���y�S�[���p�̊K�i�E�����E��ǃu���b�N�E�S�[������̔��z
		//�S�[���p�̊K�i
		if (mapdata[L][R].kaidan_on == true)
		{
			map.Kaidan->Kaidan_P = Ground_P[L][R];
			map.Kaidan->Kaidan_P.y = 120.0f;
		}else {
		//������
		if (mapdata[L][R].weightboard_map == true)
		{
			map.Weightboard->WeightBoard_on[L][R] = true;
			map.Weightboard->position[L][R] = Ground_P[L][R];
		}else {
		//��ǃu���b�N
		if (mapdata[L][R].block_on == true)
		{
			map.Block->Block_on[L][R] = true;
			map.Block->Block_P[L][R] = Ground_P[L][R];
			map.Block->Block_P[L][R].y = 200.0f;
		}else {
		//�S�[������̔�
			/*map.Ground->Ground_on[L][R] = true;
			map.Ground->Ground_P[L][R] = Ground_P[L][R];*/
		}
		}
		}
		
		
		////������
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
			////�X�̏�
			//if (mapdata[L][R].ice_on == true)
			//{

			//	mapdata[L][R].ice = NewGO<G_IceFloor>(0);
			//	mapdata[L][R].ice->position = Ground_P[L][R];
			//	mapdata[L][R].ice->position.y = -20.0f;

			//}
			//else {
			//	//���Ƃ���
			//	if (mapdata[L][R].hole_on == true)
			//	{

			//	}
			//	else {
			//������
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

	//		//��
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