#pragma once
class Player;
class Stage;
class G_BreakFloar :public IGameObject
{
public:
	G_BreakFloar();
	void InitModel();
	void Update();
	void Render(RenderContext& rc);
	void Map_On(int Y , int X);
	void Map_SetPosition(int Y, int X, Vector3 Position);
private:
	ModelRender BreakFloar[10][10];
	Vector3 BreakFloar_Position[10][10];
	PhysicsStaticObjectPos BreakFloar_PSO[10][10];
	AllLight Light;
	bool BreakFloar_On[10][10];

	Player* player = nullptr;
	Stage* stage = nullptr;
};

