#pragma once

class Player;

class G_BreakFloar :public IGameObject
{
public:
	G_BreakFloar();
	~G_BreakFloar();

	void Update();
	void Render(RenderContext& rc);

	Vector3 position[10][10];
	ModelRender m_modelRender[10][10];
	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];
	bool break_on[10][10];

	Player* player;

	AllLight breakLight;
};

