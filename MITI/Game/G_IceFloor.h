#pragma once

class Player;

class G_IceFloor:public IGameObject
{
public:
	G_IceFloor();
	~G_IceFloor();

	void Update();
	void Render(RenderContext& rc);

	Vector3 position;
	ModelRender m_modelRender;
	//ModelRender m_hitModelRender;
	PhysicsStaticObjectPos m_physicsStaticObjectpos;

	bool SlipFlag = false;

	Player* player;
};

