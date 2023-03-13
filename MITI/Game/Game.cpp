//ゲーム全体の処理はここに書いてね～
#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "IronBall.h"
#include "Player.h"
#include "Gameover.h"

Game::Game()
{
	//PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-5.0f,0.01f });
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	m_modelRender.Init("Assets/modelData/test4.tkm");
	m_modelRender.Update();

	m_player = NewGO<Player>(1, "player");

}
Game::~Game()
{
	DeleteGO(this);
}

void Game::Update()
{
	//ゲームオーバー条件を設定
	if (m_player->player_P.z >= 200.0f) {
		NewGO<Gameover>(0, "gameover");
		DeleteGO(this);
	}

	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();

}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
