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

	ModelRender Ball[5] ;
	Vector3 Ball_P[5];

	ModelRender IronBox;
	Vector3 IronBox_P;
	Vector3 SetPosition[10][10];
	
	AllLight Light;

	int ShowFlag[5];
	bool BoxFlag = false;
	bool Set;

	Player* player;
	Game* game;
	
};

