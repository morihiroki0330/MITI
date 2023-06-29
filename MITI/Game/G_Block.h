#pragma once
class G_WeightBoard;
class Box;
class Stage;
class G_Block : public IGameObject
{
public:
	bool Start();
	void SetModel(int Y, int X);
	void SetModelPosition(int Y, int X);
	void SetModelUpdate(int Y, int X);
	void NonBlockUpdate();
	void WeightBoardOn_Update();
	void WeightBoardOff_Update();
	void Map_On(int Y, int X);
	void Map_SetPosition(int Y, int X, Vector3 Position);
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender Block[10][10];
	ModelRender IceBlock[10][10];
	ModelRender GroundBlock[10][10];
	ModelRender DeleteBlock[10][10];

	ModelRender SkeletonIceBlock[10][10];
	ModelRender SkeletonBlock[10][10];
	ModelRender SkeletonGroundBlock[10][10];
	ModelRender SkeletonDeleteBlock[10][10];

	Vector3 Block_Position[10][10];
	AllLight Light;
	PhysicsStaticObjectPos Block_PSO[10][10];

	G_WeightBoard* weightboard = nullptr;
	Box* box = nullptr;
	Stage* stage = nullptr;

	bool NonBlock[10][10];
};

