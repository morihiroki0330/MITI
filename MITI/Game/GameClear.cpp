#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Bgm.h"
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

void GameClear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void GameClear::Render(RenderContext& rc)
{
	GAMECLEAR.Draw(rc);
}