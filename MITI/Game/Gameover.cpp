#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "Game.h"
#include "Bgm.h"
Gameover::Gameover()
{
	GAMEOVER.Init("Assets/sprite/RoM_gameover.DDS", 1920.0f, 1080.0f);
}

Gameover::~Gameover()
{
	bgm->PauseBGM(B_GAMEOVER);
}

void Gameover::Update()
{
	game = FindGO<Game>("game");
	bgm = FindGO<Bgm>("bgm");

	if (BgmSet == true)
	{
		BgmSet = false;
		bgm->PlayBGM(B_GAMEOVER);
	}

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		game->CreateFlag = true;
		DeleteGO(this);
	}
}

void Gameover::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
}
