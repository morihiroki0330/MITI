#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"

Gameover::Gameover()
{
	//�Q�[���N���A�̉摜��ǂݍ���
	GAMEOVER.Init("Assets/Sprite/RoM_gameover.dds", 1920.0f, 1080.0f);

}

Gameover::~Gameover()
{

}

//�X�V����
void Gameover::Update()
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
void Gameover::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
}
