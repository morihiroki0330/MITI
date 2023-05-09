#pragma once
class Player;
class Stage;
class Box;
class G_Kaidan : public IGameObject
{
public:
	G_Kaidan();
	~G_Kaidan();
	void Update();
	void Render(RenderContext& rc);

	ModelRender Kaidan;

	Vector3 Kaidan_P;

	Quaternion Kaidan_R;

	PhysicsStaticObjectPos m_physicsStaticObjectpos;

	AllLight light;

	Player* player;

	Stage* stage;

	Box* box;

	bool clearflag = false;
};

