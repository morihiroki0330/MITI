#pragma once
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
	void WeightBoardOn_Update();
	void WeightBoardOff_Update();

	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender BlockModel[10][10];
	ModelRender IceBlockModel[10][10];
	ModelRender GroundBlockModel[10][10];
	ModelRender DeleteBlockModel[10][10];

	ModelRender SkeletonIceBlockModel[10][10];
	ModelRender SkeletonBlockModel[10][10];
	ModelRender SkeletonGroundBlockModel[10][10];
	ModelRender SkeletonDeleteBlockModel[10][10];

	Vector3 BlockPosition[10][10];
	AllLight BlockLight;
	PhysicsStaticObjectPos BlockPhysicsStaticObject[10][10];

	G_WeightBoard* weightboard = nullptr;
	Box* box = nullptr;
	Stage* stage = nullptr;

	bool NonBlock[10][10];
};

