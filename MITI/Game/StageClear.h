#pragma once
#include "sound/SoundSource.h"
class Game;
class Fabe;
class StageClear : public IGameObject
{
public:
	StageClear();
	~StageClear();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender STAGECLEAR;  

	Game* game;
	Fabe* fabe;

	SoundSource* BGM;

	bool BgmSet = true;
	bool Delete = false;
};

