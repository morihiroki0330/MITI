#include "stdafx.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Bgm::Bgm()
{
	g_soundEngine->ResistWaveFileBank(1,"Assets/bgm/StageBgm.wav");
	g_soundEngine->ResistWaveFileBank(2,"Assets/bgm/WeightboardBgm.wav");
	BGM = NewGO<SoundSource>(0);
	BGM -> Init(3);
	BGM -> Play(true);
	//bgm->SetVolume(1.0f);
	
}

Bgm::~Bgm()
{
	DeleteGO(BGM);
}

void Bgm::Update()
{
	
}

