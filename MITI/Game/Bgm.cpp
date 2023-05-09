#include "stdafx.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Bgm::Bgm()
{
	g_soundEngine->ResistWaveFileBank(0, "Assets/bgm/audiostock_1297902.wav");
	bgm = NewGO<SoundSource>(0);
	bgm->Init(0);
	bgm->Play(true);
	//bgm->SetVolume(1.0f);
	
}

Bgm::~Bgm()
{

}

void Bgm::Update()
{
	
}

