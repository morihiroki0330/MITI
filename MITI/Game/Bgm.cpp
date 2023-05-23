#include "stdafx.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Bgm::Bgm()
{
	g_soundEngine->ResistWaveFileBank(0,"Assets/bgm/TitleBgm.wav");
	g_soundEngine->ResistWaveFileBank(1,"Assets/bgm/StageBgm.wav");
	g_soundEngine->ResistWaveFileBank(2,"Assets/bgm/StageClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(3,"Assets/bgm/GameClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(4,"Assets/bgm/GameOverBgm.wav");
	g_soundEngine->ResistWaveFileBank(5,"Assets/bgm/WeightboardBgm.wav");
	g_soundEngine->ResistWaveFileBank(6,"Assets/bgm/IceFloorBgm.wav");
	g_soundEngine->ResistWaveFileBank(7,"Assets/bgm/IronBallPutBgm.wav");
	g_soundEngine->ResistWaveFileBank(8,"Assets/bgm/IronBallGetBgm.wav");
	g_soundEngine->ResistWaveFileBank(9,"Assets/bgm/WalkBgm.wav");
	g_soundEngine->ResistWaveFileBank(10,"Assets/bgm/FallVoice.wav");
	g_soundEngine->ResistWaveFileBank(11,"Assets/bgm/Kaidan.wav");
}

Bgm::~Bgm()
{
	
}

void Bgm::Update()
{
	
}
