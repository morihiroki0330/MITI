#pragma once

class Player;
class IronBall;
class G_Tekyu;

class G_WeightBoard:public IGameObject
{
	public:
		G_WeightBoard();
		~G_WeightBoard();

		void Update();
		void Render(RenderContext& rc);

		Vector3 position;
		ModelRender m_modelRender;
		PhysicsStaticObjectPos m_physicsStaticObjectpos;

		Player* player;
		IronBall* ironBall;
		G_Tekyu* g_tekyu;

		//��ɉ�������Ă�t���O
		bool putFlag;

		AllLight boardLight;
};

