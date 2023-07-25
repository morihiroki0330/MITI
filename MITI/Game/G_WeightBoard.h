#pragma once
#include "NumberStorage.h"
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

	void LinkObjectSet(int Y, int X, int W, int Object);
	void LinkNumberSet(int Y, int X, int W, int Number);
	void LinkCountSet(int Y, int X, int Count);

	int GetLinkNumberY(int Y, int X, int Count) { return M_LinkNumber[Y][X][Count / 10]; }
	int GetLinkNumberX(int Y, int X, int Count) { return M_LinkNumber[Y][X][Count % 10]; }
	int GetLinkObject(int Y, int X, int Number) { return M_LinkObject[Y][X][Number]; }
	int GetLinkCount(int Y, int X) { return M_LinkCount[Y][X]; }
	bool GetSwitchOnFlag(int Y, int X) { return M_SwitchOnFlag[Y][X]; }
private:
	ModelRender M_WeightBoardModel[10][10];
	Vector3 M_WeightBoardPosition[10][10];
	Vector3 M_WeightBoardScale = { 0.6f,0.6f,0.6f };
	PhysicsStaticObjectPos M_WeightBoardPhysicsStaticObject[10][10];
	AllLight M_WeightBoardLight;

	Player* M_Player = nullptr;
	IronBall* M_IronBall = nullptr;
	G_Block* M_Block = nullptr;
	Stage* M_Stage = nullptr;
	G_WeightBoard* M_WeightBoard = nullptr;

	bool M_BgmSet[10][10];
	bool M_HitFlag[10][10];
	bool M_SwitchOnFlag[10][10];
		
	bool M_WeightBoardOn[10][10];

	int M_LinkNumber[10][10][10];
	int M_LinkCount[10][10];
	int M_LinkObject[10][10][10];

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
	PlayerInformation S_PlayerInformation;
	BlockInformation S_BlockInformation;
	WorldInformation S_WorldInformation;
	IronBallInformation S_IronBallInformation;
};

