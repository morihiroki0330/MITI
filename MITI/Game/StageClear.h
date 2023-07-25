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

	SoundSource* P_BGM = nullptr;
	Game* P_Game = nullptr;
	Fade* P_Fade = nullptr;

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