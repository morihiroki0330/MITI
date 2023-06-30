#pragma once
#include "sound/SoundSource.h"
class Game;
class Bgm;
class Story;
class Fade;
class StageClear : public IGameObject
{
public:
	StageClear();
	~StageClear();
	bool Start();

	void InitTexture();
	void InitSound();

	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender StageclearTexture;
	SpriteRender AbuttonTexture;

	SoundSource* BGM = nullptr;
	Game* game = nullptr;
	Fade* fade = nullptr;

	bool BgmSet = true;
	bool Delete = false;
	bool PressAbutton = false;
};

