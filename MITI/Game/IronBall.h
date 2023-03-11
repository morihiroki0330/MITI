#pragma once

class Player;

class IronBall : public IGameObject
{
public:
	IronBall();
	~IronBall();
	void Update();
	void Render(RenderContext& rc);

	//“S‹…‚ÌÀ•W‚ğ•Û‚·‚é”z—ñ
	Vector3 ball_P[5];

	Player* player;

	ModelRender modelRender;
};

