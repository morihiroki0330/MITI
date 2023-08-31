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
	SoundSource* P_Bgm = nullptr;

	bool M_BgmSet = true;
	bool M_ClassDeleteDecision = false;
	bool M_PressAbuttonDecision = false;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	SoundSetting S_SoundSetting;
};
