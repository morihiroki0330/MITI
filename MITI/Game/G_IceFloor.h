#pragma once

class Player;

class G_IceFloor:public IGameObject
{
public:
	G_IceFloor();
	~G_IceFloor();

	void Update();
	void Render(RenderContext& rc);

	Vector3 position[10][10];
	ModelRender m_modelRender[10][10];
	//ModelRender m_hitModelRender;
	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];

	bool ice_on[10][10];

	bool SlipFlag = false;

	Player* player;

	AllLight icefloorLight;
};

