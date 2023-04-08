#pragma once

class Player;

class G_BreakFloar :public IGameObject
{
public:
	G_BreakFloar();
	~G_BreakFloar();

	void Update();
	void Render(RenderContext& rc);

	Vector3 position;
	ModelRender m_modelRender;
	//ModelRender m_hitModelRender;
	PhysicsStaticObjectPos m_physicsStaticObjectpos;

	Player* player;
};

