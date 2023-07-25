#include "stdafx.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "NumberStorage.h"
#include "sound/SoundEngine.h"
Title::Title()
{
	InitTexture();
	InitSound();
}
Title::~Title()
{
	DeleteGO(P_BGM);
}
bool Title::Start()
{
	P_Fade = FindGO<Fade>("fade");
	P_Fade->StartFadeIn();
	return true;
}

void Title::InitTexture()
{
	M_TitleTexture.Init("Assets/sprite/RoM_Title3.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void Title::InitSound()
{
	P_BGM = NewGO<SoundSource>(0);
	P_BGM->SoundSet(BGM_TITLE , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_Loop);
}

void Title::ScreenChange()
{
	if (P_Fade->IsFade() == false && M_ClassDelete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA) && M_ClassDelete == false && P_Fade->IsFade() == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(SE_TITLEBUTTON , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_LoopNot);
		P_Fade->StartFadeOut();
		M_PressAbutton = true;
		M_ClassDelete = true;
	}
	}
}

void Title::Update()
{
	P_Fade->ButtonFade(M_AbuttonTexture, M_PressAbutton);
	ScreenChange();
}

void Title::Render(RenderContext& rc)
{
	M_TitleTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
}