#include "stdafx.h"
#include "GameOver.h"
#include "Game.h"
#include "Bgm.h"
#include "Fade.h"
#include "Number_Storage.h"
#include "sound/SoundEngine.h"
GameOver::GameOver()
{
	InitTexture();
	InitSound();
}
GameOver::~GameOver()
{
	DeleteGO(BGM);
	game->CreateFlagSet(true);
}
bool GameOver::Start()
{
	fade = FindGO<Fade>("fade");
	game = FindGO<Game>("game");
	fade->StartFadeIn();
	return true;
}

void GameOver::InitTexture()
{
	GameoverTexture.Init("Assets/sprite/gameover_bg.DDS", ScreenWide, ScreenHeight);
	AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", ScreenWide, ScreenHeight);
}
void GameOver::InitSound()
{
	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_GAMEOVER, BgmVolume, Loop);
}

void GameOver::Update()
{
	fade->ButtonFade(AbuttonTexture, PressAbutton);
	if (fade->IsFade() == false && ClassDelete == true)
	{
		DeleteGO(this);
	}
	else {
		if (g_pad[0]->IsTrigger(enButtonA) && ClassDelete == false)
		{
			SoundSource* SE = NewGO<SoundSource>(0);
			SE->SoundSet(S_BUTTON, BgmVolume, LoopNot);
			fade->StartFadeOut();
			PressAbutton = true;
			ClassDelete = true;
		}
	}
}
void GameOver::Render(RenderContext& rc)
{
	GameoverTexture.Draw(rc);
	AbuttonTexture.Draw(rc);
}