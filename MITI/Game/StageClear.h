#pragma once
class Game;
class StageClear : public IGameObject
{
public:
	StageClear();

	~StageClear();

	void Update();

	void Render(RenderContext& rc);

	SpriteRender STAGECLEAR;  

	Game* game;
};

