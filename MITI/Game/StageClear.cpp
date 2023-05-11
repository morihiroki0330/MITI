#include "stdafx.h"
#include "StageClear.h"
#include "Game.h"
#include "Bgm.h"
StageClear::StageClear()
{
	STAGECLEAR.Init("Assets/sprite/StageClear.DDS", 1920.0f, 1080.0f);
}

StageClear::~StageClear()
{
	bgm->PauseBGM(B_STAGECLEAR);
}

void StageClear::Update()
{
	bgm = FindGO<Bgm>("bgm");
	game = FindGO<Game>("game");

	if (BgmSet == true)
	{
		BgmSet = false;
		bgm->PlayBGM(B_STAGECLEAR);
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