#pragma once
class Player;
class Game;
class Stage;
class G_WeightBoard;
class IronBall : public IGameObject
{
public:
	bool Start();
	bool GetBallMap(int PlayerMap);
	void Update();
	bool WeightBoardOn(int Y, int X);
	void IronBoxToGet();
	void IronBallPut();
	void IronBallGet();
	void BallMapSet(int PlayerMap);
	void LightSet();
	void LevelSet();
	void Render(RenderContext& rc);
	int GetIronBallMax() { return IronBallMax; }
	int GetIronBallMin() { return IronBallMin; }
private:
	ModelRender IronBall[5];
	Vector3 IronBall_Position[5];

	ModelRender IronBox;
	Vector3 IronBox_Position;
	Vector3 SetPosition[10][10];
	
	AllLight Light;

	int ShowFlag[5];
	bool BoxFlag = false;
	bool Set = true;
	int IronBall_Map[5];
	int IronBox_Map = 0;
	int IronBallMax = 5;
	int IronBallMin = 0;

	Player* player = nullptr;
	Game* game = nullptr;
	Stage* stage = nullptr;
};

