#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "Game.h"
#include "Bgm.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
Gameover::Gameover()
{
	//5月24日(水)リスタート音追加
	g_soundEngine->ResistWaveFileBank(39, "Assets/Sound/Choice/audiostock_1024688.wav");

	//GAMEOVER.Init("Assets/sprite/gameover.DDS", 1920.0f, 1080.0f);
	GAMEOVER.Init("Assets/sprite/gameover_bg.DDS", 1920.0f, 1080.0f);
	PRESSA.Init("Assets/sprite/PRESS_A.DDS", 1920.0f, 1080.0f);
	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_GAMEOVER);
	BGM->SetVolume(0.3f);
	BGM->Play(true);
}

Gameover::~Gameover()
{
	DeleteGO(BGM);
	game->CreateFlag = true;
}

bool Gameover::Start()
{
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void Gameover::Update()
{
	game = FindGO<Game>("game");
	

	if (fade->IsFade() == false && Delete == true)
	{
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA) && Delete == false)
	{
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(39);
		se->SetVolume(0.6f);
		se->Play(false);
		fade->StartFadeOut();
		Delete = true;
	}
	}
}

void Gameover::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
	PRESSA.Draw(rc);
}
