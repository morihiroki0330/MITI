#pragma once
#include "NumberStorage.h"
class Player;
class Game;
class IronBall : public IGameObject
{
public:
	IronBall();
	bool Start();

	void InitModel();
	void InitSetPosition();
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
	ModelRender M_IronBallModel[M_IronBallCount];
	ModelRender M_IronBoxModel;

	Vector3 M_IronBoxPosition;
	Vector3 M_IronBoxSetPosition[M_Ymas][M_Xmas];
	Vector3 M_IronBallPosition[M_IronBallCount];
	
	AllLight M_IronBallLight;
	AllLight M_IronBoxLight;

	bool M_IronBoxFlag = false;
	bool M_IronBallFlag[M_IronBallCount];
	
	int M_ShowFlag[M_IronBallCount];
	int M_IronBallMap[M_IronBallCount];
	int M_IronBoxMap = 0;
	int M_IronBallMax = 5;
	int M_IronBallMin = 0;

	Player* P_Player = nullptr;
	Game* P_Game = nullptr;

	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
	IronBallInformation S_IronBallInformation;
};

