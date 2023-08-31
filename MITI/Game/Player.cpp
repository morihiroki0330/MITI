#include "stdafx.h"
#include "Player.h"
#include "Box.h"
#include "Stage.h"
#include "Game.h"
#include "Bgm.h"
#include "IronBall.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
Player::Player()
{
	InitAnimation();
	InitModel();
	InitSound();
	InitSetPosition();
}
Player::~Player()
{
	DeleteGO(P_WalkSe);
	DeleteGO(P_IceWalkSe);
}
bool Player::Start()
{
	P_Box = FindGO<Box>("box");
	P_Game = FindGO<Game>("game");
	P_Stage = FindGO<Stage>("stage");
	P_IronBall = FindGO<IronBall>("ironball");
	LevelSet();
	return true;
}

void Player::InitAnimation()
{
	M_PlayerAnimationClips[ANIMATIONClLIP_IDLE].Load("Assets/character/oriidle.tka");
	M_PlayerAnimationClips[ANIMATIONClLIP_IDLE].SetLoopFlag(true);
	M_PlayerAnimationClips[ANIMATIONClLIP_WALK].Load("Assets/character/oriwalk.tka");
	M_PlayerAnimationClips[ANIMATIONClLIP_WALK].SetLoopFlag(true);
	M_PlayerAnimationClips[ANIMATIONClLIP_FALL].Load("Assets/character/orifall.tka");
	M_PlayerAnimationClips[ANIMATIONClLIP_FALL].SetLoopFlag(false);
	M_PlayerAnimationClips[ANIMATIONClLIP_PUT].Load("Assets/character/oriput.tka");
	M_PlayerAnimationClips[ANIMATIONClLIP_PUT].SetLoopFlag(false);
	M_PlayerAnimationClips[ANIMATIONClLIP_SLIP].Load("Assets/character/orislip.tka");
	M_PlayerAnimationClips[ANIMATIONClLIP_SLIP].SetLoopFlag(true);
}
void Player::InitModel()
{
	M_PlayerModel.Init("Assets/Character/orichara.tkm", M_PlayerLight, M_PlayerAnimationClips, ANIMATIONClLIP_NUM, enModelUpAxisZ);
}
void Player::InitSound()
{
	P_WalkSe = NewGO<SoundSource>(0);
	P_WalkSe->Init(SE_WALK);
	P_WalkSe->SetVolume(0.2f);

	P_IceWalkSe = NewGO<SoundSource>(0);
	P_IceWalkSe->Init(SE_ICEWALK);
	P_IceWalkSe->SetVolume(0.2f);
}
void Player::InitSetPosition()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_PlayerSetPosition[Y][X].x = (Y * 192.0f) + -865.0f;
			M_PlayerSetPosition[Y][X].y = 0.0f;
			M_PlayerSetPosition[Y][X].z = (X * 192.0f) + -865.0f;
		}
	}
}
void Player::LevelSet()
{
	switch (P_Game->GetLevel())
	{
	case LEVEL0:
		M_PlayerPosition = M_PlayerSetPosition[5][1];
		break;
	case LEVEL1:
		M_PlayerPosition = M_PlayerSetPosition[2][0];
		break;
	case LEVEL2:
		M_PlayerPosition = M_PlayerSetPosition[0][0];
		break;
	case LEVEL3:
		M_PlayerPosition = M_PlayerSetPosition[2][0];
		break;
	case LEVEL4:
		M_PlayerPosition = M_PlayerSetPosition[1][0];
		break;
	case LEVEL5:
		M_PlayerPosition = M_PlayerSetPosition[9][0];
		break;
	case LEVEL6:
		M_PlayerPosition = M_PlayerSetPosition[0][0];
		break;
	case LEVEL7:
		M_PlayerPosition = M_PlayerSetPosition[0][0];
		break;
	case LEVEL8:
		M_PlayerPosition = M_PlayerSetPosition[2][0];
		break;
	case LEVEL9:
		M_PlayerPosition = M_PlayerSetPosition[0][0];
		break;
	default:
		break;
	}

	M_PlayerModel.SetPosition(M_PlayerPosition);
	M_PlayerModel.SetScale({ 1.5f,1.5f,1.5f });
	M_PlayerController.Init(S_PlayerInformation.M_CharacterControllerWide, S_PlayerInformation.M_CharacterControllerHeight, M_PlayerPosition);
}

void Player::PlayerGameOver()
{
	M_PlayerMoveSpeed.y = S_WorldInformation.M_Gravity;

	if (M_PlayerPosition.y <= S_WorldInformation.M_UnderHalfLimit && !M_FallSet)
	{
		SoundSource* P_Se = NewGO<SoundSource>(0);
		P_Se->SoundSet(SE_FALL, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_LoopNot);
		M_FallSet = true;
	}

	if (M_PlayerPosition.y <= S_WorldInformation.M_UnderLimit)
	{
		P_Game->GameOverFlagSet(true);
	}
}
void Player::PlayerGameClear()
{
	if (P_Game->GetClearFlag() == true && !M_BgmSet)
	{
		SoundSource* P_Se = NewGO<SoundSource>(0);
		P_Se->SoundSet(SE_KAIDAN, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_LoopNot);
		M_BgmSet = true;
	}
}
void Player::PlayerDirectionSet()
{
	if (M_PlayerMoveSpeed.x < S_PlayerInformation.M_MinMoveSpeed)
	{
		M_EnterDirection = PLAYERDIRECTION_UP;
	}else {
		if (M_PlayerMoveSpeed.x > S_PlayerInformation.M_MinMoveSpeed)
		{
			M_EnterDirection = PLAYERDIRECTION_DOWN;
		}else {
			if (M_PlayerMoveSpeed.z > S_PlayerInformation.M_MinMoveSpeed)
			{
				M_EnterDirection = PLAYERDIRECTION_RIGHT;
			}else {
				if (M_PlayerMoveSpeed.z < S_PlayerInformation.M_MinMoveSpeed)
				{
					M_EnterDirection = PLAYERDIRECTION_LEFT;
				}
			}
		}
	}
}

void Player::Sound()
{
	WalkSound();
	IceWalkSound();
}
void Player::WalkSound()
{
	if ((M_PlayerMoveSpeed.x < S_PlayerInformation.M_MinMoveSpeed || M_PlayerMoveSpeed.x > S_PlayerInformation.M_MinMoveSpeed || M_PlayerMoveSpeed.z > S_PlayerInformation.M_MinMoveSpeed || M_PlayerMoveSpeed.z < S_PlayerInformation.M_MinMoveSpeed) && !GetPlayerSlipFlag())
	{
		P_WalkSe->Play(true);

	}else {
		if (M_PlayerMoveSpeed.x == S_PlayerInformation.M_MinMoveSpeed || M_PlayerMoveSpeed.z == S_PlayerInformation.M_MinMoveSpeed)
		{
			P_WalkSe->Pause();
		}
	}
}
void Player::IceWalkSound()
{
	if (GetPlayerSlipFlag())
	{
		P_IceWalkSe->Play(true);
	}else {
		if (!GetPlayerSlipFlag())
		{
			P_IceWalkSe->Pause();
		}
	}
}

void Player::Update()
{
	if (P_Game->GetPauseFlag())
	{
		return;
	}

	PlayerToMove();
	PlayerToRotation();
	PlayerToIronBall();

	PlayerManageState();
	PlayerAnimation();

	PlayerMapSet();

	PlayerGameOver();
	PlayerGameClear();
	Sound();

	M_PlayerPosition = M_PlayerController.Execute(M_PlayerMoveSpeed, 1.0);
	M_PlayerModel.SetPosition(M_PlayerPosition);
	M_PlayerModel.SetRotation(M_PlayerRotation);
	M_PlayerModel.Update();
}

void Player::PlayerToMove()
{
	M_ControllerStickLeft.x = g_pad[0]->GetLStickXF();
	M_ControllerStickLeft.y = g_pad[0]->GetLStickYF();

	PlayerCollisionBlock();
	PlayerDirectionSet();
	PlayerOnIceFloor();

	if (!GetPlayerSlipFlag())
	{
		M_PlayerMoveSpeed.x = S_PlayerInformation.M_MinMoveSpeed;
		M_PlayerMoveSpeed.z = S_PlayerInformation.M_MinMoveSpeed;
		if (M_PlayerController.IsOnGround())
		{
			if (P_Game->GetGameOverFlag())
			{
				M_PlayerMoveSpeed.x = S_PlayerInformation.M_MinMoveSpeed;
				M_PlayerMoveSpeed.z = S_PlayerInformation.M_MinMoveSpeed;
			}else {
				
				M_PlayerMoveSpeed.x += M_ControllerStickLeft.y * (-9.0f + M_IronBallCount / 4);
				M_PlayerMoveSpeed.z += M_ControllerStickLeft.x * (9.0f - M_IronBallCount / 4);

				if (abs(M_PlayerMoveSpeed.x) > abs(M_PlayerMoveSpeed.z))
				{
					M_PlayerMoveSpeed.z = S_PlayerInformation.M_MinMoveSpeed;
				}
				if (abs(M_PlayerMoveSpeed.x) < abs(M_PlayerMoveSpeed.z))
				{
					M_PlayerMoveSpeed.x = S_PlayerInformation.M_MinMoveSpeed;
				}
				if (M_IronBallPutAnimationFlagDecision || M_IronBallGetAnimationFlagDecision || P_Game->GetClearFlag())
				{
					M_PlayerMoveSpeed.x = S_PlayerInformation.M_MinMoveSpeed;
					M_PlayerMoveSpeed.z = S_PlayerInformation.M_MinMoveSpeed;
				}
			}
		}
	}
	else {
		if (GetPlayerSlipFlag())
		{
			if (P_Game->GetGameOverFlag())
			{
				M_PlayerMoveSpeed.x = S_PlayerInformation.M_MinMoveSpeed;
				M_PlayerMoveSpeed.z = S_PlayerInformation.M_MinMoveSpeed;
			}else {
				if (M_PlayerMoveMap == M_PlayerMap)
				{
					M_PlayerMoveSpeed.x = (M_PlayerSetPosition[M_PlayerMoveMap / 10][M_PlayerMoveMap % 10].x - M_PlayerPosition.x);
					M_PlayerMoveSpeed.z = (M_PlayerSetPosition[M_PlayerMoveMap / 10][M_PlayerMoveMap % 10].z - M_PlayerPosition.z);
					M_PlayerMoveMap = 99;
					M_MoveFlagDecision = false;
				}else{
					if (M_EnterDirection == PLAYERDIRECTION_UP)
					{
						M_PlayerMoveSpeed.z = S_PlayerInformation.M_MinMoveSpeed;
						M_PlayerMoveSpeed.x = (-13.0f + M_IronBallCount / 4);
						if (P_Stage->GetGroundData(M_PlayerMap, PLAYERDIRECTION_UP) == ICE || P_Stage->GetGroundData(M_PlayerMap, PLAYERDIRECTION_UP) == HOLE)
						{
							M_PlayerSlipFlagDecision = true;
						}
					}else {
						if (M_EnterDirection == PLAYERDIRECTION_DOWN)
						{
							M_PlayerMoveSpeed.z = S_PlayerInformation.M_MinMoveSpeed;
							M_PlayerMoveSpeed.x = (13.0f - M_IronBallCount / 4);
							if (P_Stage->GetGroundData(M_PlayerMap, PLAYERDIRECTION_DOWN) == ICE || P_Stage->GetGroundData(M_PlayerMap, PLAYERDIRECTION_DOWN) == HOLE)
							{
								M_PlayerSlipFlagDecision = true;
							}
						}else {
							if (M_EnterDirection == PLAYERDIRECTION_RIGHT)
							{
								M_PlayerMoveSpeed.x = S_PlayerInformation.M_MinMoveSpeed;
								M_PlayerMoveSpeed.z = (13.0f - M_IronBallCount / 4);
								if (P_Stage->GetGroundData(M_PlayerMap, PLAYERDIRECTION_RIGHT) == ICE || P_Stage->GetGroundData(M_PlayerMap, PLAYERDIRECTION_RIGHT) == HOLE)
								{
									M_PlayerSlipFlagDecision = true;
								}
							}else {
								if (M_EnterDirection == PLAYERDIRECTION_LEFT)
								{
									M_PlayerMoveSpeed.x = S_PlayerInformation.M_MinMoveSpeed;
									M_PlayerMoveSpeed.z = (-13.0f + M_IronBallCount / 4);
									if (P_Stage->GetGroundData(M_PlayerMap, PLAYERDIRECTION_LEFT) == ICE || P_Stage->GetGroundData(M_PlayerMap, PLAYERDIRECTION_LEFT) == HOLE)
									{
										M_PlayerSlipFlagDecision = true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void Player::PlayerCollisionBlock()
{
	PhysicsWorld::GetInstance()->ContactTest(M_PlayerController, [&](const btCollisionObject& contactObject)
	{
		switch (M_EnterDirection)
		{
		case PLAYERDIRECTION_LEFT:
			if (P_Box->BlockIsSelf((M_PlayerMap / 10), (M_PlayerMap % 10) - 1, contactObject))
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
				if (P_Box->KabeIsSelf(STAGEBEHIND_LEFT,contactObject))
				{
					PlayerCollisionFlagSet(true);
					PlayerSlipFlagSet(false);
				}else {
					if (P_Box->KaidanIsSelf(contactObject))
					{
						if (!P_Game->GetGameOverFlag())
						{
							P_Game->ClearFlagSet(true);
							PlayerCollisionFlagSet(true);
							PlayerSlipFlagSet(false);
					}
				}
			}
			}
			break;
		case PLAYERDIRECTION_RIGHT:
			if (P_Box->BlockIsSelf((M_PlayerMap / 10), (M_PlayerMap % 10) + 1, contactObject))
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
				if (P_Box->KabeIsSelf(STAGEBEHIND_RIGHT, contactObject))
				{
					PlayerCollisionFlagSet(true);
					PlayerSlipFlagSet(false);
				}else {
					if (P_Box->KaidanIsSelf(contactObject))
					{
						if (!P_Game->GetGameOverFlag())
						{
							P_Game->ClearFlagSet(true);
							PlayerCollisionFlagSet(true);
							PlayerSlipFlagSet(false);
						}
					}
				}
			}
			break;
		case PLAYERDIRECTION_UP:
			if (P_Box->BlockIsSelf((M_PlayerMap / 10) - 1, (M_PlayerMap % 10), contactObject))
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
				if (P_Box->KabeIsSelf(STAGEBEHIND_UP, contactObject))
				{
					PlayerCollisionFlagSet(true);
					PlayerSlipFlagSet(false);
				}else {
					if (P_Box->KaidanIsSelf(contactObject))
					{
						if (!P_Game->GetGameOverFlag())
						{
							P_Game->ClearFlagSet(true);
							PlayerCollisionFlagSet(true);
							PlayerSlipFlagSet(false);
						}
					}
				}
			}
			break;
		case PLAYERDIRECTION_DOWN:
			if (P_Box->BlockIsSelf((M_PlayerMap / 10) + 1, (M_PlayerMap % 10), contactObject))
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
				if (P_Box->KabeIsSelf(STAGEBEHIND_DOWN, contactObject))
				{
					PlayerCollisionFlagSet(true);
					PlayerSlipFlagSet(false);
				}else {
					if (P_Box->KaidanIsSelf(contactObject))
					{
						if (!P_Game->GetGameOverFlag())
						{
							P_Game->ClearFlagSet(true);
							PlayerCollisionFlagSet(true);
							PlayerSlipFlagSet(false);
						}
					}
				}
			}
			break;
			}
		});
}
void Player::PlayerToRotation()
{
	if (fabsf(M_PlayerMoveSpeed.x) >= 0.001f || fabsf(M_PlayerMoveSpeed.z) >= 0.001f)
	{
		M_PlayerRotation.SetRotationYFromDirectionXZ(M_PlayerMoveSpeed);
	}
}
void Player::PlayerToIronBall()
{
	if (g_pad[0]->IsTrigger(enButtonA) && M_IronBallCount < P_IronBall->GetIronBallMax() && M_IronBallCount >= P_IronBall->GetIronBallMin() && P_Stage->GetGroundData(M_PlayerMap) == GROUND && !M_MoveFlagDecision)
	{
		if (P_IronBall->GetBallMap(M_PlayerMap))
		{
			SoundSource* P_Se = NewGO<SoundSource>(0);
			P_Se->SoundSet(SE_IRONBALLGET, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_LoopNot);
			M_IronBallGetFlagDecision = true;
			P_IronBall->IronBallMapSet(M_PlayerMap,false);
		}
	}

	if (g_pad[0]->IsTrigger(enButtonB) && M_IronBallCount > P_IronBall->GetIronBallMin() && M_IronBallCount <= P_IronBall->GetIronBallMax() && P_Stage->GetGroundData(M_PlayerMap) == GROUND && !M_MoveFlagDecision)
	{
		if (!P_IronBall->GetBallMap(M_PlayerMap))
		{
			SoundSource* P_Se = NewGO<SoundSource>(0);
			P_Se->SoundSet(SE_IRONBALLPUT, S_SoundSetting.M_BgmVolume, S_SoundSetting.M_LoopNot);
			M_IronBallPutFlagDecision = true;
			P_IronBall->IronBallMapSet(M_PlayerMap,true);
		}
	}
}
void Player::PlayerOnIceFloor()
{
	if (P_Stage->GetGroundData(GetPlayerMap()) == GROUND) { PlayerSlipFlagSet(false); }
}

void Player::PlayerManageState()
{
	if (!M_PlayerController.IsOnGround())
	{
		M_PlayerState = PLAYERANIMATION_FALL;
	}else 
		if (M_IronBallPutAnimationFlagDecision)
		{
			M_PlayerState = PLAYERANIMATION_PUT;
		}else 
			if (M_IronBallGetAnimationFlagDecision)
			{
				M_PlayerState = PLAYERANIMATION_PUT;
			}else 
				if (GetPlayerSlipFlag())
				{
					M_PlayerState = PLAYERANIMATION_SLIP;
				}else 
					if(M_PlayerMoveSpeed.x != 0.0f || M_PlayerMoveSpeed.z != 0.0f)
					{
						M_PlayerState = PLAYERANIMATION_WALK;
						}else 
							{
								M_PlayerState = PLAYERANIMATION_IDLE;
	}
}
void Player::PlayerAnimation()
{
	switch (M_PlayerState)
	{
	case PLAYERANIMATION_IDLE:
		M_PlayerModel.PlayAnimation(ANIMATIONClLIP_IDLE, 0.2f);
		break;
	case PLAYERANIMATION_WALK:
		M_PlayerModel.PlayAnimation(ANIMATIONClLIP_WALK, 0.2f);
		break;
	case PLAYERANIMATION_FALL:
		M_PlayerModel.PlayAnimation(ANIMATIONClLIP_FALL, 0.2f);
		break;
	case PLAYERANIMATION_PUT:
		M_PlayerModel.PlayAnimation(ANIMATIONClLIP_PUT);
		if (M_IronBallPutAnimationFlagDecision)
		{
			M_Frame++;
			if (M_Frame >= 30)
			{
				M_IronBallPutAnimationFlagDecision = false;
				M_Frame = 0;
			}
		}
		if (M_IronBallGetAnimationFlagDecision)
		{
			M_Frame++;
			if (M_Frame >= 30)
			{
				M_IronBallGetAnimationFlagDecision = false;
				M_Frame = 0;
			}
		}
		break;
	case PLAYERANIMATION_SLIP:
		M_PlayerModel.PlayAnimation(ANIMATIONClLIP_SLIP);
	default:
		break;
	}
}

void Player::PlayerMapSet()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (
				M_PlayerPosition.x < M_PlayerSetPosition[Y][X].x + 96.0f &&
				M_PlayerPosition.x > M_PlayerSetPosition[Y][X].x - 96.0f &&
				M_PlayerPosition.z < M_PlayerSetPosition[Y][X].z + 96.0f &&
				M_PlayerPosition.z > M_PlayerSetPosition[Y][X].z - 96.0f
				)
			{
				M_PlayerMap = (Y * 10) + X;
			}
		}
	}
}

void Player::Render(RenderContext& rc)
{
	M_PlayerModel.Draw(rc);
}

int Player::GetDirectionController(Vector3 Pos)
{
	if (abs(Pos.x) > abs(Pos.y))
	{
		if (Pos.x > 0.0f)
		{
			return MOVE_RIGHT;
		}else {
			if (Pos.x < 0.0f)
			{
				return MOVE_LEFT;
			}
		}
	}else {
	if (abs(Pos.x) < abs(Pos.y))
	{
		if (Pos.y > 0.0f)
		{
			return MOVE_UP;
		}else {
			if (Pos.y < 0.0f)
			{
				return MOVE_DOWN;
			}
		}
	}else {
	if (abs(Pos.x) == 0.0f && abs(Pos.y) == 0.0f)
	{
		return 0.0f;
	}
	}
	}
}