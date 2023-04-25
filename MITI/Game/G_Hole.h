#pragma once
class G_Hole : public IGameObject
{
public:
	G_Hole();
	~G_Hole();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Hole[10][10];
	Vector3 Hole_P[10][10];
	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];

	bool Hole_on[10][10];

	AllLight Hole_L;
};

