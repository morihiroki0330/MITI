#pragma once
#include "NumberStorage.h"
class G_Ground : public IGameObject
{
public:
	G_Ground();

	void InitModel();
	

	void GroundOnTrue(int Y, int X);
	void GroundSetPosition(int Y, int X, Vector3 Position);

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_GroundModel[M_Ymas][M_Xmas];

	Vector3 M_GroundPosition[M_Ymas][M_Xmas];
	Vector3 M_GroundSparePosition[M_Ymas][M_Xmas];

	PhysicsStaticObjectPos M_GroundPhysicsStaticObject[M_Ymas][M_Xmas];
	AllLight M_GroundLight;
	bool M_GroundOnDecision[M_Ymas][M_Xmas];

	GridPosition S_GridPosition;
};

