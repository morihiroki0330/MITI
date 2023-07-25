#include "stdafx.h"
#include "StageClear.h"
#include "Game.h"
#include "Bgm.h"
#include "NumberStorage.h"
#include "Story.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
StageClear::StageClear()
{
	InitTexture();
	InitSound();
}
StageClear::~StageClear()
{
	DeleteGO(P_BGM);
}
bool StageClear::Start()
{
	P_Game = FindGO<Game>("game");
	P_Fade = FindGO<Fade>("fade");
	P_Fade->StartFadeIn();
	return true;
}

void StageClear::InitTexture()
{
	M_StageclearTexture.Init("Assets/sprite/stageclear_bg.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void StageClear::InitSound()
{
	P_BGM = NewGO<SoundSource>(0);
	P_BGM->SoundSet(BGM_STAGECLEAR , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_Loop);
}

void StageClear::Update()
{
	P_Fade->ButtonFade(M_AbuttonTexture, M_PressAbutton);
	if (P_Fade->IsFade() == false && M_ClassDelete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonA)&& M_ClassDelete==false)
	{
		P_Fade->StartFadeOut();
		P_Game->LevelUp();
		M_ClassDelete = true;
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(SE_BUTTON , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_LoopNot);
		P_Game->DeleteFlagSet(false);
		P_Game->ClearFlagSet(false);
		M_PressAbutton = true;
	}
}
void StageClear::Render(RenderContext& rc)
{
	M_StageclearTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
}