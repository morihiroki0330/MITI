#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear()
{
	//�Q�[���N���A�̉摜��ǂݍ���
	GAMEOVER.Init("Assets/sprite/RoM_gameclear.DDS", 1820.0f, 880.0f);

}

GameClear::~GameClear()
{

}

//�X�V����
void GameClear::Update()
{

	//A�{�^���������ꂽ��
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//�^�C�g���̃I�u�W�F�N�g�����
		NewGO<Title>(0, "title");
		//���g���폜����
		DeleteGO(this);
	}
}

//�`�揈��
void GameClear::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
}