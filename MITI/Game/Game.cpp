//�Q�[���S�̂̏����͂����ɏ����Ăˁ`
#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "IronBall.h"
#include "Player.h"
#include "Gameover.h"
#include "GameClear.h"
#include "G_Tekyu.h"
#include "Stage.h"

Game::Game()
{
	//�����ɑ΂���d�͐ݒ�B
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-980.0f,0.0f });
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_modelRender.Init("Assets/modelData/test10.tkm");
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	m_player = NewGO<Player>(1, "player");
	m_G_tekyu = NewGO<G_Tekyu>(2, "g_tekyu");
	//m_stage = NewGO<Stage>(0, "stage");


}
Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_ironBall);
	DeleteGO(m_stage);
	DeleteGO(m_G_tekyu);
	DeleteGO(this);
}

void Game::Update()
{
	m_player->moveSpeed.y = -5.0f;

	//���̃Q�[���I�[�o�[������ݒ�
	if (m_player->player_P.y<=-300.0f) {
		NewGO<Gameover>(0, "gameover");
		DeleteGO(this);
	}

	//���̃Q�[���N���A������ݒ�
	else if (m_player->player_P.z >= 700.0f) {
		NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);
	}

	//��S���̍ĕ\��(�J���p)
	if (g_pad[0]->IsTrigger(enButtonLB1)) {
		m_G_tekyu = NewGO<G_Tekyu>(0);
	}

	/*if (m_G_tekyu != nullptr) {
		m_player->characterController.
	}*/

	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();

}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
