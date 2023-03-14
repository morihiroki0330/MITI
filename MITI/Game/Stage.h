#pragma once
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();

	void Render(RenderContext& rc);

	ModelRender m_modelRender;
	PhysicsStaticObject m_physicsStaticObject;
	float stageID[10][10];
};

