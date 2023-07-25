#pragma once
class G_Wall :public IGameObject
{
public:
	G_Wall();
	void InitModel();
	void InitPhysicsStaticObject();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_WallModel;
	Vector3 M_WallPosition = { 0.0f,82.0f,0.0f };
	PhysicsStaticObjectPos M_WallPhysicsStaticObject;
	AllLight M_WallLight;
};

