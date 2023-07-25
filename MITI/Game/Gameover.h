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

	Game* M_Game = nullptr;
	Fade* M_Fade = nullptr;
	SoundSource* M_BGM = nullptr;

	bool M_BgmSet = true;
	bool M_ClassDelete = false;
	bool M_PressAbutton = false;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	Color S_Color;
	FadeInformation S_FadeInformation;
	GridPosition S_GridPosition;
	SoundSetting S_SoundSetting;
	PlayerInformation S_PlayerInformation;
	BlockInformation S_BlockInformation;
	WorldInformation S_WorldInformation;
	IronBallInformation S_IronBallInformation;
};
