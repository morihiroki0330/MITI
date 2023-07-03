#pragma once
class Player;
class IronBall;
class G_Block;
class Stage;
class G_WeightBoard:public IGameObject
{
public:
	G_WeightBoard();
	bool Start();

	void InitModel();
	void InitPhysicsStaticObject();

	void WeightBoardOnTrue(int Y, int X);
	void WeightBoardSetPosition(int Y, int X, Vector3 Position);

	void WeightBoardOnPlayer();
	void Sound();

	void Update();
	void Render(RenderContext& rc);

	void LinkObjectSet(int Y, int X,int W,int Object);
	void LinkNumberSet(int Y, int X, int W,int Number);
	void LinkCountSet(int Y, int X, int Count);

	int GetLinkNumberY(int Y, int X, int Count) { return LinkNumber[Y][X][Count / 10]; }
	int GetLinkNumberX(int Y, int X, int Count) { return LinkNumber[Y][X][Count % 10]; }
	int GetLinkObject(int Y, int X, int Number) { return LinkObject[Y][X][Number]; }
	int GetLinkCount(int Y, int X) { return LinkCount[Y][X]; }
	bool GetSwitchOnFlag(int Y, int X) { return SwitchOnFlag[Y][X]; }
private:
	ModelRender WeightBoardModel[10][10];
	Vector3 WeightBoardPosition[10][10];
	Vector3 WeightBoardScale = { 0.6f,0.6f,0.6f };
	PhysicsStaticObjectPos WeightBoardPhysicsStaticObject[10][10];
	AllLight WeightBoardLight;

	Player* player = nullptr;
	IronBall* ironball = nullptr;
	G_Block* block = nullptr;
	Stage* stage = nullptr;
	G_WeightBoard* weightboard = nullptr;

	bool BgmSet[10][10];
	bool HitFlag[10][10];
	bool SwitchOnFlag[10][10];
		
	bool WeightBoardOn[10][10];

	int LinkNumber[10][10][10];
	int LinkCount[10][10];
	int LinkObject[10][10][10];
};

