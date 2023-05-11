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
//#include "G_laser.h"

Game::Game()
{
	//PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-90.0f,0.0f });

	m_player = NewGO<Player>(1, "player");
	//m_G_tekyu = NewGO<G_Tekyu>(2, "g_tekyu");
	m_gamecamera = NewGO<GameCamera>(3, "gamecamera");
	m_stage = NewGO<Stage>(0, "stage");
	m_ironBall = NewGO<IronBall>(4, "ironball");
	Ui = NewGO<UI>(0, "ui");
	box = NewGO<Box>(0, "box");
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

void Game::Update()
{
	bgm = FindGO<Bgm>("bgm");

	if (BgmSet == true)
	{
		BgmSet = false;
		bgm->PlayBGM(B_STAGE);
	}
	
	if (GameOverFlag == true) {
		NewGO<Gameover>(0, "gameover");
		Delete();
		GameOverFlag = false;
	}

	if (Level_Max == Level && ClearFlag == true)
	{
		NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);
	}else {
	if (ClearFlag == true)
	{
		NewGO<StageClear>(0, "stageclear");
		Delete();
		ClearFlag = false;
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
	bgm->PlayBGM(B_STAGE);
}

void Game::Delete()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(Ui);
	DeleteGO(box);
	bgm->PauseBGM(B_STAGE);
}

void Game::Render(RenderContext& rc)
{
	
}
