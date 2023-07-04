#include "stdafx.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "Number_Storage.h"
#include "sound/SoundEngine.h"
Title::Title()
{
	InitTexture();
	InitSound();
}
Title::~Title()
{
	DeleteGO(BGM);
}
bool Title::Start()
{
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void Title::InitTexture()
{
	TitleTexture.Init("Assets/sprite/RoM_Title3.DDS", ScreenWide, ScreenHeight);
	AbuttonTexture.Init("Assets/sprite/PRESS_A.DDS", ScreenWide, ScreenHeight);
}
void Title::InitSound()
{
	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_TITLE , BgmVolume , Loop);
}

void Title::ScreenChange()
{
	if (fade->IsFade() == false && ClassDelete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA) && ClassDelete == false && fade->IsFade() == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_TITLEBUTTON , BgmVolume , LoopNot);
		fade->StartFadeOut();
		PressAbutton = true;
		ClassDelete = true;
	}
	}
}

void Title::Update()
{
	ScreenChange();
	fade->ButtonFade(AbuttonTexture, PressAbutton);
}
void Title::Render(RenderContext& rc)
{
	TitleTexture.Draw(rc);
	AbuttonTexture.Draw(rc);
}