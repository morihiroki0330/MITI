#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Title::Title()
{
	Title_s.Init("Assets/sprite/RoM_Title2.DDS", 1920.0f, 1080.0f);
	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_TITLE);
	BGM->SetVolume(0.1f);
	BGM->Play(true);
}
Title::~Title()
{
	DeleteGO(BGM);
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	Title_s.Draw(rc);
}