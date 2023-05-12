#include "stdafx.h"
#include "Player.h"
#include "Box.h"
#include "Stage.h"
#include "Game.h"
#include "Bgm.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Player::Player()
{
	Set = true;

	AnimationClips[enAnimationClip_Idle].Load("Assets/character/oriidle.tka");
	AnimationClips[enAnimationClip_Idle].SetLoopFlag(true);
	AnimationClips[enAnimationClip_Walk].Load("Assets/character/oriwalk.tka");
	AnimationClips[enAnimationClip_Walk].SetLoopFlag(true);
	AnimationClips[enAnimationClip_Jump].Load("Assets/character/orifall.tka");
	AnimationClips[enAnimationClip_Jump].SetLoopFlag(false);
	AnimationClips[enAnimationClip_Put].Load("Assets/character/oriput.tka");
	AnimationClips[enAnimationClip_Put].SetLoopFlag(false);

	Character.Init("Assets/Character/orichara.tkm",Light, AnimationClips, enAnimationClip_Num, enModelUpAxisZ);

	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			SetPosition[L][R].x = (L * 192.0f) + -865.0f;
			SetPosition[L][R].y = 0.0f;
			SetPosition[L][R].z = (R * 192.0f) + -865.0f;
		}
	}

	WALK = NewGO<SoundSource>(0);
	WALK->Init(S_WALK);
	WALK->SetVolume(0.2f);
	
	ICEWALK = NewGO<SoundSource>(0);
	ICEWALK->Init(S_ICEFLOOR);
	ICEWALK->SetVolume(0.2f);

}

Player::~Player()
{
	DeleteGO(WALK);
	DeleteGO(ICEWALK);
}

void Player::Update()
{

	game = FindGO<Game>("game");

	if (Set == true)
	{
		if (game->Level == 0)
		{
			Character_P = SetPosition[1][0];
		}

		if (game->Level == 1)
		{
			Character_P = SetPosition[1][0];
		}

		if (game->Level == 2)
		{
			Character_P = SetPosition[2][0];
		}
		
		if (game->Level == 3)
		{
			Character_P = SetPosition[9][0];
		}

		if (game->Level == 4)
		{
			Character_P = SetPosition[2][0];
		}

		Character.SetPosition(Character_P);
		Character.SetScale({ 1.5f,1.5f,1.5f });

		CharacterController.Init(40.0f, 120.0f, Character_P);
		Set = false;
	}


	MoveSpeed.y = -5.0f;

	//�S����������u����������Ă��Ȃ��Ƃ�
	if (get_IronAnim == false || put_IronAnim == false)
	{
		//�ړ�����
		Move();
		//��]����
		Rotation();
	}
	//�S������
	Ball();
	//�v���C���[�X�e�[�g����
	ManageState();
	//�A�j���[�V��������
	Animation();
	//�X�e�[�^�X�\������
	Status();

	Character.SetPosition(Character_P);
	Character.SetRotation(Character_R);
	Character.Update();
}

void Player::Move()
{

	if (Character_P.y <= -250.0)
	{
		game->GameOverFlag = true;
	}

	MoveSpeed.y = -5.0f;

	if (box == NULL)
	{
		box = FindGO<Box>("box");
	}

	if (stage == NULL)
	{
		stage = FindGO<Stage>("stage");
	}

	if (game == NULL)
	{
		game = FindGO<Game>("game");
	}

	//�X�e�B�b�N�̓��͗ʂ̎擾
	StickL.x = g_pad[0]->GetLStickYF();
	StickL.y = g_pad[0]->GetLStickXF();

	hitflag = false;
	PhysicsWorld::GetInstance()->ContactTest(CharacterController, [&](const btCollisionObject& contactObject) {
	//�E���獶
	if (EnterDirection == Left)
	{
		if (box->box[(player_map / 10)][(player_map % 10) - 1].IsSelf(contactObject) == true)
		{
			hitflag = true;
			slipflag = false;
		}else {
		if (box->box_soto[3].IsSelf(contactObject) == true)
		{
			hitflag = true;
			slipflag = false;
		}else {
		if (box->box_kaidan.IsSelf(contactObject) == true)
		{
			game->ClearFlag = true;
			hitflag = true;
			slipflag = false;
		}
		}
		}
	} else {
	//������E
	if (EnterDirection == Right)
	{
		if (box->box[(player_map / 10)][(player_map % 10) + 1].IsSelf(contactObject) == true)
		{
			hitflag = true;
			slipflag = false;
		}else {
		if (box->box_soto[2].IsSelf(contactObject) == true)
		{
			hitflag = true;
			slipflag = false;
		}else {
		if (box->box_kaidan.IsSelf(contactObject) == true)
		{
			game->ClearFlag = true;
			hitflag = true;
			slipflag = false;
		}
		}
		}
	}else {
	//�������
	if (EnterDirection == Up)
	{
		if (box->box[(player_map / 10) - 1][(player_map % 10)].IsSelf(contactObject) == true)
		{ 
			hitflag = true;
			slipflag = false;
		}else {
		if (box->box_soto[0].IsSelf(contactObject) == true)
		{
			hitflag = true;
			slipflag = false;
		}else {
		if (box->box_kaidan.IsSelf(contactObject) == true)
		{
			game->ClearFlag = true;
			hitflag = true;
			slipflag = false;
		}
		}
		}
	}else {
	//�ォ�牺
	if (EnterDirection == Down)
	{
		if (box->box[(player_map / 10) + 1][(player_map % 10)].IsSelf(contactObject) == true)
		{
			hitflag = true;
			slipflag = false;
		}
		else {
		if (box->box_soto[1].IsSelf(contactObject) == true)
		{
			hitflag = true;
			slipflag = false;
		}else {
		if (box->box_kaidan.IsSelf(contactObject) == true)
		{
			game->ClearFlag = true;
			hitflag = true;
			slipflag = false;
		}
		}
		}
	}
	}
	}
	}
	});

	if (stage->mapdata[(player_map / 10)][(player_map % 10)].grounddata == GROUND)
	{
		slipflag = false;
	}

	if (slipflag == false)
	{
		//�ړ����x�̏�����
		MoveSpeed.x = 0.0f;
		MoveSpeed.z = 0.0f;

		//�v���C���[�̈ړ�
		MoveSpeed.x += StickL.x * (-9.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
		MoveSpeed.z += StickL.y * (9.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
	}else{
	if (slipflag == true)
	{
		if (EnterDirection == Up)
		{
			MoveSpeed.z = 0.0f;
			MoveSpeed.x = (-13.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
			if (stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == ICE && stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Down)
		{
			MoveSpeed.z = 0.0f;
			MoveSpeed.x = (13.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
			if (stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == ICE && stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Right)
		{
			MoveSpeed.x = 0.0f;
			MoveSpeed.z = (13.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
			if (stage->mapdata[(player_map / 10)][(player_map % 10) + 1].grounddata == ICE && stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Left)
		{
			MoveSpeed.x = 0.0f;
			MoveSpeed.z = (-13.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
			if (stage->mapdata[(player_map / 10)][(player_map % 10) - 1].grounddata == ICE && stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}
		}
		}
		}
	}
		//if (Character_P.x == savePos.x && Character_P.z == savePos.z)
		//{
		//	MoveSpeed.x = 0.0f;
		//	MoveSpeed.z = 0.0f;
		//	//�v���C���[�̈ړ�

		//	MoveSpeed.x += StickL.x * (-5.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
		//	MoveSpeed.z += StickL.y * (5.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
		//	//slipflag = false;
		//}else{
		//	savePos.x = Character_P.x;
		//	savePos.z = Character_P.z;
		//}
	}

	if (MoveSpeed.x < 0.0f)
	{
		EnterDirection = Up;
	}else {
	if (MoveSpeed.x > 0.0f)
	{
		EnterDirection = Down;
	}else {
	if (MoveSpeed.z > 0.0f)
	{
		EnterDirection = Right;
	}else {
	if (MoveSpeed.z < 0.0f)
	{
		EnterDirection = Left;
	}
	}
	}
	}

	if ((MoveSpeed.x < 0.0f || MoveSpeed.x > 0.0f || MoveSpeed.z > 0.0f || MoveSpeed.z < 0.0f) && slipflag == false)
	{
		WALK->Play(true);
		
	}else {
	if (MoveSpeed.x == 0.0f || MoveSpeed.x == 0.0f || MoveSpeed.z == 0.0f || MoveSpeed.z == 0.0f)
	{
			WALK->Pause();
	}
	}
	
	if (slipflag == true)
	{
		ICEWALK->Play(true);
		WALK->Pause();
	}else {
	if (slipflag == false)
	{
		ICEWALK->Pause();
	}
	}
	
	
	/*if (MoveSpeed.x > 4.8)
	{
		MoveSpeed.x = 4.8;
	}
	if (MoveSpeed.x < -4.8)
	{
		MoveSpeed.x = -4.8;
	}
	if (MoveSpeed.z > 4.8)
	{
		MoveSpeed.z = 4.8;
	}
	if (MoveSpeed.z < -4.8)
	{
		MoveSpeed.z = -4.8;
	}*/

	/*if (CharacterController.IsOnGround())
	{
		MoveSpeed.y = 0.0f;
	}
	else
	{
		MoveSpeed.y = -2.5f;
	}*/

	//�L�����N�^�[�R���g���[���[���g���č��W�̈ړ�
	Character_P = CharacterController.Execute(MoveSpeed, 1.0);

	//slipflag = false;
}

void Player::Rotation()
{
	if (fabsf(MoveSpeed.x) >= 0.001f || fabsf(MoveSpeed.z) >= 0.001f)
	{
		//�L�����N�^�[�̕����ύX
		Character_R.SetRotationYFromDirectionXZ(MoveSpeed);
	}
}

void Player::Ball()
{
	//�S���N���X�œS���̏�������ς��邽�߂Ƀt���O�ϐ���ύX����
	if (g_pad[0]->IsTrigger(enButtonA) && ironBall < 5)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->Init(S_IRONBALLGET);
		SE->SetVolume(0.1f);
		SE->Play(false);
		get_Iron = true;
	}

	if (ironBall >= 5)
	{
		get_Ui = false;
	}else {
	if (ironBall < 5 && ironBall >= 0)
	{
		get_Ui = true;
	}
	}

	if (g_pad[0]->IsTrigger(enButtonB) && ironBall > 0)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->Init(S_IRONBALLPUT);
		SE->SetVolume(0.1f);
		SE->Play(false);
		put_Iron = true;

	}

	if (ironBall <= 0)
	{
		put_Ui = false;
	}else {
	if (ironBall <= 5 && ironBall >= 1)
	{
		put_Ui = true;
	}
	}

}

void Player::ManageState()
{
	//�v���C���[�X�e�[�g�̕ύX
		if (CharacterController.IsOnGround() == false)
		{
			//����
			playerState = 2;
		}
		else if (put_IronAnim == true)
		{
			//�u��
			playerState = 3;
		}
		else if (get_IronAnim == true)
		{
			//���
			playerState = 3;
		}
		else if (StickL.x != 0 || StickL.y != 0 && slipflag == false)
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
		Character.PlayAnimation(enAnimationClip_Idle, 0.2f);
		break;
	//�������[�V����
	case 1:
		Character.PlayAnimation(enAnimationClip_Walk, 0.2f);
		break;
	//�������[�V����
	case 2:
		Character.PlayAnimation(enAnimationClip_Jump, 0.2f);
		break;
	//�ݒu���[�V����
	case 3:
		Character.PlayAnimation(enAnimationClip_Put);
		if (put_IronAnim == true)
		{
			put_IronAnim = false;
		}
		if (get_IronAnim == true)
		{
			get_IronAnim = false;
		}
		break;
	default:
		break;
	}
}

void Player::Status()
{
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (
				Character_P.x < SetPosition[L][R].x + 96 &&
				Character_P.x > SetPosition[L][R].x - 96 &&
				Character_P.z < SetPosition[L][R].z + 96 &&
				Character_P.z > SetPosition[L][R].z - 96
				)
			{
				player_map = (L * 10) + R;
			}
		}
	}
	

	wchar_t playerX[256];
	if (slipflag == true)
	{
		swprintf_s(playerX, 256, L"�����Ă���:%d", player_map);
	}else {
	{
	if (slipflag == false)
		swprintf_s(playerX, 256, L"�����Ă��Ȃ�:%d", player_map);
	}
	}
	
	as.SetText(L"�Փ�");
	as.SetPosition(Vector3(-852.0f, 350.0f, 0.0f));
	as.SetScale(1.0f);
}

void Player::Render(RenderContext& rc)
{
	Character.Draw(rc);
	//fontRender.Draw(rc);
	if (hitflag == true)
	{
		/*as.Draw(rc);*/
	}

}