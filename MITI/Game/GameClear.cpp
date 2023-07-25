#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "NumberStorage.h"
#include "sound/SoundEngine.h"
GameClear::GameClear()
{
	InitTexture();
	InitSound();
}
GameClear::~GameClear()
{
	DeleteGO(M_BGM);
}
bool GameClear::Start()
{

	M_Fade = FindGO<Fade>("fade");
	M_Fade->StartFadeIn();
	return true;
}

void GameClear::InitTexture()
{
	M_GameclearTexture.Init("Assets/sprite/RoM_StageClear.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void GameClear::InitSound()
{
	M_BGM = NewGO<SoundSource>(0);
	M_BGM->SoundSet(BGM_GAMECLEAR , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_Loop);
}

void GameClear::Update()
{
	M_Fade->ButtonFade(M_AbuttonTexture, M_PressAbutton);
	if (M_Fade->IsFade() == false && M_ClassDelete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA)&& M_ClassDelete==false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(SE_BUTTON, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_LoopNot);
		M_Fade->StartFadeOut();
		M_PressAbutton = true;
		M_ClassDelete = true;
	}
	}
}
void GameClear::Render(RenderContext& rc)
{
	M_GameclearTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
}