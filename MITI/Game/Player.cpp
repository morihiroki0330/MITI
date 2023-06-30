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
#include "G_Kaidan.h"

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

	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			PlayerSetPosition[Y][X].x = (Y * 192.0f) + -865.0f;
			PlayerSetPosition[Y][X].y = NON;
			PlayerSetPosition[Y][X].z = (X * 192.0f) + -865.0f;
		}
	}

	InitAnimation();
	InitModel();
	InitSound();
	LevelSet();
	return true;
}

void Player::InitAnimation()
{
	AnimationClips[enAnimationClip_Idle].Load("Assets/character/oriidle.tka");
	AnimationClips[enAnimationClip_Idle].SetLoopFlag(true);
	AnimationClips[enAnimationClip_Walk].Load("Assets/character/oriwalk.tka");
	AnimationClips[enAnimationClip_Walk].SetLoopFlag(true);
	AnimationClips[enAnimationClip_Jump].Load("Assets/character/orifall.tka");
	AnimationClips[enAnimationClip_Jump].SetLoopFlag(false);
	AnimationClips[enAnimationClip_Put].Load("Assets/character/oriput.tka");
	AnimationClips[enAnimationClip_Put].SetLoopFlag(false);
	AnimationClips[enAnimationClip_Slip].Load("Assets/character/orislip.tka");
	AnimationClips[enAnimationClip_Slip].SetLoopFlag(true);
}

void Player::InitModel()
{
	PlayerModel.Init("Assets/Character/orichara.tkm", PlayerLight, AnimationClips, enAnimationClip_Num, enModelUpAxisZ);
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

void Player::GameOver()
{
	MoveSpeed.y = Gravity;

	if (PlayerPosition.y <= -30.0f && FallSet == false)
	{
		FallSet = true;
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_FALL, Bgm_Volume, LoopNot);
	}

	if (PlayerPosition.y <= UnderLimit)
	{
		game->GameOverFlagSet(true);
	}
}

void Player::DirectionSet()
{
	if (MoveSpeed.x < NON)
	{
		EnterDirection = Up;
	}else {
	if (MoveSpeed.x > NON)
	{
		EnterDirection = Down;
	}else {
	if (MoveSpeed.z > NON)
	{
		EnterDirection = Right;
	}else {
	if (MoveSpeed.z < NON)
	{
		EnterDirection = Left;
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
	if ((MoveSpeed.x < 0.0f || MoveSpeed.x > 0.0f || MoveSpeed.z > 0.0f || MoveSpeed.z < 0.0f) && SlipFlag == false)
	{
		WalkSe->Play(true);

	}else {
	if (MoveSpeed.x == 0.0f || MoveSpeed.z == 0.0f)
	{
		WalkSe->Pause();
	}
	}
}

void Player::IceWalkSound()
{
	if (SlipFlag == true)
	{
		IceWalkSe->Play(true);
	}else {
	if (SlipFlag == false)
	{
		IceWalkSe->Pause();
	}
	}
}

void Player::Update()
{
	Move();
	Rotation();
	Ball();
	ManageState();
	Animation();
	PlayerMapSet();
	GameOver();
	Sound();

	PlayerPosition = PlayerController.Execute(MoveSpeed, 1.0);
	PlayerModel.SetPosition(PlayerPosition);
	PlayerModel.SetRotation(PlayerRotation);
	PlayerModel.Update();
}
void Player::BoxHit()
{
	PhysicsWorld::GetInstance()->ContactTest(PlayerController, [&](const btCollisionObject& contactObject)
	{
		switch (EnterDirection)
		{
		case Left:
			if (box->BlockBox[(PlayerMap / 10)][(PlayerMap % 10) - 1].IsSelf(contactObject) == true)
			{
				HitFlagSet(true);
				SlipFlagSet(false);
			}else {
			if (box->KabeBox[LEFT].IsSelf(contactObject) == true)
			{
				HitFlagSet(true);
				SlipFlagSet(false);
			}else {
			if (box->KaidanBox.IsSelf(contactObject) == true)
			{
				game->ClearFlagSet(true);
				HitFlagSet(true);
				SlipFlagSet(false);
			}
			}
			}
			break;
		case Right:
			if (box->BlockBox[(PlayerMap / 10)][(PlayerMap % 10) + 1].IsSelf(contactObject) == true)
			{
				HitFlagSet(true);
				SlipFlagSet(false);
			}else {
			if (box->KabeBox[RIGHT].IsSelf(contactObject) == true)
			{
				HitFlagSet(true);
				SlipFlagSet(false);
			}else {
			if (box->KaidanBox.IsSelf(contactObject) == true)
			{
				game->ClearFlagSet(true);
				HitFlagSet(true);
				SlipFlagSet(false);
			}
			}
			}
			break;
		case Up:
			if (box->BlockBox[(PlayerMap / 10) - 1][(PlayerMap % 10)].IsSelf(contactObject) == true)
			{
				HitFlagSet(true);
				SlipFlagSet(false);
			}else {
			if (box->KabeBox[UP].IsSelf(contactObject) == true)
			{
				HitFlagSet(true);
				SlipFlagSet(false);
			}else {
			if (box->KaidanBox.IsSelf(contactObject) == true)
			{
				game->ClearFlagSet(true);
				HitFlagSet(true);
				SlipFlagSet(false);
			}
			}
			}
			break;
		case Down:
			if (box->BlockBox[(PlayerMap / 10) + 1][(PlayerMap % 10)].IsSelf(contactObject) == true)
			{
				HitFlagSet(true);
				SlipFlagSet(false);
			}else {
			if (box->KabeBox[Down].IsSelf(contactObject) == true)
			{
				HitFlagSet(true);
				SlipFlagSet(false);
			}else {
			if (box->KaidanBox.IsSelf(contactObject) == true)
			{
				game->ClearFlagSet(true);
				HitFlagSet(true);
				SlipFlagSet(false);				}
			}
			}
			break;
			default:
			break;
			}
		});
}
void Player::Move()
{
	StickL.x = g_pad[0]->GetLStickYF();
	StickL.y = g_pad[0]->GetLStickXF();
	
	BoxHit();
	DirectionSet();

	if (stage->MapData[(PlayerMap / 10)][(PlayerMap % 10)].GroundData == GROUND){SlipFlag = false;}

	if (SlipFlag == false)
	{
		MoveSpeed.x = NON;
		MoveSpeed.z = NON;
		if (PlayerController.IsOnGround() == true)
		{
			MoveSpeed.x += StickL.x * (-9.0f + ironBall / 4);
			MoveSpeed.z += StickL.y * (9.0f - ironBall / 4);
			if (abs(MoveSpeed.x) > abs(MoveSpeed.z))
			{
				MoveSpeed.z = NON;
			}
			if (abs(MoveSpeed.x) < abs(MoveSpeed.z))
			{
				MoveSpeed.x = NON;
			}
			if (IronPutAnim == true || IronGetAnim == true || game->GetClearFlag() == true)
			{
				MoveSpeed.x = NON;
				MoveSpeed.z = NON;
			}
		}
	}else{
	if (SlipFlag == true)
	{
		if (EnterDirection == Up)
		{
			MoveSpeed.z = NON;
			MoveSpeed.x = (-13.0f + ironBall / 4);
			if (stage->GetMapData(PlayerMap,PlayerMap,Up) == ICE || stage->GetMapData(PlayerMap, PlayerMap, Up) == HOLE)
			{
				SlipFlag = true;
			}
		}else {
		if (EnterDirection == Down)
		{
			MoveSpeed.z = NON;
			MoveSpeed.x = (13.0f + ironBall / 4);
			if (stage->GetMapData(PlayerMap, PlayerMap, Down) == ICE || stage->GetMapData(PlayerMap, PlayerMap, Down) == HOLE)
			{
				SlipFlag = true;
			}
		}else {
		if (EnterDirection == Right)
		{
			MoveSpeed.x = NON;
			MoveSpeed.z = (13.0f - ironBall / 4);
			if (stage->GetMapData(PlayerMap, PlayerMap, Right) == ICE || stage->GetMapData(PlayerMap, PlayerMap, Right) == HOLE)
			{
				SlipFlag = true;
			}
		}else {
		if (EnterDirection == Left)
		{
			MoveSpeed.x = NON;
			MoveSpeed.z = (-13.0f - ironBall / 4);
			if (stage->GetMapData(PlayerMap, PlayerMap, Left) == ICE || stage->GetMapData(PlayerMap, PlayerMap, Left) == HOLE)
			{
				SlipFlag = true;
			}
		}
		}
		}
		}
	}
	}

	
	if (game->GetClearFlag() == true && BgmSet == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_KAIDAN, Bgm_Volume, LoopNot);
		BgmSet = true;
	}
}

void Player::Rotation()
{
	if (fabsf(MoveSpeed.x) >= 0.001f || fabsf(MoveSpeed.z) >= 0.001f)
	{
		PlayerRotation.SetRotationYFromDirectionXZ(MoveSpeed);
	}
}

void Player::Ball()
{
	if (g_pad[0]->IsTrigger(enButtonA) && ironBall < ironball->GetIronBallMax() && stage->MapData[(PlayerMap / 10)][(PlayerMap % 10)].GroundData == GROUND)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->SoundSet(S_IRONBALLGET, Bgm_Volume, LoopNot);
		IronGet = true;
		ironball->BallMapSet(0);
	}

	if (g_pad[0]->IsTrigger(enButtonB) && ironBall > ironball->GetIronBallMin() && stage->MapData[(PlayerMap / 10)][(PlayerMap % 10)].GroundData == GROUND)
	{
		if (ironball->GetBallMap(PlayerMap) == false)
		{
			SoundSource* SE = NewGO<SoundSource>(0);
			SE->SoundSet(S_IRONBALLPUT, Bgm_Volume, LoopNot);
			IronPut = true;
			ironball->BallMapSet(PlayerMap);
		}
	}
}

void Player::ManageState()
{
	if (PlayerController.IsOnGround() == false)
	{
		PlayerState = 2;
	}
	else if (IronPutAnim == true)
	{
		PlayerState = 3;
	}
	else if (IronGetAnim == true)
	{
		PlayerState = 3;
	}
	else if (SlipFlag == true)
	{
		PlayerState = 4;
	}
	else if(StickL.x != 0 || StickL.y != 0)
	{
		PlayerState = 1;
	}
	else 
	{
		PlayerState = 0;
	}
}

void Player::Animation()
{
	switch (PlayerState)
	{
	case 0:
		PlayerModel.PlayAnimation(enAnimationClip_Idle, 0.2f);
		break;
	case 1:
		PlayerModel.PlayAnimation(enAnimationClip_Walk, 0.2f);
		break;
	case 2:
		PlayerModel.PlayAnimation(enAnimationClip_Jump, 0.2f);
		break;
	case 3:
		PlayerModel.PlayAnimation(enAnimationClip_Put);
		if (IronPutAnim == true)
		{
			Frame++;
			if (Frame >= 30)
			{
				IronPutAnim = false;
				Frame = 0;
			}
		}
		if (IronGetAnim == true)
		{
			Frame++;
			if (Frame >= 30)
			{
				IronGetAnim = false;
				Frame = 0;
			}
		}
		break;
	case 4:
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
				PlayerPosition.x < PlayerSetPosition[Y][X].x + 96 &&
				PlayerPosition.x > PlayerSetPosition[Y][X].x - 96 &&
				PlayerPosition.z < PlayerSetPosition[Y][X].z + 96 &&
				PlayerPosition.z > PlayerSetPosition[Y][X].z - 96
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