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

	//�S���̍��W��ێ�����z��
	Vector3 ball_P[5];

	//�\������S����\���z��
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

