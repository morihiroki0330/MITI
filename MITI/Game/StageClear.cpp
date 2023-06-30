#include "stdafx.h"
#include "StageClear.h"
#include "Game.h"
#include "Bgm.h"
#include "Number_Storage.h"
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
	DeleteGO(BGM);
}
bool StageClear::Start()
{
	game = FindGO<Game>("game");
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void StageClear::InitTexture()
{
	StageclearTexture.Init("Assets/sprite/stageclear_bg.DDS", ScreenWide, ScreenHeight);
	AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", ScreenWide, ScreenHeight);
}
void StageClear::InitSound()
{
	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_STAGECLEAR , Bgm_Volume , Loop);
}

void StageClear::Update()
{
	fade->ButtonFade(AbuttonTexture, PressAbutton);
	if (fade->IsFade() == false && Delete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}
	if (g_pad[0]->IsTrigger(enButtonA)&&Delete==false)
	{
		fade->StartFadeOut();
		game->LevelUp();
		Delete = true;
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_BUTTON , Bgm_Volume , LoopNot);
		game->SetDelete(false);
		game->SetClear(false);
		PressAbutton = true;
	}
}
void StageClear::Render(RenderContext& rc)
{
	StageclearTexture.Draw(rc);
	AbuttonTexture.Draw(rc);
}