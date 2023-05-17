#include "stdafx.h"
#include "StageClear.h"
#include "Game.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
StageClear::StageClear()
{
	STAGECLEAR.Init("Assets/sprite/StageClear.DDS", 1920.0f, 1080.0f);
	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_STAGECLEAR);
	BGM->SetVolume(0.1f);
	BGM->Play(true);
}

StageClear::~StageClear()
{
	DeleteGO(BGM);
	game->Level += 1;
	game->CreateFlag = true;
}

void StageClear::Update()
{
	game = FindGO<Game>("game");

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		DeleteGO(this);
	}
}

void StageClear::Render(RenderContext& rc)
{
	STAGECLEAR.Draw(rc);
}