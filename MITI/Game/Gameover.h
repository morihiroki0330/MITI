#pragma once
#include "sound/SoundSource.h"
class Game;
class Fabe;
class Gameover :public IGameObject
{
public:
	Gameover();
	~Gameover();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender GAMEOVER;   

	Game* game;
	Fabe* fabe;
	SoundSource* BGM;
	bool BgmSet = true;
	bool Delete = false;
};