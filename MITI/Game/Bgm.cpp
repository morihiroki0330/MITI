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
	g_soundEngine->ResistWaveFileBank(33,"Assets/bgm/IceFloorBgm.wav");
	g_soundEngine->ResistWaveFileBank(34,"Assets/bgm/IronBallPutBgm.wav");
	g_soundEngine->ResistWaveFileBank(35,"Assets/bgm/IronBallGetBgm.wav");
	g_soundEngine->ResistWaveFileBank(36,"Assets/bgm/WalkBgm.wav");
	g_soundEngine->ResistWaveFileBank(37,"Assets/bgm/FallVoice.wav");
	g_soundEngine->ResistWaveFileBank(38,"Assets/bgm/Kaidan.wav");
	//5ŒŽ24“ú(…)box‰ñŽû‰¹’Ç‰Á(—\’è)
	g_soundEngine->ResistWaveFileBank(40, "Assets/Sound/Choice/audiostock_910363.wav");
}

Bgm::~Bgm()
{
	
}

void Bgm::Update()
{
	
}
