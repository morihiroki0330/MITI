#include "stdafx.h"
#include "StageClear.h"
#include "Game.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
StageClear::StageClear()
{
	STAGECLEAR.Init("Assets/sprite/StageClear.DDS", 1920.0f, 1080.0f);
}

StageClear::~StageClear()
{

}

void StageClear::Update()
{
	game = FindGO<Game>("game");

	if (BgmSet == true)
	{
		BgmSet = false;
		SoundSource* BGM = NewGO<SoundSource>(0);
		BGM->Init(B_STAGECLEAR);
		BGM->SetVolume(0.1f);
		BGM->Play(false);
	}

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		game->Level += 1;
		game->CreateFlag = true;
		DeleteGO(this);
	}
}

void StageClear::Render(RenderContext& rc)
{
	STAGECLEAR.Draw(rc);
}