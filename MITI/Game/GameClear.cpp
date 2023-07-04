#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "Number_Storage.h"
#include "sound/SoundEngine.h"
GameClear::GameClear()
{
	InitTexture();
	InitSound();
}
GameClear::~GameClear()
{
	DeleteGO(BGM);
}
bool GameClear::Start()
{

	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void GameClear::InitTexture()
{
	GameclearTexture.Init("Assets/sprite/RoM_StageClear.DDS", ScreenWide, ScreenHeight);
	AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", ScreenWide, ScreenHeight);
}
void GameClear::InitSound()
{
	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_GAMECLEAR , BgmVolume , Loop);
}

void GameClear::Update()
{
	fade->ButtonFade(AbuttonTexture, PressAbutton);
	if (fade->IsFade() == false && ClassDelete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA)&&ClassDelete==false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_BUTTON, BgmVolume, LoopNot);
		fade->StartFadeOut();
		PressAbutton = true;
		ClassDelete = true;
	}
	}
}
void GameClear::Render(RenderContext& rc)
{
	GameclearTexture.Draw(rc);
	AbuttonTexture.Draw(rc);
}