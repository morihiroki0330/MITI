#pragma once
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
	PhysicsStaticObjectPos m_physicsStaticObjectpos;
	Quaternion Kaidan_R;
	AllLight Light;

	Box* box;
};

