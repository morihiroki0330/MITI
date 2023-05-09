#include "stdafx.h"
#include "StageClear.h"
#include "Game.h"
StageClear::StageClear()
{
	STAGECLEAR.Init("Assets/sprite/RoM_StageClear.DDS", 1920.0f, 1080.0f);
}

StageClear::~StageClear()
{

}

void StageClear::Update()
{
	
	game = FindGO<Game>("game");

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