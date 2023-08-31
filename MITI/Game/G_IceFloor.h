#pragma once
#include "NumberStorage.h"
class Player;
class Stage;
class G_IceFloor:public IGameObject
{
public:
	G_IceFloor();
	bool Start();

	void InitModel();
	

	void IceFloorOnPlayer();
	void IceFloorOnTrue(int Y, int X);
	void IceFloorSetPosition(int Y, int X, Vector3 Position);

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_IceFloorModel[M_Ymas][M_Xmas];

	Vector3 M_IceFloorPosition[M_Ymas][M_Xmas];

	PhysicsStaticObjectPos M_IceFloorPhysicsStaticObject[M_Ymas][M_Xmas];

	AllLight M_IceFloorLight;

	bool M_IceFloorOn[M_Ymas][M_Xmas];

	Player* P_Player = nullptr;
	Stage* P_Stage = nullptr;

	GridPosition S_GridPosition;
};

