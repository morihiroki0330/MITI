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
	Set = true;

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
	stage = FindGO<Stage>("stage");
	ironball = FindGO<IronBall>("ironball");
	if (Set == true)
	{
		if (stage->StageOrder[game->Level] == 0)
		{
			Character_P = SetPosition[5][1];
			Character_R.SetRotationY({180.0f});
		}

		if (stage->StageOrder[game->Level] == 1)
		{
			Character_P = SetPosition[2][0];
		}

		if (stage->StageOrder[game->Level] == 2)
		{
			Character_P = SetPosition[1][0];
		}

		if (stage->StageOrder[game->Level] == 3)
		{
			Character_P = SetPosition[2][0];
		}
		
		if (stage->StageOrder[game->Level] == 4)
		{
			Character_P = SetPosition[9][0];
		}

		if (stage->StageOrder[game->Level] == 5)
		{
			Character_P = SetPosition[2][0];
		}

		if (stage->StageOrder[game->Level] == 6)
		{
			Character_P = SetPosition[0][0];
		}
		
		if (stage->StageOrder[game->Level] == 7)
		{
			Character_P = SetPosition[0][0];
		}

		if (stage->StageOrder[game->Level] == 8)
		{
			Character_P = SetPosition[0][0];
		}
		
		if (stage->StageOrder[game->Level] == 9)
		{
			Character_P = SetPosition[0][0];
		}

		Character.SetPosition(Character_P);
		Character.SetScale({ 1.5f,1.5f,1.5f });

		CharacterController.Init(40.0f, 120.0f, Character_P);
		Set = false;
	}


	MoveSpeed.y = -5.0f;

	//鉄球を回収も置いたりもしていないとき
	if (get_IronAnim == false || put_IronAnim == false)
	{
		//移動処理
		Move();
		//回転処理
		Rotation();
	}
	//鉄球処理
	Ball();
	//プレイヤーステート処理
	ManageState();
	//アニメーション処理
	Animation();
	//ステータス表示処理
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

	//スティックの入力量の取得
	StickL.x = g_pad[0]->GetLStickYF();
	StickL.y = g_pad[0]->GetLStickXF();

	hitflag = false;
	PhysicsWorld::GetInstance()->ContactTest(CharacterController, [&](const btCollisionObject& contactObject) {
	//右から左
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
	//左から右
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
	//下から上
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
	//上から下
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
		//移動速度の初期化
		MoveSpeed.x = 0.0f;
		MoveSpeed.z = 0.0f;
		if (CharacterController.IsOnGround() == true) {

			//プレイヤーの移動
			MoveSpeed.x += StickL.x * (-9.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
			MoveSpeed.z += StickL.y * (9.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
			if (abs(MoveSpeed.x) > abs(MoveSpeed.z))
			{
				MoveSpeed.z = 0.0f;
			}

			if (abs(MoveSpeed.x) < abs(MoveSpeed.z))
			{
				MoveSpeed.x = 0.0f;
			}

			if (abs(MoveSpeed.x) == abs(MoveSpeed.z) || put_IronAnim == true || get_IronAnim == true || game->ClearFlag == true)
			{
				MoveSpeed.x = 0.0f;
				MoveSpeed.z = 0.0f;
			}
		}
	}else{
	if (slipflag == true)
	{
		if (EnterDirection == Up)
		{
			MoveSpeed.z = 0.0f;
			MoveSpeed.x = (-13.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
			if (stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == ICE || stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Down)
		{
			MoveSpeed.z = 0.0f;
			MoveSpeed.x = (13.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
			if (stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == ICE || stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Right)
		{
			MoveSpeed.x = 0.0f;
			MoveSpeed.z = (13.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
			if (stage->mapdata[(player_map / 10)][(player_map % 10) + 1].grounddata == ICE || stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Left)
		{
			MoveSpeed.x = 0.0f;
			MoveSpeed.z = (-13.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
			if (stage->mapdata[(player_map / 10)][(player_map % 10) - 1].grounddata == ICE || stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == HOLE)
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
		//	//プレイヤーの移動

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
	if (MoveSpeed.x == 0.0f || MoveSpeed.z == 0.0f)
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

	//キャラクターコントローラーを使って座標の移動
	Character_P = CharacterController.Execute(MoveSpeed, 1.0);

	//slipflag = false;

	if (game->ClearFlag == true && BgmSet == false)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->Init(S_KAIDAN);
		SE->SetVolume(0.7f);
		SE->Play(false);
		BgmSet = true;
	}
}

void Player::Rotation()
{
	if (fabsf(MoveSpeed.x) >= 0.001f || fabsf(MoveSpeed.z) >= 0.001f)
	{
		//キャラクターの方向変更
		Character_R.SetRotationYFromDirectionXZ(MoveSpeed);
	}
}

void Player::Ball()
{
	//鉄球クラスで鉄球の所持数を変えるためにフラグ変数を変更する
	if (g_pad[0]->IsTrigger(enButtonA) && ironBall < 5 && stage->mapdata[(player_map / 10)][(player_map % 10)].grounddata == GROUND)
	{
		SoundSource* SE = NewGO<SoundSource>(0);
		SE->Init(S_IRONBALLGET);
		SE->SetVolume(0.5f);
		SE->Play(false);
		get_Iron = true;
		ironball->Ball_map[(player_map / 10)][(player_map % 10)] = false;
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

	if (g_pad[0]->IsTrigger(enButtonB) && ironBall > 0 && stage->mapdata[(player_map / 10)][(player_map % 10)].grounddata == GROUND)
	{
		if (ironball->Ball_map[(player_map / 10)][(player_map % 10)] == false)
		{
			SoundSource* SE = NewGO<SoundSource>(0);
			SE->Init(S_IRONBALLPUT);
			SE->SetVolume(0.5f);
			SE->Play(false);
			put_Iron = true;
			ironball->Ball_map[(player_map / 10)][(player_map % 10)] = true;
		}
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
	//プレイヤーステートの変更
		if (CharacterController.IsOnGround() == false)
		{
			//落下
			playerState = 2;
		}
		else if (put_IronAnim == true)
		{
			//置き
			playerState = 3;
		}
		else if (get_IronAnim == true)
		{
			//回収
			playerState = 3;
		}
		else if (slipflag == true)
		{
			//滑り
			playerState = 4;
		}
		else if(StickL.x != 0 || StickL.y != 0)
		{
			//歩き
			playerState = 1;
		}
		else 
		{
			playerState = 0;
		}
		
		if (Character_P.y <= -30.0f && FallSet == false)
		{
			FallSet = true;
			SoundSource* SE = NewGO<SoundSource>(0);
			SE->Init(S_FALL);
			SE->SetVolume(0.4f);
			SE->Play(false);
		}
}

void Player::Animation()
{
	switch (playerState)
	{
	//立ちモーション
	case 0:
		Character.PlayAnimation(enAnimationClip_Idle, 0.2f);
		break;
	//歩きモーション
	case 1:
		Character.PlayAnimation(enAnimationClip_Walk, 0.2f);
		break;
	//落下モーション
	case 2:
		Character.PlayAnimation(enAnimationClip_Jump, 0.2f);
		break;
	//設置モーション
	case 3:
		Character.PlayAnimation(enAnimationClip_Put);
		if (put_IronAnim == true)
		{
			Frame++;
			if (Frame >= 30)
			{
				put_IronAnim = false;
				Frame = 0;
			}
		}
		if (get_IronAnim == true)
		{
			Frame++;
			if (Frame >= 30)
			{
				get_IronAnim = false;
				Frame = 0;
			}
		}
		break;
	case 4:
		Character.PlayAnimation(enAnimationClip_Slip);
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
	
	wchar_t a[256];
	swprintf_s(a, 256, L"%d",player_map);
	as.SetText(a);
	as.SetPosition(Vector3(-852.0f, 350.0f, 0.0f));
	as.SetScale(1.0f);
}

void Player::Render(RenderContext& rc)
{
	Character.Draw(rc);
	asb.Draw(rc);
	//as.Draw(rc);
	if (hitflag == true)
	{
		
	}

}