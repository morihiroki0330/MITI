#pragma once
#include "NumberStorage.h"
class Player;
class Game;
class Stage;
class G_WeightBoard;
class IronBall : public IGameObject
{
public:
	IronBall();
	bool Start();

	void InitModel();
	void InitSetPosition();
	void InitLight();
	void LevelSet();

	void Update();
	void Render(RenderContext& rc);

	bool WeightBoardOn(int Y, int X);
	void IronBoxToGet();
	void IronBallPut();
	void IronBallGet();
	void IronBallMapSet(int PlayerMap, bool Flag);

	bool GetBallMap(int PlayerMap);
	int GetIronBallMax() { return M_IronBallMax; }
	int GetIronBallMin() { return M_IronBallMin; }
private:
	ModelRender M_IronBallModel[5];
	Vector3 M_IronBallPosition[5];

	ModelRender M_IronBoxModel;
	Vector3 M_IronBoxPosition;
	Vector3 M_IronBoxSetPosition[10][10];
	
	AllLight M_IronBallLight;
	AllLight M_IronBoxLight;

	int M_ShowFlag[5];
	bool M_IronBoxFlag = false;
	int M_IronBallMap[5];
	bool M_IronBallFlag[5];
	int M_IronBoxMap = 0;
	int M_IronBallMax = 5;
	int M_IronBallMin = 0;

	Player* P_Player = nullptr;
	Game* P_Game = nullptr;
	Stage* P_Stage = nullptr;

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

