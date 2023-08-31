#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
GameClear::GameClear()
{
	InitTexture();
	InitSound();
}
GameClear::~GameClear()
{
	DeleteGO(P_Bgm);
}
bool GameClear::Start()
{
	P_Fade = FindGO<Fade>("fade");
	P_Fade->StartFadeIn();
	return true;
}

void GameClear::InitTexture()
{
	M_GameclearTexture.Init("Assets/sprite/RoM_StageClear.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void GameClear::InitSound()
{
	P_Bgm = NewGO<SoundSource>(0);
	P_Bgm->SoundSet(BGM_GAMECLEAR , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_Loop);
}

void GameClear::Update()
{
	P_Fade->ButtonFade(M_AbuttonTexture, M_PressAbuttonDecision);
	if (!P_Fade->IsFade() && M_ClassDeleteDecision)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA)&& !M_ClassDeleteDecision)
	{
		SoundSource* P_Se = NewGO<SoundSource>(0);
		P_Se->SoundSet(SE_BUTTON, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_LoopNot);
		P_Fade->StartFadeOut();
		M_PressAbuttonDecision = true;
		M_ClassDeleteDecision = true;
	}
	}
}
void GameClear::Render(RenderContext& rc)
{
	M_GameclearTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
}