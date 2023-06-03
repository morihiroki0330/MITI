#include "stdafx.h"
#include "Title.h"
#include "Story.h"
#include "Bgm.h"
#include "Fade.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Title::Title()
{
	Title_s.Init("Assets/sprite/RoM_Title3.DDS", 1920.0f, 1080.0f);
	Title_f.Init("Assets/sprite/PRESS_A.DDS", 1920.0f, 1080.0f);
	Title_b.Init("Assets/sprite/black.DDS", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(11, "Assets/Sound/Choice/audiostock_805403.wav");
	Title_b.Update();
}
Title::~Title()
{
	DeleteGO(BGM);
}

bool Title::Start()
{
	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_TITLE);
	BGM->SetVolume(0.5f);
	BGM->Play(true);
	fade = FindGO<Fade>("fade");
	fade->StartFadeIn();
	return true;
}

void Title::Update()
{
	wait++;
	if (g_pad[0]->IsTrigger(enButtonA)&&Press_A==false && wait >= 50)
	{
		Press_A = true;
		Flash();
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(11);
		se->SetVolume(0.5f);
		se->Play(false);
	}

	//Aƒ{ƒ^ƒ“‚ª‰Ÿ‚³‚ê‚½Œã‚Ìˆ—
	if (Press_A == true && wait>=50) {
		if (flashCount > 2) {
			Title_f.SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
			Title_s.SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
			//SoundSource* se = NewGO<SoundSource>(0);
			//se->Init(11);
			//se->Play(false);
		}
		else {
		Title_f.SetMulColor({ 1.0f,1.0f,1.0f,alpha });
		Title_f.Update();
		return Flash();
		}
	}

	if (alpha_s < 0.0f) {
		frame++;
		if (frame > 100) {
			NewGO<Story>(0, "story");
			//NewGO<Game>(0, "game");
			DeleteGO(this);
		}
	}

	Title_f.SetMulColor({ 1.0f,1.0f,1.0f,alpha });
	Title_f.Update();
	if (flashCount == 0) {
	Fade1();
	}

}

void Title::Render(RenderContext& rc)
{
	Title_b.Draw(rc);
	Title_s.Draw(rc);
	Title_f.Draw(rc);
}

void Title::Fade1()
{
	switch (flashing)
	{
	case 1:
		alpha += 0.01f;
		break;
	default:
		alpha -= 0.01f;
		break;
	}

	if (alpha > 1.0f) {
		flashing = 0;
	}
	else if (alpha < -0.0f) {
		flashing = 1;
	}
}

void Title::Flash()
{
		switch (flashing)
		{
		case 1:
			alpha += 0.1f;
			break;
		case 2:
			alpha += 0.1f;
			break;
		case 3:
			alpha += 0.1f;
			break;
		default:
			alpha -= 0.1f;
			break;
		}
		Title_s.SetMulColor({ 1.0f,1.0f,1.0f,alpha_s });
		alpha_s -= 0.02f;

		if (alpha > 1.0f) {
			flashing = 0;
		}
		else if (alpha < -0.2f) {
			flashing = 1;
			flashCount++;
		}
}