#pragma once
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
	void IronBallMapSet(int PlayerMap,bool Flag);
	
	bool GetBallMap(int PlayerMap);
	int GetIronBallMax() { return IronBallMax; }
	int GetIronBallMin() { return IronBallMin; }
private:
	ModelRender IronBallModel[5];
	Vector3 IronBallPosition[5];

	ModelRender IronBoxModel;
	Vector3 IronBoxPosition;
	Vector3 IronBoxSetPosition[10][10];
	
	AllLight IronBallLight;
	AllLight IronBoxLight;

	int ShowFlag[5];
	bool IronBoxFlag = false;
	int IronBallMap[5];
	bool IronBallFlag[5];
	int IronBoxMap = 0;
	int IronBallMax = 5;
	int IronBallMin = 0;

	Player* player = nullptr;
	Game* game = nullptr;
	Stage* stage = nullptr;
};

