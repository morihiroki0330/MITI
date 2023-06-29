#pragma once

class Player;
class IronBall;
class G_Block;
class Stage;
class G_WeightBoard:public IGameObject
{
public:
	bool Start();
	bool GetPutFlag(int Y, int X) { return PutFlag[Y][X]; }
	void Map_On(int Y, int X);
	void Map_SetPosition(int Y, int X, Vector3 Position);
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
private:
	ModelRender WeightBoard[10][10];
	Vector3 WeightBoard_Position[10][10];
	Vector3 WeightBoard_Scale = { 0.6f,0.6f,0.6f };
	PhysicsStaticObjectPos WeightBoard_PSO[10][10];
	AllLight Light;

	Player* player = nullptr;
	IronBall* ironball = nullptr;
	G_Block* block = nullptr;
	Stage* stage = nullptr;
	G_WeightBoard* weightboard = nullptr;

	bool BgmSet[10][10];
	bool HitFlag[10][10];
	bool PutFlag[10][10];
		
	bool WeightBoard_On[10][10];

	int LinkNumber[10][10][10];
	int LinkCount[10][10];
	int LinkObject[10][10][10];
};

