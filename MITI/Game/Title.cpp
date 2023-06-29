#include "stdafx.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "Game.h"
#include "Number_Storage.h"
#include "sound/SoundEngine.h"
Title::~Title()
{
	DeleteGO(BGM);
}
bool Title::Start()
{
	Title_S.Init("Assets/sprite/RoM_Title3.DDS", ScreenWide, ScreenHeight);
	Abutton_S.Init("Assets/sprite/PRESS_A.DDS", ScreenWide, ScreenHeight);

	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_TITLE , Bgm_Volume , Loop);

	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
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
		SE->SoundSet(S_TITLEBUTTON , Bgm_Volume , LoopNot);
		fade->StartFadeOut();
		Press_Abutton = true;
		ClassDelete = true;
	}
	}
}
void Title::Update()
{
	ScreenChange();
	fade->ButtonFade(Abutton_S , Press_Abutton);
}
void Title::Render(RenderContext& rc)
{
	Title_S.Draw(rc);
	Abutton_S.Draw(rc);
}