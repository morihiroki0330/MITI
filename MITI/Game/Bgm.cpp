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
	g_soundEngine->ResistWaveFileBank(6, "Assets/audiostock_1147006.wav");
	g_soundEngine->ResistWaveFileBank(7, "Assets/Sound/Choice/audiostock_1044699.wav");
	g_soundEngine->ResistWaveFileBank(8, "Assets/Sound/Choice/audiostock_809045.wav");
	g_soundEngine->ResistWaveFileBank(9, "Assets/Sound/WHAT/audiostock_834172.wav");
	g_soundEngine->ResistWaveFileBank(11, "Assets/Sound/Choice/audiostock_805403.wav");
	//g_soundEngine->ResistWaveFileBank(12, "Assets/Sound/WHAT/audiostock_834172.wav");
	g_soundEngine->ResistWaveFileBank(13, "Assets/Sound/SE/audiostock_52741.wav");
	g_soundEngine->ResistWaveFileBank(14, "Assets/Sound/SE/audiostock_814419.wav");
	g_soundEngine->ResistWaveFileBank(15, "Assets/Sound/SE/audiostock_970277.wav");
	g_soundEngine->ResistWaveFileBank(16, "Assets/Sound/SE/audiostock_459320.wav");
	g_soundEngine->ResistWaveFileBank(17, "Assets/Sound/SE/audiostock_1301235.wav");
	g_soundEngine->ResistWaveFileBank(18, "Assets/Sound/SE/audiostock_1001890.wav");
	g_soundEngine->ResistWaveFileBank(19, "Assets/Sound/heart.wav");
	g_soundEngine->ResistWaveFileBank(20, "Assets/Sound/Ruin/audiostock_156699.wav");
	g_soundEngine->ResistWaveFileBank(21, "Assets/Sound/Ruin/audiostock_1382927.wav");
	g_soundEngine->ResistWaveFileBank(22, "Assets/Sound/Ruin/audiostock_822608.wav");
	g_soundEngine->ResistWaveFileBank(23, "Assets/Sound/Ruin/audiostock_75344.wav");
	g_soundEngine->ResistWaveFileBank(24, "Assets/Sound/Ruin/audiostock_1383970.wav");
	g_soundEngine->ResistWaveFileBank(25, "Assets/Sound/Ruin/audiostock_1394562.wav");
	g_soundEngine->ResistWaveFileBank(26, "Assets/Sound/Ruin/audiostock_192680.wav");
	g_soundEngine->ResistWaveFileBank(27, "Assets/Sound/Ruin/audiostock_1863.wav");
	g_soundEngine->ResistWaveFileBank(28, "Assets/Sound/Ruin/audiostock_944387.wav");
	g_soundEngine->ResistWaveFileBank(29, "Assets/Sound/Ruin/audiostock_133054.wav");
	g_soundEngine->ResistWaveFileBank(30, "Assets/Sound/Ruin/audiostock_1086004.wav");
	g_soundEngine->ResistWaveFileBank(31, "Assets/Sound/Ruin/audiostock_936926.wav");
	g_soundEngine->ResistWaveFileBank(32, "Assets/Sound/Ruin/audiostock_1314342.wav");
	g_soundEngine->ResistWaveFileBank(33,"Assets/bgm/IceFloorBgm.wav");
	g_soundEngine->ResistWaveFileBank(34,"Assets/bgm/IronBallPutBgm.wav");
	g_soundEngine->ResistWaveFileBank(35,"Assets/bgm/IronBallGetBgm.wav");
	g_soundEngine->ResistWaveFileBank(36,"Assets/bgm/WalkBgm.wav");
	g_soundEngine->ResistWaveFileBank(37,"Assets/bgm/FallVoice.wav");
	g_soundEngine->ResistWaveFileBank(38,"Assets/bgm/Kaidan.wav");
	g_soundEngine->ResistWaveFileBank(39, "Assets/Sound/Choice/audiostock_1024688.wav");
	//5ŒŽ24“ú(…)box‰ñŽû‰¹’Ç‰Á(—\’è)
	g_soundEngine->ResistWaveFileBank(40, "Assets/Sound/Choice/audiostock_910363.wav");
}

Bgm::~Bgm()
{
	
}

void Bgm::Update()
{
	
}
