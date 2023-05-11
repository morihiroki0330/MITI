#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Bgm.h"

Title::Title()
{
	Title_s.Init("Assets/sprite/RoM_Title2.DDS", 1920.0f, 1080.0f);
}
Title::~Title()
{
	bgm->PauseBGM(B_TITLE);
}

void Title::Update()
{
	bgm = FindGO<Bgm>("bgm");
	if (BgmSet == true)
	{
		BgmSet = false;
		bgm->PlayBGM(B_TITLE);
	}
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