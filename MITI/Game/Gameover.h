#pragma once
class Game;
class Bgm;
class Gameover :public IGameObject
{
public:
	Gameover();
	~Gameover();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender GAMEOVER;   

	Game* game;
	Bgm* bgm;
	bool BgmSet = true;
};