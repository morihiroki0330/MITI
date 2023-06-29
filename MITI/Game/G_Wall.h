#pragma once
class G_Wall:public IGameObject
{
public:
	G_Wall();
	void InitModel();
	void InitPhysicsStaticObject();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender WallModel;
	Vector3 WallPosition = { 0.0f,82.0f,0.0f };
	PhysicsStaticObjectPos WallPhysicsStaticObject;
	AllLight WallLight;
};

