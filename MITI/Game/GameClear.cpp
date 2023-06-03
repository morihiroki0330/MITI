#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
GameClear::GameClear()
{
	GAMECLEAR.Init("Assets/sprite/RoM_StageClear.DDS", 1920.0f, 1080.0f);
	PRESSA.Init("Assets/sprite/PRESS_A.DDS", 1920.0f, 1080.0f);

	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_GAMECLEAR);
	BGM->SetVolume(0.1f);
	BGM->Play(true);
}

GameClear::~GameClear()
{
	//DeleteGO(BGM);
}

bool GameClear::Start()
{
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void GameClear::Update()
{
	if (fade->IsFade() == false && Delete == true)
	{
		NewGO<Story>(0, "story");
		//NewGO<Title>(0, "title");
		DeleteGO(this);
	}
	else {
		if (g_pad[0]->IsTrigger(enButtonA)&&Delete==false)
		{
			fade->StartFadeOut();
			Delete = true;
		}
	}
}

void GameClear::Render(RenderContext& rc)
{
	GAMECLEAR.Draw(rc);
	PRESSA.Draw(rc);
}