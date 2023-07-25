#pragma once
#include "NumberStorage.h"
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
	ModelRender M_GroundModel[10][10];
	Vector3 M_GroundPosition[10][10];
	Vector3 M_GroundSparePosition[10][10];
	PhysicsStaticObjectPos M_GroundPhysicsStaticObject[10][10];
	AllLight M_GroundLight;
	bool M_GroundOn[10][10];

	GridPosition S_GridPosition;
};

