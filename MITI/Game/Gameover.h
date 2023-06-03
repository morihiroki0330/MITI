#pragma once
#include "sound/SoundSource.h"
class Game;
class Fade;
class Gameover :public IGameObject
{
public:
	Gameover();
	~Gameover();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender GAMEOVER;   
	SpriteRender PRESSA;   

	Game* game;
	Fade* fade;
	SoundSource* BGM;
	bool BgmSet = true;
	bool Delete = false;
};