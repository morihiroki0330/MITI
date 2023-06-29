#include "stdafx.h"
#include "Gameover.h"
#include "Game.h"
#include "Bgm.h"
#include "Fade.h"
#include "Number_Storage.h"
#include "sound/SoundEngine.h"
Gameover::~Gameover()
{
	DeleteGO(BGM);
	game->SetCreate(true);
}

bool Gameover::Start()
{
	Gameover_S.Init("Assets/sprite/gameover_bg.DDS", ScreenWide , ScreenHeight);
	Abutton_S.Init("Assets/sprite/PRESS_A.DDS", ScreenWide , ScreenHeight);

	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_GAMEOVER , Bgm_Volume , Loop);

	fade = FindGO<Fade>("fade");
	game = FindGO<Game>("game");
	fade->StartFadeIn();
	return true;
}

void Gameover::Update()
{
	fade->ButtonFade(Abutton_S, Press_Abutton);
	if (fade->IsFade() == false && Delete == true)
	{
		DeleteGO(this);
	}else {
	if (g_pad[0]->IsTrigger(enButtonA) && Delete == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_BUTTON , Bgm_Volume , LoopNot);
		fade->StartFadeOut();
		Press_Abutton = true;
		Delete = true;
	}
	}
}

void Gameover::Render(RenderContext& rc)
{
	Gameover_S.Draw(rc);
	Abutton_S.Draw(rc);
}
