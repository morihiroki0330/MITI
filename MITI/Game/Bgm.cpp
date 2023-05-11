#include "stdafx.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Bgm::Bgm()
{
	//���̏�����
	g_soundEngine->ResistWaveFileBank(0,"Assets/bgm/TitleBgm.wav");
	g_soundEngine->ResistWaveFileBank(1,"Assets/bgm/StageBgm.wav");
	g_soundEngine->ResistWaveFileBank(2,"Assets/bgm/StageClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(3,"Assets/bgm/GameClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(4,"Assets/bgm/GameOverBgm.wav");

	g_soundEngine->ResistWaveFileBank(5,"Assets/bgm/WeightboardBgm.wav");

	//BGM
	BGM�ESE.TITLE_BGM = NewGO<SoundSource>(0);
	BGM�ESE.STAGE_BGM = NewGO<SoundSource>(1);
	BGM�ESE.STAGECLEAR_BGM = NewGO<SoundSource>(2);
	BGM�ESE.GAMECLEAR_BGM = NewGO<SoundSource>(3);
	BGM�ESE.GAMEOVER_BGM = NewGO<SoundSource>(4);

	//SE
	BGM�ESE.WEIGHTBOARD_SE = NewGO<SoundSource>(5);

	//BGM
	BGM�ESE.TITLE_BGM -> Init(B_TITLE);
	BGM�ESE.STAGE_BGM->Init(B_STAGE);
	BGM�ESE.STAGECLEAR_BGM->Init(B_STAGECLEAR);
	BGM�ESE.GAMECLEAR_BGM->Init(B_GAMECLEAR);
	BGM�ESE.GAMEOVER_BGM->Init(B_GAMEOVER);

	//SE
	BGM�ESE.WEIGHTBOARD_SE->Init(S_WEIGHTBOARD);
}

Bgm::~Bgm()
{
	
}

void Bgm::Update()
{
	
}

void Bgm::PlayBGM(int BGM_NUMBER)
{
	if (BGM_NUMBER == B_TITLE)
	{
		BGM�ESE.TITLE_BGM->Play(true);
		return;
	}else {
	if (BGM_NUMBER == B_STAGE)
	{
		BGM�ESE.STAGE_BGM->Play(true);
		return;
	}else {
	if (BGM_NUMBER == B_STAGECLEAR)
	{
		BGM�ESE.STAGECLEAR_BGM->Play(false);
		return;
	}else {
	if (BGM_NUMBER == B_GAMECLEAR)
	{
		BGM�ESE.GAMECLEAR_BGM->Play(false);
		return;
	}else {
	if (BGM_NUMBER == B_GAMEOVER)
	{
		BGM�ESE.GAMEOVER_BGM->Play(false);
		return;
	}
	}
	}
	}
	}
}

void Bgm::PauseBGM(int BGM_NUMBER)
{
	if (BGM_NUMBER == B_TITLE)
	{
		BGM�ESE.TITLE_BGM->Pause();
		return;
	}else {
	if (BGM_NUMBER == B_STAGE)
	{
		BGM�ESE.STAGE_BGM->Pause();
		return;
	}else {
	if (BGM_NUMBER == B_STAGECLEAR)
	{
		BGM�ESE.STAGECLEAR_BGM->Pause();
		return;
	}else {
	if (BGM_NUMBER == B_GAMECLEAR)
	{
		BGM�ESE.GAMECLEAR_BGM->Pause();
		return;
	}else {
	if (BGM_NUMBER == B_GAMEOVER)
	{
		BGM�ESE.GAMEOVER_BGM->Pause();
		return;
	}
	}
	}
	}
	}
}

void Bgm::PlaySE(int BGM_NUMBER)
{
	if (BGM_NUMBER == S_WEIGHTBOARD)
	{
		BGM�ESE.WEIGHTBOARD_SE->Play(false);
		return;
	}
}