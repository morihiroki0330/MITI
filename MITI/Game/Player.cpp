#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	modelRender.Init("Assets/modelData/unityChan.tkm");

	player_P.x = 0.0f;
	player_P.y = 0.0f;
	player_P.z = 0.0f;

	modelRender.SetPosition(player_P);

	//�L�����N�^�[�R���g���[���[�̏�����
	characterController.Init(25.0f, 75.0f, player_P);
}

Player::~Player()
{

}

void Player::Update()
{
	//

	//�X�e�B�b�N�̓��͗ʂ̎擾
	StickL.x = g_pad[0]->GetLStickXF();
	StickL.y = g_pad[0]->GetLStickYF();

	//�ړ�����
	Move();
	//��]����
	Rotation();
	//�S������
	Ball();
	//�A�j���[�V��������
	Animation();

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
	moveSpeed.x += StickL.x * (0.8f * (6 - ironBall));
	moveSpeed.z += StickL.y * (0.8f * (6 - ironBall));

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

void Player::Ball()
{
	//�Ƃ肠�����������œS������
	if (g_pad[0]->IsTrigger(enButtonA) && ironBall < 5)
	{
		ironBall++;
	}

	if (g_pad[0]->IsTrigger(enButtonB) && ironBall > 0)
	{
		ironBall--;
	}
}

void Player::Animation()
{
	//�v���C���[�X�e�[�g�̕ύX
	if (player_P.y < 0)
	{
		//����
		playerState = 2;
	}
	else if (StickL.x == 0 && StickL.y == 0)
	{
		//����
		playerState = 0;
	}
	else
	{
		//����
		playerState = 1;
	}

	switch (playerState)
	{
	//�������[�V����
	case 0:
		break;
	//�������[�V����
	case 1:
		break;
	//�������[�V����
	case 2:
		break;
	//
	default:
		break;
	}
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}