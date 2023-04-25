//ゲーム全体の処理はここに書いてね～
#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "IronBall.h"
#include "Player.h"
#include "Gameover.h"
#include "GameClear.h"
#include "G_Tekyu.h"
#include "Stage.h"
#include "GameCamera.h"
#include "G_BreakFloar.h"
#include "G_WeightBoard.h"
#include "G_Wall.h"
#include "G_IceFloor.h"
#include "G_Kaidan.h"
#include "UI.h"

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
	//m_G_breakfloar = NewGO<G_BreakFloar>(5, "g_breakfloar");
	//m_G_WeightBoard = NewGO<G_WeightBoard>(6, "g_WeightBoard");
	//m_G_Wall= NewGO<G_Wall>(7, "g_Wall");
	//m_G_IceFloor = NewGO<G_IceFloor>(8, "g_IceFloor");
}
Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(Ui);
	//DeleteGO(m_G_tekyu);
	//DeleteGO(m_G_breakfloar);
	//DeleteGO(m_G_WeightBoard);
	//DeleteGO(m_G_Wall);
	//DeleteGO(m_G_IceFloor);
	DeleteGO(this);
}

void Game::Update()
{
	m_player->moveSpeed.y = -5.0f;
	timer++;

	//仮のゲームオーバーの条件を設定
	if (m_player->player_P.y <= -250.0f || timer > 60 * 60) {
		NewGO<Gameover>(0, "gameover");
		DeleteGO(this);
	}

	//仮のゲームクリアの条件を設定
	if (m_G_Kaidan == NULL)
	{
		//プレイヤーを探す
		m_G_Kaidan = FindGO<G_Kaidan>("kaidan");
	}
	if (m_G_Kaidan->clearflag == true)
	{
		NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);
	}

	//大鉄球の増殖(実験用)
	if (g_pad[0]->IsTrigger(enButtonLB1)) {
		m_G_tekyu = NewGO<G_Tekyu>(0);
	}

	// g_renderingEngine->DisableRaytracing();
	//m_modelRender.Update();


	//時間制限処理
	wchar_t clock[256];
	swprintf_s(clock, 256, L"残り時間:%d",int(timelimit - timer / 60));
	//表示するテキストを設定。
	m_fontRender.SetText(clock);
	//フォントの位置を設定。
	m_fontRender.SetPosition(Vector3(600.0f, 400.0f, 0.0f));
	//フォントの大きさを設定。
	m_fontRender.SetScale(1.0f);

	wchar_t tips[256];
	swprintf_s(tips, 256, L"Tip:ゴールを目指せ");
	//表示するテキストを設定。
	a_fontRender.SetText(tips);
	//フォントの位置を設定。
	a_fontRender.SetPosition(Vector3(570.0f, 350.0f, 0.0f));
	//フォントの大きさを設定。
	a_fontRender.SetScale({ 0.8f});
	
	wchar_t stage[256];
	swprintf_s(stage, 256, L"1階層目");
	//表示するテキストを設定。
	s_fontRender.SetText(stage);
	//フォントの位置を設定。
	s_fontRender.SetPosition(Vector3(650.0f, 450.0f, 0.0f));
	//フォントの大きさを設定。
	s_fontRender.SetScale({ 1.0f});
}

void Game::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
	m_fontRender.Draw(rc);
	a_fontRender.Draw(rc);
	s_fontRender.Draw(rc);
}
