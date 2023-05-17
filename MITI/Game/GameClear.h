#pragma once
#include "sound/SoundSource.h"
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender GAMECLEAR;

	SoundSource* BGM;

	bool BgmSet = true;
};

