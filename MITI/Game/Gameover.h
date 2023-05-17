#pragma once
#include "sound/SoundSource.h"
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
	SoundSource* BGM;
	bool BgmSet = true;
};