#include "stdafx.h"
#include "GameOver.h"
#include "Game.h"
#include "Bgm.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
GameOver::GameOver()
{
	InitTexture();
	InitSound();
}
GameOver::~GameOver()
{
	DeleteGO(P_Bgm);
	P_Game->CreateFlagSet(true);
}
bool GameOver::Start()
{
	P_Fade = FindGO<Fade>("fade");
	P_Game = FindGO<Game>("game");
	P_Fade->StartFadeIn();
	return true;
}

void GameOver::InitTexture()
{
	M_GameoverTexture.Init("Assets/sprite/gameover_bg.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
	M_AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", S_TextureWide.M_ScreenWide, S_TextureHeight.M_ScreenHeight);
}
void GameOver::InitSound()
{
	P_Bgm = NewGO<SoundSource>(0);
	P_Bgm->SoundSet(BGM_GAMEOVER, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_Loop);
}

void GameOver::Update()
{
	P_Fade->ButtonFade(M_AbuttonTexture, M_PressAbuttonDecision);
	if (!P_Fade->IsFade() && M_ClassDeleteDecision)
	{
		DeleteGO(this);
	}
	else {
		if (g_pad[0]->IsTrigger(enButtonA) && !M_ClassDeleteDecision)
		{
			SoundSource* P_Se = NewGO<SoundSource>(0);
			P_Se->SoundSet(SE_BUTTON, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_LoopNot);
			P_Fade->StartFadeOut();
			M_PressAbuttonDecision = true;
			M_ClassDeleteDecision = true;
		}
	}
}
void GameOver::Render(RenderContext& rc)
{
	M_GameoverTexture.Draw(rc);
	M_AbuttonTexture.Draw(rc);
}