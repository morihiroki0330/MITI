#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	AllLight Light;
	Light.DirectionLight_D = { 1.0f,-1.0f,-1.0f };
	Light.DirectionLight_C = { 1.0f,1.0f,1.0f,0.0f };
	//アニメーション呼び出し
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

	//キャラクターコントローラーの初期化
	characterController.Init(25.0f, 75.0f, player_P);
}

Player::~Player()
{
	//

}

void Player::Update()
{
	//

	//スティックの入力量の取得
	StickL.x = g_pad[0]->GetLStickYF();
	StickL.y = g_pad[0]->GetLStickXF();

	//移動処理
	Move();
	//回転処理
	Rotation();
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
	if (slipflag == false)
	{
		//移動速度の初期化
		moveSpeed.x = 0.0f;
		moveSpeed.z = 0.0f;

		//プレイヤーの移動
		moveSpeed.x += StickL.x * -(0.8f * (6 - ironBall));
		moveSpeed.z += StickL.y * (0.8f * (6 - ironBall));
	}
	else
	{
		//氷の床に乗った時のプレイヤーの移動
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

	//キャラクターコントローラーを使って座標の移動
	player_P = characterController.Execute(moveSpeed, 1.0f);
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

	if (g_pad[0]->IsTrigger(enButtonB) && ironBall > 0)
	{
		put_Iron = true;
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
	else if (put_Iron == true)
	{
		//置き
		playerState = 3;
	}
	else if (get_Iron == true)
	{
		//回収
		playerState = 3;
	}
	else if (StickL.x != 0 && StickL.y != 0)
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
		break;
	//
	default:
		break;
	}
}

void Player::Status()
{
	//持っている鉄球の数の表示
	wchar_t iron[256];
	swprintf_s(iron, 256, L"所持鉄球:%d", int(ironBall));
	//表示するテキストを設定。
	fontRender.SetText(iron);
	//フォントの位置を設定。
	fontRender.SetPosition(Vector3(-952.0f, 450.0f, 0.0f));
	//フォントの大きさを設定。
	fontRender.SetScale(1.0f);

	//座標を確認するためのプログラム

	////プレイヤーの座標の表示
	//wchar_t playerX[256];
	//swprintf_s(playerX, 256, L"x座標:%d", int(player_P.x));
	////表示するテキストを設定。
	//fontRender.SetText(playerX);
	////フォントの位置を設定。
	//fontRender.SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
	////フォントの大きさを設定。
	//fontRender.SetScale(1.0f);

	//wchar_t playerZ[256];
	//swprintf_s(playerZ, 256, L"z座標:%d", int(player_P.z));
	////表示するテキストを設定。
	//fontRender.SetText(playerZ);
	////フォントの位置を設定。
	//fontRender.SetPosition(Vector3(-852.0f, 450.0f, 0.0f));
	////フォントの大きさを設定。
	//fontRender.SetScale(1.0f);
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
	fontRender.Draw(rc);
}