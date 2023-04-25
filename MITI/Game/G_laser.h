#pragma once

class G_laser :public IGameObject
{
public:
	G_laser();
	~G_laser();

	void Update();
	void Render(RenderContext& rc);

	Vector3 position;
	ModelRender m_modelRender;
	PhysicsStaticObjectPos m_physicsStaticObjectpos;

	//Player* player;

	AllLight laserLight;
};

