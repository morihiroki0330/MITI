#pragma once
#include "NumberStorage.h"
class Fade;
class Story;
class Game;
class Title;
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
	Story* P_Story = nullptr;
	Title* P_Title = nullptr;

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

