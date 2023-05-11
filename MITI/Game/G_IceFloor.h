#pragma once

class Player;
class Stage;
class G_IceFloor:public IGameObject
{
public:
	G_IceFloor();
	~G_IceFloor();

	void Update();
	void Render(RenderContext& rc);


	Vector3 IceFloor_P[10][10];
	ModelRender IceFloor[10][10];
	PhysicsStaticObjectPos m_physicsStaticObjectpos[10][10];
	AllLight Light;

	bool IceFloor_on[10][10];

	Player* player;
	Stage* stage;
	
};

