#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "Number_Storage.h"
#include "sound/SoundEngine.h"
GameClear::~GameClear()
{
	DeleteGO(BGM);
}

bool GameClear::Start()
{
	Gameclear_S.Init("Assets/sprite/RoM_StageClear.DDS", 1920.0f, 1080.0f);
	Abutton_S.Init("Assets/sprite/PRESS_A.DDS", 1920.0f, 1080.0f);
	
	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_GAMECLEAR , Bgm_Volume , Loop);

	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void GameClear::Update()
{
	fade->ButtonFade(Abutton_S , Press_Abutton);
	if (fade->IsFade() == false && Delete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA)&&Delete==false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_BUTTON, Bgm_Volume, LoopNot);
		fade->StartFadeOut();
		Press_Abutton = true;
		Delete = true;
	}
	}
}

void GameClear::Render(RenderContext& rc)
{
	Gameclear_S.Draw(rc);
	Abutton_S.Draw(rc);
}