#pragma once
#include "sound/SoundSource.h"
class Game;
class StageClear : public IGameObject
{
public:
	StageClear();
	~StageClear();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender STAGECLEAR;  

	Game* game;

	SoundSource* BGM;

	bool BgmSet = true;
};

