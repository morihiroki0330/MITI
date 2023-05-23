//ゲーム全体の処理はここに書いてね～
#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "IronBall.h"
#include "Player.h"
#include "Gameover.h"
#include "GameClear.h"
#include "StageClear.h"
#include "G_Tekyu.h"
#include "Stage.h"
#include "GameCamera.h"
#include "G_BreakFloar.h"
#include "G_WeightBoard.h"
#include "G_Wall.h"
#include "G_IceFloor.h"
#include "G_Kaidan.h"
#include "UI.h"
#include "Box.h"
#include "Bgm.h"
#include "Fabe.h"
#include "sound/SoundEngine.h"
//#include "G_laser.h"

Game::Game()
{
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-180.0f,0.0f });

	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_player = NewGO<Player>(0, "player");
	m_gamecamera = NewGO<GameCamera>(0, "gamecamera");
	m_stage = NewGO<Stage>(0, "stage");
	m_ironBall = NewGO<IronBall>(0, "ironball");
	Ui = NewGO<UI>(0, "ui");
	box = NewGO<Box>(0, "box");

	BGM = NewGO<SoundSource>(0);
	BGM->Init(B_STAGE);
	BGM->SetVolume(0.1f);
	BGM->Play(true);
}

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(Ui);
	DeleteGO(box);
	DeleteGO(this);
}

bool Game::Start()
{
	fabe = FindGO<Fabe>("fabe");
	fabe->StartFadeIn();
	return true;
}

void Game::Update()
{
	if (GameOverFlag == true)
	{
		if (DeleteSet == false)
		{
			fabe->StartFadeOut();
			DeleteSet = true;
		}else {
		if (fabe->IsFade() == false && DeleteSet == true)
		{
			NewGO<Gameover>(0, "gameover");
			Delete();
			GameOverFlag = false;
		}
		}
	}

	if (Level_Max == Level && ClearFlag == true)
	{
		if (DeleteSet == false)
		{
			fabe->StartFadeOut();
			DeleteSet = true;
		}else {
		if (fabe->IsFade() == false && DeleteSet == true)
		{
			NewGO<GameClear>(0, "gameclear");
			Delete();
			DeleteGO(this);
			ClearFlag = false;
		}
		}
	}else {
	if (ClearFlag == true)
	{
		if (DeleteSet == false)
		{
			fabe->StartFadeOut();
			DeleteSet = true;
		}else {
		if (fabe->IsFade() == false && DeleteSet == true)
		{
			NewGO<StageClear>(0, "stageclear");
			Delete();
			ClearFlag = false;
		}
		}
	}
	}

	if (CreateFlag == true)
	{
		Create();
		CreateFlag = false;
	}
}

void Game::Create()
{
	m_player = NewGO<Player>(1, "player");
	m_gamecamera = NewGO<GameCamera>(3, "gamecamera");
	m_stage = NewGO<Stage>(0, "stage");
	m_ironBall = NewGO<IronBall>(4, "ironball");
	Ui = NewGO<UI>(0, "ui");
	box = NewGO<Box>(0, "box");
	bgm = NewGO<Bgm>(0, "bgm");
	BGM = NewGO<SoundSource>(0);
	fabe->StartFadeIn();
	BGM->Init(B_STAGE);
	BGM->SetVolume(0.1f);
	BGM->Play(true);
}

void Game::Delete()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(Ui);
	DeleteGO(box);
	DeleteGO(BGM);
}

void Game::Render(RenderContext& rc)
{
	
}

void Game::Countdown()
{
	Count++;
	
}
