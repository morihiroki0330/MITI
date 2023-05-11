#pragma once
class G_Ground : public IGameObject
{
public:
	G_Ground();
	~G_Ground();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Ground[10][10];
	Vector3 Ground_P[10][10];
	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];

	bool Ground_on[10][10];

	AllLight Light;
};

