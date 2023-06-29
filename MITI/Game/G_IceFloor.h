#pragma once
class Player;
class Stage;
class G_IceFloor:public IGameObject
{
public:
	bool Start();
	void IceFloorOnPlayer();
	void Map_On(int Y, int X);
	void Map_SetPosition(int Y, int X, Vector3 Position);
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender IceFloor[10][10];
	Vector3 IceFloor_Position[10][10];
	PhysicsStaticObjectPos IceFloor_PSO[10][10];
	AllLight Light;

	bool IceFloor_On[10][10];

	Player* player = nullptr;;
	Stage* stage = nullptr;;
	
};

