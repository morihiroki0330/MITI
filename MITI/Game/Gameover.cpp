#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "Game.h"

Gameover::Gameover()
{
	//�Q�[���N���A�̉摜��ǂݍ���
	GAMEOVER.Init("Assets/sprite/RoM_gameover.DDS", 1920.0f, 1080.0f);

}

Gameover::~Gameover()
{

}

//�X�V����
void Gameover::Update()
{
	game = FindGO<Game>("game");
	//A�{�^���������ꂽ��
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		game->CreateFlag = true;
		DeleteGO(this);
	}
}

//�`�揈��
void Gameover::Render(RenderContext& rc)
{
	GAMEOVER.Draw(rc);
}
