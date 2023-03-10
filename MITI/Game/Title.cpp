#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	TITLE.Init("Assets/sprite/RoM_Title.dds", 1920.0f, 1080.0f);

}

Title::~Title()
{

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