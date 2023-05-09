#pragma once

class Player;
class Game;

class IronBall : public IGameObject
{
public:
	IronBall();
	~IronBall();
	void Update();
	void Render(RenderContext& rc);

	//鉄球の座標を保持する配列
	Vector3 ball_P[5];

	//表示する鉄球を表す配列
	int showFlag[5];

	bool boxFlag = false;

	Player* player;
	Game* game;

	ModelRender IronBox;
	Vector3 IronBox_P;
	Vector3 SetPosition[10][10];

	ModelRender ironRender[5];

	AllLight ironLight;
};

