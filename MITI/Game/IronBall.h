#pragma once

class Player;

class IronBall : public IGameObject
{
public:
	IronBall();
	~IronBall();
	void Update();
	void Render(RenderContext& rc);

	//�S���̍��W��ێ�����z��
	Vector3 ball_P[5];

	Player* player;

	ModelRender modelRender;
};

