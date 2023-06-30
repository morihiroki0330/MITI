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
#include "Number_Storage.h"
Game::~Game()
{
	DeleteGO(player);
	DeleteGO(gamecamera);
	DeleteGO(stage);
	DeleteGO(ironball);
	DeleteGO(ui);
	DeleteGO(box);
	DeleteGO(BGM);
	DeleteGO(this);
}
bool Game::Start()
{
	fade = FindGO<Fade>("fade");
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
	stage = NewGO<Stage>(0, "stage");
	player = NewGO<Player>(0, "player");
	gamecamera = NewGO<GameCamera>(0, "gamecamera");
	ironball = NewGO<IronBall>(0, "ironball");
	ui = NewGO<UI>(0, "ui");
	box = NewGO<Box>(0, "box");

	BGM = NewGO<SoundSource>(0);
	BGM->SoundSet(B_STAGE , Bgm_Volume , Loop);

	DeleteFlagSet(false);

	fade->StartFadeIn();
}
void Game::ClassDelete()
{
	DeleteGO(player);
	DeleteGO(ironball);
	DeleteGO(stage);
	DeleteGO(ui);
	DeleteGO(box);
	DeleteGO(BGM);
}

void Game::Over()
{
	if (GetDeleteFlag() == false)
	{
		fade->StartFadeOut();
		DeleteFlagSet(true);
	}else {
	if (fade->IsFade() == false && DeleteFlag == true)
	{
		NewGO<GameOver>(0, "gameover");
		ClassDelete();
		GameOverFlagSet(false);
	}
	}
}
void Game::Clear()
{
	if (Level_Max == Level)
	{
		if (GetDeleteFlag() == false)
		{
			fade->StartFadeOut();
			DeleteFlagSet(true);
		}else {
		if (fade->IsFade() == false && GetDeleteFlag() == true)
		{
			NewGO<GameClear>(0, "gameclear");
			ClassDelete();
			DeleteGO(this);
			ClearFlagSet(false);
		}
		}
	}else {
		if (GetDeleteFlag() == false)
		{
			fade->StartFadeOut();
			DeleteFlagSet(true);
		}else {
		if (fade->IsFade() == false && GetDeleteFlag() == true)
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
}