#pragma once

class Player;
class IronBall;
class G_Tekyu;
class G_Block;

class G_WeightBoard:public IGameObject
{
	public:
		G_WeightBoard();
		~G_WeightBoard();

		void Update();
		void Render(RenderContext& rc);

		Vector3 position[10][10];
		ModelRender m_modelRender[10][10];
		PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];

		Player* player;
		IronBall* ironBall;
		G_Tekyu* g_tekyu;
		G_Block* block;

		//��ɉ�������Ă�t���O
		bool putFlag[10][10];

		AllLight boardLight;

		bool WeightBoard_on[10][10];
		//1.�s�@2.��@3.�s��
		int link_number[10][10][10];
		int link_count[10][10];
		int Link[10][10][10];

		bool link;
		bool block_link;
};

