#pragma once
#include "NumberStorage.h"
class Game;
class Fade;
class GameOver :public IGameObject
{
public:
	GameOver();
	~GameOver();
	bool Start();

	void InitTexture();
	void InitSound();

	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameoverTexture;
	SpriteRender M_AbuttonTexture;

	Game* P_Game = nullptr;
	Fade* P_Fade = nullptr;
	SoundSource* P_BGM = nullptr;

	bool M_BgmSet = true;
	bool M_ClassDelete = false;
	bool M_PressAbutton = false;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	SoundSetting S_SoundSetting;
};
