#pragma once
class G_Hole : public IGameObject
{
public:
	G_Hole();
	void InitModel();
	void InitPhysicsStaticObject();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender HoleModel;
	Vector3 HolePosition = { 0.0f ,-300.0f,0.0f };
	PhysicsStaticObjectPos HolePhysicsStaticObject;
	AllLight HoleLight;
};

