#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "Game.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
Gameover::Gameover()
{
	GAMEOVER.Init("Assets/sprite/RoM_gameover.DDS", 1920.0f, 1080.0f);
}

Gameover::~Gameover()
{
	
}

void Gameover::Update()
{
	game = FindGO<Game>("game");

	if (BgmSet == true)
	{
		BgmSet = false;
		SoundSource* BGM = NewGO<SoundSource>(0);
		BGM->Init(B_TITLE);
		BGM->SetVolume(0.1f);
		BGM->Play(true);
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
