#pragma once
#include "sound/SoundSource.h"
class Fabe;
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender GAMECLEAR;

	SoundSource* BGM;
	Fabe* fabe;

	bool BgmSet = true;
	bool Delete = false;
};

