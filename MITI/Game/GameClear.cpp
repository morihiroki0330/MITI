#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Bgm.h"
#include "Fabe.h"
#include "sound/SoundEngine.h"
GameClear::GameClear()
{
	GAMECLEAR.Init("Assets/sprite/RoM_StageClear.DDS", 1920.0f, 1080.0f);
	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_GAMECLEAR);
	BGM->SetVolume(0.1f);
	BGM->Play(true);
}

GameClear::~GameClear()
{
	DeleteGO(BGM);
}

bool GameClear::Start()
{
	fabe = FindGO<Fabe>("fabe");
	fabe->StartFadeIn();
	return true;
}

void GameClear::Update()
{

	if (fabe->IsFade() == false && Delete == true)
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		fabe->StartFadeOut();
		Delete = true;
	}
	}
}

void GameClear::Render(RenderContext& rc)
{
	GAMECLEAR.Draw(rc);
}