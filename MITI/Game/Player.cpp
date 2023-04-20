#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	AllLight Light;
	Light.DirectionLight_D = { 1.0f,-1.0f,-1.0f };
	Light.DirectionLight_C = { 1.0f,1.0f,1.0f,0.0f };
	//�A�j���[�V�����Ăяo��
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Put].Load("Assets/animData/put.tka");
	m_animationClips[enAnimationClip_Put].SetLoopFlag(false);

	modelRender.Init("Assets/modelData/unityChan.tkm",Light, m_animationClips, enAnimationClip_Num, enModelUpAxisY);

	player_P.x = 0.0f;
	player_P.y = 0.0f;
	player_P.z = 0.0f;

	modelRender.SetPosition(player_P);

	//�L�����N�^�[�R���g���[���[�̏�����
	characterController.Init(25.0f, 75.0f, player_P);
}

Player::~Player()
{
	//

}

void Player::Update()
{
	//

	//�X�e�B�b�N�̓��͗ʂ̎擾
	StickL.x = g_pad[0]->GetLStickYF();
	StickL.y = g_pad[0]->GetLStickXF();

	//�ړ�����
	Move();
	//��]����
	Rotation();
	//�S������
	Ball();
	//�v���C���[�X�e�[�g����
	ManageState();
	//�A�j���[�V��������
	Animation();
	//�X�e�[�^�X�\������
	Status();

	modelRender.SetPosition(player_P);
	modelRender.SetRotation(rotation);
	modelRender.Update();
}

void Player::Move()
{
	if (slipflag == false)
	{
		//�ړ����x�̏�����
		moveSpeed.x = 0.0f;
		moveSpeed.z = 0.0f;

		//�v���C���[�̈ړ�
		moveSpeed.x += StickL.x * -(0.8f * (6 - ironBall));
		moveSpeed.z += StickL.y * (0.8f * (6 - ironBall));
	}
	else
	{
		//�X�̏��ɏ�������̃v���C���[�̈ړ�
		moveSpeed.x += StickL.x * -(0.1f * (6 - ironBall));
		moveSpeed.z += StickL.y * (0.1f * (6 - ironBall));
	}

	/*if (moveSpeed.x > 4.8)
	{
		moveSpeed.x = 4.8;
	}
	if (moveSpeed.x < -4.8)
	{
		moveSpeed.x = -4.8;
	}
	if (moveSpeed.z > 4.8)
	{
		moveSpeed.z = 4.8;
	}
	if (moveSpeed.z < -4.8)
	{
		moveSpeed.z = -4.8;
	}*/

	/*if (characterController.IsOnGround())
	{
		moveSpeed.y = 0.0f;
	}
	else
	{
		moveSpeed.y = -2.5f;
	}*/

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
	//�S���N���X�œS���̏�������ς��邽�߂Ƀt���O�ϐ���ύX����
	if (g_pad[0]->IsTrigger(enButtonA) && ironBall < 5)
	{
		get_Iron = true;
	}

	if (g_pad[0]->IsTrigger(enButtonB) && ironBall > 0)
	{
		put_Iron = true;
	}
}

void Player::ManageState()
{
	//�v���C���[�X�e�[�g�̕ύX
	if (characterController.IsOnGround() == false)
	{
		//����
		playerState = 2;
	}
	else if (put_Iron == true)
	{
		//�u��
		playerState = 3;
	}
	else if (get_Iron == true)
	{
		//���
		playerState = 3;
	}
	else if (StickL.x != 0 && StickL.y != 0)
	{
		//����
		playerState = 1;
	}
	else
	{
		//����
		playerState = 0;
	}

}

void Player::Animation()
{
	switch (playerState)
	{
	//�������[�V����
	case 0:
		modelRender.PlayAnimation(enAnimationClip_Idle, 0.2f);
		break;
	//�������[�V����
	case 1:
		modelRender.PlayAnimation(enAnimationClip_Walk, 0.2f);
		break;
	//�������[�V����
	case 2:
		modelRender.PlayAnimation(enAnimationClip_Jump, 0.2f);
		break;
		//�ݒu���[�V����
	case 3:
		modelRender.PlayAnimation(enAnimationClip_Put);
		break;
	//
	default:
		break;
	}
}

void Player::Status()
{
	//�����Ă���S���̐��̕\��
	wchar_t iron[256];
	swprintf_s(iron, 256, L"�����S��:%d", int(ironBall));
	//�\������e�L�X�g��ݒ�B
	fontRender.SetText(iron);
	//�t�H���g�̈ʒu��ݒ�B
	fontRender.SetPosition(Vector3(-952.0f, 450.0f, 0.0f));
	//�t�H���g�̑傫����ݒ�B
	fontRender.SetScale(1.0f);

	//���W���m�F���邽�߂̃v���O����

	////�v���C���[�̍��W�̕\��
	//wchar_t playerX[256];
	//swprintf_s(playerX, 256, L"x���W:%d", int(player_P.x));
	////�\������e�L�X�g��ݒ�B
	//fontRender.SetText(playerX);
	////�t�H���g�̈ʒu��ݒ�B
	//fontRender.SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
	////�t�H���g�̑傫����ݒ�B
	//fontRender.SetScale(1.0f);

	//wchar_t playerZ[256];
	//swprintf_s(playerZ, 256, L"z���W:%d", int(player_P.z));
	////�\������e�L�X�g��ݒ�B
	//fontRender.SetText(playerZ);
	////�t�H���g�̈ʒu��ݒ�B
	//fontRender.SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
	////�t�H���g�̑傫����ݒ�B
	//fontRender.SetScale(1.0f);
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
	fontRender.Draw(rc);
}