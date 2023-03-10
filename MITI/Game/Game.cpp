//ゲーム全体の処理はここに書いてね〜
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

Game::Game()
{
	//物理に対する重力設定。
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-90.0f,0.0f });
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_modelRender.Init("Assets/modelData/wall2.tkm");
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	m_player = NewGO<Player>(1, "player");
	m_G_tekyu = NewGO<G_Tekyu>(2, "g_tekyu");
	m_gamecamera = NewGO<GameCamera>(3, "gamecamera");
	m_stage = NewGO<Stage>(0, "stage");
	m_ironBall = NewGO<IronBall>(4, "ironball");
	m_G_breakfloar = NewGO<G_BreakFloar>(5, "g_breakfloar");

}
Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(m_G_tekyu);
	DeleteGO(m_G_breakfloar);
	DeleteGO(this);
}

void Game::Update()
{
	m_player->moveSpeed.y = -5.0f;

	//仮のゲームオーバー条件を設定
	if (m_player->player_P.y<=-300.0f) {
		NewGO<Gameover>(0, "gameover");
		DeleteGO(this);
	}

	//仮のゲームクリア条件を設定
	else if (m_player->player_P.z >= 700.0f) {
		NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);
	}

	//大鉄球の再表示(開発用)
	if (g_pad[0]->IsTrigger(enButtonLB1)) {
		m_G_tekyu = NewGO<G_Tekyu>(0);
	}

	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();

}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
