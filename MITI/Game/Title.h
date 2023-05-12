#pragma once
#include "sound/SoundSource.h"
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
	SoundSource* BGM;
	SpriteRender Title_s;
	bool BgmSet = true;
};
