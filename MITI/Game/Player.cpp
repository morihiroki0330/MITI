#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	modelRender.Init("Assets/modelData/unityChan.tkm");

	player_P.x = 0.0f;
	player_P.y = 0.0f;
	player_P.z = 0.0f;

	modelRender.SetPosition(player_P);

	//キャラクターコントローラーの初期化
	characterController.Init(25.0f, 75.0f, player_P);
}

Player::~Player()
{

}

void Player::Update()
{
	//

	//スティックの入力量の取得
	StickL.x = g_pad[0]->GetLStickXF();
	StickL.y = g_pad[0]->GetLStickYF();

	//移動処理
	Move();
	//回転処理
	Rotation();
	//鉄球処理
	Ball();
	//アニメーション処理
	Animation();

	modelRender.SetPosition(player_P);
	modelRender.SetRotation(rotation);
	modelRender.Update();
}

void Player::Move()
{
	//移動速度の初期化
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//プレイヤーの移動
	moveSpeed.x += StickL.x * (0.8f * (6 - ironBall));
	moveSpeed.z += StickL.y * (0.8f * (6 - ironBall));

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
	//とりあえず無条件で鉄球増減
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
	//プレイヤーステートの変更
	if (player_P.y < 0)
	{
		//落下
		playerState = 2;
	}
	else if (StickL.x == 0 && StickL.y == 0)
	{
		//立ち
		playerState = 0;
	}
	else
	{
		//歩き
		playerState = 1;
	}

	switch (playerState)
	{
	//立ちモーション
	case 0:
		break;
	//歩きモーション
	case 1:
		break;
	//落下モーション
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