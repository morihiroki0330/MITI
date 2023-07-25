#include "stdafx.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Bgm::Bgm()
{
	g_soundEngine->ResistWaveFileBank(BGM_TITLE, "Assets/bgm/TitleBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_STAGE, "Assets/bgm/StageBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_STAGECLEAR, "Assets/bgm/StageClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_GAMECLEAR, "Assets/bgm/GameClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_GAMEOVER, "Assets/bgm/GameOverBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_SAD, "Assets/Sound/Ruin/audiostock_1394562.wav");
	g_soundEngine->ResistWaveFileBank(BGM_DESTINY, "Assets/Sound/Ruin/audiostock_944387.wav");
	g_soundEngine->ResistWaveFileBank(BGM_WELCOME, "Assets/Sound/Ruin/audiostock_1086004.wav");
	g_soundEngine->ResistWaveFileBank(BGM_DISTRUST, "Assets/Sound/Ruin/audiostock_1314342.wav");
	g_soundEngine->ResistWaveFileBank(BGM_TRAIN, "Assets/Sound/SE/audiostock_52741.wav");
	g_soundEngine->ResistWaveFileBank(BGM_HEART, "Assets/Sound/heart.wav");
	g_soundEngine->ResistWaveFileBank(BGM_STREET, "Assets/Sound/Ruin/audiostock_1383970.wav");
	g_soundEngine->ResistWaveFileBank(SE_WEIGHTBOARD, "Assets/bgm/WeightboardBgm.wav");
	g_soundEngine->ResistWaveFileBank(SE_TEXTBUTTON, "Assets/audiostock_1147006.wav");
	g_soundEngine->ResistWaveFileBank(SE_QUESTION, "Assets/Sound/WHAT/audiostock_834172.wav");
	g_soundEngine->ResistWaveFileBank(SE_TITLEBUTTON, "Assets/Sound/SE/audiostock_970277.wav");
	g_soundEngine->ResistWaveFileBank(SE_QUESTION2, "Assets/Sound/Ruin/audiostock_156699.wav");
	g_soundEngine->ResistWaveFileBank(SE_QUESTION3, "Assets/Sound/Ruin/audiostock_1382927.wav");
	g_soundEngine->ResistWaveFileBank(SE_ICEWALK, "Assets/bgm/IceFloorBgm.wav");
	g_soundEngine->ResistWaveFileBank(SE_IRONBALLPUT, "Assets/bgm/IronBallPutBgm.wav");
	g_soundEngine->ResistWaveFileBank(SE_IRONBALLGET, "Assets/bgm/IronBallGetBgm.wav");
	g_soundEngine->ResistWaveFileBank(SE_WALK, "Assets/bgm/WalkBgm.wav");
	g_soundEngine->ResistWaveFileBank(SE_FALL, "Assets/bgm/FallVoice.wav");
	g_soundEngine->ResistWaveFileBank(SE_KAIDAN, "Assets/bgm/Kaidan.wav");
	g_soundEngine->ResistWaveFileBank(SE_BUTTON, "Assets/Sound/Choice/audiostock_1024688.wav");
	g_soundEngine->ResistWaveFileBank(SE_BOXGET, "Assets/Sound/Choice/audiostock_910363.wav");
}
