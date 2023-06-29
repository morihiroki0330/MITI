#pragma once
class Player;
class Stage;
class G_IceFloor:public IGameObject
{
public:
	G_IceFloor();
	bool Start();

	void InitModel();
	void InitPhysicsStaticObject();

	void IceFloorOnPlayer();
	void IceFloorOnTrue(int Y, int X);
	void IceFloorSetPosition(int Y, int X, Vector3 Position);

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender IceFloorModel[10][10];
	Vector3 IceFloorPosition[10][10];
	PhysicsStaticObjectPos IceFloorPhysicsStaticObject[10][10];
	AllLight IceFloorLight;
	bool IceFloorOn[10][10];

	Player* player = nullptr;
	Stage* stage = nullptr;
};

