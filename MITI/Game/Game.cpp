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

Game::Game()
{
	//物理に対する重力設定。
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-90.0f,0.0f });
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_modelRender.Init("Assets/modelData/wall3.tkm");
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	m_player = NewGO<Player>(1, "player");
	m_G_tekyu = NewGO<G_Tekyu>(2, "g_tekyu");
	m_gamecamera = NewGO<GameCamera>(3, "gamecamera");
	m_stage = NewGO<Stage>(0, "stage");
	m_ironBall = NewGO<IronBall>(4, "ironball");
	m_G_breakfloar = NewGO<G_BreakFloar>(5, "g_breakfloar");
	m_G_WeightBoard = NewGO<G_WeightBoard>(6, "m_G_WeightBoard");
	m_G_Wall= NewGO<G_Wall>(7, "m_G_Wall");
}
Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(m_G_tekyu);
	DeleteGO(m_G_breakfloar);
	DeleteGO(m_G_WeightBoard);
	DeleteGO(m_G_Wall);
	DeleteGO(this);
}

void Game::Update()
{
	m_player->moveSpeed.y = -5.0f;
	timer++;

	//仮のゲームオーバー条件を設定
	if (m_player->player_P.y <= -300.0f || timer > 60 * 60) {
		NewGO<Gameover>(0, "gameover");
		DeleteGO(this);
	}

	//仮のゲームクリア条件を設定
	else if (m_player->player_P.z > 700.0f) {
		NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);
	}

	//大鉄球の再表示(開発用)
	if (g_pad[0]->IsTrigger(enButtonLB1)) {
		m_G_tekyu = NewGO<G_Tekyu>(0);
	}

	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();

	//時間の表示
	wchar_t clock[256];
	swprintf_s(clock, 256, L"残り時間:%d", int(timelimit - timer / 60));
	//文字設定
	m_fontRender.SetText(clock);
	//場所設定
	m_fontRender.SetPosition(Vector3(-150.0f, 525.0f, 0.0f));
	//大きさ設定
	m_fontRender.SetScale(1.0f);
}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	m_fontRender.Draw(rc);
}
