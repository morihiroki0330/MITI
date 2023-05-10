#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	TITLE.Init("Assets/sprite/RoM_Title2.DDS", 1920.0f, 900.0f);
	g_soundEngine->ResistWaveFileBank(0,"Assets/bgm/Title1.wav");
	BGM = NewGO<SoundSource>(0);
	BGM->Init(0);
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
	TITLE.Draw(rc);
}