#pragma once
class G_Ground : public IGameObject
{
public:
	G_Ground();

	void InitModel();
	void InitPhysicsStaticObject();

	void GroundOnTrue(int Y, int X);
	void GroundSetPosition(int Y, int X, Vector3 Position);

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender GroundModel[10][10];
	Vector3 GroundPosition[10][10];
	Vector3 GroundSparePosition[10][10];
	PhysicsStaticObjectPos GroundPhysicsStaticObject[10][10];
	AllLight GroundLight;
	bool GroundOn[10][10];
};

