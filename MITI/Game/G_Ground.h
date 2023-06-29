#pragma once
class G_Ground : public IGameObject
{
public:
	bool Start();
	void Map_On(int Y, int X);
	void Map_SetPosition(int Y, int X, Vector3 Position);
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender Ground[10][10];
	Vector3 Ground_Position[10][10];
	Vector3 Ground_SparePosition[10][10];
	PhysicsStaticObjectPos Ground_PSO[10][10];
	bool Ground_On[10][10];
	AllLight Light;
};

