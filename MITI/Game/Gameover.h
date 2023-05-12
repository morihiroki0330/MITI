#pragma once
class Game;
class Gameover :public IGameObject
{
public:
	Gameover();
	~Gameover();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender GAMEOVER;   

	Game* game;
	bool BgmSet = true;
};