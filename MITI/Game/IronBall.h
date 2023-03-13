#pragma once

class Player;

class IronBall : public IGameObject
{
public:
	IronBall();
	~IronBall();
	void Update();
	void Render(RenderContext& rc);

	//鉄球の座標を保持する配列
	Vector3 ball_P[5];

	int ballCounter;

	Player* player;

	ModelRender ironRender[5];
};

