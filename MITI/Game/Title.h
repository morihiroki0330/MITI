#pragma once

class Game;
//タイトル。
class Title : public IGameObject
{
public:
	Title();
	~Title();
	void Update();
	void Render(RenderContext& rc);
	Game* game;
	SpriteRender TITLE;
};
