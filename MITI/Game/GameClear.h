#pragma once
#include "NumberStorage.h"
class Fade;
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();

	void InitTexture();
	void InitSound();

	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameclearTexture;
	SpriteRender M_AbuttonTexture;

	SoundSource* P_BGM = nullptr;
	Fade* P_Fade = nullptr;

	bool M_BgmSet = true;
	bool M_ClassDelete = false;
	bool M_PressAbutton = false;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	SoundSetting S_SoundSetting;
};

