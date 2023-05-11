#pragma once
#include "sound/SoundSource.h"
class Game;
class Bgm;
//タイトル。
class Title : public IGameObject
{
public:
	Title();
	~Title();
	void Update();
	void Render(RenderContext& rc);
	Game* game;
	SpriteRender Title_s;
	Bgm* bgm;
	bool BgmSet = true;
};
