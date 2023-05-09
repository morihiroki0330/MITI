#pragma once
class G_Hole : public IGameObject
{
public:
	G_Hole();
	~G_Hole();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Hole;
	Vector3 Hole_P;
	PhysicsStaticObjectPos m_physicsStaticObjectpos;

	bool Hole_on;

	AllLight Hole_L;
};
