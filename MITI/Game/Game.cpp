#include "stdafx.h"
#include "Game.h"
#include "IronBall.h"
#include "Player.h"
#include "Gameover.h"
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
	fade->StartFadeIn();
	SetWorld();
	ClassCreate();
	return true;
}
void Game::SetWorld()
{
	PhysicsWorld::GetInstance()->SetGravity({ NON,-180.0f,NON });
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

void Game::Update()
{
	if (GameOverFlag == true){GameOver();}
	if (ClearFlag == true){Clear();}
	if (CreateFlag == true){ClassCreate();CreateFlag = false;}
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
	DeleteSet = false;
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

void Game::GameOver()
{
	if (DeleteSet == false)
	{
		fade->StartFadeOut();
		DeleteSet = true;
	}else {
	if (fade->IsFade() == false && DeleteSet == true)
	{
		NewGO<Gameover>(0, "gameover");
		ClassDelete();
		GameOverFlag = false;
	}
	}
}

void Game::Clear()
{
	if (Level_Max == Level)
	{
		if (DeleteSet == false)
		{
			fade->StartFadeOut();
			DeleteSet = true;
		}else {
		if (fade->IsFade() == false && DeleteSet == true)
		{
			NewGO<GameClear>(0, "gameclear");
			ClassDelete();
			DeleteGO(this);
			ClearFlag = false;
		}
		}
	}else {
		if (DeleteSet == false)
		{
			fade->StartFadeOut();
			DeleteSet = true;
		}else {
		if (fade->IsFade() == false && DeleteSet == true)
		{
			NewGO<StageClear>(0, "stageclear");
			ClassDelete();
			ClearFlag = false;
		}
		}
	}

}