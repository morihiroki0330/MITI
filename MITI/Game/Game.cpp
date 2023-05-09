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
	//コメントアウトする。
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-90.0f,0.0f });

	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	/*m_modelRender.Init("Assets/modelData/wall3.tkm",stagewallLight);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());*/

	m_player = NewGO<Player>(1, "player");
	//m_G_tekyu = NewGO<G_Tekyu>(2, "g_tekyu");
	m_gamecamera = NewGO<GameCamera>(3, "gamecamera");
	m_stage = NewGO<Stage>(0, "stage");
	m_ironBall = NewGO<IronBall>(4, "ironball");
	Ui = NewGO<UI>(0, "ui");
	box = NewGO<Box>(0, "box");
	bgm = NewGO<Bgm>(0, "bgm");
}

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(Ui);
	DeleteGO(box);
	DeleteGO(bgm);
	//DeleteGO(m_G_tekyu);
	//DeleteGO(m_G_breakfloar);
	//DeleteGO(m_G_WeightBoard);
	//DeleteGO(m_G_Wall);
	//DeleteGO(m_G_IceFloor);
	/*DeleteGO(m_G_tekyu);
	DeleteGO(m_G_breakfloar);
	DeleteGO(m_G_WeightBoard);
	DeleteGO(m_G_Wall);
	DeleteGO(m_G_IceFloor);*/
	//DeleteGO(m_G_laser);
	DeleteGO(this);
}

void Game::Update()
{
	//仮のゲームオーバーの条件を設定
	if (GameOverFlag == true) {
		GameOverFlag = false;
		NewGO<Gameover>(0, "gameover");
		DeleteGO(this);
	}

	//ステージクリア
	if (ClearFlag == true)
	{
		NewGO<StageClear>(0, "stageclear");
		Delete();
		ClearFlag = false;
	}

	//ステージ制作
	if (CreateFlag == true)
	{
		Create();
		CreateFlag = false;
	}else {
	if (Level_Max == Level)
	{
		NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);
	}
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
}

void Game::Delete()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(Ui);
	DeleteGO(box);
	DeleteGO(bgm);
}

void Game::Render(RenderContext& rc)
{
	
}
