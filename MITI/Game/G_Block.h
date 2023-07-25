#pragma once
#include "NumberStorage.h"
class G_WeightBoard;
class Box;
class Stage;
class G_Block : public IGameObject
{
public:
	G_Block();
	bool Start();

	void InitModel();

	void BlockOn(int Y, int X);
	void BlockSetPosition(int Y, int X, Vector3 Position);

	void NonBlockUpdate();
	void WeightBoardOnUpdate();
	void WeightBoardOffUpdate();

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_BlockModel[10][10];
	ModelRender M_IceBlockModel[10][10];
	ModelRender M_GroundBlockModel[10][10];
	ModelRender M_DeleteBlockModel[10][10];

	ModelRender M_SkeletonIceBlockModel[10][10];
	ModelRender M_SkeletonBlockModel[10][10];
	ModelRender M_SkeletonGroundBlockModel[10][10];
	ModelRender M_SkeletonDeleteBlockModel[10][10];

	Vector3 M_BlockPosition[10][10];
	AllLight M_BlockLight;
	PhysicsStaticObjectPos M_BlockPhysicsStaticObject[10][10];

	G_WeightBoard* P_WeightBoard = nullptr;
	Box* P_Box = nullptr;
	Stage* P_Stage = nullptr;

	bool M_NonBlock[10][10];

	GridPosition S_GridPosition;
};

