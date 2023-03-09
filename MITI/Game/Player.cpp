#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	modelRender.Init("Assets/modelData/unityChan.tkm");

	player_P.x = 0.0f;
	player_P.y = 0.0f;
	player_P.z = 0.0f;

	modelRender.SetPosition(player_P);

	characterController.Init(25.0f, 75.0f, player_P);
}

Player::~Player()
{

}

void Player::Update()
{
	//�X�e�B�b�N�̓��͗ʂ̎擾
	StickL.x = g_pad[0]->GetLStickXF();
	StickL.y = g_pad[0]->GetLStickYF();

	//�ړ�����
	Move();

	//��]����
	Rotation();

	modelRender.SetPosition(player_P);
	modelRender.SetRotation(rotation);
	modelRender.Update();
}

void Player::Move()
{
	//�ړ����x�̏�����
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//�v���C���[�̈ړ�
	moveSpeed.x += StickL.x * 5.0f;
	moveSpeed.z += StickL.y * 5.0f;

	//�L�����N�^�[�R���g���[���[���g���č��W�̈ړ�
	player_P = characterController.Execute(moveSpeed, 1.0f);
}

void Player::Rotation()
{
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//�L�����N�^�[�̕����ύX
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
	}

}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}