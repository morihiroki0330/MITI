#pragma once
class G_BreakFloar :public IGameObject
{
public:
	G_BreakFloar();
	~G_BreakFloar();

	void Update();
	void Render(RenderContext& rc);

	Vector3 position;
	ModelRender m_modelRender;
	PhysicsStaticObjectPos m_physicsStaticObjectpos;
};

