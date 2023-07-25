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
	DeleteGO(M_BGM);
}
bool StageClear::Start()
{
	M_Game = FindGO<Game>("game");
	M_Fade = FindGO<Fade>("fade");
	M_Fade->StartFadeIn();
	return true;
}

void StageClear::InitTexture()
{
	M_StageclearTexture.Init("Assets/sprite/stageclear_bg.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void StageClear::InitSound()
{
	M_BGM = NewGO<SoundSource>(0);
	M_BGM->SoundSet(BGM_STAGECLEAR , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_Loop);
}

void StageClear::Update()
{
	M_Fade->ButtonFade(M_AbuttonTexture, M_PressAbutton);
	if (M_Fade->IsFade() == false && M_ClassDelete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonA)&& M_ClassDelete==false)
	{
		M_Fade->StartFadeOut();
		M_Game->LevelUp();
		M_ClassDelete = true;
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(SE_BUTTON , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_LoopNot);
		M_Game->DeleteFlagSet(false);
		M_Game->ClearFlagSet(false);
		M_PressAbutton = true;
	}
}
void StageClear::Render(RenderContext& rc)
{
	M_StageclearTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
}