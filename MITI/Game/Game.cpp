#include "stdafx.h"
#include "Game.h"
#include "IronBall.h"
#include "Player.h"
#include "GameOver.h"
#include "GameClear.h"
#include "StageClear.h"
#include "Stage.h"
#include "GameCamera.h"
#include "UI.h"
#include "Box.h"
#include "Bgm.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
#include "NumberStorage.h"
Game::~Game()
{
	/*DeleteGO(player);
	DeleteGO(gamecamera);
	DeleteGO(stage);
	DeleteGO(ironball);
	DeleteGO(ui);
	DeleteGO(box);
	DeleteGO(BGM);*/
}
bool Game::Start()
{
	M_Fade = FindGO<Fade>("fade");
	InitWorld();
	ClassCreate();
	return true;
}

void Game::InitWorld()
{
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-180.0f,0.0f });
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

void Game::ClassCreate()
{
	M_Stage = NewGO<Stage>(0, "stage");
	M_Player = NewGO<Player>(0, "player");
	M_GameCamera = NewGO<GameCamera>(0, "gamecamera");
	M_IronBall = NewGO<IronBall>(0, "ironball");
	M_Ui = NewGO<UI>(0, "ui");
	M_Box = NewGO<Box>(0, "box");

	M_BGM = NewGO<SoundSource>(0);
	M_BGM->SoundSet(BGM_STAGE , S_SoundSetting.M_BgmVolume , S_SoundSetting.M_Loop);

	DeleteFlagSet(false);
	M_Flag = true;
	M_Fade->StartFadeIn();
}
void Game::ClassDelete()
{
	DeleteGO(M_Player);
	DeleteGO(M_IronBall);
	DeleteGO(M_Stage);
	DeleteGO(M_Ui);
	DeleteGO(M_Box);
	DeleteGO(M_BGM);
	M_Flag = false;
}

void Game::Over()
{
	if (GetDeleteFlag() == false)
	{
		M_Fade->StartFadeOut();
		DeleteFlagSet(true);
	}else {
	if (M_Fade->IsFade() == false && M_DeleteFlag == true)
	{
		NewGO<GameOver>(0, "gameover");
		ClassDelete();
		GameOverFlagSet(false);
	}
	}
}
void Game::Clear()
{
	if (M_Level_Max == M_Level)
	{
		if (GetDeleteFlag() == false)
		{
			M_Fade->StartFadeOut();
			DeleteFlagSet(true);
		}else {
		if (M_Fade->IsFade() == false && GetDeleteFlag() == true)
		{
			NewGO<GameClear>(0, "gameclear");
			GameClearFlagSet(true);
			ClassDelete();
			ClearFlagSet(false);
		}
		}
	}else {
		if (GetDeleteFlag() == false)
		{
			M_Fade->StartFadeOut();
			DeleteFlagSet(true);
		}else {
		if (M_Fade->IsFade() == false && GetDeleteFlag() == true)
		{
			NewGO<StageClear>(0, "stageclear");
			ClassDelete();
			ClearFlagSet(false);
		}
		}
	}

}

void Game::Update()
{
	if (GetGameOverFlag() == true) { Over(); }
	if (GetClearFlag() == true) { Clear(); }
	if (GetCreateFlag() == true) { ClassCreate(); CreateFlagSet(false); }
	
	if (g_pad[0]->IsTrigger(enButtonY) && M_Flag == true)
	{
		M_Flag = false;
		GameOverFlagSet(true);
	}
}