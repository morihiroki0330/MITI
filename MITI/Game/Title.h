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

	SoundSource* P_Bgm = nullptr;
	Story* P_Story = nullptr;
	Fade* P_Fade = nullptr;

	bool M_ClassDeleteDecision = false;
	bool M_PressAbuttonDecision = false;

	TextureHeight S_TextureHeight;
	TextureWide S_TextureWide;
	SoundSetting S_SoundSetting;
};