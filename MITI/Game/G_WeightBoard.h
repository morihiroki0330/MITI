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

		Vector3 position[10][10];
		ModelRender m_modelRender[10][10];
		PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];

		Player* player;
		IronBall* ironBall;
		G_Tekyu* g_tekyu;

		//è„Ç…âΩÇ©èÊÇ¡ÇƒÇÈÉtÉâÉO
		bool putFlag;

		AllLight boardLight;

		bool WeightBoard_on[10][10];
};

