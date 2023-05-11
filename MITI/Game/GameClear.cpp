#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Bgm.h"
GameClear::GameClear()
{
	GAMECLEAR.Init("Assets/sprite/RoM_StageClear.DDS", 1920.0f, 1080.0f);
}

GameClear::~GameClear()
{
	bgm->PauseBGM(B_GAMECLEAR);
}

void GameClear::Update()
{
	bgm = FindGO<Bgm>("bgm");

	if (BgmSet == true)
	{
		BgmSet = false;
		bgm->PlayBGM(B_GAMECLEAR);
	}

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