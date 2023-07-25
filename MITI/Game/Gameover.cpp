#include "stdafx.h"
#include "GameOver.h"
#include "Game.h"
#include "Bgm.h"
#include "Fade.h"
#include "NumberStorage.h"
#include "sound/SoundEngine.h"
GameOver::GameOver()
{
	InitTexture();
	InitSound();
}
GameOver::~GameOver()
{
	DeleteGO(M_BGM);
	M_Game->CreateFlagSet(true);
}
bool GameOver::Start()
{
	M_Fade = FindGO<Fade>("fade");
	M_Game = FindGO<Game>("game");
	M_Fade->StartFadeIn();
	return true;
}

void GameOver::InitTexture()
{
	M_GameoverTexture.Init("Assets/sprite/gameover_bg.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void GameOver::InitSound()
{
	M_BGM = NewGO<SoundSource>(0);
	M_BGM->SoundSet(BGM_GAMEOVER, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_Loop);
}

void GameOver::Update()
{
	M_Fade->ButtonFade(M_AbuttonTexture, M_PressAbutton);
	if (M_Fade->IsFade() == false && M_ClassDelete == true)
	{
		DeleteGO(this);
	}
	else {
		if (g_pad[0]->IsTrigger(enButtonA) && M_ClassDelete == false)
		{
			SoundSource* SE = NewGO<SoundSource>(0);
			SE->SoundSet(SE_BUTTON, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_LoopNot);
			M_Fade->StartFadeOut();
			M_PressAbutton = true;
			M_ClassDelete = true;
		}
	}
}
void GameOver::Render(RenderContext& rc)
{
	M_GameoverTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
}