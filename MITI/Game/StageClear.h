#pragma once
class Game;
class Bgm;
class StageClear : public IGameObject
{
public:
	StageClear();
	~StageClear();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender STAGECLEAR;  

	Game* game;
	Bgm* bgm;

	bool BgmSet = true;
};

