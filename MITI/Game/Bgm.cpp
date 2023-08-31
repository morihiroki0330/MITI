#include "stdafx.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
Bgm::Bgm()
{
	g_soundEngine->ResistWaveFileBank(BGM_TITLE, "Assets/Sound/Bgm/TitleBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_STAGE, "Assets/Sound/Bgm/StageBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_STAGECLEAR, "Assets/Sound/Bgm/StageClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_GAMECLEAR, "Assets/Sound/Bgm/GameClearBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_GAMEOVER, "Assets/Sound/Bgm/GameOverBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_SAD, "Assets/Sound/Bgm/SadBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_DESTINY, "Assets/Sound/Bgm/DestinyBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_WELCOME, "Assets/Sound/Bgm/WelcomeBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_DISTRUST, "Assets/Sound/Bgm/DistrustBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_TRAIN, "Assets/Sound/Bgm/TrainBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_HEART, "Assets/Sound/Bgm/HeartBgm.wav");
	g_soundEngine->ResistWaveFileBank(BGM_STREET, "Assets/Sound/Bgm/StreetBgm.wav");

	g_soundEngine->ResistWaveFileBank(SE_TEXTBUTTON, "Assets/Sound/Se/TextButtonSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_TITLEBUTTON, "Assets/Sound/Se/TitleButtonSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_QUESTION, "Assets/Sound/Se/Question1Se.wav");
	g_soundEngine->ResistWaveFileBank(SE_QUESTION2, "Assets/Sound/Se/Question2Se.wav");
	g_soundEngine->ResistWaveFileBank(SE_QUESTION3, "Assets/Sound/Se/Question3Se.wav");
	g_soundEngine->ResistWaveFileBank(SE_WEIGHTBOARD, "Assets/Sound/Se/WeightboardSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_ICEWALK, "Assets/Sound/Se/IceFloorSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_IRONBALLPUT, "Assets/Sound/Se/IronBallPutSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_IRONBALLGET, "Assets/Sound/Se/IronBallGetSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_WALK, "Assets/Sound/Se/WalkSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_FALL, "Assets/Sound/Se/FallVoiceSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_KAIDAN, "Assets/Sound/Se/KaidanSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_BUTTON, "Assets/Sound/Se/ButtonSe.wav");
	g_soundEngine->ResistWaveFileBank(SE_BOXGET, "Assets/Sound/Se/BoxGetSe.wav");
}
