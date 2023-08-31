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
	ModelRender M_WeightBoardModel[M_Ymas][M_Xmas];

	Vector3 M_WeightBoardPosition[M_Ymas][M_Xmas];
	Vector3 M_WeightBoardScale = { 0.6f,0.6f,0.6f };

	PhysicsStaticObjectPos M_WeightBoardPhysicsStaticObject[M_Ymas][M_Xmas];

	AllLight M_WeightBoardLight;

	Player* P_Player = nullptr;
	IronBall* P_IronBall = nullptr;
	Stage* P_Stage = nullptr;

	bool M_BgmSet[M_Ymas][M_Xmas];
	bool M_HitFlag[M_Ymas][M_Xmas];
	bool M_SwitchOnFlag[M_Ymas][M_Xmas];
	bool M_WeightBoardOn[M_Ymas][M_Xmas];

	int M_LinkNumber[M_Ymas][M_Xmas][10];
	int M_LinkCount[M_Ymas][M_Xmas];
	int M_LinkObject[M_Ymas][M_Xmas][10];

	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
};

