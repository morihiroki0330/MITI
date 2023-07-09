#include "stdafx.h"
#include "Player.h"
#include "Box.h"
#include "Stage.h"
#include "Game.h"
#include "Bgm.h"
#include "IronBall.h"
#include "Number_Storage.h"
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
	DeleteGO(WalkSe);
	DeleteGO(IceWalkSe);
}
bool Player::Start()
{
	box = FindGO<Box>("box");
	game = FindGO<Game>("game");
	stage = FindGO<Stage>("stage");
	ironball = FindGO<IronBall>("ironball");
	LevelSet();
	return true;
}

void Player::InitAnimation()
{
	PlayerAnimationClips[enAnimationClip_Idle].Load("Assets/character/oriidle.tka");
	PlayerAnimationClips[enAnimationClip_Idle].SetLoopFlag(true);
	PlayerAnimationClips[enAnimationClip_Walk].Load("Assets/character/oriwalk.tka");
	PlayerAnimationClips[enAnimationClip_Walk].SetLoopFlag(true);
	PlayerAnimationClips[enAnimationClip_Fall].Load("Assets/character/orifall.tka");
	PlayerAnimationClips[enAnimationClip_Fall].SetLoopFlag(false);
	PlayerAnimationClips[enAnimationClip_Put].Load("Assets/character/oriput.tka");
	PlayerAnimationClips[enAnimationClip_Put].SetLoopFlag(false);
	PlayerAnimationClips[enAnimationClip_Slip].Load("Assets/character/orislip.tka");
	PlayerAnimationClips[enAnimationClip_Slip].SetLoopFlag(true);
}
void Player::InitModel()
{
	PlayerModel.Init("Assets/Character/orichara.tkm", PlayerLight, PlayerAnimationClips, enAnimationClip_Num, enModelUpAxisZ);
}
void Player::InitSound()
{
	WalkSe = NewGO<SoundSource>(0);
	WalkSe->Init(S_WALK);
	WalkSe->SetVolume(0.2f);

	IceWalkSe = NewGO<SoundSource>(0);
	IceWalkSe->Init(S_ICEWALK);
	IceWalkSe->SetVolume(0.2f);
}
void Player::InitSetPosition()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			PlayerSetPosition[Y][X].x = (Y * 192.0f) + -865.0f;
			PlayerSetPosition[Y][X].y = 0.0f;
			PlayerSetPosition[Y][X].z = (X * 192.0f) + -865.0f;
		}
	}
}
void Player::LevelSet()
{
	switch (game->GetLevel())
	{
	case Level0:
		PlayerPosition = PlayerSetPosition[5][1];
		break;
	case Level1:
		PlayerPosition = PlayerSetPosition[2][0];
		break;
	case Level2:
		PlayerPosition = PlayerSetPosition[0][0];
		break;
	case Level3:
		PlayerPosition = PlayerSetPosition[2][0];
		break;
	case Level4:
		PlayerPosition = PlayerSetPosition[1][0];
		break;
	case Level5:
		PlayerPosition = PlayerSetPosition[9][0];
		break;
	case Level6:
		PlayerPosition = PlayerSetPosition[0][0];
		break;
	case Level7:
		PlayerPosition = PlayerSetPosition[0][0];
		break;
	case Level8:
		PlayerPosition = PlayerSetPosition[2][0];
		break;
	case Level9:
		PlayerPosition = PlayerSetPosition[0][0];
		break;
	default:
		break;
	}

	PlayerModel.SetPosition(PlayerPosition);
	PlayerModel.SetScale({ 1.5f,1.5f,1.5f });

	PlayerController.Init(CharacterControllerWide, CharacterControllerHeight, PlayerPosition);
}

void Player::PlayerGameOver()
{
	PlayerMoveSpeed.y = Gravity;

	if (PlayerPosition.y <= UnderHalfLimit && FallSet == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_FALL, BgmVolume, LoopNot);
		FallSet = true;
	}

	if (PlayerPosition.y <= UnderLimit)
	{
		game->GameOverFlagSet(true);
	}
}
void Player::PlayerGameClear()
{
	if (game->GetClearFlag() == true && BgmSet == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_KAIDAN, BgmVolume, LoopNot);
		BgmSet = true;
	}
}
void Player::PlayerDirectionSet()
{
	if (PlayerMoveSpeed.x < NON)
	{
		EnterDirection = PlayerDirectionUp;
	}else {
	if (PlayerMoveSpeed.x > NON)
	{
		EnterDirection = PlayerDirectionDown;
	}else {
	if (PlayerMoveSpeed.z > NON)
	{
		EnterDirection = PlayerDirectionRight;
	}else {
	if (PlayerMoveSpeed.z < NON)
	{
		EnterDirection = PlayerDirectionLeft;
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
	if ((PlayerMoveSpeed.x < NON || PlayerMoveSpeed.x > NON || PlayerMoveSpeed.z > NON || PlayerMoveSpeed.z < NON) && GetPlayerSlipFlag() == false)
	{
		WalkSe->Play(true);

	}else {
	if (PlayerMoveSpeed.x == NON || PlayerMoveSpeed.z == NON)
	{
		WalkSe->Pause();
	}
	}
}
void Player::IceWalkSound()
{
	if (GetPlayerSlipFlag() == true)
	{
		IceWalkSe->Play(true);
	}else {
	if (GetPlayerSlipFlag() == false)
	{
		IceWalkSe->Pause();
	}
	}
}

void Player::Update()
{
	PlayerToMove();
	PlayerToRotation();
	PlayerToIronBall();

	PlayerManageState();
	PlayerAnimation();

	PlayerMapSet();

	PlayerGameOver();
	PlayerGameClear();
	Sound();

	PlayerPosition = PlayerController.Execute(PlayerMoveSpeed, 1.0);
	PlayerModel.SetPosition(PlayerPosition);
	PlayerModel.SetRotation(PlayerRotation);
	PlayerModel.Update();
}

void Player::PlayerToMove()
{
	ControllerStickLeft.x = g_pad[0]->GetLStickYF();
	ControllerStickLeft.y = g_pad[0]->GetLStickXF();
	
	PlayerCollisionBlock();
	PlayerDirectionSet();
	PlayerOnIceFloor();
	
	if (GetPlayerSlipFlag() == false)
	{
		PlayerMoveSpeed.x = NON;
		PlayerMoveSpeed.z = NON;
		if (PlayerController.IsOnGround() == true)
		{
			PlayerMoveSpeed.x += ControllerStickLeft.x * (-9.0f + IronBallCount / 4);
			PlayerMoveSpeed.z += ControllerStickLeft.y * (9.0f - IronBallCount / 4);
			if (abs(PlayerMoveSpeed.x) > abs(PlayerMoveSpeed.z))
			{
				PlayerMoveSpeed.z = NON;
			}
			if (abs(PlayerMoveSpeed.x) < abs(PlayerMoveSpeed.z))
			{
				PlayerMoveSpeed.x = NON;
			}
			if (IronBallPutAnimationFlag == true || IronBallGetAnimationFlag == true || game->GetClearFlag() == true)
			{
				PlayerMoveSpeed.x = NON;
				PlayerMoveSpeed.z = NON;
			}
		}
	}else{
	if (GetPlayerSlipFlag() == true)
	{
		if (EnterDirection == PlayerDirectionUp)
		{
			PlayerMoveSpeed.z = NON;
			PlayerMoveSpeed.x = (-13.0f + IronBallCount / 4);
			if (stage->GetGroundData(PlayerMap,PlayerDirectionUp) == ICE || stage->GetGroundData(PlayerMap,PlayerDirectionUp) == HOLE)
			{
				PlayerSlipFlag = true;
			}
		}else {
		if (EnterDirection == PlayerDirectionDown)
		{
			PlayerMoveSpeed.z = NON;
			PlayerMoveSpeed.x = (13.0f + IronBallCount / 4);
			if (stage->GetGroundData(PlayerMap,PlayerDirectionDown) == ICE || stage->GetGroundData(PlayerMap,PlayerDirectionDown) == HOLE)
			{
				PlayerSlipFlag = true;
			}
		}else {
		if (EnterDirection == PlayerDirectionRight)
		{
			PlayerMoveSpeed.x = NON;
			PlayerMoveSpeed.z = (13.0f - IronBallCount / 4);
			if (stage->GetGroundData(PlayerMap,PlayerDirectionRight) == ICE || stage->GetGroundData(PlayerMap,PlayerDirectionRight) == HOLE)
			{
				PlayerSlipFlag = true;
			}
		}else {
		if (EnterDirection == PlayerDirectionLeft)
		{
			PlayerMoveSpeed.x = NON;
			PlayerMoveSpeed.z = (-13.0f - IronBallCount / 4);
			if (stage->GetGroundData(PlayerMap,PlayerDirectionLeft) == ICE || stage->GetGroundData(PlayerMap,PlayerDirectionLeft) == HOLE)
			{
				PlayerSlipFlag = true;
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
	PhysicsWorld::GetInstance()->ContactTest(PlayerController, [&](const btCollisionObject& contactObject)
	{
		switch (EnterDirection)
		{
		case PlayerDirectionLeft:
			if (box->BlockIsSelf((PlayerMap / 10), (PlayerMap % 10) - 1, contactObject) == true)
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
			if (box->KabeIsSelf(StageBehindLeft,contactObject) == true)
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
			if (box->KaidanIsSelf(contactObject) == true)
			{
				game->ClearFlagSet(true);
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}
			}
			}
			break;
		case PlayerDirectionRight:
			if (box->BlockIsSelf((PlayerMap / 10), (PlayerMap % 10) + 1, contactObject) == true)
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
			if (box->KabeIsSelf(StageBehindRight, contactObject) == true)
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
			if (box->KaidanIsSelf(contactObject) == true)
			{
				game->ClearFlagSet(true);
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}
			}
			}
			break;
		case PlayerDirectionUp:
			if (box->BlockIsSelf((PlayerMap / 10) - 1, (PlayerMap % 10), contactObject) == true)
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
			if (box->KabeIsSelf(StageBehindUp, contactObject) == true)
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
			if (box->KaidanIsSelf(contactObject) == true)
			{
				game->ClearFlagSet(true);
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}
			}
			}
			break;
		case PlayerDirectionDown:
			if (box->BlockIsSelf((PlayerMap / 10) + 1, (PlayerMap % 10), contactObject) == true)
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
			if (box->KabeIsSelf(StageBehindDown, contactObject) == true)
			{
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);
			}else {
			if (box->KaidanIsSelf(contactObject) == true)
			{
				game->ClearFlagSet(true);
				PlayerCollisionFlagSet(true);
				PlayerSlipFlagSet(false);				
			}
			}
			}
			break;
			}
		});
}
void Player::PlayerToRotation()
{
	if (fabsf(PlayerMoveSpeed.x) >= 0.001f || fabsf(PlayerMoveSpeed.z) >= 0.001f)
	{
		PlayerRotation.SetRotationYFromDirectionXZ(PlayerMoveSpeed);
	}
}
void Player::PlayerToIronBall()
{
	if (g_pad[0]->IsTrigger(enButtonA) && IronBallCount < ironball->GetIronBallMax() && IronBallCount >= ironball->GetIronBallMin() && stage->GetGroundData(PlayerMap) == GROUND)
	{
		if (ironball->GetBallMap(PlayerMap) == true)
		{
			SoundSource* SE = NewGO<SoundSource>(0);
			SE->SoundSet(S_IRONBALLGET, BgmVolume, LoopNot);
			IronBallGetFlag = true;
			ironball->IronBallMapSet(PlayerMap,Get);
		}
	}

	if (g_pad[0]->IsTrigger(enButtonB) && IronBallCount > ironball->GetIronBallMin() && IronBallCount <= ironball->GetIronBallMax() && stage->GetGroundData(PlayerMap) == GROUND)
	{
		if (ironball->GetBallMap(PlayerMap) == false)
		{
			SoundSource* SE = NewGO<SoundSource>(0);
			SE->SoundSet(S_IRONBALLPUT, BgmVolume, LoopNot);
			IronBallPutFlag = true;
			ironball->IronBallMapSet(PlayerMap,Put);
		}
	}
}
void Player::PlayerOnIceFloor()
{
	if (stage->GetGroundData(GetPlayerMap()) == GROUND) { PlayerSlipFlagSet(false); }
}

void Player::PlayerManageState()
{
	if (PlayerController.IsOnGround() == false)
	{
		PlayerState = PlayerAnimationFall;
	}else 
	if (IronBallPutAnimationFlag == true)
	{
		PlayerState = PlayerAnimationPut;
	}else 
	if (IronBallGetAnimationFlag == true)
	{
		PlayerState = PlayerAnimationPut;
	}else 
	if (GetPlayerSlipFlag() == true)
	{
		PlayerState = PlayerAnimationSlip;
	}else 
	if(ControllerStickLeft.x != NON || ControllerStickLeft.y != NON)
	{
		PlayerState = PlayerAnimationWalk;
	}else 
	{
		PlayerState = PlayerAnimationIdle;
	}
}
void Player::PlayerAnimation()
{
	switch (PlayerState)
	{
	case PlayerAnimationIdle:
		PlayerModel.PlayAnimation(enAnimationClip_Idle, 0.2f);
		break;
	case PlayerAnimationWalk:
		PlayerModel.PlayAnimation(enAnimationClip_Walk, 0.2f);
		break;
	case PlayerAnimationFall:
		PlayerModel.PlayAnimation(enAnimationClip_Fall, 0.2f);
		break;
	case PlayerAnimationPut:
		PlayerModel.PlayAnimation(enAnimationClip_Put);
		if (IronBallPutAnimationFlag == true)
		{
			Frame++;
			if (Frame >= 30)
			{
				IronBallPutAnimationFlag = false;
				Frame = 0;
			}
		}
		if (IronBallGetAnimationFlag == true)
		{
			Frame++;
			if (Frame >= 30)
			{
				IronBallGetAnimationFlag = false;
				Frame = 0;
			}
		}
		break;
	case PlayerAnimationSlip:
		PlayerModel.PlayAnimation(enAnimationClip_Slip);
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
				PlayerPosition.x < PlayerSetPosition[Y][X].x + BlockHalfX &&
				PlayerPosition.x > PlayerSetPosition[Y][X].x - BlockHalfX &&
				PlayerPosition.z < PlayerSetPosition[Y][X].z + BlockHalfZ &&
				PlayerPosition.z > PlayerSetPosition[Y][X].z - BlockHalfZ
				)
			{
				PlayerMap = (Y * 10) + X;
			}
		}
	}
}

void Player::Render(RenderContext& rc)
{
	PlayerModel.Draw(rc);
}

int Player::GetDirectionController(Vector3 Pos)
{
	if (abs(Pos.x) > abs(Pos.y))
	{
		if (Pos.x > 0.0f)
		{
			return MoveRight;
		}else {
		if (Pos.x < 0.0f)
		{
			return MoveLeft;
		}
		}
	}else {
	if (abs(Pos.x) < abs(Pos.y))
	{
		if (Pos.y > 0.0f)
		{
			return MoveUp;
		}else {
		if (Pos.y < 0.0f)
		{
			return MoveDown;
		}
		}
	}else {
	if (abs(Pos.x) == 0.0f && abs(Pos.y) == 0.0f)
	{
		return Non;
	}
	}
	}
}