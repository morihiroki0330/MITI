#pragma once

class G_WeightBoard;

class G_Wall:public IGameObject
{
public:
	G_Wall();
	~G_Wall();

	void Update();
	void Render(RenderContext& rc);

	Vector3 position;
	ModelRender m_modelRender;
	PhysicsStaticObjectPos m_physicsStaticObjectpos;

	G_WeightBoard* g_weightBoard;
};

