#include "stdafx.h"
#include "StageClear.h"
#include "Game.h"
#include "Bgm.h"
#include "Story.h"
#include "Fade.h"
StageClear::StageClear()
{
	STAGECLEAR.Init("Assets/sprite/stageclear_bg.DDS", 1920.0f, 1080.0f);
	PRESSA.Init("Assets/sprite/PRESS_A.DDS", 1920.0f, 1080.0f);
	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_STAGECLEAR);
	BGM->SetVolume(0.1f);
	BGM->Play(true);
}

StageClear::~StageClear()
{
	DeleteGO(BGM);
	//game->CreateFlag = true;
}

bool StageClear::Start()
{
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void StageClear::Update()
{
	game = FindGO<Game>("game");

	if (fade->IsFade() == false && Delete == true)
	{
		NewGO<Story>(0, "story");
		DeleteGO(this);
	}

	if (g_pad[0]->IsTrigger(enButtonA)&&Delete==false)
	{
		fade->StartFadeOut();
		game->Level += 1;
		Delete = true;
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(11);
		se->Play(false);

		{
			game->DeleteSet = false;
			game->ClearFlag = false;
		//NewGO<Story>(0,"story");
			//game->CreateFlag = true;
		//DeleteGO(this);
		}

	}
}

void StageClear::Render(RenderContext& rc)
{
	STAGECLEAR.Draw(rc);
	PRESSA.Draw(rc);
}