#pragma once

class Player;
class G_BreakFloar :public IGameObject
{
public:
	G_BreakFloar();
	~G_BreakFloar();
	void Update();
	void Render(RenderContext& rc);

	Vector3 BreakFloar_P[10][10];
	ModelRender BreakFloar[10][10];
	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];
	AllLight Light;
	bool Break_on[10][10];

	Player* player;
};

