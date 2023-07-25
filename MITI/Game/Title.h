#pragma once
#include "NumberStorage.h"
class Story;
class Fade;
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();

	void InitTexture();
	void InitSound();

	void Update();
	void ScreenChange();
	void Render(RenderContext& rc);
private:
	SpriteRender M_TitleTexture;
	SpriteRender M_AbuttonTexture;

	SoundSource* P_BGM = nullptr;
	Story* P_Story = nullptr;
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