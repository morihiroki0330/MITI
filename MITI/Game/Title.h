#pragma once

class Game;
//�^�C�g���B
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
