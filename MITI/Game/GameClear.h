#pragma once
class Bgm;
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender GAMECLEAR;

	Bgm* bgm;
	bool BgmSet = true;
};

