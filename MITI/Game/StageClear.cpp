#include "stdafx.h"
#include "StageClear.h"
#include "Game.h"
#include "Bgm.h"
#include "Number_Storage.h"
#include "Story.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
StageClear::~StageClear()
{
	DeleteGO(BGM);
}

bool StageClear::Start()
{
	Stageclear_S.Init("Assets/sprite/stageclear_bg.DDS", 1920.0f, 1080.0f);
	Abutton_S.Init("Assets/sprite/PRESS_A.DDS", 1920.0f, 1080.0f);

	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_STAGECLEAR , Bgm_Volume , Loop);

	game = FindGO<Game>("game");
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void StageClear::Update()
{
	
	fade->ButtonFade(Abutton_S, Press_Abutton);

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
		Press_Abutton = true;
	}
}

void StageClear::Render(RenderContext& rc)
{
	Stageclear_S.Draw(rc);
	Abutton_S.Draw(rc);
}