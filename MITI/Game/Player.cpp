#include "stdafx.h"
#include "Player.h"
#include "Box.h"
#include "Stage.h"
#include "Game.h"

Player::Player()
{
	Set = true;

	//アニメーション呼び出し
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Put].Load("Assets/animData/put.tka");
	m_animationClips[enAnimationClip_Put].SetLoopFlag(false);

	modelRender.Init("Assets/modelData/unityChan.tkm",playerLight, m_animationClips, enAnimationClip_Num, enModelUpAxisY);

	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			SetPosition[L][R].x = (L * 192.0f) + -865.0f;
			SetPosition[L][R].y = 0.0f;
			SetPosition[L][R].z = (R * 192.0f) + -865.0f;
		}
	}

}

Player::~Player()
{

}

void Player::Update()
{

	game = FindGO<Game>("game");

	if (Set == true)
	{
		if (game->Level == 1)
		{
			player_P = SetPosition[1][0];
		}

		if (game->Level == 2)
		{
			player_P = SetPosition[2][0];
		}
		
		if (game->Level == 3)
		{
			player_P = SetPosition[9][0];
		}

		modelRender.SetPosition(player_P);
		modelRender.SetScale({ 2.5f,2.5f,2.5f });

		characterController.Init(40.0f, 120.0f, player_P);
		Set = false;
	}


	moveSpeed.y = -5.0f;

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

	modelRender.SetPosition(player_P);
	modelRender.SetRotation(rotation);
	modelRender.Update();
}

void Player::Move()
{

	if (player_P.y <= -250.0)
	{
		game->GameOverFlag = true;
	}

	moveSpeed.y = -5.0f;

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
	PhysicsWorld::GetInstance()->ContactTest(characterController, [&](const btCollisionObject& contactObject) {
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
		moveSpeed.x = 0.0f;
		moveSpeed.z = 0.0f;

		//プレイヤーの移動
		moveSpeed.x += StickL.x * (-5.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
		moveSpeed.z += StickL.y * (5.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
	}else{
	if (slipflag == true)
	{
		if (EnterDirection == Up)
		{
			if (stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == ICE && stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Down)
		{
			if (stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == ICE && stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Right)
		{
			if (stage->mapdata[(player_map / 10)][(player_map % 10) + 1].grounddata == ICE && stage->mapdata[(player_map / 10) + 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}else {
		if (EnterDirection == Left)
		{
			if (stage->mapdata[(player_map / 10)][(player_map % 10) - 1].grounddata == ICE && stage->mapdata[(player_map / 10) - 1][(player_map % 10)].grounddata == HOLE)
			{
				slipflag = true;
			}
		}
		}
		}
		}
	}
		//if (player_P.x == savePos.x && player_P.z == savePos.z)
		//{
		//	moveSpeed.x = 0.0f;
		//	moveSpeed.z = 0.0f;
		//	//プレイヤーの移動

		//	moveSpeed.x += StickL.x * (-5.0f + ironBall / 4)/*-(0.8f * (6 - ironBall))*/;
		//	moveSpeed.z += StickL.y * (5.0f - ironBall / 4)/*(0.8f * (6 - ironBall))*/;
		//	//slipflag = false;
		//}else{
		//	savePos.x = player_P.x;
		//	savePos.z = player_P.z;
		//}
	}

	if (moveSpeed.x < 0.0f)
	{
		EnterDirection = Up;
	}else {
	if (moveSpeed.x > 0.0f)
	{
		EnterDirection = Down;
	}else {
	if (moveSpeed.z > 0.0f)
	{
		EnterDirection = Right;
	}else {
	if (moveSpeed.z < 0.0f)
	{
		EnterDirection = Left;
	}
	}
	}
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

	//キャラクターコントローラーを使って座標の移動
	player_P = characterController.Execute(moveSpeed, 1.0);

	//slipflag = false;
}

void Player::Rotation()
{
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//キャラクターの方向変更
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
	}
}

void Player::Ball()
{
	//鉄球クラスで鉄球の所持数を変えるためにフラグ変数を変更する
	if (g_pad[0]->IsTrigger(enButtonA) && ironBall < 5)
	{
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
	//プレイヤーステートの変更
		if (characterController.IsOnGround() == false)
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
		else if (StickL.x != 0 || StickL.y != 0 && slipflag == false)
		{
			//歩き
			playerState = 1;
		}
		else
		{
			//立ち
			playerState = 0;
		}
}

void Player::Animation()
{
	switch (playerState)
	{
	//立ちモーション
	case 0:
		modelRender.PlayAnimation(enAnimationClip_Idle, 0.2f);
		break;
	//歩きモーション
	case 1:
		modelRender.PlayAnimation(enAnimationClip_Walk, 0.2f);
		break;
	//落下モーション
	case 2:
		modelRender.PlayAnimation(enAnimationClip_Jump, 0.2f);
		break;
		//設置モーション
	case 3:
		modelRender.PlayAnimation(enAnimationClip_Put);
		if (put_IronAnim == true)
		{
			put_IronAnim = false;
		}
		if (get_IronAnim == true)
		{
			get_IronAnim = false;
		}
		break;
	//
	default:
		break;
	}
}

void Player::Status()
{
	////座標を確認するためのプログラム
	for (int L = 0; L < 10; L++)
	{
		for (int R = 0; R < 10; R++)
		{
			if (
				player_P.x < SetPosition[L][R].x + 96 &&
				player_P.x > SetPosition[L][R].x - 96 &&
				player_P.z < SetPosition[L][R].z + 96 &&
				player_P.z > SetPosition[L][R].z - 96
				)
			{
				player_map = (L * 10) + R;
			}
		}
	}
	

	//プレイヤーの座標の表示
	wchar_t playerX[256];
	//swprintf_s(playerX, 256, L"%d",player_map);
	if (slipflag == true)
	{
		swprintf_s(playerX, 256, L"滑っている:%d", player_map);
	}else {
	{
	if (slipflag == false)
		swprintf_s(playerX, 256, L"滑っていない:%d", player_map);
	}
	}
	//swprintf_s(playerX, 256, L"残り時間:%d", int(player_P.x));
	//表示するテキストを設定。
	fontRender.SetText(playerX);
	//フォントの位置を設定。
	fontRender.SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
	//フォントの大きさを設定。
	fontRender.SetScale(1.0f);

	
	//表示するテキストを設定。
	as.SetText(L"衝突");
	//フォントの位置を設定。
	as.SetPosition(Vector3(-852.0f, 350.0f, 0.0f));
	//フォントの大きさを設定。
	as.SetScale(1.0f);

	//wchar_t playerZ[256];
	//swprintf_s(playerZ, 256, L"z座標:%d", int(player_P.z));
	////表示するテキストを設定。
	//fontRender.SetText(playerZ);
	////フォントの位置を設定。
	//fontRender.SetPosition(Vector3(-852.0f, 250.0f, 0.0f));
	////フォントの大きさを設定。
	//fontRender.SetScale(1.0f);
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
	fontRender.Draw(rc);
	if (hitflag == true)
	{
		as.Draw(rc);
	}

}