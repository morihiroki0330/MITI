#pragma once
#include "sound/SoundSource.h"
#include "NumberStorage.h"
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
	SpriteRender M_StageclearTexture;
	SpriteRender M_AbuttonTexture;

	SoundSource* P_Bgm = nullptr;
	Game* P_Game = nullptr;
	Fade* P_Fade = nullptr;

	bool M_BgmSet = true;
	bool M_ClassDeleteDecision = false;
	bool M_PressAbuttonDecision = false;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	SoundSetting S_SoundSetting;
};