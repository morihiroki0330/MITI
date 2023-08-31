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
	
	ModelRender M_BlockModel[M_Ymas][M_Xmas];
	ModelRender M_IceBlockModel[M_Ymas][M_Xmas];
	ModelRender M_GroundBlockModel[M_Ymas][M_Xmas];
	ModelRender M_DeleteBlockModel[M_Ymas][M_Xmas];
		
	ModelRender M_SkeletonIceBlockModel[M_Ymas][M_Xmas];
	ModelRender M_SkeletonBlockModel[M_Ymas][M_Xmas];
	ModelRender M_SkeletonGroundBlockModel[M_Ymas][M_Xmas];
	ModelRender M_SkeletonDeleteBlockModel[M_Ymas][M_Xmas];
	
	Vector3 M_BlockPosition[M_Ymas][M_Xmas];

	AllLight M_BlockLight;

	PhysicsStaticObjectPos M_BlockPhysicsStaticObject[M_Ymas][M_Xmas];

	bool M_NonBlockDecision[M_Ymas][M_Xmas];

	G_WeightBoard* P_WeightBoard = nullptr;
	Box* P_Box = nullptr;
	Stage* P_Stage = nullptr;

	GridPosition S_GridPosition;
};

