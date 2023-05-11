#include "stdafx.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Bgm::Bgm()
{
	//音の初期化
	g_soundEngine->ResistWaveFileBank(0,"Assets/bgm/TitleBgm.wav");
	g_soundEngine->ResistWaveFileBank(1,"Assets/bgm/StageBgm.wav");
	g_soundEngine->ResistWaveFileBank(2,"Assets/bgm/StageClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(3,"Assets/bgm/GameClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(4,"Assets/bgm/GameOverBgm.wav");

	g_soundEngine->ResistWaveFileBank(5,"Assets/bgm/WeightboardBgm.wav");

	//BGM
	BGM・SE.TITLE_BGM = NewGO<SoundSource>(0);
	BGM・SE.STAGE_BGM = NewGO<SoundSource>(1);
	BGM・SE.STAGECLEAR_BGM = NewGO<SoundSource>(2);
	BGM・SE.GAMECLEAR_BGM = NewGO<SoundSource>(3);
	BGM・SE.GAMEOVER_BGM = NewGO<SoundSource>(4);

	//SE
	BGM・SE.WEIGHTBOARD_SE = NewGO<SoundSource>(5);

	//BGM
	BGM・SE.TITLE_BGM -> Init(B_TITLE);
	BGM・SE.STAGE_BGM->Init(B_STAGE);
	BGM・SE.STAGECLEAR_BGM->Init(B_STAGECLEAR);
	BGM・SE.GAMECLEAR_BGM->Init(B_GAMECLEAR);
	BGM・SE.GAMEOVER_BGM->Init(B_GAMEOVER);

	//SE
	BGM・SE.WEIGHTBOARD_SE->Init(S_WEIGHTBOARD);
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
		BGM・SE.TITLE_BGM->Play(true);
		return;
	}else {
	if (BGM_NUMBER == B_STAGE)
	{
		BGM・SE.STAGE_BGM->Play(true);
		return;
	}else {
	if (BGM_NUMBER == B_STAGECLEAR)
	{
		BGM・SE.STAGECLEAR_BGM->Play(false);
		return;
	}else {
	if (BGM_NUMBER == B_GAMECLEAR)
	{
		BGM・SE.GAMECLEAR_BGM->Play(false);
		return;
	}else {
	if (BGM_NUMBER == B_GAMEOVER)
	{
		BGM・SE.GAMEOVER_BGM->Play(false);
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
		BGM・SE.TITLE_BGM->Pause();
		return;
	}else {
	if (BGM_NUMBER == B_STAGE)
	{
		BGM・SE.STAGE_BGM->Pause();
		return;
	}else {
	if (BGM_NUMBER == B_STAGECLEAR)
	{
		BGM・SE.STAGECLEAR_BGM->Pause();
		return;
	}else {
	if (BGM_NUMBER == B_GAMECLEAR)
	{
		BGM・SE.GAMECLEAR_BGM->Pause();
		return;
	}else {
	if (BGM_NUMBER == B_GAMEOVER)
	{
		BGM・SE.GAMEOVER_BGM->Pause();
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
		BGM・SE.WEIGHTBOARD_SE->Play(false);
		return;
	}
}