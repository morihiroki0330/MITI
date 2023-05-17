#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "Game.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Gameover::Gameover()
{
	GAMEOVER.Init("Assets/sprite/RoM_gameover.DDS", 1920.0f, 1080.0f);
	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_GAMEOVER);
	BGM->SetVolume(0.1f);
	BGM->Play(true);
}

Gameover::~Gameover()
{
	DeleteGO(BGM);
	game->CreateFlag = true;
}

void Gameover::Update()
{
	game = FindGO<Game>("game");

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		DeleteGO(this);
	}
}

void Gameover::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
}
